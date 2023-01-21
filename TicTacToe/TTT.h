#if !defined(GAME_H)
#define GAME_H
/// @file Game.cpp
/// @brief Header file for Game class
/// @Alexandra Fomina fomina@chapman.edu
/// CPSC 298-6 Colloquium: Programming in C++

// #include <tuple>    // defines std::tuple, std::tie
#include <iostream> // defines std::cout
#include <tuple>    // defines std::tuple, std::tie
#include <cmath>    // defines std::abs
#include <random>   // defines random number generation functions
#include <ctime>    // defines time()
#include <cstdlib>
#include <ctime>

class Game
{
    static const int RowsDefault = 3;    
    static const int ColumnsDefault = 3; 
    
    public:
        void play();

    private:
        void displayGrid();
        bool GameOver();
        bool checkWin(char c);
        void initializeGrid();
        bool checkColumn(int row, char c);
        bool checkDiagonal(bool left, char c);
        bool checkRow(int row, char c);
        bool checkTie();
        bool openSquareTrue(int inputRow, int inputColumn);

        char** Grid;

};


#endif // !defined(GAME_H)