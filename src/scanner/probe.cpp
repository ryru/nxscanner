#include "scanner/probe.h"

const std::string &nxscan::scanner::Probe::get_hostname() const {
  return hostname;
}
const std::string &nxscan::scanner::Probe::get_ip_address() const {
  return ip_address;
}
void nxscan::scanner::Probe::set_ip_address(const std::string &ip) {
  Probe::ip_address = ip;
}

void nxscan::scanner::Probe::set_is_valid_hostname(bool is_valid) {
  Probe::is_valid_hostname = is_valid;
}
bool nxscan::scanner::Probe::is_valid() const {
  return is_valid_hostname;
}
bool nxscan::scanner::operator==(const nxscan::scanner::Probe &lhs, const nxscan::scanner::Probe &rhs) {
  return lhs.get_hostname() == rhs.get_hostname();
}
