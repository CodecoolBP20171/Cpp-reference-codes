#pragma once

#include <cstddef> // for std::size_t

// forward declare a node
class Node;

class LinkedList {

protected:
  Node *headp = nullptr;
  Node *lastp = nullptr;

public:
  Node *head() const;
  Node *last() const;
  virtual Node *tail() const;
  virtual std::size_t length() const;

  virtual void insertAfter(Node *const, Node &) = 0;
  virtual void unlink(Node *const) = 0;

  LinkedList(LinkedList &) = delete;
  LinkedList(LinkedList &&) = delete;
  LinkedList &operator=(LinkedList &) = delete;
  LinkedList &operator=(LinkedList &&) = delete;

  LinkedList() = default;
  virtual ~LinkedList() {}
};
