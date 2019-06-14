#include "scanner/probe.h"

const std::string &nxscan::scanner::Probe::getDomainname() const {
  return domainname;
}
const std::string &nxscan::scanner::Probe::getIpAddress() const {
  return ipAddress;
}
void nxscan::scanner::Probe::setIpAddress(const std::string &ip) {
  Probe::ipAddress = ip;
}

void nxscan::scanner::Probe::setIsValidDomainname(bool isValid) {
  Probe::isValidDomainname = isValid;
}
bool nxscan::scanner::Probe::isValid() const {
  return isValidDomainname;
}
bool nxscan::scanner::operator==(const nxscan::scanner::Probe &lhs, const nxscan::scanner::Probe &rhs) {
  return lhs.getDomainname() == rhs.getDomainname();
}
