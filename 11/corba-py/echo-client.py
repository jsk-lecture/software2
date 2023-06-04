#!/usr/bin/env python

# http://omniorb.sourceforge.net/omnipy3/omniORBpy/omniORBpy002.html
import sys
from omniORB import CORBA
import CosNaming, EchoApp

# Initialise the ORB
orb = CORBA.ORB_init(sys.argv, CORBA.ORB_ID)

# Obtain a reference to the root naming context
obj         = orb.resolve_initial_references("NameService")
rootContext = obj._narrow(CosNaming.NamingContext)

if rootContext is None:
    print "Failed to narrow the root naming context"
    sys.exit(1)

# Resolve the name "test.my_context/ExampleEcho.Object"
name = [CosNaming.NameComponent("context", ""),
        CosNaming.NameComponent("Example", "")]
try:
    obj = rootContext.resolve(name)

except CosNaming.NamingContext.NotFound, ex:
    print "Name not found"
    sys.exit(1)

# Narrow the object to an Example::Echo
eo = obj._narrow(EchoApp.Echo)

if eo is None:
    print "Object reference is not an Example::EchoApp"
    sys.exit(1)

# Invoke the echoString operation
message = "Hello from Python"
result = obj.echoString(message)

print "I said '%s'. The object said '%s'." % (message,result)

