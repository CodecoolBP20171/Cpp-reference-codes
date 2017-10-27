#include "linked_list.h"
#include "node.h"

Node *LinkedList::head() const {
  return headp;
}

Node *LinkedList::last() const {
  return lastp;
}

Node *LinkedList::tail() const {
  if (headp)
    return headp->next;
  return nullptr;
}

std::size_t LinkedList::length() const {
  std::size_t size = 0;
  if (headp)
    for (auto n = headp; n; n = n->next) {
      size++;
    }
  return size;
}
