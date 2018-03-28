#include <iostream>
#include "Grid.h"

#include<thread>
#include<fstream>
#include "Multithreads.h"

int main(int argc, char** argv) {
    Grid g;
    if (argc > 2 && argv[2]) {
        Grid m(argv[2]);
        g = m;
    }
    else
    {
        Grid m;
        g = m;
    }
    system("cls");

    int gen = 100;
    if (argc > 1 && argv[1]) {
        gen = std::stoi(argv[1]);
    }
    Multithreads m;
    for (int i = 0; i < gen ;++i)
    {
        if (i == 0) g.writeGrid("right.txt");
        m.run(g);
        if (i == 0) g.writeGrid("test.txt");
    }

    return 0;
}
