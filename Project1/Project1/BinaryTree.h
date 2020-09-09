#pragma once

//Includes---------------------------------------------------------------------
#include <memory>

//Types------------------------------------------------------------------------
class IntBTreeNode final
{
public:
    using IntBTNode = std::shared_ptr<IntBTreeNode>;

    explicit IntBTreeNode();

    int GetData() const;
    void SetData(const int value);

    IntBTNode GetLeftNode() const;
    void SetLeftNode(const IntBTNode node);

    IntBTNode GetRightNode() const;
    void SetRightNode(const IntBTNode node);

private:

    int _data;
    std::shared_ptr<IntBTreeNode> _leftNode;
    std::shared_ptr<IntBTreeNode> _rightNode;
};

class IntBinaryTree final
{
    using IntBTNode = std::shared_ptr<IntBTreeNode>;

public:
    explicit IntBinaryTree();

    IntBTNode Search(const IntBTNode root, int key);

private:
    std::shared_ptr<IntBTreeNode> _root;
};

