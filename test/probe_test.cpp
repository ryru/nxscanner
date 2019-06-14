#include "scanner/probe.h"
#include <gtest/gtest.h>

using nxscan::scanner::Probe;

TEST(Probe, test_get_hostname) {
  Probe probe{"example.com"};
  std::string expected{"example.com"};
  ASSERT_EQ(expected, probe.get_hostname());
}

TEST(Probe, test_get_ip) {
  Probe probe{"example.com"};
  std::string expected;
  ASSERT_EQ(expected, probe.get_ip_address());
}

TEST(Probe, test_set_ip) {
  Probe probe{"example.com"};
  probe.set_ip_address("127.0.0.1");
  std::string expected{"127.0.0.1"};
  ASSERT_EQ(expected, probe.get_ip_address());
}

TEST(Probe, test_is_valid) {
  Probe probe{"example.com"};
  bool expected{false};
  ASSERT_EQ(expected, probe.is_valid());
}

TEST(Probe, test_set_valid) {
  Probe probe{"example.com"};
  probe.set_is_valid_hostname(true);
  bool expected{true};
  ASSERT_EQ(expected, probe.is_valid());
}

TEST(Probe, test_equal_operator) {
  Probe probe1{"example.com"};
  Probe probe2{"example.com"};
  ASSERT_EQ(probe1, probe2);
}
