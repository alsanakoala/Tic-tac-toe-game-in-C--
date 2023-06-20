#include <iostream>
using namespace std;

char board[3][3]; // Game board

// Initializes the game board to the initial state
void initializeBoard()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            board[i][j] = ' ';
        }
    }
}

// Draws the game board on the screen
void drawBoard()
{
    cout << "-------------" << endl;
    for (int i = 0; i < 3; i++)
    {
        cout << "| ";
        for (int j = 0; j < 3; j++)
        {
            cout << board[i][j] << " | ";
        }
        cout << endl << "-------------" << endl;
    }
}

// Places the player's move on the game board
void makeMove(int row, int column, char symbol)
{
    board[row][column] = symbol;
}

// Checks if the player's move is valid
bool isValidMove(int row, int column)
{
    if (row < 0 || row >= 3 || column < 0 || column >= 3)
    {
        return false;
    }
    if (board[row][column] != ' ')
    {
        return false;
    }
    return true;
}

// Checks for the winner of the game
char checkWinner()
{
    // Horizontal check
    for (int i = 0; i < 3; i++)
    {
        if (board[i][0] != ' ' && board[i][0] == board[i][1] && board[i][0] == board[i][2])
        {
            return board[i][0];
        }
    }

    // Vertical check
    for (int i = 0; i < 3; i++)
    {
        if (board[0][i] != ' ' && board[0][i] == board[1][i] && board[0][i] == board[2][i])
        {
            return board[0][i];
        }
    }

    // Diagonal check
    if (board[0][0] != ' ' && board[0][0] == board[1][1] && board[0][0] == board[2][2])
    {
        return board[0][0];
    }

    if (board[0][2] != ' ' && board[0][2] == board[1][1] && board[0][2] == board[2][0])
    {
        return board[0][2];
    }

    // Tie check
    bool isFull = true;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (board[i][j] == ' ')
            {
                isFull = false;
                break;
            }
        }
    }
    if (isFull)
    {
        return 'T';
    }
    // Game is still ongoing
    return ' ';
}

int main()
{
    initializeBoard(); // Initialize the game board

    char currentPlayer = 'X'; // First player starts with X
    bool gameEnded = false;

    while (!gameEnded)
    {
        drawBoard(); // Draw the game board

        // Ask the player for their move coordinates
        int row, column;
        cout << "Player " << currentPlayer << "'s turn. Enter the row and column number to make a move (1-3): ";
        cin >> row >> column;

        // Convert the coordinates to 0-based indexing
        row--;
        column--;

        if (isValidMove(row, column))
        {
            makeMove(row, column, currentPlayer); // Place the move on the game board

            char winner = checkWinner(); // Check for a winner

            if (winner != ' ')
            {
                // There is a winner or it's a tie
                drawBoard();
                if (winner == 'T')
                {
                    cout << "The game ended in a tie!" << endl;
                }
                else {
                    cout << "Congratulations! Player " << winner << " won the game!" << endl;
                }
                gameEnded = true;
            }
            else
            {
                // Switch player
                if (currentPlayer == 'X')
                {
                    currentPlayer = 'O';
                }
                else
                {
                    currentPlayer = 'X';
                }
            }
        }
        else
        {
            cout << "Invalid move. Please try again." << endl;
        }
    }

    return 0;
}