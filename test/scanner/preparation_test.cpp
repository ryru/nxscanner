#include "scanner/preparation.h"
#include "scanner/probe_set.h"
#include <gtest/gtest.h>

#include <vector>

TEST(Preparation, testDomain) {
  std::string expect{"example.com"};
  std::vector<std::string> domains{expect};
  std::vector<nxs::scanner::Probes> probes = nxs::scanner::getProbes(domains);
  ASSERT_EQ(expect, probes[0].getDomain().getDomainName());
}

TEST(Preparation, testHost) {
  std::string domain{"example.com"};
  std::string expect{"www.example.com"};
  std::vector<std::string> domains{domain};
  std::vector<nxs::scanner::Probes> probes = nxs::scanner::getProbes(domains);
  ASSERT_EQ(expect, probes[0].getHost().getDomainName());
}
