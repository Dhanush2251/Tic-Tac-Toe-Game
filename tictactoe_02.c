#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

char board[3][3];
const char YOU = 'X';
const char COMP = 'O';

void resetboard();
void printboard();
int checkfreespaces();
void yourchoice();
void compchoice();
char checkwinner();
void printwinner(char winner);
void playwithcomputer();
void playwithopponent();


// This is helps to reset the board.
void resetboard() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = ' ';
        }
    }
}


// This helps to print the board in 3x3 matrix.
void printboard() 
{
    printf(" %c | %c | %c \n", board[0][0], board[0][1], board[0][2]);
    printf("---|---|---\n");
    printf(" %c | %c | %c \n", board[1][0], board[1][1], board[1][2]);
    printf("---|---|---\n");
    printf(" %c | %c | %c \n", board[2][0], board[2][1], board[2][2]);
}


// This helps to check the free spaces on the board.
int checkfreespaces() 
{
    int freespaces = 9;
    for (int i = 0; i < 3; i++) 
    {
        for (int j = 0; j < 3; j++) 
        {
            if (board[i][j] != ' ') 
            {
                freespaces--;
            }
        }
    }
    return freespaces;
}


// This helps to give the input to the board by your choice.
void yourchoice() 
{
    int x, y;
    do 
    {
        printf("Enter row (1-3): ");
        scanf("%d", &x);
        x--;
        printf("Enter column (1-3): ");
        scanf("%d", &y);
        y--;

        if (board[x][y] != ' ') 
        {
            printf("Invalid move\n");
        } else 
        {
            board[x][y] = YOU;
            break;
        }
    } while (board[x][y] != ' ');
}


// This helps the computer to take its choice. 
void compchoice() 
{
    srand(time(0));
    int x, y;

    if (checkfreespaces() > 0) 
    {
        do 
        {
            x = rand() % 3;
            y = rand() % 3;
        } while (board[x][y] != ' ');

        board[x][y] = COMP;
    } 
    else 
    {
        printwinner(' ');
    }
}


// This helps to check the winner.
char checkwinner() 
{
   
    for (int i = 0; i < 3; i++) // Check rows
    {
        if (board[i][0] == board[i][1] && board[i][0] == board[i][2] && board[i][0] != ' ') {
            return board[i][0];
    }
}
   
    for (int i = 0; i < 3; i++) // Check columns
    {
        if (board[0][i] == board[1][i] && board[0][i] == board[2][i] && board[0][i] != ' ') 
        {
            return board[0][i];
        }
    }

    // Check diagonals
    if (board[0][0] == board[1][1] && board[0][0] == board[2][2] && board[0][0] != ' ') 
    {
        return board[0][0];
    }
    if (board[0][2] == board[1][1] && board[0][2] == board[2][0] && board[0][2] != ' ') 
    {
        return board[0][2];
    }

    return ' ';
}


// This helps to print the winner of the game.
void printwinner(char winner) 
{
    if (winner == YOU) 
    {
        printf("You won the game!\n");
    } 
    else if (winner == COMP) 
    {
        printf("You lost the game.\n");
    } 
    else 
    {
        printf("The game is a tie.\n");
    }
}


//This helps to play with the computer.
void playwithcomputer() 
{
    char winner = ' ';
    char response;

    do 
    {
        resetboard();
        winner = ' ';
        while (winner == ' ' && checkfreespaces() != 0) 
        {
            printboard();
            yourchoice();
            winner = checkwinner();
            if (winner != ' ' || checkfreespaces() == 0) 
            {
                break;
            }
            compchoice();
            winner = checkwinner();
        }
        printboard();
        printwinner(winner);

        printf("Would you like to play again? (Y/N): ");
        while ((getchar()) != '\n'); // Clear input buffer
        response = getchar();
    } while (toupper(response) == 'Y');
}


/*This helps to play with the opponent. One chance gives to the player 1 with 'X'
and another chance for opponent gives to the player 2 with 'O'.*/
void playwithopponent() 
{
    char current_player = 'X';
    char opponent = 'O';
    char winner = ' ';
    int row, col;

    resetboard();
    while (1) 
    {
        printboard();
        printf("Player %c, enter your move row: and enter your move coloumn:", current_player);
        scanf("%d %d", &row,&col);

        if (row >= 1 && row <= 3 && col >= 1 && col <= 3 && board[row - 1][col - 1] == ' ') 
        {
            board[row - 1][col - 1] = current_player;
            winner = checkwinner();
            if (winner != ' ' || checkfreespaces() == 0) 
            {
                break;
            }
            current_player = (current_player == 'X') ? 'O' : 'X';
        } 
        else 
        {
            printf("Invalid move, try again.\n");
        }
    }
    printboard();
    printwinner(winner);
}

int main() 
{
    char option;
    printf("Enter the game mode:\n");
    printf("Enter 'c' to play with computer and 'o' to play with opponent: ");
    while ((getchar()) != '\n'); // Clear input buffer
    option = getchar();

    if (option == 'c') 
    {
        playwithcomputer();
    } 
    else if (option == 'o') 
    {
        playwithopponent();
    } 
    else 
    {
        printf("Invalid option. Exiting the game.\n");
    }
    printf("Thanks for playing. Hope you enjoyed!\n");
    return 0;
}