#ifndef NXSCANNER_INCLUDE_SCANNER_PROBE_SET_H_
#define NXSCANNER_INCLUDE_SCANNER_PROBE_SET_H_

#include "probe.h"

#include <utility>

namespace nxs::scanner {
class Probes {
 public:
  Probes(Probe domain, Probe host, Probe randomHost)
      : domain(std::move(domain)), host(std::move(host)), randomHost(std::move(randomHost)) {}

  Probe &getDomain();
  Probe &getHost();
  Probe &getRandomHost();
  Probe const &getDomain() const;
  Probe const &getHost() const;
  Probe const &getRandomHost() const;

 private:
  Probe domain;
  Probe host;
  Probe randomHost;
};
}

#endif //NXSCANNER_INCLUDE_SCANNER_PROBE_SET_H_