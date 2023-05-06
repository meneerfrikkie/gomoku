/*
Student number: 2426234
Name and Surname: Muaawiyah Dadabhay    
Date: 15/05/22
Project Title: Gomoku Game

File Description: Class header file containing functions declaration 
that would control the overall operation and 
set-up of the Gomoku game.
*/

#ifndef Gomoku_H
#define Gomoku_H

using namespace std;

class Gomoku{
    
    private:
     int board_size; 
     int player1_loop;
     int player2_loop;
     int temp_row , temp_col ;

    public:
     void setBoardSize(int size);
     void createBoard(int game_board[][15], ofstream & output);
     void placePiece(int game_board[][15], int player, int row , int col);
     void printBoard(int game_board[][15]);
     void playPlayer1(int game_board[][15], ofstream & output);
     void playPlayer2(int game_board[][15], ofstream & output);
     int  generateRandomNumber();
     bool determineWinner(int game_board[][15], int row , int col , int player);
     bool emptyPlacement(int game_board[][15], int row , int col);
     bool fullBoard(int game_board[][15]);
     bool checkHorizontalFiveRight(int game_board[][15], int row , int col, int player);
     bool checkHorizontalFiveLeft(int game_board[][15], int row , int col, int player);
     bool checkVerticalFiveUp(int game_board[][15], int row , int col, int player);
     bool checkVerticalFiveDown(int game_board[][15], int row , int col, int player);
     bool checkDiagonalRightUp(int game_board[][15], int row , int col, int player);
     bool checkDiagonalRightDown(int game_board[][15], int row , int col, int player);
     bool checkDiagonalLeftUp(int game_board[][15], int row , int col, int player);
     bool checkDiagonalLeftDown(int game_board[][15], int row , int col, int player);
     

};

#endif
