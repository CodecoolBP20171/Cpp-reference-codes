#pragma once
#include <memory>
#include <iostream>
#include "BinaryTreeExceptions.hpp"

class TreeNode
{
public:
  TreeNode(int value) : value(value) {}

  std::unique_ptr<TreeNode>& getLeft() { return left; }
  std::unique_ptr<TreeNode>& getRight() { return right; }
  void setLeft(std::unique_ptr<TreeNode> value) { left = std::move(value); }
  void setRight(std::unique_ptr<TreeNode> value) { right = std::move(value); }
  int getValue() { return value; }

  void removeChild(const int value)
  {
    if (left->getValue() == value) {
      left.reset();
    } else if (right->getValue() == value) {
      right.reset();
    }
  }

private:
  int value;
  std::unique_ptr<TreeNode> left;
  std::unique_ptr<TreeNode> right;
};
