#ifndef NXSCANNER_INCLUDE_VALIDATOR_INPUT_H_
#define NXSCANNER_INCLUDE_VALIDATOR_INPUT_H_

#include <string>
#include <variant>
#include <vector>

namespace nxscan::validator {

std::variant<std::vector<std::string>, std::string> parse(int argc, char **argv);
}

#endif //NXSCANNER_INCLUDE_VALIDATOR_INPUT_H_
