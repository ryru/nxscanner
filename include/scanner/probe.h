#ifndef NXSCANNER_INCLUDE_SCANNER_PROBE_H_
#define NXSCANNER_INCLUDE_SCANNER_PROBE_H_

#include <string>

namespace nxscan::scanner {
class Probe {
 public:
  explicit Probe(std::string hostname) : hostname{std::move(hostname)} {}

  const std::string &get_hostname() const {
    return hostname;
  }

  const std::string &get_ip_address() const {
    return ip_address;
  }
  void set_ip_address(const std::string &ip) {
    Probe::ip_address = ip;
  }

  void set_is_valid_hostname(bool is_valid) {
    Probe::is_valid_hostname = is_valid;
  }

  bool is_valid() const {
    return is_valid_hostname;
  }

 private:
  std::string hostname;
  std::string ip_address;
  bool is_valid_hostname{};
};

inline bool operator==(const Probe &lhs, const Probe &rhs) {
  return lhs.get_hostname() == rhs.get_hostname();
}
}

#endif //NXSCANNER_INCLUDE_SCANNER_PROBE_H_
