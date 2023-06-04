#include <iostream>

#include "list.h"

class Stack {
 public:
  int pop() {
    if ( stack.getHead()->getNext() == NULL ) {
      return -1;
    }
    int ret = stack.getHead()->getNext()->getData();
    stack.removeNode(*(stack.getHead()->getNext()));
    return ret;
  }
  void push(int data) {
    Node* node = new Node(data);
    stack.insertNode(*(stack.getHead()), node);
  }
  friend std::ostream& operator<<(std::ostream& os, Stack& s);
 private:
  LinkedList stack;
};
std::ostream &operator<<(std::ostream &os, Stack& s) {
  os << s.stack;
}

class Queue {
 public:
  int dequeue() {
    if ( queue.getHead()->getNext() == NULL ) {
      return -1;
    }
    int ret = queue.getHead()->getNext()->getData();
    queue.removeNode(*(queue.getHead()->getNext()));
    return ret;
  }
  void enqueue(int data) {
    Node* node = new Node(data);
    // find tail node
    Node* tail = queue.getHead();
    while ( tail->getNext() != NULL ) {
      tail = tail->getNext();
    }
    // inset data to the last
    queue.insertNode(*tail, node);
  }
  friend std::ostream& operator<<(std::ostream& os, Queue& s);
 private:
  LinkedList queue;
};
std::ostream &operator<<(std::ostream &os, Queue& s) {
  os << s.queue;
}

class Stack2 {
 public:
  Stack2() {
    tail = 0;
  }
  int pop() {
    tail--;
    return stack[tail];
  }
  void push(int data) {
    stack[tail] = data;
    tail++;
  }
  friend std::ostream& operator<<(std::ostream& os, Stack2& s);
 private:
  int stack[10];
  int tail;
};
std::ostream &operator<<(std::ostream &os, Stack2& s) {
  for(int i = 0; i < s.tail; i++){
    os << s.stack[i] << " ";
  }
}

int main() {
  Stack stack;
  stack.push(12); // std::cout << stack << std::endl;
  stack.push(99); // std::cout << stack << std::endl;
  stack.push(37); // std::cout << stack << std::endl;

  std::cout << "stack : ";
  std::cout << stack.pop() << " "; // std::cout << stack << std::endl;
  std::cout << stack.pop() << " "; // std::cout << stack << std::endl;
  std::cout << stack.pop() << std::endl; // std::cout << stack << std::endl;

  Queue queue;
  queue.enqueue(12); // std::cout << queue << std::endl;
  queue.enqueue(99); // std::cout << queue << std::endl;
  queue.enqueue(37); // std::cout << queue << std::endl;

  std::cout << "queue : ";
  std::cout << queue.dequeue() << " "; // std::cout << queue << std::endl;
  std::cout << queue.dequeue() << " "; // std::cout << queue << std::endl;
  std::cout << queue.dequeue() << std::endl; // std::cout << queue << std::endl;

  Stack2 stack2;
  stack2.push(12); // std::cout << stack2 << std::endl;
  stack2.push(99); // std::cout << stack2 << std::endl;
  stack2.push(37); // std::cout << stack2 << std::endl;

  std::cout << "stack2 : ";
  std::cout << stack2.pop() << " "; // std::cout << stack2 << std::endl;
  std::cout << stack2.pop() << " "; // std::cout << stack2 << std::endl;
  std::cout << stack2.pop() << std::endl; // std::cout << stack2 << std::endl;
}
