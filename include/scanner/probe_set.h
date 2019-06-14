#ifndef NXSCANNER_INCLUDE_SCANNER_PROBE_SET_H_
#define NXSCANNER_INCLUDE_SCANNER_PROBE_SET_H_

#include "probe.h"

namespace nxscan::scanner {
class Probes {
 public:
  Probes(Probe domain, Probe host, Probe randomHost)
      : domain(std::move(domain)), host(std::move(host)), randomHost(std::move(randomHost)) {}

  Probe &getDomain();
  Probe &getHost();
  Probe &getRandomHost();
  const Probe &getDomain() const;
  const Probe &getHost() const;
  const Probe &getRandomHost() const;

 private:
  Probe domain;
  Probe host;
  Probe randomHost;
};
}

#endif //NXSCANNER_INCLUDE_SCANNER_PROBE_SET_H_