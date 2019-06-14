#ifndef NXSCANNER_INCLUDE_SCANNER_SCANNER_H_
#define NXSCANNER_INCLUDE_SCANNER_SCANNER_H_

#include "probe_set.h"
#include "resolver.h"

#include <vector>

namespace nxscan::scanner {

class Scanner {
 public:
  explicit Scanner(std::vector<nxscan::scanner::Probes> &allProbes) : allProbes{allProbes} {}
  void scan();

 private:
  std::vector<nxscan::scanner::Probes> &allProbes;
};
}

#endif //NXSCANNER_INCLUDE_SCANNER_SCANNER_H_
