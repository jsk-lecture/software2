#include <stdio.h>

typedef struct node {
  int data;
  struct node* next;
} node;

void print_list(node *head) {
  for(node* p = head->next;
      p != NULL;
      p = p->next) {
    printf("%d -> ", p->data);
  }
  printf("NULL\n");
}

void insert_after(node *head,
                  node *target, node *new_node) {
  for(node* p = head; p != NULL; p = p->next) {
    if ( p == target ) {
      new_node->next = p->next;
      p->next = new_node;
    }
  }
}

void remove_node(node *head, node *target) {
  for(node *p0 = head, *p1 = head->next; p1 != NULL; p0 = p1, p1 = p1->next) {
    if ( p1 == target ) {
      p0->next = p1->next;
    }
  }
}

int main() {
  node head;
  node node1, node2, node3;
  head.next = &node1;
  node1.data = 12;
  node1.next = &node2;
  node2.data = 99;
  node2.next = NULL;
  node3.data = 37;

  // print list
  print_list(&head);

  // insert node3
  insert_after(&head, &node1, &node3);

  // print list
  print_list(&head);

  // insert node3
  remove_node(&head, &node2);

  // print list
  print_list(&head);
}
