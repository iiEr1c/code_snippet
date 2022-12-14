#include <boost/array.hpp>
#include <boost/asio.hpp>
#include <iostream>

using boost::asio::ip::tcp;

int main(int argc, char *argv[]) {
  try {
    if (argc != 3) {
      std::cerr << "Usage: client <host> <port>\n";
      return 1;
    }
    boost::asio::io_context io_context;

    tcp::resolver resolver(io_context);
    tcp::socket socket(io_context);
    boost::asio::connect(socket, resolver.resolve(argv[1], argv[2]));
    for (;;) {
      boost::array<char, 128> buf;
      boost::system::error_code error;

      size_t len = socket.read_some(boost::asio::buffer(buf), error);
      if (error == boost::asio::error::eof) {
        std::cout << "recv eof\n";
        break;
      }
      else if (error)
        throw boost::system::system_error(error);
      std::cout.write(buf.data(), len);
    }
  } catch (std::exception &e) {
    std::cerr << e.what() << std::endl;
  }
}