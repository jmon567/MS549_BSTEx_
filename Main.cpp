#include "BST.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{
    BST bst;
    int random, maximum;
    for (int i = 0; i < 100; i++)
    {
        random = 1 + rand() % 100;
        cout << "inserting " << random << endl;
        bst.add(random);
    }

    cout << "\nIn-order traversal of BST:\n";
    bst.inorder();

    maximum = bst.max();
    cout << "\nMax value = " << maximum << endl;

    // Test the remove function
    cout << "\nRemoving elements from BST...\n";
    bst.remove(maximum); // Remove the maximum element

    cout << "\nIn-order traversal after removing the max element:\n";
    bst.inorder();

    // Optionally, try removing a few more elements
    int removeVals[] = { random, 50, 75 }; // Adjust these values as needed
    for (int val : removeVals)
    {
        if (bst.remove(val))
        {
            cout << "\nRemoved " << val << " successfully.\n";
        }
        else
        {
            cout << "\nValue " << val << " not found in BST.\n";
        }
        bst.inorder();
    }

    return 0;
}
