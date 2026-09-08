#include <iostream>
#include <vector>

using namespace std;

// Function prototype from task3.cpp
vector<int> findAllIndices(const vector<int>& arr, int key);

// Function to print a vector
void printVector(const vector<int>& vec) {
    cout << "[ ";
    for (int val : vec) {
        cout << val << " ";
    }
    cout << "]";
}

int main() {
    cout << "=== TASK 3 TESTS ===" << endl;

    // Test Case 1: Multiple occurrences
    vector<int> arr1 = {10, 20, 30, 20, 40, 20};
    cout << "Test 1 (Multiple occurrences of 20): ";
    printVector(findAllIndices(arr1, 20));
    cout << " | Expected: [ 1 3 5 ]" << endl;

    // Test Case 2: Key not present
    vector<int> arr2 = {1, 2, 3, 4, 5};
    cout << "Test 2 (Key 99 not present): ";
    printVector(findAllIndices(arr2, 99));
    cout << " | Expected: [ ]" << endl;

    // Test Case 3: Empty array
    vector<int> arr3 = {};
    cout << "Test 3 (Empty array): ";
    printVector(findAllIndices(arr3, 10));
    cout << " | Expected: [ ]" << endl;

    return 0;
}