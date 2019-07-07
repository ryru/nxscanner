#include "scanner/probe.h"
#include <gtest/gtest.h>

using nxs::scanner::Probe;

TEST(Probe, testGetDomainname) {
  Probe probe{"example.com"};
  std::string expected{"example.com"};
  ASSERT_EQ(expected, probe.getDomainName());
}

TEST(Probe, testGetIp) {
  Probe probe{"example.com"};
  std::string expected;
  ASSERT_EQ(expected, probe.getIpAddress());
}

TEST(Probe, testSetIp) {
  Probe probe{"example.com"};
  probe.setIpAddress("127.0.0.1");
  std::string expected{"127.0.0.1"};
  ASSERT_EQ(expected, probe.getIpAddress());
}

TEST(Probe, testIsValid) {
  Probe probe{"example.com"};
  bool expected{false};
  ASSERT_EQ(expected, probe.isValid());
}

TEST(Probe, testSetValid) {
  Probe probe{"example.com"};
  probe.setIsValidDomainName(true);
  bool expected{true};
  ASSERT_EQ(expected, probe.isValid());
}

TEST(Probe, testEqualOperator) {
  Probe probe1{"example.com"};
  Probe probe2{"example.com"};
  ASSERT_EQ(probe1, probe2);
}
