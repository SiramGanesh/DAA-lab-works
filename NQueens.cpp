#include <iostream>
#include <vector>
using namespace std;

bool isSafe(int row, int col, vector<string> &board, int n) {

    for (int i = 0; i < row; i++)
        if (board[i][col] == 'Q')
            return false;

    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
        if (board[i][j] == 'Q')
            return false;

    for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++)
        if (board[i][j] == 'Q')
            return false;

    return true;
}

bool solve(int row, vector<string> &board, int n) {
    if (row == n) {
        for (auto &r : board)
            cout << r << endl;
        cout << endl;
        return true;
    }

    bool anySolution = false;

    for (int col = 0; col < n; col++) {
        if (isSafe(row, col, board, n)) {
            board[row][col] = 'Q';

            // Try next row
            if (solve(row + 1, board, n))
                anySolution = true;

            board[row][col] = '.';
        }
    }
    return anySolution;
}

int main() {
    int n;
    cout << "Enter N: ";
    cin >> n;

    vector<string> board(n, string(n, '.'));

    if (!solve(0, board, n))
        cout << "No solution exists";
}
