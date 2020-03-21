#include "Cell.h"
#include <winbgim.h>
#include <graphics.h>


Cell::Cell(bool otherState, int otherColor, int otherX, int otherY)
{
    state=otherState;
    color=otherColor;
    x=otherX;
    y=otherY;
}

void Cell::DrawCell()
{
    setfillstyle(SOLID_FILL,color);
    bar(x,y,x+measure,y+measure);
}
