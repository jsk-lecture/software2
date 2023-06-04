#!/usr/bin/env python

# http://omniorb.sourceforge.net/omnipy3/omniORBpy/omniORBpy002.html
import sys
from omniORB import CORBA, PortableServer
import CosNaming, EchoApp, EchoApp__POA

# Define an implementation of the Echo interface
class Echo_i (EchoApp__POA.Echo):
    def echoString(self, mesg):
        print "echoString() called with message:", mesg
        return mesg + ", Copy"

# Initialise the ORB and find the root POA
orb = CORBA.ORB_init(sys.argv, CORBA.ORB_ID)
poa = orb.resolve_initial_references("RootPOA")

# Create an instance of Echo_i and an Echo object reference
ei = Echo_i()
eo = ei._this()

# Obtain a reference to the root naming context
obj         = orb.resolve_initial_references("NameService")
rootContext = obj._narrow(CosNaming.NamingContext)

if rootContext is None:
    print "Failed to narrow the root naming context"
    sys.exit(1)

# Bind a context named "test.my_context" to the root context
name = [CosNaming.NameComponent("context", "")]
try:
    testContext = rootContext.bind_new_context(name)
    print "New test context bound"

except CosNaming.NamingContext.AlreadyBound, ex:
    print "Test context already exists"
    obj = rootContext.resolve(name)
    testContext = obj._narrow(CosNaming.NamingContext)
    if testContext is None:
        print "test.mycontext exists but is not a NamingContext"
        sys.exit(1)

# # Bind the Echo object to the test context
name = [CosNaming.NameComponent("Example", "")]
try:
    testContext.bind(name, eo)
    print "New Example object bound"

except CosNaming.NamingContext.AlreadyBound:
    testContext.rebind(name, eo)
    print "Example binding already existed -- rebound"

# Activate the POA
poaManager = poa._get_the_POAManager()
poaManager.activate()

# Block for ever (or until the ORB is shut down)
orb.run()
