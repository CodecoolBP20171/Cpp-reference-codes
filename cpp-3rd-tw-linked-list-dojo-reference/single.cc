#include <cassert>

#include "single.h"
#include "node.h"

void SinglyLinkedList::insertAfter(Node * const where, Node &node) {
  if(!headp && !where){
    assert(!lastp);
    headp = &node;
    lastp = &node;
    node.next = nullptr;
    return;
  }

  for (auto n = headp; n; n = n->next)
    if (n == where) {
      node.next = where->next;
      where->next = &node;
      if (!node.next)
        lastp = &node;
      return;
    }

  assert(!"Tried to insert after a node not in the list");
  return;
}

void SinglyLinkedList::unlink(Node *const where) {
  if (where)
    for (auto n = headp; n; n = n->next)
      if (n->next == where) {
        n->next = where->next;
        where->next = nullptr;
        return;
      }
  assert(!"Node was not in the list");
  return;
}
