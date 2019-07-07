#include "scanner/probe.h"

const std::string &nxs::scanner::Probe::getDomainName() const {
  return domainName;
}
const std::string &nxs::scanner::Probe::getIpAddress() const {
  return ipAddress;
}
void nxs::scanner::Probe::setIpAddress(const std::string &ip) {
  Probe::ipAddress = ip;
}

void nxs::scanner::Probe::setIsValidDomainName(bool isValid) {
  Probe::isValidDomainName = isValid;
}
bool nxs::scanner::Probe::isValid() const {
  return isValidDomainName;
}
bool nxs::scanner::operator==(nxs::scanner::Probe const &lhs, nxs::scanner::Probe const &rhs) {
  return lhs.getDomainName() == rhs.getDomainName();
}
