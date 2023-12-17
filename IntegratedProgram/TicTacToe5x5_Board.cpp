// Class definition for X_O_Board class
// Author:  Mohammad El-Ramly
// Date:    10/10/2022
// Version: 1
#include <iostream>
#include <random>
#include <iomanip>
#include <algorithm>
#include "BoardGame_Classes.hpp"
using namespace std;

// Set the board
TicTacToe5x5_Board::TicTacToe5x5_Board () {
    n_rows = n_cols = 5;
    board = new char*[n_rows];
    for (int i = 0; i < n_rows; i++) {
        board [i] = new char[n_cols];
        for (int j = 0; j < n_cols; j++)
            board[i][j] = 0;
    }
}
// within board boundaries in empty cell
// Return false always
bool TicTacToe5x5_Board::update_board (int x, int y, char mark){
    // Only update if move is valid
    if (!(x < 0 || x > 4 || y < 0 || y > 4) && (board[x][y] == 0)) {
        board[x][y] = toupper(mark);
        n_moves++;
        return true;
    }
    else
        return false;
}

// Display the board and the pieces on it
void TicTacToe5x5_Board::display_board() {
    for (int i: {0,1,2,3,4}) {
        cout << "\n| ";
        for (int j: {0,1,2,3,4}) {
            cout << "(" << i << "," << j << ")";
            cout << setw(2) << board [i][j] << " |";
        }
        cout << "\n-----------------------------";
    }
    cout << endl;
}

// Returns false always
// either X or O
int check = 0;
bool TicTacToe5x5_Board::is_winner() {
    int Xcnt = 0, Ycnt = 0;

    // Check vertically
    for (int i = 0; i <= n_rows - 3; ++i) {
        for (int j = 0; j < n_cols; ++j) {
            if (board[i][j] == 'X' &&
                board[i][j] == board[i + 1][j] && board[i+1][j] == 'X' &&
                board[i][j] == board[i + 2][j] && board[i+2][j] == 'X') {
                Xcnt++;
            }
            if (board[i][j] == 'O' &&
                board[i][j] == board[i + 1][j] && board[i+1][j] == 'O' &&
                board[i][j] == board[i + 2][j] && board[i+2][j] == 'O') {
                Ycnt++;
            }
        }
    }

    // Check horizontally
    for (int i = 0; i < n_rows; ++i) {
        for (int j = 0; j <= n_cols - 3; ++j) {
            if (board[i][j] == 'X' &&
                board[i][j] == board[i][j + 1] && board[i][j+1] == 'X' &&
                board[i][j] == board[i][j + 2] && board[i][j+2] == 'X') {
                Xcnt++;
            }
            if (board[i][j] == 'O' &&
                board[i][j] == board[i][j + 1] && board[i][j+1] == 'O' &&
                board[i][j] == board[i][j + 2] && board[i][j+2] == 'O') {
                Ycnt++;
            }
        }
    }

    // Check diagonally
    for (int i = 0; i <= n_rows - 3; ++i) {
        for (int j = 0; j <= n_cols - 3; ++j) {
            if (board[i][j] == 'X' &&
                board[i][j] == board[i + 1][j + 1] && board[i+1][j+1] == 'X' &&
                board[i][j] == board[i + 2][j + 2] && board[i+2][j+2] == 'X') {
                Xcnt++;
            }
            if (board[i][j] == 'O' &&
                board[i][j] == board[i + 1][j + 1] && board[i+1][j+1] == 'O' &&
                board[i][j] == board[i + 2][j + 2] && board[i+2][j+2] == 'O') {
                Ycnt++;
            }
        }
    }

    // Check diagonally the other way
    for (int i = 0; i <= n_rows - 3; ++i) {
        for (int j = 2; j < n_cols; ++j) {
            if (board[i][j] == 'X' &&
                board[i][j] == board[i + 1][j - 1] && board[i+1][j-1] == 'X' &&
                board[i][j] == board[i + 2][j - 2] && board[i+2][j-2] == 'X') {
                Xcnt++;
            }
            if (board[i][j] == 'O' &&
                board[i][j] == board[i + 1][j - 1] && board[i+1][j-1] == 'O' &&
                board[i][j] == board[i + 2][j - 2] && board[i+2][j-2] == 'O') {
                Ycnt++;
            }
        }
    }

    if (n_moves == 24 && Xcnt > Ycnt) {
        cout << "X wins with " << Xcnt << " times 3Xs" << endl;
        cout << "Y loses with " << Ycnt << " times 3Ys" << endl;
        return false;
    }
    else if(n_moves == 24 && Ycnt > Xcnt){
        cout << "Y wins with " << Ycnt << " times 3Ys" << endl;
        cout << "X loses with " << Xcnt << " times 3Xs" << endl;
        return false;
    }
    else if(Xcnt==Ycnt)
        check = 1;
    return false;
}
// Return true if 9 moves are done and no winner
bool TicTacToe5x5_Board::is_draw() {
    return (n_moves == 24 && !is_winner() && check==1);
}

bool TicTacToe5x5_Board::game_is_over () {
    return n_moves >= 24;
}
