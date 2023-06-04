// http://omniorb.sourceforge.net/omni41/omniORB/omniORB002.html#toc13
// https://xennis.org/wiki/CORBA_-_Advanced_example_with_server-client_in_Java_and_C%2B%2B#C.2B.2B_non-interactive_client
#include "echo.hh"
#include <iostream>

EchoApp::Echo_ptr service_server;
using namespace std;

/** Name is defined in the server */
#define SERVER_NAME		"Example"

int main(int argc, char ** argv)
{
  try {
    //------------------------------------------------------------------------
    // Initialize ORB object.
    //------------------------------------------------------------------------
    CORBA::ORB_ptr orb = CORBA::ORB_init(argc, argv);
    //------------------------------------------------------------------------
    // Resolve service
    //------------------------------------------------------------------------
    service_server = 0;
    try {
      //------------------------------------------------------------------------
      // Bind ORB object to name service object.
      // (Reference to Name service root context.)
      //------------------------------------------------------------------------
      CORBA::Object_var ns_obj = orb->resolve_initial_references("NameService");
      if (!CORBA::is_nil(ns_obj)) {
        //------------------------------------------------------------------------
        // Bind ORB object to name service object.
        // (Reference to Name service root context.)
        //------------------------------------------------------------------------
        CosNaming::NamingContext_ptr nc = CosNaming::NamingContext::_narrow(ns_obj);
        //------------------------------------------------------------------------
        // The "name text" put forth by CORBA server in name service.
        // This same name ("MyServerName") is used by the CORBA server when
        // binding to the name server (CosNaming::Name).
        //------------------------------------------------------------------------
        CosNaming::Name name;
        name.length(2);
        name[0].id = CORBA::string_dup("context");
        name[0].kind = CORBA::string_dup("");
        name[1].id = CORBA::string_dup(SERVER_NAME);
        name[1].kind = CORBA::string_dup("");
        //------------------------------------------------------------------------
        // Resolve "name text" identifier to an object reference.
        //------------------------------------------------------------------------
        CORBA::Object_ptr obj = nc->resolve(name);
        if (!CORBA::is_nil(obj)) {
          service_server = EchoApp::Echo::_narrow(obj);
        }
      }
    } catch (CosNaming::NamingContext::NotFound &) {
      cerr << "Caught corba not found" << endl;
    } catch (CosNaming::NamingContext::InvalidName &) {
      cerr << "Caught corba invalid name" << endl;
    } catch (CosNaming::NamingContext::CannotProceed &) {
      cerr << "Caught corba cannot proceed" << endl;
    }
    //------------------------------------------------------------------------
    // Do stuff
    //------------------------------------------------------------------------
    if (!CORBA::is_nil(service_server)) {
      cout << "EchoApp client is running ..." << endl;
      string result = service_server->echoString("Hello from C++");
      cerr << "The object said " << result << endl;
    }
    //------------------------------------------------------------------------
    // Destroy OBR
    //------------------------------------------------------------------------
    orb->destroy();
  } catch (CORBA::UNKNOWN) {
    cerr << "Caught CORBA exception: unknown exception" << endl;
  }
}

