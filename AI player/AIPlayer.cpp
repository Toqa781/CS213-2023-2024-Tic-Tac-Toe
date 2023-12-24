#include "BoardGame_Classes.hpp"

AIPlayer::AIPlayer(char symbol,Board* board):Player(symbol),board(board){
    this->name = "AI player";
    cout<<"My name is "<<name<<'\n';
}
void AIPlayer::get_move(int& x, int& y) {
    board->MM(x,y,false,true);
}
