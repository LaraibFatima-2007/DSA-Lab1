#include <iostream>
#include <vector>

using namespace std;

// Function prototype from task5.cpp
vector<vector<int>> generatePascalsTriangle(int n);

// Helper function to print 2D vector
void printTriangle(const vector<vector<int>>& triangle) {
    for (const auto& row : triangle) {
        cout << "[ ";
        for (int val : row) {
            cout << val << " ";
        }
        cout << "]" << endl;
    }
}

int main() {
    cout << "=== TASK 5 TESTS ===" << endl;

    // Test Case 1: n = 0
    cout << "Test 1 (n = 0):" << endl;
    printTriangle(generatePascalsTriangle(0));

    // Test Case 2: n = 1
    cout << "\nTest 2 (n = 1):" << endl;
    printTriangle(generatePascalsTriangle(1));

    // Test Case 3: n = 5 (Verify row 5 {1, 4, 6, 4, 1})
    cout << "\nTest 3 (n = 4 for 5th row index):" << endl;
    printTriangle(generatePascalsTriangle(4));

    return 0;
}