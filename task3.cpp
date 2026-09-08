#include <iostream>
#include <vector>

using namespace std;

/**
 * Author: Laraib Fatima
 * Date: 08-09-2026
 * Lab 1 Task 3: Find All Indices of an Element
 * Searches an array for all occurrences of a specified key.
 */
    vector<int> findAllIndices(const vector<int>& arr, int key) {
    vector<int> indices;
    
    // Iterate and  check for matching elements
    for (int i = 0; i < static_cast<int>(arr.size()); ++i) {
        if (arr[i] == key) {
            indices.push_back(i); // Store matching index
        }
    }
    
    return indices;
}