#ifndef NXSCANNER_INCLUDE_VALIDATOR_DISPLAY_H_
#define NXSCANNER_INCLUDE_VALIDATOR_DISPLAY_H_

#include "scanner/probe_set.h"

#include <ostream>
#include <vector>

namespace nxscan::validator {

class Display {

 public:
  Display(std::ostream &out, const std::vector<nxscan::scanner::Probes> &allProbes) : out{out},
                                                                                      allProbes{allProbes} {}
  void print();
  uint32_t getDomainTotal() const;
  uint32_t getBlockedDomainTotal() const;

 private:
  std::ostream &out;
  const std::vector<nxscan::scanner::Probes> &allProbes;
  unsigned int domainTotal{0};
  unsigned int blockedDomainTotal{0};

  void printBlockedDomain(const nxscan::scanner::Probes &p);
  void printNonBlockedDomain(const nxscan::scanner::Probes &p);
  void printNonResolvableDomain(const nxscan::scanner::Probes &p);
  void printAllResult(const std::string &hostname, std::string &&prefix, std::string &&postfix);

};

}

#endif //NXSCANNER_INCLUDE_VALIDATOR_DISPLAY_H_