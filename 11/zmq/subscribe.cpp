#include <iostream>
#include <string>
#include <zmq.hpp>

int main(int argc, char *argv[]) {
  // initialize the 0MQ context
  zmq::context_t context(1);

  // generate a subscribe socket
  zmq::socket_t socket (context, zmq::socket_type::sub);

  // bind to the socket
  std::cout << "Wait for Connecting" << std::endl;
  socket.connect("tcp://localhost:5555");

  // set filter option "" means pass through
  socket.set(zmq::sockopt::subscribe, "");

  while (1) {
    // receive the message
    zmq::message_t message;
    // decompose the message
    auto ok = socket.recv(message, zmq::recv_flags::none);
    if (!ok) continue;
    std::string text(static_cast<char*>(message.data()), message.size());
    std::cout << "Received: " << text << std::endl;
  }
}
