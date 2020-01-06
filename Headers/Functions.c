//
// Created by noam guy on 11/09/2019.
//
#include <stdio.h>
#include "Functions.h"

void Fill_Safety_Wall(char mat[][MAT+2])  //fills the wall with 'wall'
{
    int i, j;

    for(i = 0; i < MAT + 2; i++){
        for(j = 0; j < MAT + 2 ; j++){
            if(i == 0 || j == 0) mat[i][j] = WALL;
            else if(i == MAT+1 || j == MAT+1) mat[i][j] = WALL;
            else mat[i][j] = EMPTY;

        }
    }
}

void Print_Mat_Row(char mat[][MAT+2], int row)  // Gets matrix and a row and prints all of the columns in the row
{
    int i;

    for (i = 0; i < MAT + 2; i++)
    {
        printf("%c ", mat[row][i]);
    }

}

void Print_Game_Board(char mat[][MAT+2]) // Gets matrix (and its length) and prints all of it
{
    int i;

    for(i = 0; i < MAT + 2; i++)
    {
        Print_Mat_Row(mat, i);
        printf("\n");
    }
}

void Insert_Wall(char mat[][MAT+2], int row, int col)
{
    mat[row][col] = WALL;
}

int Fill_Empty_Slots_With_Points(char mat[][MAT+2]){
    int i, j, count = 0;

    for(i = 0; i < MAT + 2; i++){
        for(j = 0; j < MAT + 2 ; j++){
            if(mat[i][j] == EMPTY){
                mat[i][j] = POINT;
                count++;
            }
        }
    }
    return count;
}

void Update_Board(char mat[][MAT+2], Buli buli, Cop cop)
{
    mat[buli.row][buli.col] = BOLI;
    mat[cop.row][cop.col] = COP;

}

int Start_Placement(char mat[][MAT+2], Buli *buli, Cop *cop, int bulirow, int coprow, int bulicol, int copcol){

    if (mat[bulirow][bulicol] == WALL || mat[copcol][coprow] == WALL) return 0;
    else
    {
        buli->row = bulirow;
        buli->col = bulicol;
        cop->row = coprow;
        cop->col = copcol;
        return 1;
    }

}

int Move(char mat[][MAT+2], Buli *buli, Cop *cop, decision dec, int points) {

    switch (dec) {

        case Right:
            if (mat[buli->row][buli->col + 1] == WALL) return points;
            else {
                mat[buli->row][buli->col] = EMPTY;
                if (mat[buli->row][buli->col + 1] == POINT) {
                    points--;
                }
                buli->col++;
            }
            return points;


        case Left:
            if (mat[buli->row][buli->col - 1] == WALL) return points;
            else {
                mat[buli->row][buli->col] = EMPTY;
                if (mat[buli->row][buli->col - 1] == POINT) {
                    points--;
                }
                buli->col--;
            }
            return points;


        case Up:
            if (mat[buli->row - 1][buli->col] == WALL) return points;
            else {
                mat[buli->row][buli->col] = EMPTY;
                if (mat[buli->row - 1][buli->col] == POINT) {
                    points--;
                }
                buli->row--;
            }
            return points;


        case Down:
            if (mat[buli->row + 1][buli->col] == WALL) return points;
            else {
                mat[buli->row][buli->col] = EMPTY;
                if (mat[buli->row + 1][buli->col] == POINT) {
                    points--;
                }
                buli->row++;
            }
            return points;


    }

}

    void Cop_Move(char mat[][MAT+2], Buli *buli, Cop *cop){
        if (buli->row > cop->row) {
            if (mat[cop->row + 1][cop->col] != WALL){
                if (cop->onpoint) mat[cop->row][cop->col] == POINT;
                else mat[cop->row][cop->col] == EMPTY;
                cop->row++;
                if (mat[cop->row][cop->col] == POINT) cop->onpoint = 1;
                else cop->onpoint = 0;
            }


        }
        else if (buli->row < cop->row) {
            if (mat[cop->row - 1][cop->col] != WALL) {
                if (cop->onpoint) mat[cop->row][cop->col] == POINT;
                else mat[cop->row][cop->col] == EMPTY;
                cop->row--;
                if (mat[cop->row][cop->col] == POINT) cop->onpoint = 1;
                else cop->onpoint = 0;
            }
        }
        if (buli->col > cop->col) {
            if (mat[cop->row][cop->col+1] != WALL){
                if (cop->onpoint) mat[cop->row][cop->col] == POINT;
                else mat[cop->row][cop->col] == EMPTY;
                cop->col++;
                if (mat[cop->row][cop->col] == POINT) cop->onpoint = 1;
                else cop->onpoint = 0;
            }
        }
        else if (buli->col < cop->col) {
            if (mat[cop->row][cop->col-1] != WALL){
                if (cop->onpoint) mat[cop->row][cop->col] == POINT;
                else mat[cop->row][cop->col] == EMPTY;
                cop->col--;
                if (mat[cop->row][cop->col] == POINT) cop->onpoint = 1;
                else cop->onpoint = 0;
            }
        }

    };



