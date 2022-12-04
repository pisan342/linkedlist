
#include "linkedlist.h"

using namespace std;

LinkedList::Node::Node(int val, Node *next) : val{val}, next{next} {}

LinkedList::LinkedList() : head{nullptr} {}

void LinkedList::add(int val) { head = new Node(val, head); }

LinkedList::Iterator LinkedList::begin() {
  return LinkedList::Iterator(this, head);
}
LinkedList::Iterator LinkedList::end() {
  return LinkedList::Iterator(this, nullptr);
}

LinkedList::Iterator::Iterator(LinkedList *myList, Node *myNode)
    : myList{myList}, myNode{myNode} {}

bool LinkedList::Iterator::operator==(const Iterator &other) const {
  return myList == other.myList && myNode == other.myNode;
}

bool LinkedList::Iterator::operator!=(const Iterator &other) const {
  return !(*this == other);
}

// preincrement
LinkedList::Iterator &LinkedList::Iterator::operator++() {
  myNode = myNode->next;
  return *this;
}

// postincrement;
LinkedList::Iterator LinkedList::Iterator::operator++(int) {
  LinkedList::Iterator thecopy(*this);
  myNode = myNode->next;
  return thecopy;
}

LinkedList::Node *LinkedList::Iterator::operator*() { return myNode; }

ostream &operator<<(ostream &out, LinkedList &lst) {
  out << "[";
  LinkedList::Iterator it = lst.begin();
  while (it != lst.end()) {
    LinkedList::Node *curr = *it;
    out << curr->val << " ";
    ++it;
  }
  return out << "]";
}
