#pragma once
#include <graphics.h>
#include <winbgim.h>
#include <iostream>
#include "Cell.h"
#define HEIGHT 700
#define WIDTH 700
#define GOLD 70
#define INITIAL_CELLS 4000
int matrix[GOLD][GOLD]={-1};

void DrawMatrix(int matrix[GOLD][GOLD])
{
    for(int i=0;i<GOLD;i++)
        for(int j=0;j<GOLD;j++)
    {
        if(matrix[i][j]==1)
        {
            Cell c(1,RED,i*10,j*10);
            c.DrawCell();
        }
        else if(matrix[i][j]==0)
        {
            Cell c(0,BLACK,i*10,j*10);
            c.DrawCell();
        }
    }
}

int NumberOfNeighbours(int i, int j, int matrix[GOLD][GOLD])
{
    int ok=0;
    if(matrix[i-1][j-1]==1)
        ok++;
    if(matrix[i][j-1]==1)
        ok++;
    if(matrix[i+1][j-1]==1)
        ok++;
    if(matrix[i-1][j]==1)
        ok++;
    if(matrix[i+1][j]==1)
        ok++;
    if(matrix[i][j+1]==1)
        ok++;
    if(matrix[i+1][j+1]==1)
        ok++;
    if(matrix[i-1][j+1]==1)
        ok++;
    return ok;

}
void MatrixRules(int matrix[GOLD][GOLD])
{
    for(int i=0;i<GOLD;i++)
        for(int j=0;j<GOLD;j++)
    {
        if(matrix[i][j]==1)
        {
            matrix[i][j]=0;
            if(NumberOfNeighbours(i,j,matrix)==2 || NumberOfNeighbours(i,j,matrix)==3)
                matrix[i][j]=1;
        }
        if(matrix[i][j]==0)
        {
            if(NumberOfNeighbours(i,j,matrix)==3)
                matrix[i][j]=1;
        }
    }
}
int Random()
{
    int r=rand()%GOLD;
    return r;
}

void GenerateRandomCells()
{
    /*for(int i=0;i<10;i++)
    {
        int r1=Random();
        int r2=Random();
        std::cout<<r1<<' '<<r2<<'\n';
        Cell obj(1,r1,r2,15);
        obj.DrawCell();
    }*/
    for(int i=1;i<=INITIAL_CELLS;i++)
    {
        int r1=Random();
        int r2=Random();
        matrix[r1][r2]=1;
    }
}
void DrawGrid()
{
    for(int i=0;i<=WIDTH;i+=20)
        for(int j=0;j<=HEIGHT;j+=20)
    {
        line(i,0,i,HEIGHT);
        line(0,j,WIDTH,j);
    }
}

void ConfigureScreen(int width, int height)
{
    initwindow(width,height);
    //DrawGrid();
    GenerateRandomCells();
    //getch();
}


