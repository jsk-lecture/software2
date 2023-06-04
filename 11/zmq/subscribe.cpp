#include <zmqpp/zmqpp.hpp>

int main(int argc, char *argv[]) {
  // initialize the 0MQ context
  zmqpp::context context;

  // generate a subscribe socket
  zmqpp::socket socket (context, zmqpp::socket_type::subscribe);

  // bind to the socket
  std::cout << "Wait for Connecting" << std::endl;
  socket.bind("tcp://*:5555");

  // set filter option "" means pass through
  socket.subscribe("");

  while (1) {
    // receive the message
    zmqpp::message message;
    // decompose the message
    socket.receive(message);
    std::string text;
    message >> text;
    std::cout << "Received: " << text << std::endl;
  }
}
