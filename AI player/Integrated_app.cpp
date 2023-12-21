#include<bits/stdc++.h>
#include "BoardGame_Classes.hpp"
#include "X_O_Board.cpp"
#include "four_in_a_row_Board.cpp"
#include "AIPlayer.cpp"
#include "GameManager.cpp"
#include "Player.cpp"
#include "Pyramic_X_O_Board.cpp"
#include "RandomPlayer.cpp"
#include "TicTacToe5x5_Board.cpp"
using namespace std;
void playXO(){
    int choice;
    Player* players[2];
    players[0] = new Player (1, 'x');

    cout << "Welcome to FCAI X-O Game. :)\n";
    cout << "Press 1 if you want to play with computer and 2 if you want to play with another user: ";
    cin >> choice;
    if (choice == 2)
        players[1] = new Player (2, 'o');
    else if(choice==1)
        //Player pointer points to child
        players[1] = new RandomPlayer ('o', 5);
    else {
        Board* board;
        players[1]=new AIPlayer('o',board);
    }

    GameManager x_o_game (new X_O_Board(), players);
    x_o_game.run();
    system ("pause");
}
void playPyramicTicTacToe(){
    int choice;
    Player* players[2];
    players[0] = new Player (1, 'x');

    cout << "Welcome to FCAI X-O Game. :)\n";
    cout << "Press 1 if you want to play with computer: ";
    cin >> choice;
    if (choice != 1)
        players[1] = new Player (2, 'o');
    else
        //Player pointer points to child
        players[1] = new RandomPlayer ('o', 3);

    GameManager x_o_game (new  Pyramic_X_O_Board(), players);
    x_o_game.run();
    system ("pause");
}
void playFourInARow(){
    int choice;
    Player* players[2];
    players[0] = new Player (1, 'x');

    cout << "Welcome to FCAI Four in a row Game. :)\n";
    cout << "Press 1 if you want to play with computer and 2 if you want play with other player: ";
    cin >> choice;
    if (choice != 1)
        players[1] = new Player (2, 'o');
    else
        //Player pointer points to child
        players[1] = new RandomPlayer ('o', 3);

    GameManager x_o_game (new four_in_a_row_Board(), players);
    x_o_game.run();
    system ("pause");
}
void play5x5TicTacToe(){
    int choice;
    Player* players[2];
    players[0] = new Player (1, 'x');

    cout << "Welcome to FCAI 5x5 Tic Tac Toe Game. :)\n";
    cout << "Press 1 if you want to play with computer: ";
    cin >> choice;
    if (choice != 1)
        players[1] = new Player (2, 'o');
    else
        //Player pointer points to child
        players[1] = new RandomPlayer ('o', 5);

    GameManager x_o_game (new TicTacToe5x5_Board(), players);
    x_o_game.run();
    system ("pause");

}
void IntegratedProgram(int choice){
    if(choice==1){
        playXO();
    }
    else if(choice==2){
        playPyramicTicTacToe();
    }
    else if(choice==3){
        playFourInARow();
    }
    else if(choice==4){
        play5x5TicTacToe();
    }
    else{
        cout<<"Invalid choice"<<endl;
    }
}
int main(){
    cout<<"Welcome to the Game"<<endl;
    cout<<"Choose the game you want to play"<<endl<<
        "1- XO."<<endl<<"2- Pyramic Tic-Tac-Toe."<<endl<<"3-Four-in-a-row."<<endl
        <<"4- 5 x 5 Tic Tac Toe."<<endl;
    int choice;
    cin>>choice;
    IntegratedProgram(choice);

}