#include "linkedlist.h"
#include <iostream>
#include <vector>

using namespace std;

template <class T> void printit(LinkedList<T> &lst) {
  for (auto nptr : lst) {
    cout << nptr->val << " ";
  }
  cout << endl;
}

void test1() {
  LinkedList<int> lst;
  lst.add(10);
  lst.add(20);
  lst.add(30);
  cout << lst << endl;
  LinkedList<string> lst2;
  lst2.add("hello");
  lst2.add("world");
  printit(lst2);
  // vector<int> v(lst.begin(), lst.end());
}

int main() { test1(); }