#pragma once

//Includes---------------------------------------------------------------------
#include <memory>

//Types------------------------------------------------------------------------
class IntBTreeNode final
{
public:
    using IntBTNode = std::shared_ptr<IntBTreeNode>;

    explicit IntBTreeNode();
    explicit IntBTreeNode(const int value);

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

    void InsertNode(const int value);

    IntBTNode Search(const int value);

    void PrintTreeValues();

private:
    IntBTNode insertNode(IntBTNode node, const int value);
    IntBTNode search(const IntBTNode root, int key);

private:
    std::shared_ptr<IntBTreeNode> _root;
};

