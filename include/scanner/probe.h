#ifndef NXSCANNER_INCLUDE_SCANNER_PROBE_H_
#define NXSCANNER_INCLUDE_SCANNER_PROBE_H_

#include <string>
#include <utility>

namespace nxs::scanner {
class Probe {
 public:
  explicit Probe(std::string domainName) : domainName{std::move(domainName)} {}

  const std::string &getDomainName() const;
  const std::string &getIpAddress() const;
  void setIpAddress(const std::string &ip);
  void setIsValidDomainName(bool isValid);
  bool isValid() const;

 private:
  std::string const domainName;
  std::string ipAddress;
  bool isValidDomainName{};
};

bool operator==(Probe const &lhs, Probe const &rhs);
}

#endif //NXSCANNER_INCLUDE_SCANNER_PROBE_H_
