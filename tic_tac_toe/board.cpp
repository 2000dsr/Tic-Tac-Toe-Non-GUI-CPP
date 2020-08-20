#include "board.h"
#include <iostream>
#include <stdlib.h>

board::board() // constructor
{
    for (int a = 0; a < 9; a++){
        the_board[a] = 0;
    }
    curr_turn = 0; // starting state
    turns = 0;

}

bool board::has_someone_won(){


    
    bool r1 = the_board[0]==the_board[1] && the_board[1]==the_board[2] && the_board[2] != 0;
    bool r2 = the_board[3] == the_board[4] && the_board[4] ==the_board[5] && the_board[5] != 0;
    bool r3 = the_board[6] == the_board[7] && the_board[7] == the_board[8] && the_board[8] != 0;

    bool c1 = the_board[0]==the_board[3] && the_board[3]==the_board[6] && the_board[6] != 0;
    bool c2 = the_board[1] == the_board[4] && the_board[4] ==the_board[7] && the_board[7] != 0;
    bool c3 = the_board[2] == the_board[5] && the_board[5] == the_board[8] && the_board[8] != 0;

    bool d1 = the_board[0]==the_board[4] && the_board[4]==the_board[8] && the_board[8] != 0;
    bool d2 = the_board[2]==the_board[4] && the_board[4]==the_board[6] && the_board[6] != 0;

    if (r1 || r2 || r3 || c1 || c2 || c3 || d1 || d2) {
        std::cout << "Game Over!" << "\n";
        print_board();
        return true;
    }

    if (turns == 9) {
        std::cout << "Game Over! Tie!" << "\n";
        return true;
    }
    
    return false;

}

void board::print_board() {
    for (int i = 0; i<9; i++){
        std::cout << transpose_char(the_board[i]);
        if (i==2 || i == 5) {
            std::cout << "\n";
            std::cout << "-----\n";
        }
        else {
            if (i != 8) {
            std::cout << "|";
            }
        }
    }
    std::cout << "\n";
}

std::string board::transpose_char(int a) {
    std::string output = " ";
    switch (a) {
        case 0:
            output = " ";
            break;
        case 1:
            output = "O";
            break;
        case 2:
            output = "X";
            break;

    }

    return output;
}


void board::turn() {
   if (curr_turn == 0) {
       std::string inputted;
       std::cout << "Who goes first? X or O?" << "\n";
       std::cin >> inputted;
        if (inputted == "X") {
            curr_turn =  2;
        }
        else if (inputted == "O") {
            curr_turn = 1;
        }
        else{
            std::cout << "X or O??" << "\n";
        }
        print_board();
   }

   if (curr_turn == 1 ) { // O's turn 
        std::cout << "O's Turn. What spot?" << "\n";
        int response;
        std::cin >> response;
        response --; // aligns it to the index
        if (response > 8 || response < 0) {
            std::cout << "Pick a spot between 1 and 9!"<< "\n";
        }
        
        else if (the_board[response] != 0) {
            std::cout << "That spot is taken. Pick a different one!" << "\n";
        }

        else {
            the_board[response] = 1;
            print_board();
            curr_turn = 2;
            turns ++;
        }

   }

   else if (curr_turn == 2 ) { // X's turn 
        std::cout << "X's Turn. What spot?" << "\n";
        int response;
        std::cin >> response;
        response --; // aligns it to the index
        if (response > 8 || response < 0) {
            std::cout << "Pick a spot between 1 and 9!"<< "\n";
        }
        
        else if (the_board[response] != 0) {
            std::cout << "That spot is taken. Pick a different one!" << "\n";
        }

        else {
            the_board[response] = 2;
            print_board();
            curr_turn = 1;
            turns ++;
        }

   }

}
