#ifndef NXSCANNER_INCLUDE_SCANNER_RESOLVER_H_
#define NXSCANNER_INCLUDE_SCANNER_RESOLVER_H_

#include "probe.h"

#include <boost/asio.hpp>
#include <boost/bind.hpp>

namespace nxscan::scanner {

class Resolver {

 public:

  explicit Resolver(boost::asio::io_service &ioService, Probe &probe) : resolver{ioService}, probe{probe} {}

  void resolve();

 private:
  boost::asio::ip::tcp::resolver resolver;
  Probe &probe;

  void handle_resolve(const boost::system::error_code &err,
                      const boost::asio::ip::tcp::resolver::iterator &endpointIterator);
};

}

#endif //NXSCANNER_INCLUDE_SCANNER_RESOLVER_H_