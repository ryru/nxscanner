#ifndef NXSCANNER_INCLUDE_SCANNER_PROBE_H_
#define NXSCANNER_INCLUDE_SCANNER_PROBE_H_

#include <string>

namespace nxscan::scanner {
class Probe {
 public:
  explicit Probe(std::string domainname) : domainname{std::move(domainname)} {}

  const std::string &getDomainname() const;
  const std::string &getIpAddress() const;
  void setIpAddress(const std::string &ip);
  void setIsValidDomainname(bool isValid);
  bool isValid() const;

 private:
  std::string domainname;
  std::string ipAddress;
  bool isValidDomainname{};
};

bool operator==(const Probe &lhs, const Probe &rhs);
}

#endif //NXSCANNER_INCLUDE_SCANNER_PROBE_H_
