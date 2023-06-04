#include "SystemProxy.h"

int main (int argc, char **argv) {
  XmlRpcClient::Initialize("example", "0.1");
  XmlRpcClient server ("http://gggeek.altervista.org/sw/xmlrpc/demo/server/server.php");

  SystemProxy proxy = SystemProxy(server);

  int ret = proxy.addtwo(4, 7);

  printf("%d\n", ret);
}
