#include <iostream>

using namespace std;

// one tick with optional label
void drawOneTick(int tickLength, int tickLabel = -1)
{
    for (int i = 0; i < tickLength; i++)
        cout << "-";
    if (tickLabel >= 0)
        cout << " " << tickLabel;
    cout << "\n";
}
void drawTicks(int tickLength)
{
// draw ticks of given length
    if (tickLength > 0)
    {
// stop when length drops to 0
        drawTicks(tickLength-1);
// recursively draw left ticks
        drawOneTick(tickLength);
// draw center tick
        drawTicks(tickLength-1);
// recursively draw right ticks
    }
}
void drawRuler(int nInches, int majorLength)  // draw the entire ruler
{
    drawOneTick(majorLength, 0);
// draw tick 0 and its label
    for (int i = 1; i <= nInches; i++)
    {
        drawTicks(majorLength-1);
// draw ticks for this inch
        drawOneTick(majorLength, i);
// draw tick i and its label
    }
}


int main()
{
    drawRuler(2, 3);
    return 0;
}
