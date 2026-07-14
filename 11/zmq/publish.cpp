#include <iostream>
#include <string>
#include <chrono>
#include <thread>
#include <zmq.hpp>

int main(int argc, char *argv[]) {
  // initialize the 0MQ context
  zmq::context_t context(1);

  // generate a publish socket
  zmq::socket_t socket (context, zmq::socket_type::pub);

  // open the connection
  std::cout << "Connecting to 5555" << std::endl;
  socket.bind("tcp://*:5555");

  // PUB/SUBでは接続直後のメッセージが落ちることがあるため少し待つ
  std::this_thread::sleep_for(std::chrono::milliseconds(500));

  int request_nbr;
  for (request_nbr = 0; request_nbr != 10; request_nbr++) {
    // compose a message from a string and a number
    std::stringstream ss;
    ss << "Hello World " << request_nbr;
    std::cout << "Sending: " << ss.str() << std::endl;

    // send a message
    std::string text = ss.str();
    socket.send(zmq::buffer(text), zmq::send_flags::none);

    // wait for next loop
    std::this_thread::sleep_for(std::chrono::seconds(1));
  }
}
