#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>

using namespace std;

// Node for LinkedList
class Node {
public:
  int val;
  Node *next;
  explicit Node(int val = 0, Node *next = nullptr);
};

// LinkedList class
class LinkedList {
    friend ostream &operator<<(ostream &os, const LinkedList &lst);
private:
  Node *head;
  int list_size;
public:
  LinkedList();
  ~LinkedList();
  bool empty() const;
  int size() const;
  void clear();
  void push_front(int val);
  void push_back(int val);
  int pop_front();
  int pop_back();
  int front() const;
  int back() const;
  // Iterator class for LinkedList
  class Iterator {
  private:
    Node *current;
  public:    explicit Iterator(Node *node);
    int &operator*() const;
    Iterator &operator++(); // Pre-increment
    Iterator operator++(int); // Post-increment
    bool operator==(const Iterator &other) const;
    bool operator!=(const Iterator &other) const;
  };
  Iterator begin() const;
  Iterator end() const;
};


#endif