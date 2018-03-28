#include "Test.h"

void Test::gridValidity(Matrix const & rightGrid, Matrix const & testGrid)
{
    for (int i = 0; i < testGrid.size(); ++i)
    {
        for (int j = 0; j < testGrid[0].size(); ++j)
        {
            try
            {
                if (testGrid[i][j] != 0 && testGrid[i][j] != 1) throw 1;
                if (rightGrid[i][j] != 0 && rightGrid[i][j] != 1) throw 2;
                std::cout << "Both elements of grids element [" << i << "][" << j << "] are valid" << std::endl;
            }
            catch(int m)
            {
                switch (m)
                {
                    case 1:
                        std::cout << "The test grid is not valid. The cell value of test grid is" << testGrid[i][j] << std::endl;
                        break;
                    case 2:
                        std::cout << "The previous grid is not valid. The cell value of previous grid is" << rightGrid[i][j] << std::endl;
                        break;
                }

            }
        }
    }
    try
    {
        if (rightGrid.size() != testGrid.size()) throw 1;
        if (rightGrid[0].size() != rightGrid[0].size()) throw 2;
        std::cout<<"Both parameters of grids are valid" << std::endl;
    }
    catch(int i)
    {
        switch (i)
        {
            case 1:
                std::cout << "The height of right grid differs from height of test grid" << std::endl;
                break;
            case 2:
                std::cout << "The width of right grid differs from width of test grid" << std::endl;
                break;
        }
    }

}

void Test::isBorn(Matrix const & rightGrid, Matrix const & testGrid)
{
    std::cout<<"Cells that should born"<<std::endl;
    for (int i = 0; i < rightGrid.size(); ++i)
    {
        for (int j = 0; j < rightGrid[0].size(); ++j)
            if (rightGrid[i][j] == 0 && countNeighbours(rightGrid, j, i) == 3)  bornCell(testGrid, j , i);
    }
}

void Test::isAlive (Matrix const & rightGrid, Matrix const & testGrid)
{
    std::cout<<"Cells that should stay alive"<<std::endl;
    for (int i = 0; i < rightGrid.size(); ++i)
    {
        for (int j = 0; j < rightGrid[0].size(); ++j)
            if (rightGrid[i][j] == 1 && (countNeighbours(rightGrid, j, i) == 3 || countNeighbours(rightGrid, j, i) == 2))  aliveCell(testGrid, j , i);

    }
}

void Test::isDying (Matrix const & rightGrid, Matrix const & testGrid)
{
    std::cout<<"Cells that should die"<<std::endl;
    for (int i = 0; i < rightGrid.size(); ++i)
    {
        for (int j = 0; j < rightGrid[0].size(); ++j)
            if (rightGrid[i][j] == 1 && (countNeighbours(rightGrid, j, i) > 3 || countNeighbours(rightGrid, j, i) < 2))  dieCell(testGrid, j , i, countNeighbours(rightGrid,j, i));

    }
}


int Test::countNeighbours(Matrix const & grid, int x, int y)
{
    int counter = 0;
    if (x >= 0 && y >= 0 && x < grid [0].size() && y < grid.size()) {
        for (int i = y - 1; i <= y + 1; ++i)
            for (int j = x - 1; j <= x + 1; ++j) {
                if (i != y or j != x)
                {
                    counter += grid[(grid.size() + i) % grid.size()][(grid[0].size() + j) % grid[0].size()];
                }
            }
    }
    return counter;
}

void Test::bornCell(Matrix const & grid, int x, int y)
{
    try
    {
        if (grid [y][x] == 0) throw 1;
        std::cout << "Cell ["<<y<<"]["<<x<<"]"<<"state is right" << std::endl;
    }
    catch(int i)
    {
        std::cout << "Cell state isn't rigth. Grid[" << y << "]" << "[" << x << "]" <<"should have being born" << std::endl;
    }
}
void Test::aliveCell(Matrix const & grid, int x, int y)
{
    try
    {
        if (grid [y][x] == 0) throw 1;
        std::cout << "Cell ["<<y<<"]"<<"["<<x<<"] state is right" << std::endl;
    }
    catch(int i)
    {
        std::cout << "Cell state isn't rigth. Cell[" << y << "]" << "[" << x << "]" <<"should stay alive" << std::endl;
    }
}

void Test::dieCell(Matrix const & grid, int x, int y, int z)
{
    try
    {
        if (grid [y][x] != 0) throw 1;
        std::cout << "Cell state ["<<y<<"]"<<"["<<x<<"] is right" << std::endl;
        if (z > 3) throw 2;
        if (z < 2) throw 3;
    }
    catch(int i)
    {
        switch(i)
        {
            case 1:
            std::cout << "Cell state isn't right.Cell[" << y << "]" << "[" << x << "]" << "should die";
                break;
            case 2:
            std::cout << "Cell died alone" << std::endl;
                break;
            case 3:
            std::cout<<"Cell died because of overpopulation" << std::endl;

        }
    }
}