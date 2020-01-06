#include <stdio.h>
#include "Functions.h"

int main() {

    char board[MAT+2][MAT+2] = {}; // creating a board with safety wall (+1 each side)
    int wallplacement_row, wallplacement_col, points, bulirow, bulicol, coprow, copcol;
    decision dec;

    Fill_Safety_Wall(board); // filling the borders

    Print_Game_Board(board); // printing the game board

    printf("Insert wall (row col):\n");   // inserting x/y's for walls until 0/0
    scanf("%d %d",&wallplacement_row,&wallplacement_col);
    while (wallplacement_row && wallplacement_col)
    {
        Insert_Wall(board,wallplacement_row,wallplacement_col);
        scanf("%d %d",&wallplacement_row,&wallplacement_col);
    }
    Insert_Wall(board,wallplacement_row,wallplacement_col);


    Buli buli ={};
    buli.last = Down;
    Cop cop ={};
    cop.onpoint = 1;
    printf("buli starting place: ");
    scanf("%d %d",&bulirow,&bulicol);
    printf("buli starting place: ");
    scanf("%d %d",&coprow,&copcol);
    if (Start_Placement(board, &buli, &cop, bulirow, coprow, bulicol, copcol)){
        Update_Board(board, buli, cop);
        points = Fill_Empty_Slots_With_Points(board); // filling all of the empty slots with points
        Print_Game_Board(board);
    }
    else
        printf("Error");


    while (points != 0 && board[buli.row][buli.col] != board[cop.row][cop.col]){
        printf("\nEnter Movement: ");
        scanf("%d", &dec);
        if (dec == Same) dec = buli.last;
        buli.last = dec;
        points = Move(board, &buli, &cop, dec, points);
        Update_Board(board, buli, cop);
        Cop_Move(board, &buli, &cop);
        Update_Board(board, buli, cop);
        Print_Game_Board(board);
        printf("\n%d %d %d pints: %d", buli.row, buli.col, dec, points);
    }





}