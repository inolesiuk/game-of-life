## C++ multi-thread implementation of Conway's Game of Life
This is console (terminal) application for windows.
To use it enter:
```
> GameOfLife [number_of_epochs] [load filepath (optional)]
```
### Please note!
MinGW was used for compiling, so you should place *.dll files from cmake-build-debug to folder with .exe file before running it.

### Test
In UnitTest folder you can find unit test for game of life which tests the validity of step.
It takes the grid from last epoch and the grid from current epoch as input and tells if the step is wrong.
