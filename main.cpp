/*
Student number: 2426234
Name and Surname: Muaawiyah Dadabhay    
Date: 15/05/22
Project Title: Gomoku Game

File Description: Main CPP File of the ELEN2020 2022 Project
*/

#include <iostream>
#include <fstream> // header that allows you to read/write data to text files
#include <vector> // header for the use of vectors
#include <stdlib.h> // header which contains a function that allows us to generate random numbers 
#include <time.h> // we will use the system time as a seed for the random number
#include "gomoku.h" // user defined class header file
#include "gomoku.cpp" // access to the header files functions

using namespace std;

// Main Program
int main()
{
    // (Begin) Program Variables:
    ifstream        input; // input text file
    ofstream        output; // output text file
    int             input_line, current_row, current_col , current_size, current_winner, current_turn , player1_win_count, player2_win_count, draw_count; // integer variables
    int             board[15][15]; // array that stores current game boards
    bool            game_complete , player1_win , player2_win , game_draw; // boolean variables
    vector<int>     board_sizes; // vector that stores the sizes of each games board
    Gomoku          gomoku; // making use of the defined 'Gomoku' class
    
    // (Input) File Handling
    input.open("input.txt");
    output.open("gomokuResults.txt");

    if (!input) // (Validation) Test input files existence 
    {
        cout << "Unable to open the file \"input.txt\"" << endl;
        return 1;
    }

    // (Input) Receive game board size from the input text file

    while (input >> input_line)
    {
        board_sizes.push_back(input_line); // stores board sizes into a vector
    }

    // (Process) Loop through each game
    player1_win_count = 0;
    player2_win_count = 0;
    draw_count = 0; 

    srand(time(NULL)); // uses the current time as a seed for the generation of random numbers

    for (size_t i = 0; i < board_sizes.size(); i++) // loops through the amount of games
    {   
        current_size = board_sizes[i];

        // Set up game board
        gomoku.setBoardSize(current_size);
        gomoku.createBoard(board,output);
        game_complete = false;
        current_turn = 1;
        player1_win = false;
        player2_win = false;
        game_draw = false;
        
        // Play the game
        while (game_complete == false)
        {
                // Play Player 1 or 2
                switch (current_turn)
                {
                case 1:
                    {
                        gomoku.playPlayer1(board,output);
                    }   
                    break;
                case 2:
                    {
                        gomoku.playPlayer2(board,output);
                    }   
                    break;
                            
                default:
                    break;
                }

                // Check for winner 
                for (int j = 0; j < current_size; j++) // loops through the rows of the 2D array
                {
                    for (int k = 0; k < current_size; k++) // loops through the columns of the 2D array
                        {
                        if (gomoku.determineWinner(board,j,k,current_turn) == true)
                            {
                                if (current_turn == 1)
                                {
                                    player1_win = true; 
                                }
                                else if (current_turn == 2)
                                {
                                    player2_win = true;
                                }
                                game_complete = true; // game over 
                                break; // exist loop since the game is complete
                            } else if (gomoku.fullBoard(board) == true) {
                                game_draw = true;
                                game_complete = true; // game over 
                                break; // exist loop since the game is complete
                            } 
                        }    
                }
                
                // (Output)
                if (player1_win == true)
                {
                    output << "win=alg1" << endl; // desired output according to project brief
                    player1_win_count++; // increases the number of times player 1 won
                }
                else if (player2_win == true)
                {
                    output << "win=alg2" << endl; // desired output according to project brief
                    player2_win_count++; // increases the number of times player 2 won
                }
                else if (game_draw == true)
                {
                    output << "win=none" << endl;
                    draw_count++; // increases the number of draws
                }

                current_turn = 3 - current_turn; 
        }

        // (Output)
        output << endl;
        // gomoku.printBoard(board); // uncomment this line if you want to print the board to console
        // cout << endl;
    }

    // (Output) Return total wins
    output << "wins alg1=" << player1_win_count << endl; // desired output according to project brief
    output << "wins alg2=" << player2_win_count << endl; // desired output according to project brief
    output << "wins draw=" << draw_count << endl; 

    // (End) Close files and return 0
    input.close();
    output.close();
    return 0;
}