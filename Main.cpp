#include "BST.h"
#include <iostream>
#include <string>
#include <chrono>
#include <random>

using namespace std;
using namespace chrono;

void testBST(int numNodes) {
    BST bst;
    int random;
    cout << "\nTesting with " << numNodes << " nodes...\n";

    // Seed with a real random value, if available
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distr(1, numNodes * 10);

    // Measure time for adding nodes
    auto startAdd = high_resolution_clock::now();
    for (int i = 0; i < numNodes; i++) {
        random = distr(gen);
        bst.add(random);
    }
    auto endAdd = high_resolution_clock::now();
    auto durationAdd = duration_cast<milliseconds>(endAdd - startAdd).count();
    cout << "Time taken to add " << numNodes << " nodes: " << durationAdd << " ms\n";

    // Find and display the max value
    int maximum = bst.max();
    cout << "Max value after adding " << numNodes << " nodes: " << maximum << endl;

    // Measure time for removing nodes
    auto startRemove = high_resolution_clock::now();
    for (int i = 0; i < numNodes; i++) {
        random = distr(gen);
        bst.remove(random);
    }
    auto endRemove = high_resolution_clock::now();
    auto durationRemove = duration_cast<milliseconds>(endRemove - startRemove).count();
    cout << "Time taken to remove " << numNodes << " nodes: " << durationRemove << " ms\n";
}

int main() {
    testBST(100);       // Test with 100 nodes
    testBST(1000);      // Test with 1,000 nodes
    testBST(10000);     // Test with 10,000 nodes
    testBST(100000);    // Test with 100,000 nodes
    return 0;
}

