#include <iostream>
#include <vector>

typedef std::vector <std::vector <int>> Array;

#ifndef GAMEOFLIFE_GRID_H
#define GAMEOFLIFE_GRID_H

class Grid
/* Class representing the main algorithm of the game.*/
{
    int width_;
    int height_;
    Array grid_;

    void createGrid();
    int countNeighbours(int, int) const;


public:
    Grid();
    Grid(int, int);
    explicit Grid(const char *);
    Grid(Grid &);
    Grid & operator = (Grid const &);
    ~Grid();

    int getHeight() const;
    int getWidth() const;
    Array const & getGrid() const;
    void setGrid (const Array & grid);

    void showGrid();

    void readGrid(const char*  filename = "input.txt");
    void writeGrid(const char * filename = "output.txt") const;

    void newGeneration(int, int, Array&);
};

#endif //GAMEOFLIFE_GRID_H
