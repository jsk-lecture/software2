#include "echo_impl.h"

#include <iostream>

using namespace std;

char * EchoApp_impl::echoString(const char * message) {
  cout << "C++ (omniORB) server: " << message << endl;
  char * server = CORBA::string_alloc(42);
  strncpy(server, "Message from C++ (omniORB) server", 42);
  return server;
}

