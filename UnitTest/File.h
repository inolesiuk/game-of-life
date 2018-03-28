#include <iostream>
#include <vector>

typedef std::vector <std::vector <int>> Grid;

#ifndef UNITTEST_FILE_H
#define UNITTEST_FILE_H

class File
{
    Grid rightGrid_;
    Grid testGrid_;
    void readGrid(const char*  filename, Grid &);
public:
    File();
    const Grid& getRightGrid() const;
    const Grid& getTestGrid() const;
    void showGrid();
};

#endif //UNITTEST_FILE_H
