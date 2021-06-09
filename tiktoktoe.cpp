#include<bits/stdc++.h>
using namespace std;
struct Move
{
    int row, col;
};
char board[3][3] =
{
    { '1', '2', '3' },
    { '4', '5', '6' },
    { '7', '8', '9' }
};
char player1 = 'X', player2 = 'O';
int nop;
bool isMovesLeft(char board[3][3])
{
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (isdigit(board[i][j]))
                return true;
    return false;
}
int evaluate(char b[3][3])
{
    for (int row = 0; row < 3; row++)
    {
        if (b[row][0] == b[row][1] &&
                b[row][1] == b[row][2])
        {
            if (b[row][0] == player2)
                return +10;
            else if (b[row][0] == player1)
                return -10;
        }
    }
    for (int col = 0; col < 3; col++)
    {
        if (b[0][col] == b[1][col] &&
                b[1][col] == b[2][col])
        {
            if (b[0][col] == player2)
                return +10;
            else if (b[0][col] == player1)
                return -10;
        }
    }
    if (b[0][0] == b[1][1] && b[1][1] == b[2][2])
    {
        if (b[0][0] == player2)
            return +10;
        else if (b[0][0] == player1)
            return -10;
    }
    if (b[0][2] == b[1][1] && b[1][1] == b[2][0])
    {
        if (b[0][2] == player2)
            return +10;
        else if (b[0][2] == player1)
            return -10;
    }
    return 0;
}
int minimax(char board[3][3], int depth, bool isMax)
{
    int score = evaluate(board);
    if (score == 10)
        return score;
    if (score == -10)
        return score;
    if (isMovesLeft(board) == false)
        return 0;
    if (isMax)
    {
        int best = -1000;
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (isdigit(board[i][j]))
                {
                    char temp = board[i][j];
                    board[i][j] = player2;
                    best = max( best,
                                minimax(board, depth + 1, !isMax) );
                    board[i][j] = temp;
                }
            }
        }
        return best;
    }
    else
    {
        int best = 1000;
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (isdigit(board[i][j]))
                {
                    char temp = board[i][j];
                    board[i][j] = player1;
                    best = min(best,
                               minimax(board, depth + 1, !isMax));
                    board[i][j] = temp;
                }
            }
        }
        return best;
    }
}
Move findBestMove(char board[3][3])
{
    int bestVal = -1000;
    Move bestMove;
    bestMove.row = -1;
    bestMove.col = -1;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (isdigit(board[i][j]))
            {
                char temp = board[i][j];
                board[i][j] = player2;
                int moveVal = minimax(board, 0, false);
                board[i][j] = temp;
                if (moveVal > bestVal)
                {
                    bestMove.row = i;
                    bestMove.col = j;
                    bestVal = moveVal;
                }
            }
        }
    }
    return bestMove;
}
void dboard()
{
    system("clear");
    cout << "\n\n\t\tTic Tac Toe\n\n";
    cout << "\tPlayer 1 (" << player1 << ") - Player 2 (" << player2 << ")" << endl << endl;
    cout << endl;
    cout << " \t\t _________________\n";
    cout << "\t\t|     |     |     |" << endl;
    cout << "\t\t|  " << board[0][0] << "  |  " << board[0][1] <<
         "  |  " << board[0][2] << "  |" << endl;
    cout << "\t\t|_____|_____|_____|" << endl;
    cout << "\t\t|     |     |     |" << endl;
    cout << "\t\t|  " << board[1][0] << "  |  " << board[1][1] <<
         "  |  " << board[1][2] << "  |" << endl;
    cout << "\t\t|_____|_____|_____|" << endl;
    cout << "\t\t|     |     |     |" << endl;
    cout << "\t\t|  " << board[2][0] << "  |  " << board[2][1] <<
         "  |  " << board[2][2] << "  |" << endl;
    cout << "\t\t|_____|_____|_____|" << endl << endl << endl;
}
int checkwin()
{
    int i, j;
    for (i = 0; i < 3; i++)
    {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2])
            return 1;
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i])
            return 1;
    }
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2])
        return 1;
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0])
        return 1;
    else if (board[0][0] != '1' && board[0][1] != '2' &&
             board[0][2] != '3' &&
             board[1][0] != '4' && board[1][1] != '5' &&
             board[1][2] != '6'
             && board[2][0] != '7' && board[2][1] != '8' &&
             board[2][2] != '9')
        return 0;
    else
        return -1;
}
int main()
{
    int player = 1, i, choice;
    char mark;
    printf("\n\t1. Single Player(vs Computer) - HARD\n\t2. Single Player(vs Computer) - EASY\n\t3. Two Players\n");
    do
    {
        printf("Enter your Choice: ");
        scanf("%d", &nop);
        if (nop != 1 && nop != 2 && nop != 3)
            printf("Invalid choice\n");
    }
    while (nop != 1 && nop != 2 && nop != 3);
    if (nop == 1)
    {
        do
        {
            dboard();
            if(player % 2 == 1)
                player = 1;
            else
                player = 2;
            // player 2
            if(player == 2)
            {
                cout << "Player " << player << endl;
                cout << "Press Enter for CPU" << endl;
                Move m = findBestMove(board);
                mark = player2;
                int turn = 1;
                int placed = 0;
                while(placed == 0)
                {
                    if (m.row == 0 && m.col == 0 && board[0][0] == '1')
                    {
                        board[0][0] = mark;
                        placed = 1;
                    }
                    else if (m.row == 0 && m.col == 1 && board[0][1] ==
                             '2')
                    {
                        board[0][1] = mark;
                        placed = 1;
                    }
                    else if (m.row == 0 && m.col == 2 && board[0][2] ==
                             '3')
                    {
                        board[0][2] = mark;
                        placed = 1;
                    }
                    else if (m.row == 1 && m.col == 0 && board[1][0] ==
                             '4')
                    {
                        board[1][0] = mark;
                        placed = 1;
                    }
                    else if (m.row == 1 && m.col == 1 && board[1][1] ==
                             '5')
                    {
                        board[1][1] = mark;
                        placed = 1;
                    }
                    else if (m.row == 1 && m.col == 2 && board[1][2] ==
                             '6')
                    {
                        board[1][2] = mark;
                        placed = 1;
                    }
                    else if (m.row == 2 && m.col == 0 && board[2][0] ==
                             '7')
                    {
                        board[2][0] = mark;
                        placed = 1;
                    }
                    else if (m.row == 2 && m.col == 1 && board[2][1] ==
                             '8')
                    {
                        board[2][1] = mark;
                        placed = 1;
                    }
                    else if (m.row == 2 && m.col == 2 && board[2][2] ==
                             '9')
                    {
                        board[2][2] = mark;
                        placed = 1;
                    }
                    else
                    {
                        m = findBestMove(board);
                    }
                }
                i = checkwin();
                player++;
                getchar();
                dboard();
            }
            // player 1
            else if(player == 1)
            {
                cout << "Player " << player << ", enter a number: ";
                cin >> choice;
                mark = player1;
                if (choice == 1 && board[0][0] == '1')
                    board[0][0] = mark;
                else if (choice == 2 && board[0][1] == '2')
                    board[0][1] = mark;
                else if (choice == 3 && board[0][2] == '3')
                    board[0][2] = mark;
                else if (choice == 4 && board[1][0] == '4')
                    board[1][0] = mark;
                else if (choice == 5 && board[1][1] == '5')
                    board[1][1] = mark;
                else if (choice == 6 && board[1][2] == '6')
                    board[1][2] = mark;
                else if (choice == 7 && board[2][0] == '7')
                    board[2][0] = mark;
                else if (choice == 8 && board[2][1] == '8')
                    board[2][1] = mark;
                else if (choice == 9 && board[2][2] == '9')
                    board[2][2] = mark;
                else
                {
                    cout << "Invalid move ";
                    player--;
                    getchar();
                }
                i = checkwin();
                player++;
            }
        }
        while(i == -1);
    }
    else if (nop == 2)
    {
        do
        {
            dboard();
            if(player % 2 == 1)
                player = 1;
            else
                player = 2;
            // player 2
            if(player == 2)
            {
                cout << "Player " << player << endl;
                cout << "Press Enter for CPU" << endl;
                choice = rand() % 9;
                mark = player2;
                int turn = 1;
                int placed = 0;
                while(placed == 0)
                {
                    if (choice == 1 && board[0][0] == '1')
                    {
                        board[0][0] = mark;
                        placed = 1;
                    }
                    else if (choice == 2 && board[0][1] == '2')
                    {
                        board[0][1] = mark;
                        placed = 1;
                    }
                    else if (choice == 3 && board[0][2] == '3')
                    {
                        board[0][2] = mark;
                        placed = 1;
                    }
                    else if (choice == 4 && board[1][0] == '4')
                    {
                        placed = 1;
                        board[1][0] = mark;
                    }
                    else if (choice == 5 && board[1][1] == '5')
                    {
                        board[1][1] = mark;
                        placed = 1;
                    }
                    else if (choice == 6 && board[1][2] == '6')
                    {
                        board[1][2] = mark;
                        placed = 1;
                    }
                    else if (choice == 7 && board[2][0] == '7')
                    {
                        board[2][0] = mark;
                        placed = 1;
                    }
                    else if (choice == 8 && board[2][1] == '8')
                    {
                        board[2][1] = mark;
                        placed = 1;
                    }
                    else if (choice == 0 && board[2][2] == '9')
                    {
                        board[2][2] = mark;
                        placed = 1;
                    }
                    else
                    {
                        choice = rand() % 9;
                    }
                }
                i = checkwin();
                player++;
                getchar();
                dboard();
            }
            // player 1
            else if(player == 1)
            {
                cout << "Player " << player << ", enter a number: ";
                cin >> choice;
                mark = player1;
                if (choice == 1 && board[0][0] == '1')
                    board[0][0] = mark;
                else if (choice == 2 && board[0][1] == '2')
                    board[0][1] = mark;
                else if (choice == 3 && board[0][2] == '3')
                    board[0][2] = mark;
                else if (choice == 4 && board[1][0] == '4')
                    board[1][0] = mark;
                else if (choice == 5 && board[1][1] == '5')
                    board[1][1] = mark;
                else if (choice == 6 && board[1][2] == '6')
                    board[1][2] = mark;
                else if (choice == 7 && board[2][0] == '7')
                    board[2][0] = mark;
                else if (choice == 8 && board[2][1] == '8')
                    board[2][1] = mark;
                else if (choice == 9 && board[2][2] == '9')
                    board[2][2] = mark;
                else
                {
                    cout << "Invalid move ";
                    player--;
                    getchar();
                }
                i = checkwin();
                player++;
            }
        }
        while(i == -1);
    }
    else if (nop == 3)
    {
        do
        {
            dboard();
            player = (player % 2) ? 1 : 2;
            cout << "\tPlayer " << player << ", enter a number: ";
            cin >> choice;
            mark = (player == 1) ? player1 : player2;
            if (choice == 1 && board[0][0] == '1')
                board[0][0] = mark;
            else if (choice == 2 && board[0][1] == '2')
                board[0][1] = mark;
            else if (choice == 3 && board[0][2] == '3')
                board[0][2] = mark;
            else if (choice == 4 && board[1][0] == '4')
                board[1][0] = mark;
            else if (choice == 5 && board[1][1] == '5')
                board[1][1] = mark;
            else if (choice == 6 && board[1][2] == '6')
                board[1][2] = mark;
            else if (choice == 7 && board[2][0] == '7')
                board[2][0] = mark;
            else if (choice == 8 && board[2][1] == '8')
                board[2][1] = mark;
            else if (choice == 9 && board[2][2] == '9')
                board[2][2] = mark;
            else
            {
                cout << "\tInvalid move ";
                player--;
                getchar();
            }
            i = checkwin();
            player++;
        }
        while(i == -1);
    }
    dboard();
    if(i == 1)
        cout << "Congratulation! \nPlayer " << --player << " win ";
    else
        cout << "OOPS!\nGame draw";
    getchar();
}
