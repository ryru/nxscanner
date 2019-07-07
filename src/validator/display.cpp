#include "validator/display.h"

#include <algorithm>

void nxs::validator::Display::print() {
  std::for_each(allProbes.begin(), allProbes.end(), [&](nxs::scanner::Probes const &p) {
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
uint32_t nxs::validator::Display::getDomainTotal() const {
  return domainTotal;
}
uint32_t nxs::validator::Display::getBlockedDomainTotal() const {
  return blockedDomainTotal;
}
void nxs::validator::Display::printBlockedDomain(nxs::scanner::Probes const &p) const {
  printAllResult(p.getDomain().getDomainName(), "!", "is potentially DNS blocked");

}
void nxs::validator::Display::printNonBlockedDomain(nxs::scanner::Probes const &p) const {
  printAllResult(p.getDomain().getDomainName(), " ", "is okay");

}
void nxs::validator::Display::printNonResolvableDomain(nxs::scanner::Probes const &p) const {
  printAllResult(p.getDomain().getDomainName(), " ", "is not resolvable");
}
void nxs::validator::Display::printAllResult(std::string const &hostname,
                                             std::string &&prefix,
                                             std::string &&postfix) const {
  out << prefix;
  out << hostname;
  out << " ";
  out << postfix;
  out << '\n';

}
