
#include <stdio.h>
void printBoard();
void system();
int checkWin() ;

char board[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
int main(void)
{
    printBoard();

    int player = 1, input, status = -1,result;
    char mark;

    while (status = -1)
    {
        player = (player%2==0) ? 2 : 1;
        mark = (player == 1) ? 'X' : 'O';
        printf("\nPlayer %d's turn :  ", player);
        scanf("%d", &input);
        if(input<=0 || input>9 ){
            printf("\nInvalid Input\n");
        }
        board[input] = mark;
        printBoard();
        player++ ;

        // to check if any one win or match is draw

        result = checkWin() ;

        if(result == 1 ){
            printf("Congratulations Player %d you won!!!\n", player);
            return 0 ;
        }
        else if(result == 0 ){
            printf("Ohh!!! Match is draw.........\n");
        }
        else{
            status = result ;
        }
    }

    return 0;
}

void printBoard()
{
    system("cls") ;
    printf("******Tik Tok Toe******\n");
    printf("   |   |   \n");
    printf(" %c | %c | %c \n", board[1], board[2], board[3]);
    printf("___|___|___\n");
    printf("   |   |   \n");
    printf(" %c | %c | %c \n", board[4], board[5], board[5]);
    printf("___|___|___\n");
    printf("   |   |   \n");
    printf(" %c | %c | %c \n", board[7], board[8], board[9]);
    printf("   |   |   \n");
}


int checkWin(){

    //wining conditions 
    if(board[1]==board[2] && board[2] == board[3]){
        return 1 ;
    }
    if(board[4]==board[5] && board[5] == board[6]){
        return 1 ;
    }
    if(board[7]==board[8] && board[8] == board[9]){
        return 1 ;
    }
    if(board[1]==board[4] && board[4] == board[7]){
        return 1 ;
    }
    if(board[2]==board[5] && board[5] == board[8]){
        return 1 ;
    }
    if(board[3]==board[6] && board[6] == board[9]){
        return 1 ;
    }
    if(board[1]==board[5] && board[5] == board[9]){
        return 1 ;
    }
    if(board[3]==board[5] && board[5] == board[7]){
        return 1 ;
    }

    // draw condition
    int count = 0 ;
    for (int i = 1; i <= 9; i++)
    {
        if(board[i]=='X' || board[i]=='O'){
            count++ ;
        }
    }
    if(count == 9){
        return 0 ;
    }
    return -1;   //return -1 neither win nor draw 
    

}