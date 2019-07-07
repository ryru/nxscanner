#ifndef NXSCANNER_INCLUDE_SCANNER_SCANNER_H_
#define NXSCANNER_INCLUDE_SCANNER_SCANNER_H_

#include "probe_set.h"

#include <vector>

namespace nxs::scanner {

class Scanner {
 public:
  explicit Scanner(std::vector<nxs::scanner::Probes> &allProbes) : allProbes{allProbes} {}
  void scan();

 private:
  std::vector<nxs::scanner::Probes> &allProbes;
};
}

#endif //NXSCANNER_INCLUDE_SCANNER_SCANNER_H_
