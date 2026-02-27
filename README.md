# STL like Linked List

```
  friend ostream &operator<<(ostream &os, const LinkedList &lst);

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
  Iterator begin() const;
  Iterator end() const;
```

Use `make run` to compile and run it.

Alternatively use `runit.sh` or `run-full.sh` to run it and check for formatting.
