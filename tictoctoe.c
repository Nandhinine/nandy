#include 
#include 
#include 
//****Length Of Our Board i.e 3*3 so Side is 3****//
#define SIDE 3
#define CPU 1
#define PLAYER 2
#define CPUMOVE 'O'
#define PLAYERMOVE 'X'
//******Our Tic Tac Toe Board With Data*********//
void ShowTicTacToeBoard(char board[][SIDE]){
 printf("\n\n");
     
    printf("\t\t  %c | %c  | %c  \n", board[0][0],
                             board[0][1], board[0][2]);
    printf("\t\t--------------\n");
    printf("\t\t  %c | %c  | %c  \n", board[1][0],
                             board[1][1], board[1][2]);
    printf("\t\t--------------\n");
    printf("\t\t  %c | %c  | %c  \n\n", board[2][0],
                             board[2][1], board[2][2]);
  
    return;
}

//****Our First Time Instruction Board********//
void showGameInstruction(){
	printf("||============Tic Tac Toe Game==========||\n");
	printf("---Choose A Cell For Your Chance-------\n");
	printf("\n\n");
	printf("\t\t 1 | 2 | 3 \t\t\t\n");
	printf("\t\t 4 | 5 | 6 \t\t\t\n");
	printf("\t\t 7 | 8 | 9 \t\t\t\n");
	printf("\n\n");
}

void IntitialIzeGame(char board[][SIDE], int moves[])
{
	//************Intialize Random No. With Current Time From Millisec************//

    srand(time(NULL)); 
    
    //************Intial Our Tic Tae Board is Empty***************//

    //***********For Each Row Loop*************//
    for (int i=0; i<SIDE; i++)
    {
    	//*********For Each Row Column Loop (Means Cell)*****//
        for (int j=0; j<SIDE; j++)
        {
            //=====Intial There is No Any Run So it is Blank===//
            board[i][j] = ' ';

        }

    }
     
    //====With Our Chance=============
    for (int i=0; i<SIDE*SIDE; i++)
        moves[i] = i;
 
    //****Randomize The Data************//
    std::random_shuffle(moves, moves + SIDE*SIDE);
    return;
}


void declareWinner(int whoseTurn)
{
    if (whoseTurn == CPU)
        printf("COMPUTER has won\n");
    else
        printf("HUMAN has won\n");
    return;
}

bool rowCrossed(char board[][SIDE])
{
	//*********Checking Our Board Data That MAtch any Row in 3 units*****
    for (int i=0; i<SIDE; i++)
    {
        if (board[i][0] == board[i][1] &&
            board[i][1] == board[i][2] && 
            board[i][0] != ' ')

            //=======if match return true=========
            return (true);
    }

    //=============else false=========
    return(false);
}

bool columnCrossed(char board[][SIDE])
{
		//*********Checking Our Board Data That MAtch any Columns in 3 units*****
    for (int i=0; i<SIDE; i++)
    {
    	//===same as above but this time m running loop after static values===
        if (board[0][i] == board[1][i] &&
            board[1][i] == board[2][i] && 
            board[0][i] != ' ')
            return (true);
    }
    return(false);
}

bool diagonalCrossed(char board[][SIDE])
{
			//*********Checking Our Board Data That MAtch any Diagonal from right in 3 units*****
    if (board[0][0] == board[1][1] &&
        board[1][1] == board[2][2] && 
        board[0][0] != ' ')
        return(true);
         
         	//*********Checking Our Board Data That MAtch any Diagonal from Left in 3 units*****

    if (board[0][2] == board[1][1] &&
        board[1][1] == board[2][0] &&
         board[0][2] != ' ')
        return(true);
 
    return(false);
}

bool gameOver(char board[][SIDE])
{
	//==========Return if Diagonal or Column or row any match result==========
    return(rowCrossed(board) || columnCrossed(board)
            || diagonalCrossed(board) );
}

void StartGame(int whoseTurn)
{
    //=======initialize board with 3*3============ 
    char board[SIDE][SIDE];
     
     //======Intialize Moves Lenght 3*3=9 Total 9 Turn will available==== 
    int moves[SIDE*SIDE];
     
    //========Start Game============
    IntitialIzeGame(board, moves);
     
    //====== Display Instruction Before Start our Game================
    showGameInstruction();
     
    int moveIndex = 0, x, y;
     
    //=======Keep RUnning Our Till Our Game Not End===================
    while (gameOver(board) == false &&  moveIndex != SIDE*SIDE)
    {
        if (whoseTurn == CPU)
        {
            x = moves[moveIndex] / SIDE;
            y = moves[moveIndex] % SIDE;
            board[x][y] = CPUMOVE;
            printf("COMPUTER has put a %c in cell %d\n",
                    CPUMOVE, moves[moveIndex]+1);
            ShowTicTacToeBoard(board);
            moveIndex ++;
            whoseTurn = PLAYER;
        }
         
        else if (whoseTurn == PLAYER)
        {
            x = moves[moveIndex] / SIDE;
            y = moves[moveIndex] % SIDE;
            board[x][y] = PLAYERMOVE;
            printf ("HUMAN has put a %c in cell %d\n",
                    PLAYERMOVE, moves[moveIndex]+1);
            ShowTicTacToeBoard(board);
            moveIndex ++;
            whoseTurn = CPU;
        }
    }
 
    // If the game has drawn
    if (gameOver(board) == false && 
            moveIndex == SIDE * SIDE)
        printf("It's a draw\n");
    else
    {
        // Toggling the user to declare the actual
        // winner
        if (whoseTurn == CPU)
            whoseTurn = PLAYER;
        else if (whoseTurn == PLAYER)
            whoseTurn = CPU;
         
        // Declare the winner
        declareWinner(whoseTurn);
    }
    return;
}
int main(){
	StartGame(CPU);
}
