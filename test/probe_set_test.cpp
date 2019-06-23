
#include "../include/scanner/probe.h"
#include "../include/scanner/probe_set.h"
#include <gtest/gtest.h>

using nxscan::scanner::Probe;
using nxscan::scanner::Probes;

Probe domain{"example.com"};
Probe host{"www.example.com"};
Probe invalid{"abcde.example.com"};

TEST(Probes, testGetDomainConstReference) {
  Probes probes{domain, host, invalid};
  Probe const &crDomain{probes.getDomain()};
  ASSERT_EQ(domain, crDomain);
}

TEST(Probes, testGetHostConstReference) {
  Probes probes{domain, host, invalid};
  Probe const &crHost{probes.getHost()};
  ASSERT_EQ(host, crHost);
}

TEST(Probes, testGetRandomConstReference) {
  Probes probes{domain, host, invalid};
  Probe const &crRandom{probes.getRandomHost()};
  ASSERT_EQ(invalid, crRandom);
}
