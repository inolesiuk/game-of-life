#include <iostream>
#include <ctime>
#include <fstream>

#include <windows.h>

#include "Grid.h"

Grid::Grid()
{
    height_ = 10;
    width_ = 10;
    createGrid();
};

void setcolor(int color)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),color);
}

Grid::Grid(int width, int height)
{
    height_ = height;
    width_ = width;
    createGrid();
}

Grid::Grid(const char * filename)
{
    std::cout<<filename;
    readGrid(filename);
    width_ = grid_[0].size();
    height_ = grid_.size();
}

Grid::Grid(Grid& grid)
{
    if (this != & grid)
    {
        height_ = grid.getHeight();
        width_ = grid.getWidth();
        grid_ = grid.getGrid();
    }
}

Grid& Grid::operator = (Grid const & grid)
{
    if (this != & grid)
    {
        height_ = grid.getHeight();
        width_ = grid.getWidth();
        grid_ = grid.getGrid();
    }
    return *this;
}

void Grid::createGrid()
/* Randomly generate grid for GoL. */
{
    std::vector <int> temp;
    srand (time(0));
    for(int i = 0; i < height_; ++i)
    {
        for (int j = 0; j < width_; ++j)
            temp.push_back(rand() % 2);
        grid_.push_back(temp);
        temp.clear();
    }
}

void Grid::showGrid()
/* Print grid to console. */
{
    for (int i = 0; i < height_; ++i)
    {
        for (int j = 0; j < width_; ++j)
        {
            if (grid_[i][j] == 1) setcolor(4);
            else setcolor(7);
            std::cout << grid_[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

void Grid::readGrid(const char* filename)
/* Read grid from file. */
{
        std::ifstream fin (filename);
        std::vector <std::string> strVec;
        if (!fin.is_open())
        {
            std::cout << "Error : file is not opened " << std::endl;
        }
        std::string str;
        while (getline(fin, str))
        {
            if (str[str.length()])
            {
                str.erase(str.length()-1,str.length()-1);
            }
            strVec.push_back(str);
        }
        fin.close();
        std::vector<int> intVec;
        for(int i = 0; i < strVec.size(); i++)
        {
            for (int j = 0; j < strVec[0].size(); ++j)
            {
                if (strVec[i][j] != ' ') intVec.push_back((strVec[i][j] == '1') ? 1 : 0);
            }
            grid_.push_back(intVec);
            intVec.clear();
        }
}

void Grid::writeGrid(const char *filename) const
/* Write grid to file. */
{
    std::ofstream fout;
    fout.open(filename);
    std::string temp;
    for (int i = 0; i < height_; ++i)
    {
        for (int j = 0; j < width_; ++j)
        {
            temp += std::to_string(grid_[i][j]) + " ";
        }
        fout << temp + "\n";
        temp.clear();
    }
    fout.close();
}

int Grid::getHeight() const
{
    return height_;
}

int Grid::getWidth() const
{
    return width_;
}

Array const & Grid::getGrid() const
{
    return grid_;
}

void Grid::setGrid (const Array & grid)
{
    grid_ = grid;
    height_ = grid.size();
    width_ = grid[0].size();
}

int Grid::countNeighbours(int x, int y) const
/* Count the number of living neighbours for each cell. */
{
    int counter = 0;
    if (x >= 0 && y >= 0 && x < width_ && y < height_) {
        for (int i = y - 1; i <= y + 1; ++i)
            for (int j = x - 1; j <= x + 1; ++j) {
                if (i != y or j != x)
                {
                    counter += grid_[(height_ + i) % height_][(width_ + j) % width_];
                }
            }
    }
    return counter;
}

void Grid::newGeneration(int start, int end, Array& fgrid)
/* Evaluate new grid state. */
{
    int neighbours;
    for (int i = start; i < end; ++i)
        for (int j = 0 ; j < grid_.size(); ++j)
        {
            neighbours = countNeighbours(j, i);
            if (grid_[i][j] == 1 && (neighbours < 2 || neighbours > 3)) fgrid[i][j] = 0;
            else if (grid_[i][j] == 0 && neighbours ==3) fgrid[i][j] = 1;
        }
}

Grid::~Grid(){}