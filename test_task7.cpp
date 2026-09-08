#include <iostream>
#include <vector>

using namespace std;

typedef vector<vector<int>> Matrix;

Matrix multiplyNaive(const Matrix& A, const Matrix& B);
Matrix multiplyStrassen(const Matrix& A, const Matrix& B);

void printMatrix(const Matrix& M) {
    for (const auto& row : M) {
        cout << "[ ";
        for (int val : row) cout << val << " ";
        cout << "]" << endl;
    }
}

int main() {
    cout << "=== TASK 7 TESTS ===" << endl;

    // 2x2 Matrix Test
    Matrix A2 = {{1, 2}, {3, 4}};
    Matrix B2 = {{5, 6}, {7, 8}};

    cout << "2x2 Strassen Result:" << endl;
    printMatrix(multiplyStrassen(A2, B2));

    cout << "2x2 Naive Result:" << endl;
    printMatrix(multiplyNaive(A2, B2));

    // 4x4 Matrix Test
    Matrix A4 = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 1, 2, 3}, {4, 5, 6, 7}};
    Matrix B4 = {{8, 7, 6, 5}, {4, 3, 2, 1}, {1, 2, 3, 4}, {5, 6, 7, 8}};

    cout << "\n4x4 Strassen Result:" << endl;
    printMatrix(multiplyStrassen(A4, B4));

    return 0;
}