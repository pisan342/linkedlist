#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>

using namespace std;

class LinkedList {
  friend ostream &operator<<(ostream &out, LinkedList &lst);

private:
  // Node for LinkedList
  class Node {
  public:
    int val;
    Node *next;
    explicit Node(int val = 0, Node *next = nullptr);
  };
  // Iterator for LinkedList
  class Iterator {
  public:
    LinkedList *myList;
    Node *myNode;
    Iterator(LinkedList *myList, Node *myNode);
    bool operator==(const Iterator &other) const;
    bool operator!=(const Iterator &other) const;
    Iterator &operator++();   // preincrement
    Iterator operator++(int); // postincrement;
    Node *operator*();
  };
  // private LinkedList variables
  Node *head;

public:
  // constructor
  LinkedList();
  // add to beginning of list
  void add(int val);

  // get an iterator pointing to beginning
  Iterator begin();

  // get an iterator pointing beyon ed of list
  Iterator end();
};

#endif