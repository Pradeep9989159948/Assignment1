#include <iostream>
using namespace std;

int main() {
    int row, column;
    cout << "Enter number of rows and columns of sparse matrix: ";
    cin >> row >> column;
    int mat[row][column];
    cout << "Enter elements of the matrix: ";
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            cin >> mat[i][j];
        }
    }

    cout << "Sparse matrix is: " << endl;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }

    
    int nonZeroCount = 0;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            if (mat[i][j] != 0) {
                nonZeroCount++;
            }
        }
    }

    
    int sparseMatrix[3][nonZeroCount];
    int k = 0;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            if (mat[i][j] != 0) {
                sparseMatrix[0][k] = i;
                sparseMatrix[1][k] = j;
                sparseMatrix[2][k] = mat[i][j];
                k++;
            }
        }
    }

   
    cout << "Representation of sparse matrix is: " << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < nonZeroCount; j++) {
            cout << sparseMatrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
