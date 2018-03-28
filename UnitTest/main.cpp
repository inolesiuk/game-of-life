#include <iostream>

#include "File.h"
#include "Test.h"

int main() {
    File f;
    Test t;
    t.gridValidity(f.getRightGrid(),f.getTestGrid());
    t.isAlive(f.getRightGrid(), f.getTestGrid());
    t.isBorn(f.getRightGrid(), f.getTestGrid());
    t.isDying(f.getRightGrid(), f.getTestGrid());

    return 0;
}