#include <iostream>
class board
{
int the_board [9];
int turns;
int curr_turn;

public:
    board();
    bool has_someone_won();
    void print_board();
    static std::string transpose_char(int a);
    void turn();
};



