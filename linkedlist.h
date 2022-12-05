#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>

using namespace std;

// Node for LinkedList
template <class T> class Node {
public:
  T val;
  Node *next;
  explicit Node(T val = 0, Node *next = nullptr);
};

// forward declaration
template <class T> class LinkedList;

// Iterator for LinkedList
template <class T> class LinkedListIterator {
  //   friend class template <class K> LinkedList;

private:
  LinkedList<T> *myList;
  Node<T> *myNode;

public:
  LinkedListIterator(LinkedList<T> *myList, Node<T> *myNode);
  bool operator==(const LinkedListIterator<T> &other) const;
  bool operator!=(const LinkedListIterator<T> &other) const;
  LinkedListIterator<T> &operator++();   // preincrement
  LinkedListIterator<T> operator++(int); // postincrement;
  Node<T> *operator*();
};

template <class T> class LinkedList {
  template <class K>
  friend ostream &operator<<(ostream &out, LinkedList<K> &lst);

private:
  // private LinkedList variables
  Node<T> *head;

public:
  // constructor
  LinkedList();
  // add to beginning of list
  void add(T val);

  // get an iterator pointing to beginning
  LinkedListIterator<T> begin();

  // get an iterator pointing beyon ed of list
  LinkedListIterator<T> end();
};

// implementation file for LinkedList
#include "linkedlist.ipp"

#endif