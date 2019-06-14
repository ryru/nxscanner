//
// Created by pascal on 07.06.19.
//
#ifndef NXSCANNER_INCLUDE_SCANNER_RESOLVER_H_
#define NXSCANNER_INCLUDE_SCANNER_RESOLVER_H_

#include "probe.h"

#include <boost/asio.hpp>
#include <boost/bind.hpp>

namespace nxscan::scanner {

class Resolver {

 public:

  Resolver(boost::asio::io_service &io_service, Probe &probe) : resolver{io_service}, probe{probe} {}

  void resolve();

 private:
  boost::asio::ip::tcp::resolver resolver;
  Probe &probe;

  void handle_resolve(const boost::system::error_code &err,
                      const boost::asio::ip::tcp::resolver::iterator &endpoint_iterator);
/**/};

}

#endif //NXSCANNER_INCLUDE_SCANNER_RESOLVER_H_