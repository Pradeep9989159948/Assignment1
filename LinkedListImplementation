#include <iostream>
using namespace std;
struct Node {
    int row;
    int col;
    int value;
    Node* next;
};

Node* createNode(int row, int col, int value) {
    Node* newNode = new Node();
    newNode->row = row;
    newNode->col = col;
    newNode->value = value;
    newNode->next = nullptr;
    return newNode;
}

Node* convertToLinkedList(int** mat, int row, int col) {
    Node* head = nullptr;
    Node* tail = nullptr;

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (mat[i][j] != 0) {
                Node* newNode = createNode(i, j, mat[i][j]);
                if (head == nullptr) {
                    head = newNode;
                    tail = newNode;
                } else {
                    tail->next = newNode;
                    tail = newNode;
                }
            }
        }
    }
    return head;
}

void printList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << "(" << temp->row << ", " << temp->col << ", " << temp->value << ") -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int main() {
    int row, column;
    cout << "Enter number of rows and columns of sparse matrix: ";
    cin >> row >> column;
    
    int** mat = new int*[row];
    for (int i = 0; i < row; i++) {
        mat[i] = new int[column];
    }

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
    Node* head = convertToLinkedList(mat, row, column);
    cout << "Linked list representation of sparse matrix is: " << endl;
    printList(head);
    for (int i = 0; i < row; i++) {
        delete[] mat[i];
    }
    delete[] mat;

    return 0;
}
