#ifndef NXSCANNER_INCLUDE_SCANNER_PREPARATION_H_
#define NXSCANNER_INCLUDE_SCANNER_PREPARATION_H_

#include "probe_set.h"

#include <string>
#include <vector>

namespace nxs::scanner {

std::vector<nxs::scanner::Probes> getProbes(std::vector<std::string> const &allDomain);

}
#endif //NXSCANNER_INCLUDE_SCANNER_PREPARATION_H_
