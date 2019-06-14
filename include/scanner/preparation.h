#ifndef NXSCANNER_INCLUDE_SCANNER_PREPARATION_H_
#define NXSCANNER_INCLUDE_SCANNER_PREPARATION_H_

#include "probe_set.h"

#include <string>
#include <vector>


namespace nxscan::scanner {

std::vector<nxscan::scanner::Probes> get_probes(std::vector<std::string> &all_domains);

}
#endif //NXSCANNER_INCLUDE_SCANNER_PREPARATION_H_
