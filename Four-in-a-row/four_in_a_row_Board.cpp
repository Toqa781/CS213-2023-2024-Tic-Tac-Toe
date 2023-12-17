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
four_in_a_row_Board::four_in_a_row_Board () {
    n_rows =6;
    n_cols = 7;
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
bool four_in_a_row_Board::update_board (int x, int y, char mark){
    // Only update if move is valid
    if(y<0 || y>=n_cols){
        return false;
    }
    // find the lowest available row in the selected column
    x=n_rows-1;
    while(x>=0&& board[x][y]!=0){
        x--;
    }
    //if the column is full return false
    if(x<0){
        return false;
    }
    //place the mark at the lowest available position in the column
    board[x][y]=toupper(mark);
    n_moves++;
    return true;
}

// Display the board and the pieces on it
void four_in_a_row_Board::display_board() {
    for (int i: {0,1,2,3,4,5}) {
        cout << "\n| ";
        for (int j: {0,1,2,3,4,5,6}) {
            cout << "(" << i << "," << j << ")";
            cout << setw(2) << board [i][j] << " |";
        }
        cout << "\n-----------------------------------------------------------------";
    }
    cout << endl;
}

// Returns true if there is any winner
// either X or O
// Written in a complex way. DO NOT DO LIKE THIS.
bool four_in_a_row_Board::is_winner() {
    //check horizontally
    for(int row=0;row<n_rows;row++){
        for(int col=0;col<=n_cols-4;col++){
            if(board[row][col]!=0 &&
               board[row][col]==board[row][col+1]&&
               board[row][col]==board[row][col+2]&&
               board[row][col]==board[row][col+3]){
                return true;
            }
        }
    }
    //check vertically
    for(int col=0;col<n_cols;col++){
        for(int row=0;row<=n_rows-4;row++){
            if (board[row][col] != 0 &&
                board[row][col] == board[row + 1][col] &&
                board[row][col] == board[row + 2][col] &&
                board[row][col] == board[row + 3][col]) {
                return true;
            }
        }
    }
    //check diagonally(ascending)
    for (int row = 3; row < n_rows; ++row) {
        for (int col = 0; col <= n_cols - 4; ++col) {
            if (board[row][col] != 0 &&
                board[row][col] == board[row - 1][col + 1] &&
                board[row][col] == board[row - 2][col + 2] &&
                board[row][col] == board[row - 3][col + 3]) {
                return true;
            }
        }
    }
    // Check diagonally (descending)
    for (int row = 0; row <= n_rows - 4; ++row) {
        for (int col = 0; col <= n_cols - 4; ++col) {
            if (board[row][col] != 0 &&
                board[row][col] == board[row + 1][col + 1] &&
                board[row][col] == board[row + 2][col + 2] &&
                board[row][col] == board[row + 3][col + 3]) {
                return true;
            }
        }
    }

    return false;
}

// Return true if 9 moves are done and no winner
bool four_in_a_row_Board::is_draw() {
    return (n_moves == n_rows*n_cols);
}

bool four_in_a_row_Board::game_is_over () {
    return is_winner()||is_draw();
}
