#include <iostream>
#include <ctime>
#include <cstdlib>
#include <fstream>
#include <string>
using namespace std;
const int row = 3;
const int col = 3;
const int sizeS = 8;
int player = 1;
bool player1 = false;
bool player2 = false;
int win1 = 0, win2 = 0, lose1 = 0, lose2 = 0, draw = 0, compW = 0, compL = 0, draws = 0;
void main_menu();
void play_game();
void rules();
void printArr(char[][col]);
bool playerT();
void scoreBoard();
void pvp(char[][col]);
int skynet_Turn();
void pve(char[][col]);
void winningCondition(char[row][col]);
void toss(string);
void credits();
int main()
{
    main_menu();
    system("pause");
    return 0;

}
void rules()
{
    cout << "Come On it's tic tac toe you know what it is\n\n\n1. The game is played on a grid that's 3 squares by 3 squares\n2. You are X, your friend (or the computer) is O,Players take turns putting their marks in empty squares.\n3.The first player to get 3 of her marks in a row(up, down, across, or diagonally) is the winner.\n4. When all 9 squares are full, the game is over.If no player has 3 marks in a row, the game ends in a tie";
    system("pause");
    main_menu();
}
int skynet_Turn()
{
    static int x;
    x = rand() % 3;
    return x;
}
void printArr(char arr[][col])
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << "\t " << arr[i][j] << "	";
            if (j != 2)
                cout << "||";
        }
        cout << endl;
        if (i != 2)
        {
            cout << "    ------------------------------------------" << endl;
        }
    }
}
void toss(string x)
{
    srand(time(0));
    cout << "Player 1 is Heads\n\n";
    cout << x << " is Tails\n\n";
    player = rand() % 2;
    if (player == 0)
    {
        cout << "Player 1 won the toss\n\n";
    }
    else
        cout << x << " won the toss\n\n";
}
void winningCondition(char arr[row][col])
{
    static int condition1[8], condition2[8];
    for (int i = 0; i < 8; i++)
    {
        condition1[i] = 0;
        condition2[i] = 0;
    }
    for (int j = 0; j < col; j++)
    {
        if (arr[0][j] == 'X')
        {
            condition1[0] = 1;
        }
        else
        {
            condition1[0] = 0;
            break;
        }
    }
    for (int j = 0; j < col; j++)
    {
        if (arr[0][j] == 'O')
        {
            condition2[0] = 1;
        }
        else
        {
            condition2[0] = 0;
            break;
        }
    }
    for (int j = 0; j < col; j++)
    {
        if (arr[row - 1][j] == 'X')
        {
            condition1[1] = 1;
        }
        else
        {
            condition1[1] = 0;
            break;
        }
    }

    for (int j = 0; j < col; j++)
    {
        if (arr[row - 1][j] == 'O')
        {
            condition2[1] = 1;
        }
        else
        {
            condition2[1] = 0;
            break;
        }
    }
    for (int j = 0; j < col; j++)
    {
        if (arr[row - 2][j] == 'X')
        {
            condition1[2] = 1;
        }
        else
        {
            condition1[2] = 0;
            break;
        }
    }
    for (int j = 0; j < col; j++)
    {
        if (arr[row - 2][j] == 'O')
        {
            condition2[2] = 1;
        }
        else
        {
            condition2[2] = 0;
            break;
        }
    }
    for (int j = 0; j < col; j++)
    {
        if (arr[j][0] == 'X')
        {
            condition1[3] = 1;
        }
        else
        {
            condition1[3] = 0;
            break;
        }
    }
    for (int j = 0; j < col; j++)
    {
        if (arr[j][0] == 'O')
        {
            condition2[3] = 1;
        }
        else
        {
            condition2[3] = 0;
            break;
        }
    }
    for (int j = 0; j < col; j++)
    {
        if (arr[j][col - 1] == 'X')
        {
            condition1[4] = 1;
        }
        else
        {
            condition1[4] = 0;
            break;
        }
    }
    for (int j = 0; j < col; j++)
    {
        if (arr[j][col - 1] == 'O')
        {
            condition2[4] = 1;
        }
        else
        {
            condition2[4] = 0;
            break;
        }
    }
    for (int j = 0; j < col; j++)
    {
        if (arr[j][col - 2] == 'X')
        {
            condition1[5] = 1;
        }
        else
        {
            condition1[5] = 0;
            break;
        }
    }
    for (int j = 0; j < col; j++)
    {
        if (arr[j][col - 2] == 'O')
        {
            condition2[5] = 1;
        }
        else
        {
            condition2[5] = 0;
            break;
        }
    }
    for (int i = 0; i < col; i++)
    {
        if (arr[i][i] == 'X')
        {
            condition1[6] = 1;
        }
        else
        {
            condition1[6] = 0;
            break;
        }
    }
    for (int i = 0; i < col; i++)
    {
        if (arr[i][i] == 'O')
        {
            condition2[6] = 1;
        }
        else
        {
            condition2[6] = 0;
            break;
        }
    }
    int e;
    e = col - 1;
    for (int i = 0; i < col; i++)
    {
        if (arr[i][e] == 'X')
        {
            condition1[7] = 1;
        }
        else
        {
            condition1[7] = 0;
            break;
        }
        --e;
    }
    int r = col - 1;
    for (int i = 0; i < col; i++)
    {
        if (arr[i][r] == 'O')
        {
            condition2[7] = 1;
        }
        else
        {
            condition2[7] = 0;
            break;
        }
        --r;
    }
    for (int i = 0; i < 8; i++)
    {
        if (condition1[i] == 1)
        {
            player1 = true;
            system("cls");
            break;
        }
        else if (condition2[i] == 1)
        {
            player2 = true;
            system("cls");
            break;
        }

    }

}
bool playerT()
{
    bool playerTurn = true;
    player = player % 2;
    if (player + 1 == 1)
    {
        playerTurn = true;

    }
    if (player + 1 == 2)
    {
        playerTurn = false;
    }

    return playerTurn;
}
void scoreBoard()
{
    system("cls");
    cout << "\nGAMES WON BY PLAYER 1 ARE: " << win1 << endl;
    cout << "GAMES WON BY PLAYER 2 ARE: " << win2 << endl;
    cout << "GAMES WON BY COMPUTER ARE: " << compW << endl;
    cout << "GAMES LOST BY PLAYER 1 ARE: " << lose1 << endl;
    cout << "GAMES LOST BY PLAYER 2 ARE: " << lose2 << endl;
    cout << "GAMES LOST BY COMPUTER ARE: " << compL << endl;
    cout << "NUMBER OF DRAWS ARE: " << draws << endl;
    ofstream fout;
    fout.open("Scores.txt", ios::app);
    fout << "\nGAMES WON BY PLAYER 1 ARE: " << win1 << endl;
    fout << "GAMES WON BY PLAYER 2 ARE: " << win2 << endl;
    fout << "GAMES WON BY COMPUTER ARE: " << compW << endl;
    fout << "GAMES LOST BY PLAYER 1 ARE: " << lose1 << endl;
    fout << "GAMES LOST BY PLAYER 2 ARE: " << lose2 << endl;
    fout << "GAMES LOST BY COMPUTER ARE: " << compL << endl;
    fout << "NUMBER OF DRAWS ARE: " << draws << endl;
    fout.close();
    system("pause");
    main_menu();
}
void credits()
{
    system("cls");
    cout << "MADE FROM SCRATCH BY YOUR'S TRUELY\n\n\t\tSADEED\n\n";
    system("pause");
    main_menu();
}
void pve(char arr[row][col])
{
    string x = "Skynet ";
    toss(x);
    system("pause");
    char chr;
    int option = 0;
    int count = 0;
    while (player1 == false && player2 == false && count < 9)
    {
        system("cls");
        cout << "\t\t    TIC TAC TOE\n\n";
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                cout << "\t " << arr[i][j] << "	";
                if (j != 2)
                    cout << "||";
            }
            cout << endl;
            if (i != 2)
            {
                cout << "    ------------------------------------------" << endl;
            }
        }
        if (playerT() == true)
        {
            cout << "Player 1 turn: ";
            chr = 'X';
            cin >> option;
        }
        if (playerT() == false)
        {

            cout << "Skynet's turn: ";
            chr = 'O';
            static int x, y;
            srand(time(0));
            while (1)
            {
                x = skynet_Turn();
                y = skynet_Turn();
                if (arr[x][y] == ' ')
                {
                    if (x == 0 && y == 0)
                    {
                        option = 1;
                        break;
                    }
                    else if (x == 0 && y == 1)
                    {
                        option = 2;
                        break;
                    }
                    else if (x == 0 && y == 2)
                    {
                        option = 3;
                        break;
                    }
                    else if (x == 1 && y == 0)
                    {
                        option = 4;
                        break;
                    }
                    else if (x == 1 && y == 1)
                    {
                        option = 5;
                        break;
                    }
                    else if (x == 1 && y == 2)
                    {
                        option = 6;
                        break;
                    }
                    else if (x == 2 && y == 0)
                    {
                        option = 7;
                        break;
                    }
                    else if (x == 2 && y == 1)
                    {
                        option = 8;
                        break;
                    }
                    else
                    {
                        option = 9;
                        break;
                    }
                }
            }
            //These conditions provide AI functionality. 
            if (arr[0][0] == 'X' && arr[1][1] == 'X')
            {
                if (arr[2][2] == ' ')
                {
                    option = 9;
                }
            }
            else if (arr[0][0] == 'X' && arr[0][2] == 'X')
            {
                if (arr[0][1] == ' ')
                {
                    option = 2;
                }
            }
            else if (arr[2][1] == 'X' && arr[1][1] == 'X')
            {
                if (arr[0][1] == ' ')
                {
                    option = 2;
                }
            }
            else if (arr[0][0] == 'X' && arr[2][0] == 'X')
            {
                if (arr[1][0] == ' ')
                {
                    option = 4;
                }
            }
            else if (arr[0][2] == 'X' && arr[2][2] == 'X')
            {
                if (arr[1][2] == ' ')
                {
                    option = 6;
                }
            }
            else if (arr[2][0] == 'X' && arr[2][2] == 'X')
            {
                if (arr[2][1] == ' ')
                {
                    option = 8;
                }
            }
            else if (arr[0][0] == 'X' && arr[0][1] == 'X')
            {
                if (arr[0][2] == ' ')
                {
                    option = 3;
                }
            }
            else if (arr[0][0] == 'X' && arr[1][0] == 'X')
            {
                if (arr[2][0] == ' ')
                {
                    option = 7;
                }
            }
            else if (arr[2][2] == 'X' && arr[2][1] == 'X')
            {
                if (arr[2][0] == ' ')
                {
                    option = 7;
                }
            }
            else if (arr[2][2] == 'X' && arr[1][2] == 'X')
            {
                if (arr[0][2] == ' ')
                {
                    option = 3;
                }
            }
            else if (arr[0][1] == 'X' && arr[1][1] == 'X')
            {
                if (arr[2][1] == ' ')
                {
                    option = 8;
                }
            }
            else if (arr[2][0] == 'X' && arr[1][0] == 'X')
            {
                if (arr[0][0] == ' ')
                {
                    option = 1;
                }
            }
            else if (arr[2][2] == 'X' && arr[1][1] == 'X')
            {
                if (arr[0][0] == ' ')
                {
                    option = 1;
                }
            }
            else if (arr[0][2] == 'X' && arr[1][2] == 'X')
            {
                if (arr[2][2] == ' ')
                {
                    option = 9;
                }
            }
            else if (arr[0][2] == 'X' && arr[2][2] == 'X')
            {
                if (arr[1][2] == ' ')
                {
                    option = 6;
                }
            }
            else if (arr[2][1] == 'O' && arr[1][1] == 'O')
            {
                if (arr[0][1] == ' ')
                {
                    option = 2;
                }
            }
            else if (arr[1][1] == 'O' && arr[1][2] == 'O')
            {
                if (arr[1][0] == ' ')
                {
                    option = 3;
                }
            }
            else if (arr[0][0] == 'O' && arr[0][2] == 'O')
            {
                if (arr[0][1] == ' ')
                {
                    option = 2;
                }
            }
            else if (arr[0][0] == 'O' && arr[2][0] == 'O')
            {
                if (arr[1][0] == ' ')
                {
                    option = 4;
                }
            }
            else if (arr[2][0] == 'O' && arr[2][2] == 'O')
            {
                if (arr[2][1] == ' ')
                {
                    option = 8;
                }
            }
            else if (arr[0][0] == 'O' && arr[0][1] == 'O')
            {
                if (arr[0][2] == ' ')
                {
                    option = 3;
                }
            }
            else if (arr[0][0] == 'O' && arr[1][0] == 'O')
            {
                if (arr[2][0] == ' ')
                {
                    option = 7;
                }
            }
            else if (arr[2][2] == 'O' && arr[2][1] == 'O')
            {
                if (arr[2][0] == ' ')
                {
                    option = 7;
                }
            }
            else if (arr[2][2] == 'O' && arr[1][2] == 'O')
            {
                if (arr[0][2] == ' ')
                {
                    option = 3;
                }
            }
            else if (arr[0][1] == 'O' && arr[1][1] == 'O')
            {
                if (arr[2][1] == ' ')
                {
                    option = 8;
                }
            }
            else if (arr[1][1] == 'O' && arr[1][2] == 'O')
            {
                if (arr[0][0] == ' ')
                {
                    option = 1;
                }
            }
            else if (arr[0][0] == 'O' && arr[0][1] == 'O')
            {
                if (arr[0][2] == ' ')
                {
                    option = 3;
                }
            }
            else if (arr[2][2] == 'O' && arr[2][1] == 'O')
            {
                if (arr[2][0] == ' ')
                {
                    option = 7;
                }
            }
            else if (arr[0][1] == 'O' && arr[1][1] == 'O')
            {
                if (arr[2][1] == ' ')
                {
                    option = 8;
                }
            }
            else if (arr[2][2] == 'O' && arr[1][2] == 'O')
            {
                if (arr[0][2] == ' ')
                {
                    option = 3;
                }
            }
            else if (arr[0][0] == 'O' && arr[1][1] == 'O')
            {
                if (arr[2][2] == ' ')
                {
                    option = 9;
                }
            }
            else if (arr[2][2] == 'O' && arr[1][1] == 'O')
            {
                if (arr[0][0] == ' ')
                {
                    option = 1;
                }
            }
            else if (arr[0][2] == 'O' && arr[1][2] == 'O')
            {
                if (arr[2][2] == ' ')
                {
                    option = 9;
                }
            }
            else if (arr[0][2] == 'O' && arr[2][2] == 'O')
            {
                if (arr[1][2] == ' ')
                {
                    option = 6;
                }
            }
            system("pause");
        }
        if (option == 1 && arr[0][0] == ' ')
        {
            arr[0][0] = chr;
            player++;
            count++;
        }
        else if (option == 2 && arr[0][1] == ' ')
        {
            arr[0][1] = chr;
            player++;
            count++;
        }
        else if (option == 3 && arr[0][2] == ' ')
        {
            arr[0][2] = chr;
            player++;
            count++;
        }
        else if (option == 4 && arr[1][0] == ' ')
        {
            arr[1][0] = chr;
            player++;
            count++;
        }
        else if (option == 5 && arr[1][1] == ' ')
        {
            arr[1][1] = chr;
            player++;
            count++;
        }
        else if (option == 6 && arr[1][2] == ' ')
        {
            arr[1][2] = chr;
            player++;
            count++;
        }
        else if (option == 7 && arr[2][0] == ' ')
        {
            arr[2][0] = chr;
            player++;
            count++;
        }
        else if (option == 8 && arr[2][1] == ' ')
        {
            arr[2][1] = chr;
            player++;
            count++;
        }
        else if (option == 9 && arr[2][2] == ' ')
        {
            arr[2][2] = chr;
            player++;
            count++;
        }
        else
        {
            cout << "\nInavlid Input\n";
        }
        printArr(arr);
        winningCondition(arr);
    }
    if (player1 == true)
    {
        cout << "\nPLAYER 1 HAS WON\n\n";
        win1 = win1 + 1;
        compL = compL + 1;
        printArr(arr);
    }
    else if (player2 == true)
    {
        cout << "\nSKYNET HAS WON\n\n";
        compW = compW + 1;
        lose1 = lose1 + 1;
        printArr(arr);
    }
    else
    {
        system("cls");
        draw = draw + 1;
        cout << "\nDRAW\n\n";
        printArr(arr);
    }
    player1 = false;
    player2 = false;
    system("pause");
    main_menu();
}
void pvp(char arr[row][col])
{
    char chr;
    int option;
    int count = 0;
    string x = "Player 2";
    toss(x);
    system("pause");
    while (player1 == false && player2 == false && count < 9)
    {
        system("cls");
        cout << "\t\t    TIC TAC TOE\n\n";
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                cout << "\t " << arr[i][j] << "	";
                if (j != 2)
                    cout << "||";
            }
            cout << endl;
            if (i != 2)
            {
                cout << "    ------------------------------------------" << endl;
            }
        }
        if (playerT() == true)
        {
            cout << "Player 1 turn: ";
            chr = 'X';
            cin >> option;
        }
        if (playerT() == false)
        {
            cout << "Player 2 turn: ";
            chr = 'O';
            cin >> option;
            system("cls");
        }
        if (option == 1 && arr[0][0] == ' ')
        {
            arr[0][0] = chr;
            player++;
            count++;
        }
        else if (option == 2 && arr[0][1] == ' ')
        {
            arr[0][1] = chr;
            player++;
            count++;
        }
        else if (option == 3 && arr[0][2] == ' ')
        {
            arr[0][2] = chr;
            player++;
            count++;
        }
        else if (option == 4 && arr[1][0] == ' ')
        {
            arr[1][0] = chr;
            player++;
            count++;
        }
        else if (option == 5 && arr[1][1] == ' ')
        {
            arr[1][1] = chr;
            player++;
            count++;
        }
        else if (option == 6 && arr[1][2] == ' ')
        {
            arr[1][2] = chr;
            player++;
            count++;
        }
        else if (option == 7 && arr[2][0] == ' ')
        {
            arr[2][0] = chr;
            player++;
            count++;
        }
        else if (option == 8 && arr[2][1] == ' ')
        {
            arr[2][1] = chr;
            player++;
            count++;
        }
        else if (option == 9 && arr[2][2] == ' ')
        {
            arr[2][2] = chr;
            player++;
            count++;
        }
        else
        {
            cout << "\nInavlid Input\n";
        }
        printArr(arr);
        winningCondition(arr);
    }
    if (player1 == true)
    {
        cout << "\nPLAYER 1 HAS WON\n\n";
        win1 = win1 + 1;
        lose2 = lose2 + 1;
        printArr(arr);
    }
    else if (player2 == true)
    {
        cout << "\nPLAYER 2 HAS WON\n\n";
        win2 = win2 + 1;
        lose1 = lose1 + 1;
        printArr(arr);
    }
    else
    {
        system("cls");
        cout << "\nDRAW\n\n";
        draw = draw + 1;
        printArr(arr);
    }
    player1 = false;
    player2 = false;
    system("pause");
    main_menu();
}
void play_game()
{
    system("cls");
    char arr[row][col];
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            arr[i][j] = ' ';
        }
    }
    int option;
    cout << "DO YOU WANT TO PLAY PVP OR PVE?\nENTER \n1 FOR PVP\n2 FOR PVE\n";
    cin >> option;
    system("cls");
    switch (option)
    {
    case 1:
        pvp(arr);
        break;
    case 2:
        pve(arr);
        break;
    default:
        cout << "INVALID OPTION TRY AGAIN\n";
        cin >> option;
    }
}
void main_menu()
{
    system("cls");
    int option;
    cout << "WELCOME TO TIC TAC TOE BATTLE\n";
    cout << "ENTER 1 TO PLAY THE GAME\n" << "ENTER 2 TO SEE THE CREDITS\n" << "ENTER 3 TO VIEW SCORE HISTORY\n" << "ENTER 4 TO VIEW RULES\n" << "\nENTER 0 TO EXIT\n\n";
    cin >> option;
    switch (option)
    {
    case 1:
        play_game();
        break;
    case 2:
        credits();
        break;
    case 3:
        scoreBoard();
        break;
    case 4:
        rules();
        break;
    }
}

