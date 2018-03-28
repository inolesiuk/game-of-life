#include <windows.h>

#include <mutex>
#include <thread>

#include "Multithreads.h"
#include "Grid.h"

std::mutex m;

void threadFunc(Grid & grid, Array & fgrid, int start, int end)
/* Run the function in thread.
 *
 * Params:
 *  grid: Game of life grid.
 *  fgrid: The grid of next epoch.
 *  start: Thread function's starting point.
 *  end: Thread function's ending point.
 *
 */
{
    m.lock();
    grid.newGeneration(start, end, fgrid);
    m.unlock();
}

Multithreads::Multithreads()
{
    num = 1;
}

void clearScreen()
/* Clear the screen. */
{
    HANDLE handle;
    COORD Position;

    handle = GetStdHandle(STD_OUTPUT_HANDLE);

    Position.X = 0;
    Position.Y = 0;
    SetConsoleCursorPosition(handle, Position);
}


void Multithreads::run(Grid & grid)
/* Game of life iteration. */
{
    Sleep(200);
    clearScreen();
    grid.showGrid();
    num = grid.getHeight();
    int division  = grid.getGrid().size() / num;
    std::thread array [num];
    int counter = 0;
    Array fgrid(grid.getGrid());
    for (int i = 0; i < grid.getGrid().size(); i += division)
    {
        array[counter] = std::thread(threadFunc,std::ref(grid),std::ref(fgrid), i, i + division);
        ++counter;
    }
    for (int i = 0;  i < num; ++i)
    {
        array[i].join();
    }
    grid.setGrid(fgrid);
}
