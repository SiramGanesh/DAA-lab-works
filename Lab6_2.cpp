#include <iostream>
using namespace std;

const int MAX = 2; // For simplicity, using 2x2 matrices

// Strassen’s multiplication
void strassen(int A[MAX][MAX], int B[MAX][MAX], int C[MAX][MAX]) {
    int M1 = (A[0][0] + A[1][1]) * (B[0][0] + B[1][1]);
    int M2 = (A[1][0] + A[1][1]) * B[0][0];
    int M3 = A[0][0] * (B[0][1] - B[1][1]);
    int M4 = A[1][1] * (B[1][0] - B[0][0]);
    int M5 = (A[0][0] + A[0][1]) * B[1][1];
    int M6 = (A[1][0] - A[0][0]) * (B[0][0] + B[0][1]);
    int M7 = (A[0][1] - A[1][1]) * (B[1][0] + B[1][1]);

    C[0][0] = M1 + M4 - M5 + M7;
    C[0][1] = M3 + M5;
    C[1][0] = M2 + M4;
    C[1][1] = M1 - M2 + M3 + M6;
}

int main() {
    int A[MAX][MAX], B[MAX][MAX], C[MAX][MAX];

    cout << "Enter elements of Matrix A (2x2):\n";
    for (int i = 0; i < MAX; i++)
        for (int j = 0; j < MAX; j++)
            cin >> A[i][j];

    cout << "Enter elements of Matrix B (2x2):\n";
    for (int i = 0; i < MAX; i++)
        for (int j = 0; j < MAX; j++)
            cin >> B[i][j];

    strassen(A, B, C);

    cout << "Resultant Matrix C:\n";
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++)
            cout << C[i][j] << " ";
        cout << endl;
    }

    return 0;
}
