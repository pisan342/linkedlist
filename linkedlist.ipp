
// This ipp file is included from .h file

using namespace std;

template <class T> Node<T>::Node(T val, Node<T> *next) : val{val}, next{next} {}

template <class T> LinkedList<T>::LinkedList() : head{nullptr} {}

template <class T> void LinkedList<T>::add(T val) {
  head = new Node<T>(val, head);
}

template <class T> LinkedListIterator<T> LinkedList<T>::begin() {
  return LinkedListIterator<T>(this, head);
}

template <class T> LinkedListIterator<T> LinkedList<T>::end() {
  return LinkedListIterator<T>(this, nullptr);
}

template <class T>
LinkedListIterator<T>::LinkedListIterator(LinkedList<T> *myList,
                                          Node<T> *myNode)
    : myList{myList}, myNode{myNode} {}

template <class T>
bool LinkedListIterator<T>::operator==(
    const LinkedListIterator<T> &other) const {
  return myList == other.myList && myNode == other.myNode;
}

template <class T>
bool LinkedListIterator<T>::operator!=(
    const LinkedListIterator<T> &other) const {
  return !(*this == other);
}

// preincrement
template <class T> LinkedListIterator<T> &LinkedListIterator<T>::operator++() {
  myNode = myNode->next;
  return *this;
}

// postincrement
template <class T>
LinkedListIterator<T> LinkedListIterator<T>::operator++(int) {
  LinkedListIterator thecopy(*this);
  myNode = myNode->next;
  return thecopy;
}

template <class T> Node<T> *LinkedListIterator<T>::operator*() {
  return myNode;
}

template <class T> ostream &operator<<(ostream &out, LinkedList<T> &lst) {
  out << "[";
  LinkedListIterator<T> it = lst.begin();
  while (it != lst.end()) {
    Node<T> *curr = *it;
    out << curr->val << " ";
    ++it;
  }
  return out << "]";
}
