#ifndef NXSCANNER_INCLUDE_VALIDATOR_DISPLAY_H_
#define NXSCANNER_INCLUDE_VALIDATOR_DISPLAY_H_

#include "scanner/probe_set.h"

#include <ostream>
#include <vector>

namespace nxscan::validator {

class Display {

 public:
  Display(std::ostream &out, const std::vector<nxscan::scanner::Probes> &all_probes) : out{out},
                                                                                       all_probes{all_probes} {}
  void print();
  uint32_t get_hostname_total() const;
  uint32_t get_dns_blocks() const;

 private:
  std::ostream &out;
  const std::vector<nxscan::scanner::Probes> &all_probes;
  unsigned int hostname_total{0};
  unsigned int dns_blocks{0};

  void print_blocked(const nxscan::scanner::Probes &p);
  void print_non_blocked(const nxscan::scanner::Probes &p);
  void print_non_resolvable(const nxscan::scanner::Probes &p);
  void print_result(const std::string &hostname, std::string &&prefix, std::string &&postfix);

};

}

#endif //NXSCANNER_INCLUDE_VALIDATOR_DISPLAY_H_