#include "scanner/preparation.h"
#include "scanner/probe_set.h"
#include <gtest/gtest.h>

#include <vector>

TEST(Preparation, test_domain) {
  std::string expect{"example.com"};
  std::vector<std::string> domains{expect};
  std::vector<nxscan::scanner::Probes> probes = nxscan::scanner::get_probes(domains);
  ASSERT_EQ(expect, probes[0].get_t1_domain().get_hostname());
}

TEST(Preparation, test_host) {
  std::string domain{"example.com"};
  std::string expect{"www.example.com"};
  std::vector<std::string> domains{domain};
  std::vector<nxscan::scanner::Probes> probes = nxscan::scanner::get_probes(domains);
  ASSERT_EQ(expect, probes[0].get_t2_host().get_hostname());
}
