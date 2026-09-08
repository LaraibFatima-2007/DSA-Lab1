#include <iostream>
#include <vector>

using namespace std;

/**
 * Author: Laraib Fatima
 * Date: 08-09-2026
 * Task 5: Pascal's Triangle
 * Generates Pascal's Triangle up to n rows.
 */
vector<vector<int>> generatePascalsTriangle(int n) {
    vector<vector<int>> triangle;

    if (n < 0) {
        return triangle;
    }

    for (int i = 0; i <= n; ++i) {
        vector<int> row(i + 1, 1); // Fill row with 1s

        // Calculate inner values for row > 1
        for (int j = 1; j < i; ++j) {
            row[j] = triangle[i - 1][j - 1] + triangle[i - 1][j];
        }

        triangle.push_back(row);
    }

    return triangle;
}