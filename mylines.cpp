#include "mylines.h"
#include "math.h"

myLines::myLines(float _x1, float _y1, float _x2, float _y2)
{
    x1=_x1;
    x2=_x2;
    y1=_y1;
    y2=_y2;
}
myLines::myLines()
{
    x1=0;
    x2=0;
    y1=0;
    y2=0;
}



myLines myLines::getLine1()
{
    float x = (x1 + x2)/2;
    float y = (y1 + y2)/2;

    myLines l = myLines(x,y,x1,y1);
    return l;
}

myLines myLines::getLine2()
{
    float x = (x1 + x2)/2;
    float y = (y1 + y2)/2;

    myLines l = myLines(x,y,x2,y2);
    return l;
}

float myLines::getLong()
{
    float lo;
    lo = (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
    lo = sqrt(lo);
    return lo;
}

myLines myLines::getLine3()
{
    float x = (x1 + x2)/2;
    float y = (y1 + y2)/2;
    if(x1==x2)
    {
        float _x;
        _x=getLong()*0.4 + x;
        return myLines(x,y,_x,y);
    }
    if(y1==y2)
    {
        float _y;
        _y=getLong()*0.4 + y;
        return myLines(x,y,x,_y);
    }
}

myLines myLines::getLine4()
{
    float x = (x1 + x2)/2;
    float y = (y1 + y2)/2;
    if(x1==x2)
    {
        float _x;
        _x=-getLong()*0.4 + x;
        return myLines(x,y,_x,y);
    }
    if(y1==y2)
    {
        float _y;
        _y=-getLong()*0.4 + y;
        return myLines(x,y,x,_y);
    }
}


