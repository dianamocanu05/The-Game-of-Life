#include "UtilitaryFun.h"
#include "Cell.h"
#include <iostream>
#define HEIGHT 700
#define WIDTH 700
#define GOLD 70


void Live()
{
    //DrawGrid();
    DrawMatrix(matrix);
    MatrixRules(matrix);
    //Sleep(100);
    Sleep(100);
    /*for(int i=0;i<GOLD;i++)
        {for(int j=0;j<GOLD;j++)
            std::cout<<matrix[i][j];
        std::cout<<std::endl;}*/

}


int main()
{
    for(int i=0;i<GOLD;i++)
        for(int j=0;j<GOLD;j++)
    {
        matrix[i][j]=-1;
    }
    ConfigureScreen(WIDTH, HEIGHT);
    while(1)
        Live();
    getch();

    return 0;
}
