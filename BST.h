#pragma once

#include <iostream>
#include <ctime>
#include <chrono>
#include <algorithm>

using namespace std;

struct treeNode
{
    int data;
    treeNode* Left;
    treeNode* Right;
};

class BST
{
public:
    BST();
    bool add(int i);
    bool remove(int i);

    void inorder();
    void inorder(treeNode*);
    int max();

private:
    bool remove(treeNode* n, treeNode* parent, int i); // Updated function signature
    treeNode* root;
};

