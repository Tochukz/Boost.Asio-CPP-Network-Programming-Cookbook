#include <boost/asio.hpp>
#include <iostream>

using namespace boost;

int main() {

	/** Create an endoint */
	std::string raw_ip_address = "127.0.0.1";
	unsigned short port_num = 3333;
	boost::system::error_code ip_ec;

	asio::ip::address ip_address = asio::ip::address::from_string(raw_ip_address, ip_ec);

	if (ip_ec.value() != 0) {
		std::cout << "Failed to parse the IP address. Error code = "
			<< ip_ec.value() << ". Message : " << ip_ec.message();
		return ip_ec.value();
	}

	asio::ip::tcp::endpoint ep(ip_address, port_num);

	/** Create and open an active socket */
	asio::io_service ios;
	asio::ip::tcp protocol = asio::ip::tcp::v4();
	asio::ip::tcp::socket sock(ios);
	boost::system::error_code sock_ec;
	sock.open(protocol, sock_ec);

	if (sock_ec.value() != 0) {
		std::cout << "Failed to open the socket! Error code = "
			<< sock_ec.value() << ". Message: " << sock_ec.message();
		return sock_ec.value();
	}


	return 0;
}