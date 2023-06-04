#include <iostream>

#include "list.h"

int main() {
  LinkedList l = LinkedList();
  Node node1, node2, node3;
  l.getHead()->setNext(&node1);
  node1.setData(12);
  node1.setNext(&node2);
  node2.setData(99);
  node3.setData(37);

  // print list
  std::cout << l << std::endl;

  // insert node3 after node2
  l.insertNode(node1, &node3);

  // print list
  std::cout << l << std::endl;

  // remove node2
  l.removeNode(node2);

  // print list
  std::cout << l << std::endl;
}
