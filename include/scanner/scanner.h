#ifndef NXSCANNER_INCLUDE_SCANNER_SCANNER_H_
#define NXSCANNER_INCLUDE_SCANNER_SCANNER_H_

#include "probe_set.h"
#include "resolver.h"

#include <vector>

namespace nxscan::scanner {

class Scanner {
 public:
  explicit Scanner(std::vector<nxscan::scanner::Probes> &all_probes) : all_probes{all_probes} {}
  void scan();

 private:
  std::vector<nxscan::scanner::Probes> &all_probes;
};
}

#endif //NXSCANNER_INCLUDE_SCANNER_SCANNER_H_
