#include "scanner/probe.h"

const std::string &nxscan::scanner::Probe::getDomainName() const {
  return domainName;
}
const std::string &nxscan::scanner::Probe::getIpAddress() const {
  return ipAddress;
}
void nxscan::scanner::Probe::setIpAddress(const std::string &ip) {
  Probe::ipAddress = ip;
}

void nxscan::scanner::Probe::setIsValidDomainName(bool isValid) {
  Probe::isValidDomainName = isValid;
}
bool nxscan::scanner::Probe::isValid() const {
  return isValidDomainName;
}
bool nxscan::scanner::operator==(nxscan::scanner::Probe const &lhs, nxscan::scanner::Probe const &rhs) {
  return lhs.getDomainName() == rhs.getDomainName();
}
