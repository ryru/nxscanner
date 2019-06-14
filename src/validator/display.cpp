#include "validator/display.h"

#include <algorithm>

void nxscan::validator::Display::print() {
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
unsigned int nxscan::validator::Display::get_hostname_total() const {
  return hostname_total;
}
unsigned int nxscan::validator::Display::get_dns_blocks() const {
  return dns_blocks;
}
void nxscan::validator::Display::print_blocked(const nxscan::scanner::Probes &p) {
  print_result(p.get_t1_domain().get_hostname(), "!", "is potentially DNS blocked");

}
void nxscan::validator::Display::print_non_blocked(const nxscan::scanner::Probes &p) {
  print_result(p.get_t1_domain().get_hostname(), " ", "is okay");

}
void nxscan::validator::Display::print_non_resolvable(const nxscan::scanner::Probes &p) {
  print_result(p.get_t1_domain().get_hostname(), " ", "is not resolvable");
}
void nxscan::validator::Display::print_result(const std::string &hostname,
                                              std::string &&prefix,
                                              std::string &&postfix) {
  out << prefix;
  out << hostname;
  out << " ";
  out << postfix;
  out << '\n';

}
