#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

typedef vector<vector<int>> Matrix;

// Function prototypes from task7.cpp
Matrix multiplyNaive(const Matrix& A, const Matrix& B);
Matrix multiplyStrassen(const Matrix& A, const Matrix& B);

// Helper function to print a matrix
void printMatrix(const Matrix& M) {
    for (const auto& row : M) {
        cout << "[ ";
        for (int val : row) {
            cout << val << " ";
        }
        cout << "]" << endl;
    }
}

// Helper function to compare two matrices for equality
bool matricesEqual(const Matrix& A, const Matrix& B) {
    int n = A.size();
    if (n != static_cast<int>(B.size())) return false;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (A[i][j] != B[i][j]) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    cout << "==========================================" << endl;
    cout << "             TASK 7 TEST CASES            " << endl;
    cout << "==========================================" << endl << endl;

    // ------------------------------------------------------------------
    // Test Case 1: 2x2 Matrix
    // ------------------------------------------------------------------
    Matrix A2 = {{1, 2}, {3, 4}};
    Matrix B2 = {{5, 6}, {7, 8}};

    Matrix standard2 = multiplyNaive(A2, B2);
    Matrix strassen2 = multiplyStrassen(A2, B2);

    cout << "Test Case 1 - 2x2 Matrix:" << endl;
    printMatrix(strassen2);
    cout << "Comparison: " << (matricesEqual(standard2, strassen2) ? "PASS" : "FAIL") << endl << endl;

    // ------------------------------------------------------------------
    // Test Case 2: 4x4 Matrix
    // ------------------------------------------------------------------
    Matrix A4 = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    };

    Matrix B4 = {
        {16, 15, 14, 13},
        {12, 11, 10, 9},
        {8, 7, 6, 5},
        {4, 3, 2, 1}
    };

    Matrix standard4 = multiplyNaive(A4, B4);
    Matrix strassen4 = multiplyStrassen(A4, B4);

    cout << "Test Case 2 - 4x4 Matrix:" << endl;
    printMatrix(strassen4);
    cout << "Comparison: " << (matricesEqual(standard4, strassen4) ? "PASS" : "FAIL") << endl << endl;

    // ------------------------------------------------------------------
    // Test Case 3: Random values
    // ------------------------------------------------------------------
    srand(42); // Seed pseudo-random generator

    Matrix randomA(4, vector<int>(4));
    Matrix randomB(4, vector<int>(4));

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            randomA[i][j] = rand() % 10;
            randomB[i][j] = rand() % 10;
        }
    }

    Matrix standardRandom = multiplyNaive(randomA, randomB);
    Matrix strassenRandom = multiplyStrassen(randomA, randomB);

    cout << "Test Case 3 - Random Values:" << endl;
    cout << "Comparison: " << (matricesEqual(standardRandom, strassenRandom) ? "PASS" : "FAIL") << endl;

    return 0;
}