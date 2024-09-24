#include <ncurses.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <signal.h>

#include "game.h"
#include "ncurses_helper.h"
#include "utils.h"
#include "combat.h"


int main() {


    init_ncurses();
    int yMax, xMax;
    getmaxyx(stdscr, yMax, xMax);



    int panelHeight = yMax /4;
    int panelWidth = xMax; // Largeur complète de l'écran

    // Positionner la fenêtre en bas de l'écran
    int startY = yMax - panelHeight; // Position Y en bas de l'écran
    int startX = 0; // Début à gauche de l'écran

    WINDOW *win = newwin(yMax/3, panelWidth-40, 0, 20);
    WINDOW *win2 = newwin(panelHeight, panelWidth, startY, startX);

    box(win, 0, 0);
    box(win2, 0, 0);

    wrefresh(win);
    printHeader();
    getch();
    wrefresh(win2);

//     wrefresh(win);
//     display_centered_text();
    boucle_principale();

    refresh();
    clear();

    printw("\nMerci d'avoir jouer :)\n");
    refresh();
    sleep(1);

    attroff(COLOR_PAIR(1));
    getch();

    return 0;
}
