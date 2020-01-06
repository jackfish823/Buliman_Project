//
// Created by noam guy on 11/09/2019.
//


#include "Defenitions.h"

typedef struct Buli
{
// char symbol;
    int row;
    int col;
    int last;
} Buli;

typedef struct Cop
{
    int row;
    int col;
    int onpoint;
} Cop;

enum Decision {Same, Right, Left, Up, Down};

typedef enum Decision decision;

void Fill_Safety_Wall(char mat[][MAT+2]);

void Print_Game_Board(char mat[][MAT+2]);

void Insert_Wall(char mat[][MAT+2], int row, int col);

int Fill_Empty_Slots_With_Points(char mat[][MAT+2]);

void Update_Board(char mat[][MAT+2], Buli buli, Cop cop);

int Start_Placement(char mat[][MAT+2], Buli *buli, Cop *cop, int bulirow, int coprow, int bulicol, int copcol);

int Move(char mat[][MAT+2], Buli *buli, Cop *cop, decision dec, int points);

void Cop_Move(char mat[][MAT+2], Buli *buli, Cop *cop);



#endif
