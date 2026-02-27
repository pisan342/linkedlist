#include "linkedlist.h"
#include <iostream>

using namespace std;

ostream &operator<<(ostream &os, const LinkedList &lst) {
  os << "[";
  Node *nptr = lst.head;
  if (nptr != nullptr) {
    os << nptr->val;
    nptr = nptr->next;
  }
  for (; nptr != nullptr; nptr = nptr->next) {
    os << "," << nptr->val;
  }
  os << "]";
  return os;
}

// Constructor for Node
Node::Node(int val, Node *next) : val(val), next(next) {}

// Constructor for LinkedList
LinkedList::LinkedList() : head(nullptr), list_size(0) {}

// Destructor for LinkedList
LinkedList::~LinkedList() { clear(); }

// Check if the list is empty
bool LinkedList::empty() const { return head == nullptr; }

// Get the size of the list
int LinkedList::size() const { return list_size; }

// Clear the list
void LinkedList::clear() {
  Node *current = head;
  while (current != nullptr) {
    Node *next = current->next;
    delete current;
    current = next;
  }
  head = nullptr;
  list_size = 0;
}

// Push a value to the front of the list
void LinkedList::push_front(int val) {
  head = new Node(val, head);
  list_size++;
}

// Push a value to the back of the list
void LinkedList::push_back(int val) {
  if (head == nullptr) {
    head = new Node(val);
  } else {
    Node *current = head;
    while (current->next != nullptr) {
      current = current->next;
    }
    current->next = new Node(val);
  }
  list_size++;
}

// Pop a value from the front of the list
int LinkedList::pop_front() {
  if (head == nullptr) {
    throw runtime_error("List is empty");
  }
  int val = head->val;
  Node *temp = head;
  head = head->next;
  delete temp;
  list_size--;
  return val;
}

// Pop a value from the back of the list
int LinkedList::pop_back() {
  if (head == nullptr) {
    throw runtime_error("List is empty");
  }
  if (head->next == nullptr) {
    int val = head->val;
    delete head;
    head = nullptr;
    list_size--;
    return val;
  }
  Node *current = head;
  while (current->next->next != nullptr) {
    current = current->next;
  }
  int val = current->next->val;
  delete current->next;
  current->next = nullptr;
  list_size--;
  return val;
}

// Get the value at the front of the list
int LinkedList::front() const {
  if (head == nullptr) {
    throw runtime_error("List is empty");
  }
  return head->val;
}

// Get the value at the back of the list
int LinkedList::back() const {
  if (head == nullptr) {
    throw runtime_error("List is empty");
  }
  Node *current = head;
  while (current->next != nullptr) {
    current = current->next;
  }
  return current->val;
}

// Constructor for Iterator
LinkedList::Iterator::Iterator(Node *node) : current(node) {}

// Dereference operator for Iterator
int &LinkedList::Iterator::operator*() const {
  if (current == nullptr) {
    throw runtime_error("Iterator out of bounds");
  }
  return current->val;
}

// Pre-increment operator for Iterator
LinkedList::Iterator &LinkedList::Iterator::operator++() {
  if (current != nullptr) {
    current = current->next;
  }
  return *this;
}

// Post-increment operator for Iterator
LinkedList::Iterator LinkedList::Iterator::operator++(int) {
  Iterator temp = *this;
  ++(*this);
  return temp;
}

// Equality operator for Iterator
bool LinkedList::Iterator::operator==(const Iterator &other) const {
  return current == other.current;
}

// Inequality operator for Iterator
bool LinkedList::Iterator::operator!=(const Iterator &other) const {
  return current != other.current;
}

// Get an iterator to the beginning of the list
LinkedList::Iterator LinkedList::begin() const { return Iterator(head); }

// Get an iterator to the end of the list
LinkedList::Iterator LinkedList::end() const { return Iterator(nullptr); }
