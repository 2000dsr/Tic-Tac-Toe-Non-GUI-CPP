#include <iostream>
#include "board.h"

int main() {
    board me;
    while (!me.has_someone_won()) {
        me.turn();
    }
    return 0;
}

