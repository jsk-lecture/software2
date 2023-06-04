#ifndef __ECHO_IMPL_H__
#define __ECHO_IMPL_H__
#include "echo.hh"

class EchoApp_impl : public POA_EchoApp::Echo
{
public:
  virtual char * echoString(const char * message);
};

#endif
