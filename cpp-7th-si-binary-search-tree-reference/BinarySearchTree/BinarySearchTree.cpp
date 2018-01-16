#include "stdafx.h"
#include "BinarySearchTree.h"
#include "BinaryTreeExceptions.hpp"

std::unique_ptr<BinarySearchTree> BinarySearchTree::build(const std::vector<int>& elements)
{
  std::unique_ptr<BinarySearchTree> tree(new BinarySearchTree());
  tree->root = tree->buildTree(elements, 0, elements.size());
  return tree;
}

std::unique_ptr<TreeNode> BinarySearchTree::buildTree(const std::vector<int>& elems, 
                                                      unsigned start, 
                                                      unsigned end)
{
  int elemsSize = end - start;
  if (elemsSize > 0) {
    int middle = start + elemsSize / 2;
    std::unique_ptr<TreeNode> newNode(new TreeNode(elems[middle]));
    newNode->setLeft(buildTree(elems, start, middle));
    if (elemsSize > 2) {
      newNode->setRight(buildTree(elems, middle + 1, end));
    }
    return newNode;
  }
  return nullptr;
}

bool BinarySearchTree::contains(const int element) {
  if (!root) {
    return false;
  }
  return contains(*root, element);
}

bool BinarySearchTree::contains(TreeNode& node, const int element) {
  if (node.getValue() == element) {
    return true;
  }
  auto& left = node.getLeft();
  if (left && contains(*left, element)) {
    return true;
  }
  auto& right = node.getRight();
  if (right) {
    return contains(*right, element);
  }
  return false;
}

void BinarySearchTree::add(const int element)
{
  if (!root) {
    root.reset(new TreeNode(element));
    return;
  }
  add(*root, element);
}

void BinarySearchTree::add(TreeNode& node, const int element)
{
  if (element == node.getValue())
  {
    throw ArgumentException();
  }
  
  if (element < node.getValue()) {
    if (!node.getLeft()) {
      node.setLeft(std::unique_ptr<TreeNode>(new TreeNode(element)));
      return;
    } else {
      add(*node.getLeft(), element);
    }
  } else { // element > node.getvalue()
    if (!node.getRight()) {
      node.setRight(std::unique_ptr<TreeNode>(new TreeNode(element)));
      return;
    } else {
      add(*node.getRight(), element);
    }
  }
}

void BinarySearchTree::remove(int element)
{
  if (root->getValue() == element) {
    root = nullptr;
    return;
  }
  remove(*root, *root, element);
}

void BinarySearchTree::remove(TreeNode& current, TreeNode& parent, const int element)
{
  if (element == current.getValue()) {
    parent.removeChild(element);
    return;
  } else if (element < current.getValue()) {
    if (current.getLeft()) {
      remove(*current.getLeft(), current, element);
      return;
    }
  } else {
    if (current.getRight()) {
      remove(*current.getRight(), current, element);
      return;
    }
  }
  throw IllegalArgumentException();
}

BinarySearchTree::BinarySearchTree()
{
    // private constructor so it can't be instantiated like this
}
