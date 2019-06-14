#include "validator/display.h"

#include <algorithm>

void nxscan::validator::Display::print() {
  std::for_each(allProbes.begin(), allProbes.end(), [&](const nxscan::scanner::Probes &p) {
    domainTotal++;

    if (!p.getDomain().isValid()) {
      printNonResolvableDomain(p);
    } else if (p.getRandomHost().isValid()) {

      bool domain_is_equal_host = (p.getDomain().getIpAddress() == p.getHost().getIpAddress());
      bool domain_is_equal_random = (p.getDomain().getIpAddress() == p.getRandomHost().getIpAddress());

      if (domain_is_equal_host and domain_is_equal_random) {
        blockedDomainTotal++;
        printBlockedDomain(p);
      } else {
        printNonBlockedDomain(p);
      }
    } else {
      printNonBlockedDomain(p);
    }
  });

}
uint32_t nxscan::validator::Display::getDomainTotal() const {
  return domainTotal;
}
uint32_t nxscan::validator::Display::getBlockedDomainTotal() const {
  return blockedDomainTotal;
}
void nxscan::validator::Display::printBlockedDomain(const nxscan::scanner::Probes &p) {
  printAllResult(p.getDomain().getDomainname(), "!", "is potentially DNS blocked");

}
void nxscan::validator::Display::printNonBlockedDomain(const nxscan::scanner::Probes &p) {
  printAllResult(p.getDomain().getDomainname(), " ", "is okay");

}
void nxscan::validator::Display::printNonResolvableDomain(const nxscan::scanner::Probes &p) {
  printAllResult(p.getDomain().getDomainname(), " ", "is not resolvable");
}
void nxscan::validator::Display::printAllResult(const std::string &hostname,
                                                std::string &&prefix,
                                                std::string &&postfix) {
  out << prefix;
  out << hostname;
  out << " ";
  out << postfix;
  out << '\n';

}
