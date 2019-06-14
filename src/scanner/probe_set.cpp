#include "scanner/probe_set.h"

nxscan::scanner::Probe &nxscan::scanner::Probes::get_t1_domain() {
  return t1_domain;
}
nxscan::scanner::Probe &nxscan::scanner::Probes::get_t2_host() {
  return t2_host;
}
nxscan::scanner::Probe &nxscan::scanner::Probes::get_t3_random() {
  return t3_random;
}
const nxscan::scanner::Probe &nxscan::scanner::Probes::get_t1_domain() const {
  return t1_domain;
}
const nxscan::scanner::Probe &nxscan::scanner::Probes::get_t2_host() const {
  return t2_host;
}
const nxscan::scanner::Probe &nxscan::scanner::Probes::get_t3_random() const {
  return t3_random;
}
