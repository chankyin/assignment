#include <iostream>

using namespace std;

void displayBoard(const char *board);

const char BOARD_X = 1, BOARD_O = 2;

int main() {
    char board[9] = {};
    int validMoves = 0;
    char turn = BOARD_X;
    while (validMoves < 4) {
        displayBoard(board);
        if (turn == BOARD_X) {
            cout << "x: ";
        } else {
            cout << "o: ";
        }
        int input;
        cin >> input;
        --input;
        if (0 <= input && input < 9 && board[input] == 0) {
            // update board
            board[input] = turn;
            // switch turn
            if (turn == BOARD_X) {
                turn = BOARD_O;
            } else {
                turn = BOARD_X;
            }
            ++validMoves;
        }
        // invalid input, turn retained
    }
    displayBoard(board);
}

void displayBoard(const char *board) {
    for (int row = 0; row < 3; ++row) {
        for (int col = 0; col < 3; ++col) {
            char state = board[row * 3 + col];
            if (state == BOARD_X) {
                cout << 'x';
            } else if (state == BOARD_O) {
                cout << 'o';
            } else {
                cout << (row * 3 + col + 1);
            }
        }
        cout << endl;
    }
}