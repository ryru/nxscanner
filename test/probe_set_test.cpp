
#include "../include/scanner/probe.h"
#include "../include/scanner/probe_set.h"
#include <gtest/gtest.h>

using nxscan::scanner::Probe;
using nxscan::scanner::Probes;

Probe domain{"example.com"};
Probe host{"www.example.com"};
Probe invalid{"abcde.example.com"};

TEST(Probes, testTetDomainReference) {
  Probes probes{domain, host, invalid};
  Probe &rDomain{probes.getDomain()};
  ASSERT_EQ(domain, rDomain);
}

TEST(Probes, testGetDomainConstReference) {
  Probes probes{domain, host, invalid};
  const Probe &crDomain{probes.getDomain()};
  ASSERT_EQ(domain, crDomain);
}

TEST(Probes, testGetHostReference) {
  Probes probes{domain, host, invalid};
  Probe &rHost{probes.getHost()};
  ASSERT_EQ(host, rHost);
}

TEST(Probes, testGetHostConstReference) {
  Probes probes{domain, host, invalid};
  const Probe &crHost{probes.getHost()};
  ASSERT_EQ(host, crHost);
}

TEST(Probes, testGetRandomReference) {
  Probes probes{domain, host, invalid};
  Probe &rRandom{probes.getRandomHost()};
  ASSERT_EQ(invalid, rRandom);
}

TEST(Probes, testGetRandomConstReference) {
  Probes probes{domain, host, invalid};
  Probe &crRandom{probes.getRandomHost()};
  ASSERT_EQ(invalid, crRandom);
}
