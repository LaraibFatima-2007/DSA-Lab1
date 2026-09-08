#include <iostream>
#include <vector>

using namespace std;

// Function prototype from task6.cpp
vector<int> findMode(const vector<int>& arr);

void printVector(const vector<int>& vec) {
    cout << "[ ";
    for (int val : vec) {
        cout << val << " ";
    }
    cout << "]";
}

int main() {
    cout << "=== TASK 6 TESTS ===" << endl;

    // Test Case 1: Unique mode
    vector<int> arr1 = {1, 3, 3, 3, 2, 1};
    cout << "Test 1 (Unique mode): ";
    printVector(findMode(arr1));
    cout << " | Expected: [ 3 ]" << endl;

    // Test Case 2: Multiple modes
    vector<int> arr2 = {1, 1, 2, 2, 3};
    cout << "Test 2 (Multiple modes): ";
    printVector(findMode(arr2));
    cout << " | Expected: [ 1 2 ] (or [ 2 1 ])" << endl;

    // Test Case 3: Empty array
    vector<int> arr3 = {};
    cout << "Test 3 (Empty array): ";
    printVector(findMode(arr3));
    cout << " | Expected: [ ]" << endl;

    return 0;
}