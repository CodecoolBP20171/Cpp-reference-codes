#pragma once

#include "linked_list.h"

class SinglyLinkedList : public LinkedList {
  void insertAfter(Node *const, Node &) override;
  void unlink(Node *const) override;
};
