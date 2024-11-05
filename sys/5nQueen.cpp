#include <iostream>
#include <vector>
using namespace std;

#define N 4

// Function to print the board
void printBoard(const vector<vector<int>>& board) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << (board[i][j] == 1 ? "Q " : ". ");
        }
        cout << endl;
    }
}

// Function to check if a queen can be placed at board[row][col]
bool isSafe(const vector<vector<int>>& board, int row, int col) {
    // Check this row on the left side
    for (int i = 0; i < col; i++)
        if (board[row][i] == 1)
            return false;

    // Check the upper diagonal on the left side
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j] == 1)
            return false;

    // Check the lower diagonal on the left side
    for (int i = row, j = col; j >= 0 && i < N; i++, j--)
        if (board[i][j] == 1)
            return false;

    return true;
}

// Function to solve the 8-Queens problem using backtracking
bool solve8Queens(vector<vector<int>>& board, int col) {
    // Base case: If all queens are placed
    if (col >= N)
        return true;

    // Iterate over each row to place a queen in the current column
    for (int i = 0; i < N; i++) {
        // Check if placing a queen here is safe
        if (isSafe(board, i, col)) {
            // Place the queen
            board[i][col] = 1;

            // Recur to place queens in the rest of the columns
            if (solve8Queens(board, col + 1))
                return true;

            // Backtrack: Remove the queen
            board[i][col] = 0;
        }
        cout<<endl;
        printBoard(board);
        cout<<endl;
    }
    return false; // Trigger backtracking
}

int main() {
    vector<vector<int>> board(N, vector<int>(N, 0));

    // Place the first queen in a specific position (e.g., top-left corner)
    board[0][0] = 1;

    // Start from the second column as the first queen is already placed
    if (solve8Queens(board, 1)) {
        cout << "Solution for the 8-Queens problem:\n";
        printBoard(board);
    } else {
        cout << "No solution exists.\n";
    }

    return 0;
}
