#include <gtest/gtest.h>

#include "node.h"
#include "single.h"

class ListTest : public ::testing::Test {
public:
  Node *nodes = nullptr;
  constexpr static std::size_t nodenum = 10;

  void SetUp() {
    nodes = new Node[nodenum];
    for (std::size_t i = 0; i < nodenum; i++)
      nodes[i].id = i;
  }

  void TearDown() { delete[] nodes; }
  void empty(LinkedList &l) {
    EXPECT_EQ(l.length(), 0);
    EXPECT_EQ(l.head(), l.last());
    EXPECT_EQ(l.head(), nullptr);
    EXPECT_EQ(l.tail(), nullptr);
  }
  void addOne(LinkedList &l) {
    l.insertAfter(l.head(), nodes[0]);
    EXPECT_EQ(l.length(), 1);
    EXPECT_EQ(l.head(), l.last());
    EXPECT_NE(l.head(), nullptr);
    EXPECT_EQ(l.tail(), nullptr);
  }
  void addTwo(LinkedList &l) {
    l.insertAfter(l.head(), nodes[0]);
    l.insertAfter(l.head(), nodes[1]);
    EXPECT_EQ(l.length(), 2);
    EXPECT_NE(l.head(), l.last());
    EXPECT_NE(l.head(), nullptr);
    EXPECT_NE(l.last(), nullptr);
    EXPECT_EQ(l.tail(), l.last());
  }
  void unlink(LinkedList &l) {
    l.insertAfter(l.head(), nodes[0]);
    l.insertAfter(l.head(), nodes[1]);
    l.insertAfter(l.head(), nodes[2]);
    l.unlink(l.tail());
    EXPECT_EQ(l.length(), 2);
    EXPECT_NE(l.head(), l.last());
    EXPECT_NE(l.head(), nullptr);
    EXPECT_NE(l.last(), nullptr);
    EXPECT_EQ(l.tail(), l.last());
  }
};

TEST_F(ListTest, SingleEmpty) {
  SinglyLinkedList l;
  empty(l);
}

TEST_F(ListTest, SingleAddOne) {
  SinglyLinkedList l;
  addOne(l);
}

TEST_F(ListTest, SingleAddTwo) {
  SinglyLinkedList l;
  addTwo(l);
}

TEST_F(ListTest, SingleUnlink) {
  SinglyLinkedList l;
  unlink(l);
}
