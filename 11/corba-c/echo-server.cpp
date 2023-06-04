// https://xennis.org/wiki/CORBA#Server

#include "echo.hh"
#include "echo_impl.h"
#include <iostream>

/** Server name, clients needs to know this name */
#define SERVER_NAME		"Example"
using namespace std;

int main(int argc, char ** argv)
{
  try {
    CORBA::ORB_ptr orb = CORBA::ORB_init(argc, argv);
    CORBA::Object_var poa_obj = orb->resolve_initial_references("RootPOA");
    PortableServer::POA_var poa = PortableServer::POA::_narrow(poa_obj);
    PortableServer::POAManager_var manager = poa->the_POAManager();
    //------------------------------------------------------------------------
    // Create service
    //------------------------------------------------------------------------
    EchoApp_impl * service = new EchoApp_impl;
    try {
      CORBA::Object_var ns_obj = orb->resolve_initial_references("NameService");
      if (!CORBA::is_nil(ns_obj)) {
        CosNaming::NamingContext_ptr nc = CosNaming::NamingContext::_narrow(ns_obj);
        CosNaming::Name context_name;
        context_name.length(1);
        context_name[0].id = CORBA::string_dup("context");
        context_name[0].kind = CORBA::string_dup("");
        CosNaming::NamingContext_var tc;
        try{
          tc = nc->bind_new_context(context_name);
        }catch(CosNaming::NamingContext::AlreadyBound& ex) {
          CORBA::Object_var obj;
          obj = nc->resolve(context_name);
          tc = CosNaming::NamingContext::_narrow(obj);
          if( CORBA::is_nil(tc) ) {
            cerr << "Failed to narrow naming context." << endl;
            return 0;
          }
        }
        CosNaming::Name object_name;
        object_name.length(1);
        object_name[0].id = CORBA::string_dup(SERVER_NAME);
        object_name[0].kind = CORBA::string_dup("");
        try{
          tc->bind(object_name, service->_this());
        }catch(CosNaming::NamingContext::AlreadyBound& ex) {
          cerr << "Example binding already existed -- rebound" << endl;
          tc->rebind(object_name, service->_this());
        }
        cout << argv[0] << " C++ (omniORB) server '" << SERVER_NAME << "' is running .." << endl;
      }
    } catch (CosNaming::NamingContext::NotFound &) {
      cerr << "Caught CORBA exception: not found" << endl;
    } catch (CosNaming::NamingContext::InvalidName &) {
      cerr << "Caught CORBA exception: invalid name" << endl;
    } catch (CosNaming::NamingContext::CannotProceed &) {
      cerr << "Caught CORBA exception: cannot proceed" << endl;
    }
    manager->activate();
    orb->run();
    delete service;
    orb->destroy();
  } catch (CORBA::UNKNOWN) {
    cerr << "Caught CORBA exception: unknown exception" << endl;
  } catch (CORBA::SystemException &) {
    cerr << "Caught CORBA exception: system exception" << endl;
  }
}
