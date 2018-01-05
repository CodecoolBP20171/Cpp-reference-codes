#pragma once
#include <vector>
#include <memory>
#include "TreeNode.h"

class BinarySearchTree
{
public:
    static std::unique_ptr<BinarySearchTree> build(const std::vector<int>& elements);
    bool contains(const int element);
    void add(const int element);
    void remove(int element);

private:
    std::unique_ptr<TreeNode> root;

    BinarySearchTree();
    std::unique_ptr<TreeNode> buildTree(const std::vector<int>& elems,
                                        unsigned start,
                                        unsigned end);
    bool contains(TreeNode& node, const int element);
    void add(TreeNode& node, const int element);
    void remove(TreeNode& current, TreeNode& parent, const int element);
};
