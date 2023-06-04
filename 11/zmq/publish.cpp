#include <zmqpp/zmqpp.hpp>
#include <sstream>

int main(int argc, char *argv[]) {
  // initialize the 0MQ context
  zmqpp::context context;

  // generate a publish socket
  zmqpp::socket socket (context, zmqpp::socket_type::publish);

  // open the connection
  std::cout << "Connecting to 5555" << std::endl;
  socket.connect("tcp://localhost:5555");

  int request_nbr;
  for (request_nbr = 0; request_nbr != 10; request_nbr++) {
    // compose a message from a string and a number
    std::stringstream ss;
    ss << "Hello World " << request_nbr;
    std::cout << "Sending: " << ss.str() << std::endl;

    // send a message
    zmqpp::message message = ss.str();
    socket.send(message);

    // wait for next loop
    std::this_thread::sleep_for(std::chrono::seconds(1));
  }
}
