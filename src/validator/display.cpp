#include "validator/display.h"

#include <algorithm>

void nxscan::validator::Display::print() {
  std::for_each(allProbes.begin(), allProbes.end(), [&](nxscan::scanner::Probes const &p) {
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
void nxscan::validator::Display::printBlockedDomain(nxscan::scanner::Probes const &p) const {
  printAllResult(p.getDomain().getDomainName(), "!", "is potentially DNS blocked");

}
void nxscan::validator::Display::printNonBlockedDomain(nxscan::scanner::Probes const &p) const {
  printAllResult(p.getDomain().getDomainName(), " ", "is okay");

}
void nxscan::validator::Display::printNonResolvableDomain(nxscan::scanner::Probes const &p) const {
  printAllResult(p.getDomain().getDomainName(), " ", "is not resolvable");
}
void nxscan::validator::Display::printAllResult(std::string const &hostname,
                                                std::string &&prefix,
                                                std::string &&postfix) const {
  out << prefix;
  out << hostname;
  out << " ";
  out << postfix;
  out << '\n';

}
