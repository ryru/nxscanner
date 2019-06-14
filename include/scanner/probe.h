#ifndef NXSCANNER_INCLUDE_SCANNER_PROBE_H_
#define NXSCANNER_INCLUDE_SCANNER_PROBE_H_

#include <string>

namespace nxscan::scanner {
class Probe {
 public:
  explicit Probe(std::string hostname) : hostname{std::move(hostname)} {}

  const std::string &get_hostname() const;
  const std::string &get_ip_address() const;
  void set_ip_address(const std::string &ip);
  void set_is_valid_hostname(bool is_valid);
  bool is_valid() const;

 private:
  std::string hostname;
  std::string ip_address;
  bool is_valid_hostname{};
};

bool operator==(const Probe &lhs, const Probe &rhs);
}

#endif //NXSCANNER_INCLUDE_SCANNER_PROBE_H_
