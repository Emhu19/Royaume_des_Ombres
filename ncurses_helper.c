#include <stdlib.h>

#include "ncurses_helper.h"
#include "graphique.h"

void init_ncurses() {
    initscr();
//     noecho();
    cbreak();
    keypad(stdscr, TRUE);  // Permet de capturer des touches spéciales comme les flèches
//     curs_set(0);  // Masque le curseur



    atexit(end_ncurses);
    color();
}

void end_ncurses() {
    endwin();
}

void reset_screen() {
    clear();
    refresh();
}

/*f
void display_centered_text(WINDOW *win, int starty, int width, const char *text) {
    int length, x, y;
    float temp;

    if (win == NULL) {
        win = stdscr;
    }

    getyx(win, y, x);
    if (starty != 0) {
        y = starty;
    }

    length = strlen(text);
    temp = (width - length) / 2;
    x = startx + (int)temp;

    mvwprintw(win, y, x, "%s", text);
    refresh();
}
*/
