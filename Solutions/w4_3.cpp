#include <iostream>
using namespace std;

void matrixMultiplication(int** A, int** B, int** C, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            C[i][j] = 0;
            for (int k = 0; k < n; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

int main() {
    int n;
    cin >> n; // input size of matrix
    int** matrix1 = new int*[n];
    for (int i = 0; i < n; i++)
        matrix1[i] = new int[n];
    int** matrix2 = new int*[n];
    for (int i = 0; i < n; i++)
        matrix2[i] = new int[n];
    int** result = new int*[n];
    for (int i = 0; i < n; i++)
        result[i] = new int[n];

    // Input and fill matrix1
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix1[i][j];
        }
    }
    // Input and fill matrix2
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix2[i][j];
        }
    }

    matrixMultiplication(matrix1, matrix2, result, n);

   
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }

    for (int i = 0; i < n; i++) {
        delete [] matrix1[i];
        delete [] matrix2[i];
        delete [] result[i];
    }
    delete [] matrix1;
    delete [] matrix2;
    delete [] result;
    return 0;
}
