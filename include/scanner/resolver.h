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

  Resolver(boost::asio::io_service &io_service, Probe &probe) : resolver{io_service}, probe{probe} {
    resolve();
  }

  void resolve() {
    boost::asio::ip::tcp::resolver::query query(probe.get_hostname(), "http");

    resolver.async_resolve(query,
                           boost::bind(&Resolver::handle_resolve, this,
                                       boost::asio::placeholders::error,
                                       boost::asio::placeholders::iterator));

  }

 private:

  void handle_resolve(const boost::system::error_code &err,
                      const boost::asio::ip::tcp::resolver::iterator &endpoint_iterator) {
    if (!err) {
      probe.set_is_valid_hostname(true);
      std::string ipv4{};
      boost::asio::ip::tcp::resolver::iterator it = endpoint_iterator;
      boost::asio::ip::tcp::resolver::iterator end;
      for (; it != end; ++it) {
        boost::asio::ip::tcp::endpoint ep = it->endpoint();
        if (ep.address().is_v4()) {
          ipv4 = ep.address().to_string();
          probe.set_ip_address(ipv4);
          break;
        }

      }
    } else {
      probe.set_is_valid_hostname(false);
    }
  }

  boost::asio::ip::tcp::resolver resolver;
  Probe &probe;
};

}

#endif //NXSCANNER_INCLUDE_SCANNER_RESOLVER_H_