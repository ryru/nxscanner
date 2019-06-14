#ifndef NXSCANNER_INCLUDE_SCANNER_PREPARATION_H_
#define NXSCANNER_INCLUDE_SCANNER_PREPARATION_H_

#include "probe_set.h"

#include <string>
#include <vector>


namespace nxscan::scanner {

std::vector<nxscan::scanner::Probes> getProbes(std::vector<std::string> &allDomain);

}
#endif //NXSCANNER_INCLUDE_SCANNER_PREPARATION_H_
