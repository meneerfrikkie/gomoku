/*
Student number: 2426234
Name and Surname: Muaawiyah Dadabhay    
Date: 15/05/22
Project Title: Gomoku Game

File Description: Class file containing functions declaration 
that would control the overall operation and 
set-up of the Gomoku game.
*/

#include "gomoku.h"

using namespace std;

void Gomoku::setBoardSize(int size){
    board_size = size;
}

void Gomoku::createBoard(int game_board[][15], ofstream & output){
    // Variable Initialization
    player1_loop = 1;
    player2_loop = 2;

    // (Process)
    for (int j = 0; j < board_size; j++) // loops through the rows of the 2D array
        {
        for (int k = 0; k < board_size; k++) // loops through the columns of the 2D array
            {
            game_board[j][k] = 0; // assigns a "null" number to the board
            }    
        }
    
    // (Output)

    output << "size=" << board_size << endl;
}

void Gomoku::printBoard(int game_board[][15]){
    // (Console Output)
    for (int j = 0; j < board_size; j++) 
        {
            for (int k = 0; k < board_size; k++)
            {
                cout << game_board[j][k] << " ";
            }    
        cout << endl;
        }   
}

void Gomoku::playPlayer1(int game_board[][15], ofstream & output){
    // For Players 1 Algorithm , a loop will be run an odd amount of times generating a random number each time. On the last run of the loop, the random numbers would be stored as the row and col respectively

    // Variables
    int row , col;
    bool move_completed = false;

    player1_loop += 2;

    // (Process)
    while (move_completed == false)
    {
        for (int i = 1; i <= player1_loop; i++)
        {
            row = generateRandomNumber();
            col = generateRandomNumber();
        }
        
        if (emptyPlacement(game_board,row,col) == true){
            placePiece(game_board,1,row,col);
            temp_row = row;
            temp_col = col;
            output << "r" << row << "c" << col << " alg1" << endl;
            move_completed = true;
        }
    }        
}

void Gomoku::playPlayer2(int game_board[][15], ofstream & output){
    // For Players 1 Algorithm , a loop will be run an even amount of times generating a random number each time. On the last run of the loop, the random numbers would be stored as the row and col respectively

    // Variables
    int row , col;
    bool move_completed = false;

    player2_loop += 2;

    // (Process)
    while (move_completed == false)
    {
        for (int i = 0; i <= player2_loop; i++)
        {
            row = generateRandomNumber();
            col = generateRandomNumber();
        }
        
        if (emptyPlacement(game_board,row,col) == true){
            placePiece(game_board,2,row,col);
            temp_row = row;
            temp_col = col;
            output << "r" << row << "c" << col << " alg2" << endl;
            move_completed = true;
        }
    }        
}
    

void Gomoku::placePiece(int game_board[][15], int player, int row , int col){
    // (Process) Using the empty placement function, a piece is placed onto the according to which algorithm is playing
        switch (player)
        {
        case 1:
            game_board[row][col] = 1;
            break;
        case 2:
            game_board[row][col] = 2;
            break;
        
        default:
            break;
        }
}

int Gomoku::generateRandomNumber(){
    // Variables 
    int random_number;

    // (Process) Creating a random number which represents the pieces position on the board
    random_number = rand() % board_size;

    // Return the random number
    return random_number;
}

bool Gomoku::emptyPlacement(int game_board[][15], int row , int col){
    // Variables and Intitialization
    bool free_piece = false; 

    // (Process)
    if (game_board[row][col] == 0)  // makes use of an if statement to determine if the desired piece is empty for placement
        {
            free_piece = true;
        }
    
    return free_piece;
}

bool Gomoku::fullBoard(int game_board[][15]){
    // Variables and Initialization
    bool full_board = true; // assumes the board is full

    // (Process) A loop run through the board to test if the board is full
    for (int j = 0; j < board_size; j++) // loops through the rows of the 2D array
        {
        for (int k = 0; k < board_size; k++) // loops through the columns of the 2D array
            {
                if (game_board[j][k] == 0)
                {
                    full_board = false; // if the board contains a piece that is zero, it means there is still available space to continue playing
                }
            }    
        }

    return full_board;
}

bool Gomoku::checkHorizontalFiveRight(int game_board[][15], int row , int col, int player){
    // Variables
    bool place1 = false , place2 = false , place3 = false , place4 = false , place5 = false, is_Horizontal = false;

    // (Process) Checks 5 numbers next to each other horizontally to see if they contain the required players piece
    if ((game_board[row][col] == player) && (col + 4 < board_size)) {place1 = true;}
    if (game_board[row][col+1] == player) {place2 = true;}
    if (game_board[row][col+2] == player) {place3 = true;}
    if (game_board[row][col+3] == player) {place4 = true;}
    if (game_board[row][col+4] == player) {place5 = true;}

    if (place1 && place2 && place3 && place4 && place5) { is_Horizontal = true; }
    // if the horizontal line of pieces are 5 consecutive , return a true value

    return is_Horizontal;
}

bool Gomoku::checkHorizontalFiveLeft(int game_board[][15], int row , int col, int player){
    // Variables
    bool place1 = false , place2 = false , place3 = false , place4 = false , place5 = false, is_Horizontal = false;

    // (Process) Checks 5 numbers next to each other horizontally to see if they contain the required players piece
    if ((game_board[row][col] == player) && (col - 4 >= 0)) {place1 = true;}
    if (game_board[row][col-1] == player) {place2 = true;}
    if (game_board[row][col-2] == player) {place3 = true;}
    if (game_board[row][col-3] == player) {place4 = true;}
    if (game_board[row][col-4] == player) {place5 = true;}

    if (place1 && place2 && place3 && place4 && place5) { is_Horizontal = true; }
    // if the horizontal line of pieces are 5 consecutive , return a true value

    return is_Horizontal;
}

bool Gomoku::checkVerticalFiveUp(int game_board[][15], int row , int col, int player){
    // Variables
    bool place1 = false , place2 = false , place3 = false , place4 = false , place5 = false, is_Vertical = false;
    
    // (Process) Checks 5 numbers above one another vertically to see if they contain the required players piece
    if ((game_board[row][col] == player) && (row - 4 >= 0)) {place1 = true;}
    if (game_board[row-1][col] == player) {place2 = true;}
    if (game_board[row-2][col] == player) {place3 = true;}
    if (game_board[row-3][col] == player) {place4 = true;}
    if (game_board[row-4][col] == player) {place5 = true;}

    if (place1 && place2 && place3 && place4 && place5) { is_Vertical = true; }
    // if the vertical line of pieces are 5 consecutive , return a true value

    return is_Vertical;
}

bool Gomoku::checkVerticalFiveDown(int game_board[][15], int row , int col, int player){
    // Variables
    bool place1 = false , place2 = false , place3 = false , place4 = false , place5 = false, is_Vertical = false;
    
    // (Process) Checks 5 numbers below one another vertically to see if they contain the required players piece
    if ((game_board[row][col] == player) && (row + 4 < board_size)) {place1 = true;}
    if (game_board[row+1][col] == player) {place2 = true;}
    if (game_board[row+2][col] == player) {place3 = true;}
    if (game_board[row+3][col] == player) {place4 = true;}
    if (game_board[row+4][col] == player) {place5 = true;}

    if (place1 && place2 && place3 && place4 && place5) { is_Vertical = true; }
    // if the vertical line of pieces are 5 consecutive , return a true value

    return is_Vertical;
}

bool Gomoku::checkDiagonalRightUp(int game_board[][15], int row , int col, int player){
    // Variables
    bool place1 = false , place2 = false , place3 = false , place4 = false , place5 = false, is_Diagonal_Right = false;

    // (Process) Checks 5 numbers that are diagonal to the right
    if ((game_board[row][col] == player) && (col + 4 < board_size) && (row - 4 >= 0)) {place1 = true;}
    if (game_board[row-1][col+1] == player) {place2 = true;}
    if (game_board[row-2][col+2] == player) {place3 = true;}
    if (game_board[row-3][col+3] == player) {place4 = true;}
    if (game_board[row-4][col+4] == player) {place5 = true;}

    if (place1 && place2 && place3 && place4 && place5) { is_Diagonal_Right = true; }
    // if diagonal to the right of the pieces are 5 consecutive peieces that are equal, return a true value

    return is_Diagonal_Right;
}

bool Gomoku::checkDiagonalRightDown(int game_board[][15], int row , int col, int player){
    // Variables
    bool place1 = false , place2 = false , place3 = false , place4 = false , place5 = false, is_Diagonal_Right = false;

    // (Process) Checks 5 numbers that are diagonal to the right
    if ((game_board[row][col] == player) && (row + 4 < board_size) && (col + 4 < board_size)) {place1 = true;}
    if (game_board[row+1][col+1] == player) {place2 = true;}
    if (game_board[row+2][col+2] == player) {place3 = true;}
    if (game_board[row+3][col+3] == player) {place4 = true;}
    if (game_board[row+4][col+4] == player) {place5 = true;}

    if (place1 && place2 && place3 && place4 && place5) { is_Diagonal_Right = true; }
    // if diagonal to the right of the pieces are 5 consecutive peieces that are equal, return a true value

    return is_Diagonal_Right;
}

bool Gomoku::checkDiagonalLeftUp(int game_board[][15], int row , int col, int player){
    // Variables
    bool place1 = false , place2 = false , place3 = false , place4 = false , place5 = false, is_Diagonal_Left = false;

    // (Process) Checks 5 numbers that are diagonal to the left
    if ((game_board[row][col] == player) && (row - 4 >= 0) && (col - 4 >= 0)) {place1 = true;}
    if (game_board[row-1][col-1] == player) {place2 = true;}
    if (game_board[row-2][col-2] == player) {place3 = true;}
    if (game_board[row-3][col-3] == player) {place4 = true;}
    if (game_board[row-4][col-4] == player) {place5 = true;}

    if (place1 && place2 && place3 && place4 && place5) { is_Diagonal_Left = true; }
    // if diagonal to the left of the pieces are 5 consecutive peieces that are equal, return a true value

    return is_Diagonal_Left;
}

bool Gomoku::checkDiagonalLeftDown(int game_board[][15], int row , int col, int player){
    // Variables
    bool place1 = false , place2 = false , place3 = false , place4 = false , place5 = false, is_Diagonal_Left = false;

    // (Process) Checks 5 numbers that are diagonal to the left
    if ((game_board[row][col] == player) && (row + 4 < board_size) && (col - 4 >= 0)) {place1 = true;}
    if (game_board[row+1][col-1] == player) {place2 = true;}
    if (game_board[row+2][col-2] == player) {place3 = true;}
    if (game_board[row+3][col-3] == player) {place4 = true;}
    if (game_board[row+4][col-4] == player) {place5 = true;}

    if (place1 && place2 && place3 && place4 && place5) { is_Diagonal_Left = true; }
    // if diagonal to the left of the pieces are 5 consecutive peieces that are equal, return a true value

    return is_Diagonal_Left;
}

bool Gomoku::determineWinner(int game_board[][15], int row , int col , int player){
    bool winner = false;

    if ((checkHorizontalFiveRight(game_board, row, col, player) == true) || (checkHorizontalFiveLeft(game_board, row, col, player) == true) || (checkVerticalFiveDown(game_board, row, col, player) == true) || (checkVerticalFiveUp(game_board, row, col, player) == true) || (checkDiagonalLeftUp(game_board, row, col, player) == true) || (checkDiagonalLeftDown(game_board, row, col, player) == true) || (checkDiagonalRightUp(game_board, row, col, player)== true) || (checkDiagonalRightDown(game_board, row, col, player)== true))
    {
        winner = true;
    }

    return winner;
}
