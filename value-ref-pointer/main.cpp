#include <stdio.h>

struct Node {
  int data;
  Node* next;
};

void fillNode(Node* node) {
  node->data = 10;
  node->next = NULL;
}

void fillByCopyNode(Node node) {
  node.data = 10;
  node.next = NULL;
}

Node starterNode() {
  Node node;
  node.data = 10;
  node.next = NULL;

  return node;
}

void passByValue(int a) {
  printf("a = %p\n", &a);
  a = 20;
}

int passByValueModify(int a) {
  printf("a = %p\n", &a);
  a = 20;
  return a;
}

void passByReference(int &a) {
  printf("a = %p\n", &a);
  a = 20;
}

void passByPointer(int* a) {
  printf("a = %p\n", a);
  *a = 20;
}

int main(void) {
  printf("Hello World\n");
  int a = 10;
  printf("a = %p\n", &a);

  // printf("a = %d\n", a);
  // passByValue(a);
  // printf("a = %d\n", a);

  // passByReference(a);
  // printf("a = %d\n", a);
  
  // a = passByValueModify(a);
  // printf("a = %d\n", a);

  // passByPointer(&a);
  // printf("a = %d\n", a);

  int& b = a;
  // printf("b = %p\n", &b);
  // printf("b = %d\n", b);
  // b = 20;
  // printf("b = %d\n", b);
  // printf("a = %d\n", a);
  
  passByReference(b);
  printf("b = %d\n", b);
  printf("a = %d\n", a);

  return 0;
}
