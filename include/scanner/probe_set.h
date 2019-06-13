#ifndef NXSCANNER_INCLUDE_SCANNER_PROBE_SET_H_
#define NXSCANNER_INCLUDE_SCANNER_PROBE_SET_H_

#include "probe.h"

namespace nxscan::scanner {
class Probes {
 public:
  Probes(Probe t1_domain, Probe t2_host, Probe t3_random)
      : t1_domain(std::move(t1_domain)), t2_host(std::move(t2_host)), t3_random(std::move(t3_random)) {}

  Probe &get_t1_domain() {
    return t1_domain;
  }

  Probe &get_t2_host() {
    return t2_host;
  }

  Probe &get_t3_random() {
    return t3_random;
  }

  const Probe &get_t1_domain() const {
    return t1_domain;
  }

  const Probe &get_t2_host() const {
    return t2_host;
  }

  const Probe &get_t3_random() const {
    return t3_random;
  }

 private:
  Probe t1_domain;
  Probe t2_host;
  Probe t3_random;
};
}

#endif //NXSCANNER_INCLUDE_SCANNER_PROBE_SET_H_