#include <iostream>
using namespace std;

const int ROWS = 6;
const int COLS = 7;

void printBoard(char board[][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

bool checkWin(char board[][COLS], char player) {
    // Check for horizontal wins
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS - 3; j++) {
            if (board[i][j] == player && board[i][j+1] == player && board[i][j+2] == player && board[i][j+3] == player) {
                return true;
            }
        }
    }

    // Check for vertical wins
    for (int i = 0; i < ROWS - 3; i++) {
        for (int j = 0; j < COLS; j++) {
            if (board[i][j] == player && board[i+1][j] == player && board[i+2][j] == player && board[i+3][j] == player) {
                return true;
            }
        }
    }

    // Check for diagonal wins (top-left to bottom-right)
    for (int i = 0; i < ROWS - 3; i++) {
        for (int j = 0; j < COLS - 3; j++) {
            if (board[i][j] == player && board[i+1][j+1] == player && board[i+2][j+2] == player && board[i+3][j+3] == player) {
                return true;
            }
        }
    }

    // Check for diagonal wins (bottom-left to top-right)
    for (int i = ROWS - 1; i >= 3; i--) {
        for (int j = 0; j < COLS - 3; j++) {
            if (board[i][j] == player && board[i-1][j+1] == player && board[i-2][j+2] == player && board[i-3][j+3] == player) {
                return true;
            }
        }
    }

    return false;
}

int main() {
    char board[ROWS][COLS];
    char currentPlayer = 'R';
    cout<<"***********************************"<<endl;
    cout<<" Welcome to the Connect -4 game "<<endl;
    cout<<"***********************************"<<endl;
    cout<<endl;
    cout<<endl;
    cout<<endl;
    cout<< "Rules:"<<endl;

    cout<<"->2 player red(R) and Blue (B) game"<<endl;
    cout<<"->A player wins if he/she is able to connect 4 dots horizontally, vertiocally or diagonally"<<endl;
    cout<<"-> Draw  when the matrix is fully filled"<<endl;


  cout<< "lests start the game and here the empty board of size 6*7" <<endl;
  
    // Initialize the board
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            board[i][j] = '-';
        }
    }

    // Start the game
    while (true) {
        // Print the board
        printBoard(board);

        // Get the column to drop the piece
        int col;
        cout << "Player " << currentPlayer << "'s turn. Enter a column number (0-6): ";
        cin >> col;

        // Check if the column is valid
        if (col < 0 || col >= COLS) {
            cout << "Invalid column number! Please try again." << endl;
            continue;
        }

        // Drop the piece
        for (int i = ROWS - 1; i >= 0; i--) {
            if (board[i][col] == '-') {
                board[i][col] = currentPlayer;
            break;
        }
        if (i == 0) {
            cout << "Column is full! Please try again." << endl;
            continue;
        }
    }

    // Check if the current player has won
    if (checkWin(board, currentPlayer)) {
        cout << "Player " << currentPlayer << " wins!" << endl;
        break;
    }

    // Check if the board is full
    bool isBoardFull = true;
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (board[i][j] == '-') {
                isBoardFull = false;
                break;
            }
        }
    }
    if (isBoardFull) {
        cout << "The game is a tie!" << endl;
        break;
    }

    // Switch to the other player
    if (currentPlayer == 'R') {
        currentPlayer = 'B';
    } else {
        currentPlayer = 'R';
    }
}

// Print the final board
printBoard(board);

return 0;
}