#include <iostream>
#include "TTT.h"
using namespace std;

// Game::Game()
// {
//     initializeGrid();
// }

void Game::initializeGrid()
{
    Grid = new char*[RowsDefault];
    for (int currRow = 0;  currRow < RowsDefault ; currRow++) 
    {
        Grid[currRow] = new char[ColumnsDefault];
        for (int currColumn = 0; currColumn < ColumnsDefault; currColumn++)
        {
            Grid[currRow][currColumn] = '~';
        }
    }
}

void Game::displayGrid()
{
    for (int currRow = 0;  currRow < RowsDefault ; currRow++) 
    {
        for (int currColumn = 0; currColumn < ColumnsDefault; currColumn++)
        {
            cout << Grid[currRow][currColumn] << " ";
        }
        cout << endl;
    }

}

bool Game::GameOver()
{
    return (checkWin('X') || checkWin('O') || checkTie());
}

bool Game::checkWin(char c) {
    int total = 0;
    for(int i = 0; i < RowsDefault; i++) {
        total += checkRow(i, c);
    }
    for(int j = 0; j < ColumnsDefault; j++) {
        total += checkColumn(j, c);
    }
    total += checkDiagonal(true, c);
    total += checkDiagonal(false, c);

    return total;
}

bool Game::checkRow(int i, char c) {
    return Grid[i][0] == c && Grid[i][1] == c && Grid[i][2] == c;
}

bool Game::checkColumn(int i, char c) {
    return Grid[0][i] == c && Grid[1][i] == c && Grid[2][i] == c;
}

bool Game::checkDiagonal(bool left, char c) {
    if(left) {
        return Grid[0][0] == c && Grid[1][1] == c && Grid[2][2] == c;
    } else {
        return Grid[0][2] == c && Grid[1][1] == c && Grid[2][0] == c;
    }
}
bool Game::checkTie(){
    int openSquares = 0;
    for (int currRow = 0;  currRow < RowsDefault ; currRow++) {
        for (int currColumn = 0; currColumn < ColumnsDefault; currColumn++)
        {
            if (Grid[currRow][currColumn] == '~'){
                openSquares += 1;
            }
        }
    }
    if (openSquares == 0){
        cout << "There was a tie!" << endl;
        return true;
    }
    else{
        return false;
    }
}

bool Game::openSquareTrue(int inputRow, int inputColumn){
    if (Grid[inputRow][inputColumn] == '~'){
        return true;
    }
}

void Game::play()
{
    initializeGrid();
    displayGrid();
    while (!GameOver())
    {
        char temp;
        int inputRow;
        int inputColumn;
        cout << "Please enter the grid row number" << endl;
        cin >> temp;
        inputRow = temp - '0';
        while (inputRow < 0 || inputRow > 2){
            cout << "Please re-enter the grid row number. You can enter 0, 1 or 2"<< endl;
            cin >> temp;
            inputRow = temp - '0';
        }
        cout << "Please enter the grid column number" << endl;
        cin >> temp;
        inputColumn = temp - '0';
        while (inputColumn < 0 || inputColumn > 2) {
            cout << "Please re-enter the grid column number. You can enter 0, 1 or 2"<< endl;
            cin >> temp;
            inputColumn = temp - '0';
        }
        //check if the square they chose is open
        while (!openSquareTrue(inputRow, inputColumn)){
            cout << "That square is already taken. Please choose an open square" << endl;
            cout << "Please enter a grid row number" << endl;
            cin >> temp;
            inputRow = temp - '0';
            while (inputRow < 0 || inputRow > 2){
                cout << "Please re-enter the grid row number. You can enter 0, 1 or 2"<< endl;
                cin >> temp;
                inputRow = temp - '0';
            }
            cout << "Please enter the grid column number" << endl;
            cin >> temp;
            inputColumn = temp - '0';
            while (inputColumn < 0 || inputColumn > 2) {
                cout << "Please re-enter the grid column number. You can enter 0, 1 or 2"<< endl;
                cin >> temp;
                inputColumn = temp - '0';
            }
        }
        Grid[inputRow][inputColumn] = 'X';
        cout << endl;
        displayGrid();

        if(checkWin('X')) {
            cout << "WINNER: X" << endl;
            break;
        } 

        if (checkTie()){
            break;
        }
        //check for game over, then move to Ai turn
        cout << endl;
        cout << "Computer's Turn" << endl;
        // Check how many squares are open, save that number
        // choose a random number 0 - openSquares
        // cycle through the open squares until you reach openSquares that equals to generated number
        //now the AI turn plays;
        for (int currRow = 0;  currRow < RowsDefault ; currRow++) {
            for (int currColumn = 0; currColumn < ColumnsDefault; currColumn++)
            {
                if (Grid[currRow][currColumn] == '~'){
                    Grid[currRow][currColumn] = 'O';
                    goto break_me_here;
                }
            }
        }
        break_me_here:
        cout << endl;

        displayGrid();
        //check for game over, then move to next round
        if(checkWin('O')) {
            cout << "WINNER: O" << endl;
        }

        if (checkTie()){
            break;
        }
    }
    cout << "GAME OVER. ";
}
