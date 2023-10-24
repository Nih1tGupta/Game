#include <iostream>
#include <vector>
using namespace std;

void drawBoard(const std::vector<std::vector<char>>& board) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
           cout << board[i][j];
            if (j < 2) {
                cout << " | ";
            }
        }
      cout << endl;
        if (i < 2) {
           cout << "---------" << endl;
        }
    }
}
bool isGameOver(const std::vector<std::vector<char>>& board, char player) {
    for (int i = 0; i < 3; ++i) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) {
            return true;
        }
    }
    for (int j = 0; j < 3; ++j) {
        if (board[0][j] == player && board[1][j] == player && board[2][j] == player) {
            return true;
        }
    }
    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
        (board[0][2] == player && board[1][1] == player && board[2][0] == player)) {
        return true;
    }

    return false;
}

int main() {
    std::vector<std::vector<char>> board(3, std::vector<char>(3, ' '));
    int row, col;
    char currentPlayer = '1';
    

 cout << "Welcome to Tic-Tac-Toe Game!" << endl;
    while (true) {
        drawBoard(board);
cout << "Player " << currentPlayer << ", enter your move (Row and Column): ";
    cin >> row >> col;

        if (row < 1 || row > 3 || col < 1 || col > 3 || board[row - 1][col - 1] != ' ') {
            cout << "Invalid move. Try again." << endl;
            continue;
        }
        board[row - 1][col - 1] = currentPlayer;
        //agar draw ho gya toh!!!!!!!
        if (isGameOver(board, currentPlayer)) {
            drawBoard(board);
           cout << "Player " << currentPlayer << " wins! Congratulations!" <<endl;
            break;
        }
        bool isDraw = true;
        for (const auto& row : board) {
            for (char cell : row) {
                if (cell == ' ') {
                    isDraw = false;
                    break;
                }
            }
            if (!isDraw) {
                break;
            }
        }
        if (isDraw) {
            drawBoard(board);
           cout << "It's a draw! Game over." << endl;
            break;
        }
        // if.......
        currentPlayer = (currentPlayer == '1') ? '2' : '1';
    }
    return 0;
}
