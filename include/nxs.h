#ifndef NXSCANNER_INCLUDE_NXS_H_
#define NXSCANNER_INCLUDE_NXS_H_

#include <stdint-gcc.h>
#include <ostream>

namespace nxs {
static const constexpr uint32_t versionMajor{1};
static const constexpr uint32_t versionMinor{2};

int scannerFoo(std::ostream &, int argc, char **argv);
}

#endif //NXSCANNER_INCLUDE_NXS_H_
