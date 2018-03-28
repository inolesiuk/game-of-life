#include <iostream>
#include <vector>

typedef std::vector <std::vector<int>> Matrix;

#ifndef UNITTEST_TEST_H
#define UNITTEST_TEST_H

class Test
{
    void bornCell(Matrix const &, int, int);
    void aliveCell(Matrix const &, int, int);
    void dieCell(Matrix const &, int , int , int);
    int countNeighbours(Matrix const &, int, int);
public:
    void gridValidity(Matrix const &, Matrix const &);
    void isBorn(Matrix const &, Matrix const &);
    void isAlive(Matrix const &, Matrix const &);
    void isDying(Matrix const &, Matrix const &);
};

#endif //UNITTEST_TEST_H
