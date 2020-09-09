
//Includes---------------------------------------------------------------------
#include "BinaryTree.h"

//Implementation---------------------------------------------------------------

//IntBTreeNode
IntBTreeNode::IntBTreeNode() :
    _data(-1),
    _leftNode(nullptr),
    _rightNode(nullptr)
{
}

int IntBTreeNode::GetData() const
{
    return _data;
}

void IntBTreeNode::SetData(const int value)
{
    _data = value;
}

IntBTreeNode::IntBTNode IntBTreeNode::GetLeftNode() const
{
    return _leftNode;
}

void IntBTreeNode::SetLeftNode(const IntBTNode node)
{
    _leftNode = node;
}

IntBTreeNode::IntBTNode IntBTreeNode::GetRightNode() const
{
    return _rightNode;
}

void IntBTreeNode::SetRightNode(const IntBTNode node)
{
    _rightNode = node;
}

//IntBinaryTree
IntBinaryTree::IntBinaryTree() = default;

IntBinaryTree::IntBTNode IntBinaryTree::Search(const IntBTNode root, int key)
{
    if (root->GetData() == key)
        return root;

    if (root->GetData() > key)
        return Search(root->GetLeftNode(), key);

    return Search(root->GetRightNode(), key);
}
