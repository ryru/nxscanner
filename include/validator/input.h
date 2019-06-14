#ifndef NXSCANNER_INCLUDE_VALIDATOR_INPUT_H_
#define NXSCANNER_INCLUDE_VALIDATOR_INPUT_H_

#include <ostream>
#include <vector>
#include <string>

namespace nxscan::validator {

std::vector<std::string> parse(std::ostream &out, int argc, char **argv);
}

#endif //NXSCANNER_INCLUDE_VALIDATOR_INPUT_H_
