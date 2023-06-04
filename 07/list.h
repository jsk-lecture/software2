class LinkedList;
class Node {
public:
  Node(){ this->next = NULL; }
  Node(int data) { this->data = data; this->next = NULL; }
  Node(int data, Node *next) { this->data = data; this->next = next; }
  int getData() { return this->data; }
  void setData(int data) { this->data = data; }
  Node* getNext() { return this->next; }
  void setNext(Node *node) { this->next = node; }
  friend std::ostream& operator<<(std::ostream& os, const Node& n);
private:
  int data;
  Node* next;
};

std::ostream &operator<<(std::ostream &os, const Node& n) {
  os << n.data;
}

class LinkedList {
public:
  LinkedList() {}
  void insertNode(Node& target, Node *new_node) {
    for(Node* p = &head; p != NULL; p = p->getNext()) {
      if ( p == &target) {
        new_node->setNext(p->getNext());
        p->setNext(new_node);
      }
    }
  }
  void removeNode(Node& node) {
    for(Node *p0 = &head, *p1 = head.getNext(); p1 != NULL; p0 = p1, p1 = p1->getNext() ) {
      if ( p1 == &node ) {
        p0->setNext(p1->getNext());
      }
    }
  }
  Node* getHead() { return &(this->head); }
  friend std::ostream&
    operator<<(std::ostream& os,
	       LinkedList& l);
private:
  Node head;
};

std::ostream&
   operator<<(std::ostream &os,
	      LinkedList& l) {
  for ( Node* p = l.getHead()->getNext(); p != NULL; p = p->getNext() ) {
    os << *(p) << " -> ";
  }
  os << "NULL";
}

