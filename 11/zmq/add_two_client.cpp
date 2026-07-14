#include <iostream>
#include <nlohmann/json.hpp>
#include <string>
#include <zmq.hpp>

int main(int argc, char *argv[]) {
  // initialize the 0MQ context
  zmq::context_t context(1);

  // generate a publish socket
  zmq::socket_t socket (context, zmq::socket_type::req);

  // open the connection
  std::cout << "Connecting to 5555" << std::endl;
  socket.connect("tcp://localhost:5555");

  // create request message
  nlohmann::json request = {{"i1", 4}, {"i2", 7}};

  // compose a message from JSON object
  std::string text = request.dump();
  printf("Sending: %s\n", text.c_str());

  // send a request
  socket.send(zmq::buffer(text), zmq::send_flags::none);

  // receive the response
  zmq::message_t message;
  // decompose the message
  socket.recv(message, zmq::recv_flags::none);
  std::string reply_text(static_cast<char*>(message.data()), message.size());

  printf("Received: %s\n", reply_text.c_str());
  auto response = nlohmann::json::parse(reply_text);
  printf("Answer is %d\n", response["i3"].get<int>());
}
