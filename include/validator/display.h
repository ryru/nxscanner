#ifndef NXSCANNER_INCLUDE_VALIDATOR_DISPLAY_H_
#define NXSCANNER_INCLUDE_VALIDATOR_DISPLAY_H_

#include "../scanner/probe_set.h"

#include <algorithm>
#include <ostream>
#include <vector>

namespace nxscan::validator {

class Display {

 public:
  Display(std::ostream &out, const std::vector<nxscan::scanner::Probes> &all_probes) : out{out},
                                                                                       all_probes{all_probes} {}

  void print() {
    std::for_each(all_probes.begin(), all_probes.end(), [&](const nxscan::scanner::Probes &p) {
      hostname_total++;

      if (!p.get_t1_domain().is_valid()) {
        print_non_resolvable(p);
      } else if (p.get_t3_random().is_valid()) {

        bool domain_is_equal_host = (p.get_t1_domain().get_ip_address() == p.get_t2_host().get_ip_address());
        bool domain_is_equal_random = (p.get_t1_domain().get_ip_address() == p.get_t3_random().get_ip_address());

        if (domain_is_equal_host && domain_is_equal_random) {
          dns_blocks++;
          print_blocked(p);
        } else {
          print_non_blocked(p);
        }
      } else {
        print_non_blocked(p);
      }
    });

  }

  unsigned int get_hostname_total() const {
    return hostname_total;
  }
  unsigned int get_dns_blocks() const {
    return dns_blocks;
  }

 private:

  void print_blocked(const nxscan::scanner::Probes &p) {
    print_result(p.get_t1_domain().get_hostname(), "!", "is potentially DNS blocked");
  }

  void print_non_blocked(const nxscan::scanner::Probes &p) {
    print_result(p.get_t1_domain().get_hostname(), " ", "is okay");
  }

  void print_non_resolvable(const nxscan::scanner::Probes &p) {
    print_result(p.get_t1_domain().get_hostname(), " ", "is not resolvable");
  }

  void print_result(const std::string &hostname, std::string &&prefix, std::string &&postfix) {
    out << prefix;
    out << hostname;
    out << " ";
    out << postfix;
    out << '\n';
  }

  std::ostream &out;
  const std::vector<nxscan::scanner::Probes> &all_probes;
  unsigned int hostname_total{0};
  unsigned int dns_blocks{0};
};

}

#endif //NXSCANNER_INCLUDE_VALIDATOR_DISPLAY_H_