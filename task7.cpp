#include <iostream>
#include <vector>

using namespace std;

/**
 * Author: Laraib Fatima
 * Date: 08-09-2026
 * Task 7: Strassen’s Matrix Multiplication
 * Implements Strassen's algorithm for matrix multiplication.
 */

typedef vector<vector<int>> Matrix;

// Standard Naive Matrix Multiplication: O(N^3)

Matrix multiplyNaive(const Matrix& A, const Matrix& B) {
    int n = A.size();
    Matrix C(n, vector<int>(n, 0));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            for (int k = 0; k < n; ++k) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    return C;
}

// Matrix Addition
Matrix addMatrix(const Matrix& A, const Matrix& B) {
    int n = A.size();
    Matrix C(n, vector<int>(n, 0));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            C[i][j] = A[i][j] + B[i][j];
    return C;
}

// Matrix Subtraction
Matrix subtractMatrix(const Matrix& A, const Matrix& B) {
    int n = A.size();
    Matrix C(n, vector<int>(n, 0));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            C[i][j] = A[i][j] - B[i][j];
    return C;
}

// Strassen's Matrix Multiplication Algorithm

Matrix multiplyStrassen(const Matrix& A, const Matrix& B) {
    int n = A.size();

    // for 1x1 matrix
    if (n == 1) {
        return {{A[0][0] * B[0][0]}};
    }

    int k = n / 2;
    Matrix A11(k, vector<int>(k)), A12(k, vector<int>(k)),
           A21(k, vector<int>(k)), A22(k, vector<int>(k));
    Matrix B11(k, vector<int>(k)), B12(k, vector<int>(k)),
           B21(k, vector<int>(k)), B22(k, vector<int>(k));

    for (int i = 0; i < k; ++i) {
        for (int j = 0; j < k; ++j) {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j + k];
            A21[i][j] = A[i + k][j];
            A22[i][j] = A[i + k][j + k];

            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j + k];
            B21[i][j] = B[i + k][j];
            B22[i][j] = B[i + k][j + k];
        }
    }

    // Calculating 7 Strassen products
    Matrix P1 = multiplyStrassen(A11, subtractMatrix(B12, B22));
    Matrix P2 = multiplyStrassen(addMatrix(A11, A12), B22);
    Matrix P3 = multiplyStrassen(addMatrix(A21, A22), B11);
    Matrix P4 = multiplyStrassen(A22, subtractMatrix(B21, B11));
    Matrix P5 = multiplyStrassen(addMatrix(A11, A22), addMatrix(B11, B22));
    Matrix P6 = multiplyStrassen(subtractMatrix(A12, A22), addMatrix(B21, B22));
    Matrix P7 = multiplyStrassen(subtractMatrix(A11, A21), addMatrix(B11, B12));

    // Combine products into submatrices
    Matrix C11 = addMatrix(subtractMatrix(addMatrix(P5, P4), P2), P6);
    Matrix C12 = addMatrix(P1, P2);
    Matrix C21 = addMatrix(P3, P4);
    Matrix C22 = subtractMatrix(subtractMatrix(addMatrix(P1, P5), P3), P7);

    // Group into output matrix
    Matrix C(n, vector<int>(n, 0));
    for (int i = 0; i < k; ++i) {
        for (int j = 0; j < k; ++j) {
            C[i][j] = C11[i][j];
            C[i][j + k] = C12[i][j];
            C[i + k][j] = C21[i][j];
            C[i + k][j + k] = C22[i][j];
        }
    }

    return C;
}