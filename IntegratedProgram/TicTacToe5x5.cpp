// Class definition for X_O_Board class
// Author:  Mohammad El-Ramly
// Date:    10/10/2022
// Version: 1
#include <iostream>
#include <random>
#include <iomanip>
#include <algorithm>
#include "BoardGame_Classes.h"
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

// Return true  if move is valid and put it on board
// within board boundaries in empty cell
// Return false otherwise
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

// Returns true if there is any winner
// either X or O
// Written in a complex way. DO NOT DO LIKE THIS.
bool TicTacToe5x5_Board::is_winner() {
    int Xcnt = 0, Ycnt = 0;
    //check vertically
    for (int i = 0; i < n_rows; ++i) {
        for (int j = 0; j <= n_cols - 5; ++j) {
            if (board[i][j] == 'X' &&
                board[i][j] == board[i][j + 1] && board[i][j] == 'X' &&
                board[i][j] == board[i][j + 2] && board[i][j] == 'X' &&
                board[i][j] == board[i][j + 3] && board[i][j] == 'X') {
                Xcnt++;
                //return true;
            }
        }
    }
    for (int i = 0; i < n_rows; ++i) {
        for (int j = 0; j <= n_cols - 5; ++j) {
            if (board[i][j] == 'O' &&
                board[i][j] == board[i][j + 1] && board[i][j] == 'O' &&
                board[i][j] == board[i][j + 2] && board[i][j] == 'O' &&
                board[i][j] == board[i][j + 3] && board[i][j] == 'O') {
                Ycnt++;
                //return true;
            }
        }
    }
    //check horizontally
    for (int i = 0; i <= n_rows - 5; ++i) {
        for (int j = 0; j < n_cols; ++j) {
            if (board[i][j] == 'O' &&
                board[i][j] == board[i + 1][j] && board[i][j] == 'O' &&
                board[i][j] == board[i + 2][j] && board[i][j] == 'O' &&
                board[i][j] == board[i + 3][j] && board[i][j] == 'O') {
                Ycnt++;
                //return true;
            }
        }
    }
    for (int i = 0; i <= n_rows - 5; ++i) {
        for (int j = 0; j < n_cols; ++j) {
            if (board[i][j] == 'X' &&
                board[i][j] == board[i + 1][j] && board[i][j] == 'X' &&
                board[i][j] == board[i + 2][j] && board[i][j] == 'X' &&
                board[i][j] == board[i + 3][j] && board[i][j] == 'X') {
                Xcnt++;
                //return true;
            }
        }
    }
    //check diagonally
    for (int i = 0; i < n_rows; ++i) {
        for (int j = 0; j < n_cols; ++j) {
            if (i == j) {
                if (board[i][j] == 'X') {
                    Xcnt++;
                    //return true;
                }
            }
        }
    }
    for (int i = 0; i < n_rows; ++i) {
        for (int j = 0; j < n_cols; ++j) {
            if (i == j) {
                if (board[i][j] == 'O') {
                    Ycnt++;
                    //return true;
                }
            }
        }
    }
    if (Xcnt>Ycnt) {
        cout<<n_moves<<endl;
        cout << "X wins by :"<<Xcnt<<endl;
        cout << "Y wins by: "<<Ycnt<<endl;
    }
    else
        cout<<n_moves<<endl;
    cout << "X wins by :"<<Xcnt<<endl;
    cout << "Y wins by: "<<Ycnt<<endl;
    return false;
}
// Return true if 9 moves are done and no winner
bool TicTacToe5x5_Board::is_draw() {
    return (n_moves == 25 && !is_winner());
}

bool TicTacToe5x5_Board::game_is_over () {
    return n_moves >= 25;
}
