#include <iostream>
#include <cmath>

using namespace std;

// check if a certain position on the board is occupied by a red or black piece
string checkPos(int x, int y, int red[][6], int black[][6])
{
    string str = "";
    if (red[x][y] != 0)
        if (red[x][y] == 1)
            str = "r1";
        else
            str = "r2";
    else if (black[x][y] != 0)
        if (black[x][y] == 1)
            str = "b1";
        else
            str = "b2";
    else
        str = "  ";

    return str;
}
bool validMove(int xP, int yP, int xL, int yL, int red[][6], int black[][6], string o, string o2, string p, string p2, bool& j)
{
    /// INVALID MOVES
    if (checkPos(xL, yL, red, black) != "  ") {
        cout << "You can not move onto another piece! " << endl;
        return false;
    }
    else if (xL == xP || yL == yP) {
        cout << "You can only move diagonally! " << endl;
        return false;
    }
    // CHECKING JUMPING LOGIC
    else if (abs(xP - xL) == 2) {
        if (checkPos(abs((xL + xP) / 2), abs((yL + yP) / 2), red, black) == o2 && checkPos(xP, yP, red, black) == p2) {
            j = true;
            return true;
        }
        if (checkPos(abs((xL + xP) / 2), abs((yL + yP) / 2), red, black) == o && checkPos(xP, yP, red, black) == p) {
            j = true;
            return true;
        }
        else {
            cout << "Invalid jump! Remember, you can only jump pieces with the opposite letter and same number!" << endl;
            return false;
        }
    }
    else if (abs(xP - xL) != 1 || abs(yP - yL) != 1) {
        cout << "You can't move this far! 1 space only unless jumping!" << endl;
        return false;
    }
    /// END OF INVALID MOVES
    /// EVERYTHING PASSES; RETURN TRUE
    else {
        return true;
    }
}

//print board according to red and black arrays indicating positions on the board
void printBoard(int red[][6], int black[][6])
{
    cout << "\n";
    cout << "   ____ ____ ____ ____ ____ ____ " << endl;
    cout << "  |    |    |    |    |    |    |" << endl;
    cout << "5 | " << checkPos(0, 5, red, black) << " |    | " << checkPos(2, 5, red, black) << " |    | " << checkPos(4, 5, red, black) << " |    |" << endl;
    cout << "  |____|____|____|____|____|____|" << endl;
    cout << "  |    |    |    |    |    |    |" << endl;
    cout << "4 |    | " << checkPos(1, 4, red, black) << " |    | " << checkPos(3, 4, red, black) << " |    | " << checkPos(5, 4, red, black) << " |" << endl;
    cout << "  |____|____|____|____|____|____|" << endl;
    cout << "  |    |    |    |    |    |    |" << endl;
    cout << "3 | " << checkPos(0, 3, red, black) << " |    | " << checkPos(2, 3, red, black) << " |    | " << checkPos(4, 3, red, black) << " |    |" << endl;
    cout << "  |____|____|____|____|____|____|" << endl;
    cout << "  |    |    |    |    |    |    |" << endl;
    cout << "2 |    | " << checkPos(1, 2, red, black) << " |    | " << checkPos(3, 2, red, black) << " |    | " << checkPos(5, 2, red, black) << " |" << endl;
    cout << "  |____|____|____|____|____|____|" << endl;
    cout << "  |    |    |    |    |    |    |" << endl;
    cout << "1 | " << checkPos(0, 1, red, black) << " |    | " << checkPos(2, 1, red, black) << " |    | " << checkPos(4, 1, red, black) << " |    |" << endl;
    cout << "  |____|____|____|____|____|____|" << endl;
    cout << "  |    |    |    |    |    |    |" << endl;
    cout << "0 |    | " << checkPos(1, 0, red, black) << " |    | " << checkPos(3, 0, red, black) << " |    | " << checkPos(5, 0, red, black) << " |" << endl;
    cout << "  |____|____|____|____|____|____|" << endl;
    cout << "    0    1    2    3    4    5   \n" << endl;
}

void initializePieces(int red[][6], int black[][6])
{
    for (int i = 0; i < 6; i++)
        for (int j = 0; j < 6; j++) {
            red[i][j] = 0;
            black[i][j] = 0;
        }
    red[0][1] = 1;
    red[1][0] = 2;
    red[2][1] = 1;
    red[3][0] = 2;
    red[4][1] = 1;
    red[5][0] = 2;

    black[0][5] = 2;
    black[1][4] = 1;
    black[2][5] = 2;
    black[3][4] = 1;
    black[4][5] = 2;
    black[5][4] = 1;
}

void playGame(int red[][6], int black[][6], int& redPoints, int& blackPoints)
{
    bool redturn = false, blackturn = false, win = false, invalid = false, jump = false;
    int pieceX, pieceY, locationX, locationY;
    string player, piece1, piece2, opppiece1, opppiece2;

    while (blackPoints < 3 && redPoints < 3) {
        /// BLACK PLAYER PROFILE
        if (redturn) {
            redturn = false;
            blackturn = true;
            player = "Black";
            piece1 = "b1";
            piece2 = "b2";
            opppiece1 = "r1";
            opppiece2 = "r2";
        }
        /// RED PLAYER PROFILE
        else {
            redturn = true;
            blackturn = false;
            player = "Red";
            piece1 = "r1";
            piece2 = "r2";
            opppiece1 = "b1";
            opppiece2 = "b2";
        }

        cout << player << " Player, select the piece you would like to move(x, y): ";
        cin >> pieceX >> pieceY; /// PLAYER CHOSES PIECE TO MOVE
        /// CHECKS IF PIECE CHOSEN IS THEIRS TO MOVE
        while ((checkPos(pieceX, pieceY, red, black) != piece1 && checkPos(pieceX, pieceY, red, black) != piece2) || pieceX < 0 || pieceY < 0) {
            printBoard(red, black);
            cout << player << " Player, this is not a valid piece to move!" << endl;
            cout << player << " Player, select the piece you would like to move(x, y): ";
            cin >> pieceX >> pieceY;
        }
        invalid = true; /// FOR WHILE LOOP
        jump = false; /// TO ADD POINTS, DEFAULTS FALSE
        /// WHILE LOOP TO DETERMINE PIECE MOVEMENT
        while (invalid) {
            cout << player << " Player, select the place to move your piece (i.e. x y)(-1 -1 to pass): ";
            cin >> locationX >> locationY;
            /// USER CAN SKIP TURN
            if (locationX == -1 && locationY == -1) {
                cout << "Turn skipped!" << endl;
                invalid = false;
            }
            /// IF VALID MOVE FUNCTION RETURNS TRUE! PROCEED WITH PROPER STEPS
            else if (validMove(pieceX, pieceY, locationX, locationY, red, black, opppiece1, opppiece2, piece1, piece2, jump)) {
                if (redturn) {
                    red[locationX][locationY] = red[pieceX][pieceY]; /// MOVES PIECE
                    red[pieceX][pieceY] = 0; /// SETS LOCATION TO NOTHING
                    if (jump) { /// ADDS POINTS IF USER JUMPS!
                        black[((locationX + pieceX) / 2)][((locationY + pieceY) / 2)] = 0; /// SETS LOCATION TO NOTHING
                        cout << "+1 Point for " << player << "! " << endl;
                        redPoints++; /// ADDS USER POINT
                    }
                }
                else {
                    black[locationX][locationY] = black[pieceX][pieceY]; /// MOVES PIECE
                    black[pieceX][pieceY] = 0; /// SETS LOCATION TO NOTHING
                    if (jump) { /// ADDS POINTS IF USER JUMPS!
                        red[((locationX + pieceX) / 2)][((locationY + pieceY) / 2)] = 0; /// SETS LOCATION TO NOTHING
                        cout << "+1 Point for " << player << "! " << endl;
                        blackPoints++; /// ADDS USER POINT
                    }
                }

                invalid = false; /// ALLOWS FOR WHILE LOOP TO END
            }
            else {
                cout << player << " Player, this is not a valid place to move!" << endl; /// NOT VALID MOVE STATEMENT
            }
        }
        printBoard(red, black); /// PRINTS BOARD
    }
    cout << endl;
    /// END GAME, PRINTS SCORES
    cout << "Red Points: " << redPoints << endl;
    cout << "Black Points: " << blackPoints << endl;

    if (redPoints >= 3) {
        cout << "Red Player wins!";
    }
    else {
        cout << "Black Player wins!";
    }
}

int main()
{
    int red[6][6];
    int black[6][6];
    int redPoints = 0;
    int blackPoints = 0;
    initializePieces(red, black);
    printBoard(red, black);
    playGame(red, black, redPoints, blackPoints);
    return 0;
}
