#include <stdlib.h>
#include <ncurses.h>

#include "utils.h"

void clear_screen() {
    clear();
    refresh();
}

void display_message(const char *message) {
    printw("%s\n", message);
    refresh();
}

int random_int(int min, int max) {
    return rand() % (max - min + 1) + min;
}
