#include <iostream>
#include <vector>

using namespace std;

class Pyramidal_XO {
public:
    Pyramidal_XO(int size) :
            boardSize(size), currentCompetitor('X') {
        board.resize(size, vector<char>(2 * size - 1, ' '));
    }

    void showBoard() {
        for (int i = 0; i < boardSize; ++i) {
            for (int j = 0; j < boardSize - i - 1; ++j) {
                cout << " ";
            }

            for (int j = 0; j < 2 * i + 1; ++j) {
                cout << board[i][j];
            }

            cout << endl;
        }
    }

    bool checkWinner() const {
        // Check rows and columns
        for (int i = 0; i < boardSize; ++i) {
            int rowCounter = 0;
            int columnCounter = 0;

            for (int j = 0; j < boardSize; ++j) {
                if (board[i][j] == currentCompetitor) {
                    rowCounter++;
                }

                if (board[j][i] == currentCompetitor) {
                    columnCounter++;
                }
            }

            if (rowCounter == boardSize || columnCounter == boardSize) {
                return true;
            }
        }

        // Check diagonals
        int leftDiagCounter = 0;
        int rightDiagCounter = 0;

        for (int i = 0; i < boardSize; ++i) {
            if (board[i][i] == currentCompetitor) {
                leftDiagCounter++;
            }

            if (board[i][2*i] == currentCompetitor) {
                rightDiagCounter++;
            }
        }

        return (leftDiagCounter == boardSize || rightDiagCounter == boardSize);
    }

    bool isBoardFilled() const {
        for (int i = 0; i < boardSize; ++i) {
            for (int j = 0; j < 2 * i + 1; ++j) {
                if (board[i][j] == ' ') {
                    return false;
                }
            }
        }
        return true;
    }

    void makeMove(int row, int col) {
        board[row - 1][col - 1] = currentCompetitor;
    }

    bool islogicalMove(int row, int col) const {
        return (row >= 1 && row <= boardSize && col >= 1 && col <= 2 * row - 1 && board[row - 1][col - 1] == ' ');
    }

    void switchCompetitor() {
        if (currentCompetitor == 'X') {
            currentCompetitor = 'O';
        } else {
            currentCompetitor = 'X';
        }
    }


    char getcurrentCompetitor() const {
        return currentCompetitor;
    }

private:
    int boardSize;
    vector<vector<char>> board;
    char currentCompetitor;
};

int main() {
    const int boardSize = 3;
    Pyramidal_XO match(boardSize);

    while (true) {
        // Display the current state of the board
        match.showBoard();

        // Get the player's move
        int row, col;
        cout << "Player " << match.getcurrentCompetitor() << ", enter your move (row and column): ";
        cin >> row >> col;

        // Check if the move is valid or not
        if (!match.islogicalMove(row, col)) {
            cout << "Invalid move. Try again." << endl;
            continue;
        }

        // Make the move
        match.makeMove(row, col);

        // Check for the winner
        if (match.checkWinner()) {
            match.showBoard();
            cout << "Player " << match.getcurrentCompetitor() << " wins!" << endl;
            break;
        }

        // Check for a tie
        if (match.isBoardFilled()) {
            match.showBoard();
            cout << "It' a tie!" << endl;
            break;
        }

        // Switch Competitor
        match.switchCompetitor();
    }
    //pyramid indexes
    //             [1 1]
    //        [2 1] [2 2] [2 3]
    //   [3 1] [3 2] [3 3] [3 4] [3 5]

    return 0;
}
