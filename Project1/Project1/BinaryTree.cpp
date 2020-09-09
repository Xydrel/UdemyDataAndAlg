
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

IntBTreeNode::IntBTreeNode(const int value) :
    _data(value),
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

void IntBinaryTree::InsertNode(const int value)
{
    _root = insertNode(_root, value);
}

IntBinaryTree::IntBTNode IntBinaryTree::Search(const int value)
{
    return search(_root, value);
}

IntBinaryTree::IntBTNode IntBinaryTree::insertNode(IntBTNode node, const int value)
{
    if (node == nullptr)
        node = std::make_shared<IntBTreeNode>(value);

    if (value < node->GetData())
        node->SetLeftNode(insertNode(node->GetLeftNode(), value));
    else if (value > node->GetData())
        node->SetRightNode(insertNode(node->GetRightNode(), value));

    return node;
}

IntBinaryTree::IntBTNode IntBinaryTree::search(const IntBTNode root, int key)
{
    if (root == nullptr) 
        return IntBTNode();

    if (root->GetData() == key)
        return root;

    if (root->GetData() > key)
        return search(root->GetLeftNode(), key);

    return search(root->GetRightNode(), key);
}

void IntBinaryTree::PrintTreeValues()
{
    //Implement me!
}
