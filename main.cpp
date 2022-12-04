#include "linkedlist.h"
#include <iostream>
#include <vector>

using namespace std;

void test1() {
  LinkedList lst;
  lst.add(10);
  lst.add(20);
  lst.add(30);
  cout << lst << endl;
}

int main() { test1(); }