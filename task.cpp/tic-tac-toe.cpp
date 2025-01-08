#include <iostream>
#include <vector>
using namespace std;

class TicTacToe {
private:
    vector<vector<char>> board;
    char currentPlayer;
public:
    TicTacToe() {
        board = vector<vector<char>>(3, vector<char>(3, ' ')); //3*3
        currentPlayer = 'X';  // 'X' starts the game
    }

    void displayBoard() {
        cout << "\nTic-Tac-Toe Board: \n";
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                cout << board[i][j];
                if (j < 2) cout << " | ";
            }
            cout << endl;
            if (i < 2) cout << "--+---+--\n";
        }
    }

    bool checkWin() {
        for (int i = 0; i < 3; i++) {
            if (board[i][0] == currentPlayer && board[i][1] == currentPlayer && board[i][2] == currentPlayer)
                return true;  
            if (board[0][i] == currentPlayer && board[1][i] == currentPlayer && board[2][i] == currentPlayer)
                return true;  
        }
        if (board[0][0] == currentPlayer && board[1][1] == currentPlayer && board[2][2] == currentPlayer)
            return true;  
        if (board[0][2] == currentPlayer && board[1][1] == currentPlayer && board[2][0] == currentPlayer)
            return true;  

        return false;
    }

    bool isBoardFull() {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[i][j] == ' ') return false; 
            }
        }
        return true;  
    }

    void switchPlayer() {
        if (currentPlayer == 'X') {
            currentPlayer = 'O';
        } else {
            currentPlayer = 'X';
        }
    }

    bool makeMove(int row, int col) {
        if (row < 0 || row >= 3 || col < 0 || col >= 3 || board[row][col] != ' ') {
            cout << "Invalid move, try again!" << endl;
            return false;
        }
        board[row][col] = currentPlayer;
        return true;
    }

    void playGame() {
        int row, col;
        while (true) {
            displayBoard();
            cout << "\nPlayer " << currentPlayer << "'s turn!" << endl;
            cout << "Enter row and column (0, 1, or 2) separated by space: ";
            cin >> row >> col;

            if (makeMove(row, col)) {
                if (checkWin()) {
                    displayBoard();
                    cout << "\nPlayer " << currentPlayer << " wins!" << endl;
                    break;
                } else if (isBoardFull()) {
                    displayBoard();
                    cout << "\nIt's a draw!" << endl;
                    break;
                }
                switchPlayer();
            }
        }
    }
};

int main() {
    TicTacToe game;
    game.playGame();
    return 0;
}

