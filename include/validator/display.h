#ifndef NXSCANNER_INCLUDE_VALIDATOR_DISPLAY_H_
#define NXSCANNER_INCLUDE_VALIDATOR_DISPLAY_H_

#include "scanner/probe_set.h"

#include <ostream>
#include <string>
#include <vector>

namespace nxscan::validator {

class Display {

 public:
  Display(std::ostream &out, std::vector<nxscan::scanner::Probes> &allProbes) : out{out}, allProbes{allProbes} {}
  void print();
  uint32_t getDomainTotal() const;
  uint32_t getBlockedDomainTotal() const;

 private:
  std::ostream &out;
  const std::vector<nxscan::scanner::Probes> &allProbes;
  uint32_t domainTotal{0};
  uint32_t blockedDomainTotal{0};

  void printBlockedDomain(nxscan::scanner::Probes const &p) const;
  void printNonBlockedDomain(nxscan::scanner::Probes const &p) const;
  void printNonResolvableDomain(nxscan::scanner::Probes const &p) const;
  void printAllResult(std::string const &hostname, std::string &&prefix, std::string &&postfix) const;
};

}

#endif //NXSCANNER_INCLUDE_VALIDATOR_DISPLAY_H_