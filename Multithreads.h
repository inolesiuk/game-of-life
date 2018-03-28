#include<vector>

#include "Grid.h"

#ifndef GAMEOFLIFE_MULTITHREADS_H
#define GAMEOFLIFE_MULTITHREADS_H

class Multithreads
/* Class implements the simplets multithreading. */
{
    int num;
public:
    Multithreads();
    void run(Grid &);
};

#endif //GAMEOFLIFE_THREADS_H
