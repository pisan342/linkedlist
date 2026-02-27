
#include "linkedlist.h"
#include <cassert>
#include <iostream>
#include <sstream>

using namespace std;

// Testing all linkesdlist functions
void test1() {
  stringstream ss;
  LinkedList lst;
  lst.push_back(10);
  lst.push_back(20);
  lst.push_back(30);
  ss << lst;
  assert(ss.str() == "[10,20,30]");
  assert(lst.size() == 3);
  assert(lst.front() == 10);
  assert(lst.back() == 30);
  assert(!lst.empty());
  lst.clear();
  assert(lst.empty());
  lst.push_front(40);
  lst.push_front(50);
  ss.str("");
  ss << lst;
  assert(ss.str() == "[50,40]");
  assert(lst.pop_front() == 50);
  assert(lst.pop_back() == 40);
  assert(lst.empty());
}

void test2() {
  stringstream ss;
  LinkedList lst;
  lst.push_back(10);
  lst.push_back(20);
  lst.push_back(30);
  LinkedList::Iterator it = lst.begin();
  assert(*it == 10);
  ++it;
  assert(*it == 20);
  it++;
  assert(*it == 30);
  ++it;
  assert(it == lst.end());
  ss << lst;
  assert(ss.str() == "[10,20,30]");
}

void test3() {
  LinkedList lst;
  try {
    lst.front();
    assert(false); // Should not reach here
  } catch (const runtime_error &e) {
    assert(string(e.what()) == "List is empty");
  }
  try {
    lst.back();
    assert(false); // Should not reach here
  } catch (const runtime_error &e) {
    assert(string(e.what()) == "List is empty");
  }
}

void test4() {
  LinkedList lst;
  try {
    lst.pop_front();
    assert(false); // Should not reach here
  } catch (const runtime_error &e) {
    assert(string(e.what()) == "List is empty");
  }
  try {
    lst.pop_back();
    assert(false); // Should not reach here
  } catch (const runtime_error &e) {
    assert(string(e.what()) == "List is empty");
  }
}

void test5() {
  LinkedList lst;
  for (int i = 0; i < 100; i++) {
    lst.push_back(i);
  }
  assert(lst.size() == 100);
  for (int i = 0; i < 100; i++) {
    assert(lst.pop_front() == i);
  }
  assert(lst.empty());
}

void test6() {
  LinkedList lst;
  for (int i = 0; i < 100; i++) {
    lst.push_front(i);
  }
  assert(lst.size() == 100);
  for (int i = 0; i < 100; i++) {
    assert(lst.pop_back() == i);
  }
  assert(lst.empty());
}

void test7() {
  LinkedList lst;
  for (int i = 0; i < 10; i++) {
    lst.push_back(i);
  }
  LinkedList::Iterator it = lst.begin();
  for (int i = 0; i < 10; i++) {
    assert(*it == i);
    ++it;
  }
  assert(it == lst.end());
}

void test8() {
  LinkedList lst;
  for (int i = 0; i < 10; i++) {
    lst.push_back(i);
  }
  LinkedList::Iterator it1 = lst.begin();
  LinkedList::Iterator it2 = lst.begin();
  assert(it1 == it2);
  ++it1;
  assert(it1 != it2);
}

void test9() {
  LinkedList lst;
  for (int i = 0; i < 10; i++) {
    lst.push_back(i);
  }
  LinkedList::Iterator it = lst.begin();
  for (int i = 0; i < 10; i++) {
    assert(*it == i);
    it++;
  }
  assert(it == lst.end());

  // Test post-increment
  it = lst.begin();
  for (int i = 0; i < 10; i++) {
    assert(*it == i);
    it++;
  }
  assert(it == lst.end());
}

// Modify values through iterator
void test10() {
  LinkedList lst;
  for (int i = 0; i < 10; i++) {
    lst.push_back(i);
  }
  LinkedList::Iterator it = lst.begin();
  for (int i = 0; i < 10; i++) {
    *it = *it + 1; // Increment each value by 1
    it++;
  }
  it = lst.begin();
  for (int i = 0; i < 10; i++) {
    assert(*it == i + 1); // Check if values are incremented
    it++;
  }
}

void testAll() {
  test1();
  test2();
  test3();
  test4();
  test5();
  test6();
  test7();
  test8();
  test9();
  test10();
  cout << "All tests passed!" << endl;
}
