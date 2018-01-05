#include "pch.h"
#include <vector>
#include "../BinarySearchTree/BinarySearchTree.h"

namespace BinarySearchTreeTests
{
  std::vector<int> GenerateNumbers(int numOfItems)
  {
    std::vector<int> result;
    for (int i = 0; i < numOfItems; ++i) {
      result.push_back(i * 2 + 5);
    }
    return result;
  }

  TEST(BinarySearchTreeTests, BuildTest)
  {
    auto numbers = GenerateNumbers(50);
    auto tree = BinarySearchTree::build(numbers);

    EXPECT_NE(nullptr, tree);
  }

  TEST(BinarySearchTreeTests, ContainsTest)
  {
    auto numbers = GenerateNumbers(50);
    auto tree = BinarySearchTree::build(numbers);

    ASSERT_EQ(false, tree->contains(34535));
    ASSERT_EQ(true, tree->contains(7));
    ASSERT_EQ(true, tree->contains(55));
    ASSERT_EQ(true, tree->contains(7));
    ASSERT_EQ(false, tree->contains(34535));
  }

  TEST(BinarySearchTreeTests, AddTest)
  {
    auto numbers = GenerateNumbers(50);
    auto tree = BinarySearchTree::build(numbers);
    tree->add(21344);
    tree->add(10);

    ASSERT_EQ(true, tree->contains(21344));
    ASSERT_EQ(true, tree->contains(10));
  }
    
  TEST(BinarySearchTreeTests, AddExceptionTest)
  {
    auto numbers = GenerateNumbers(50);
    auto tree = BinarySearchTree::build(numbers);
    tree->add(21344);
    ASSERT_THROW(tree->add(21344), ArgumentException);
  }

  TEST(BinarySearchTreeTests, RemoveTest)
  {
    auto numbers = GenerateNumbers(50);
    auto tree = BinarySearchTree::build(numbers);

    ASSERT_EQ(true, tree->contains(93));
    tree->remove(93);
    ASSERT_EQ(false, tree->contains(93));
  }

  TEST(BinarySearchTreeTests, RemoveExceptionTest)
  {
    auto numbers = GenerateNumbers(50);
    auto tree = BinarySearchTree::build(numbers);

    ASSERT_EQ(true, tree->contains(9));
    tree->remove(9);
    ASSERT_EQ(false, tree->contains(9));
    ASSERT_THROW(tree->remove(9), IllegalArgumentException);
  }
}
