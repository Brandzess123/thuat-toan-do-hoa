#include<iostream>
#include <graphics.h>
#include <stdio.h>
#define Round(a) (int)(a+0.5)
#define DELAY 10

using namespace std;

int color = RED;

struct point        // diem gom tung do x va hoanh do y
{
    int x, y;
};
 
void lineDDA(int x1, int y1, int x2, int y2)        // DDA algorithm
{           
    int x_unit = 1, Dx = x2 - x1, Dy = y2 - y1; // Init first value
    int x = x1;
    float y = y1;
    float y_unit = 1;
     
    if (Dx < 0)          
        x_unit = -1;
    if (Dy < 0)
        y_unit = -1;
         
    if (x1 == x2)   // duong thang dung
    {
        while (y != y2)
        {
            delay(DELAY);
            y += y_unit;
            putpixel(x, Round(y), color);
        }   
    }
    else if (y1 == y2)  // duong ngang
    {
        while (x != x2)
        {
            delay(DELAY);
            x += x_unit;
            putpixel(x, Round(y), color);
        }
    }
    else if (x1 != x2 && y1 != y2)// duong xien
    {
        float m = (float) abs(Dy) / abs(Dx);
        cout<<"m la: "<<m;
        cout<<endl<<"dy: "<<abs(Dy)<<" dx: "<<abs(Dx)<<"int m la: "<<(int)m;
        x_unit = 1;
        y_unit = m;
        x = x1;
        y = y1;
         
        if (Dx < 0)          
            x_unit = -1;        // ve x giam
        if (Dy < 0)
            y_unit = -m;        // ve y giam
         
        putpixel(x, Round(y), color);
        while(x != x2)
        {
            delay(10);  // thoi gian tre khi ve 1 diem anh
            x += x_unit;
            y += y_unit;
            putpixel(x, Round(y), 1);
        }
    }
}
int main(){
    int gd,gm=VGA; gd=DETECT;
    initgraph(&gd,&gm,NULL);
    setbkcolor(2);
    
    int x = 200, y = 100;
    lineDDA(10,10,210,210);
    getchar();
    return 0;
}
