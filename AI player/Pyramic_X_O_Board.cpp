#include <iostream>
#include <random>
#include <iomanip>
#include <algorithm>
#include "BoardGame_Classes.hpp"
using namespace std;

Pyramic_X_O_Board::Pyramic_X_O_Board() {
    n_rows = 3;
    n_cols = 5;
    board = new char*[n_rows];
    for (int i = 0; i < n_rows; i++) {
        board[i] = new char[n_cols];
        for (int j = 0; j < n_cols; j++)
            board[i][j] = 0;
    }

}
bool Pyramic_X_O_Board::update_board(int x, int y, char mark) {
    if (!((x==0 && (y==0||y==1||y==3||y==4)) || (x==1 && (y==0 || y==4)) ) && board[x][y] == 0) {
        board[x][y] = toupper(mark);
        n_moves++;
        return true;
    }
    else
        return false;
}
void Pyramic_X_O_Board:: display_board(){
    for (int i: {0,1,2}) {
        if (i!=0 || i !=1)
        {
            cout << "\n ";
        }
        for (int j: {0,1,2,3,4}) {
            if ((i==0 && j != 2)  )
            {
                if ( j == 0 || j == 1 || j == 3 || j ==4)
                {

                    cout << "         ";
                }
            }else if ( (i==1 && j==0) || (i==1 && j ==4))
            {
                cout << "         " ;
            }else
            {
                if (board[i][j] == 0)
                {
                    cout << "|(" << i << "," << j << ")";
                    cout << setw(2) << board [i][j] ;
                } else
                {
                    cout << "|   " ;
                    cout << setw(2) << board [i][j] << "   " ;
                }

            }
            if ((i==0&&j==2) || (i==1 && j==3) || (i==2 && j == 4))
            {
                cout << " |" ;
            }
        }
        cout << "\n----------------------------------------------";
    }
    cout << endl;
}

bool Pyramic_X_O_Board::is_winner(){
    // Check rows and columns
    for (int i = 0; i < n_rows; i++) {
        if ((board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != 0) ||
            (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != 0)) {
            return true;
        }
    }

    // Check diagonals
    if ((board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != 0) ||
        (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != 0)) {
        return true;
    }

    return false;

}

bool Pyramic_X_O_Board::is_draw(){
    return (n_moves == 9 && !is_winner());
}
bool Pyramic_X_O_Board::game_is_over(){
    return n_moves >= 9;
}

int Pyramic_X_O_Board::MM(int &x, int &y, bool, bool) {
    return 0;
}

