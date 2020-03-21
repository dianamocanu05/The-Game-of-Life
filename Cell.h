#pragma once
class Cell{
private:
    bool state; //0:dead, 1:live
    int color;
    int x,y;
    const int measure=10;
public:
    Cell(bool, int, int, int);
    ~Cell()=default;
    void DrawCell();


};
