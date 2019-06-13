
#include "../include/scanner/probe.h"
#include "../include/scanner/probe_set.h"
#include <gtest/gtest.h>

using nxscan::scanner::Probe;
using nxscan::scanner::Probes;

Probe domain{"example.com"};
Probe host{"www.example.com"};
Probe invalid{"abcde.example.com"};

TEST(Probes, test_get_domain_reference) {
  Probes probes{domain, host, invalid};
  Probe &r_domain{probes.get_t1_domain()};
  ASSERT_EQ(domain, r_domain);
}

TEST(Probes, test_get_domain_const_reference) {
  Probes probes{domain, host, invalid};
  const Probe &cr_domain{probes.get_t1_domain()};
  ASSERT_EQ(domain, cr_domain);
}

TEST(Probes, test_get_host_reference) {
  Probes probes{domain, host, invalid};
  Probe &r_host{probes.get_t2_host()};
  ASSERT_EQ(host, r_host);
}

TEST(Probes, test_get_host_const_reference) {
  Probes probes{domain, host, invalid};
  const Probe &cr_host{probes.get_t2_host()};
  ASSERT_EQ(host, cr_host);
}

TEST(Probes, test_get_random_reference) {
  Probes probes{domain, host, invalid};
  Probe &r_random{probes.get_t3_random()};
  ASSERT_EQ(invalid, r_random);
}

TEST(Probes, test_get_random_const_reference) {
  Probes probes{domain, host, invalid};
  Probe &cr_random{probes.get_t3_random()};
  ASSERT_EQ(invalid, cr_random);
}
