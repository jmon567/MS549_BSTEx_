#include "BST.h"
#include <iostream>

using namespace std;

BST::BST() // default constructor
{
	root = NULL;
}

bool BST::add(int i)
{
	treeNode* n = new treeNode();
	n->data = i;

	if (root == NULL)
	{
		root = n;
		return true;

	}
	else
	{
		treeNode* p = root;
		while (p != NULL)
		{
			if (i == p->data)
			{
				return false;

			}
			else if(i< p->data)
			{
				if (p->Left == NULL)
				{
					p->Left = n;
					return true;
				}
				else
				{
					p = p->Left;
				}
			}
			else
			{
				if (p->Right == NULL)
				{
					p->Right = n;
					return true;
				}
				else
				{
					p = p->Right;
				}
			}
			
		}
		return true;
	}


}

void BST::inorder()
{
	inorder(root);
}
void BST:: inorder(treeNode*n)

{
	if (n == NULL)
	{
		return;
	}
	inorder(n->Left);
	cout << n->data << "   ";
	inorder(n->Right);

}

int BST::max()
{
	if (root == NULL)
	{
		return -1;
	}
	else
	{
		treeNode* p = root;

		while (p->Right != NULL)
		{
			p = p->Right;
		}
		return p->data;

	}
}

bool BST::remove(int i) {
	return remove(root, nullptr, i);
}

bool BST::remove(treeNode* n, treeNode* parent, int i) {
	if (n == nullptr) {
		return false;
	}

	if (i < n->data) {
		return remove(n->Left, n, i);
	}
	else if (i > n->data) {
		return remove(n->Right, n, i);
	}
	else {
		// Node to be removed found
		if (n->Left == nullptr && n->Right == nullptr) {
			// Case 1: Node is a leaf
			if (n == root) {
				root = nullptr;
			}
			else if (parent->Left == n) {
				parent->Left = nullptr;
			}
			else {
				parent->Right = nullptr;
			}
			delete n;
		}
		else if (n->Left == nullptr) {
			// Case 2: Node has one child (right child)
			if (n == root) {
				root = n->Right;
			}
			else if (parent->Left == n) {
				parent->Left = n->Right;
			}
			else {
				parent->Right = n->Right;
			}
			delete n;
		}
		else if (n->Right == nullptr) {
			// Case 2: Node has one child (left child)
			if (n == root) {
				root = n->Left;
			}
			else if (parent->Left == n) {
				parent->Left = n->Left;
			}
			else {
				parent->Right = n->Left;
			}
			delete n;
		}
		else {
			// Case 3: Node has two children
			treeNode* successor = n->Right;
			treeNode* successorParent = n;
			while (successor->Left != nullptr) {
				successorParent = successor;
				successor = successor->Left;
			}
			n->data = successor->data;
			remove(successor, successorParent, successor->data);
		}
		return true;
	}
}
