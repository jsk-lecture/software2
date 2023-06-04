#include <zmqpp/zmqpp.hpp>
#include <jsoncpp/json/json.h>
#include <sstream>

int main(int argc, char *argv[]) {
  // initialize the 0MQ context
  zmqpp::context context;

  // generate a publish socket
  zmqpp::socket socket (context, zmqpp::socket_type::request);

  // open the connection
  std::cout << "Connecting to 5555" << std::endl;
  socket.connect("tcp://localhost:5555");

  // create request message
  Json::Value root;
  root["i1"] = 4;
  root["i2"] = 7;

  // compose a message from JSON object
  std::stringstream ss;
  ss << root;
  printf("Sending: %s\n", ss.str().c_str());

  // send a request
  zmqpp::message request = ss.str();
  socket.send(request);

  // receive the response
  zmqpp::message message;
  // decompose the message
  socket.receive(message);
  std::string text;
  message >> text;

  printf("Received: %s\n", text.c_str());
  Json::Reader reader;
  Json::Value response;
  reader.parse(text, response);
  printf("Answer is %d\n", response["i3"].asInt());
}
