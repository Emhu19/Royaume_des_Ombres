#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <ncurses.h>

const int START_COL = 23;
const char* BORDER = "--------------------------------------------------------------------------------------------------------------------------------------------------------------------";

void printHeader() {
    int x = 1;

    move(x, START_COL);
//     printw("%s", BORDER);

    move(x + 1, START_COL);
    printw("| ######    #####   ##  ##     ##     ##   ##  ##   ##  #######           #####    #######   #####             #####   ##   ##  ######   ######   #######   #####  |\n");

    move(x + 2, START_COL);
    printw("|  ##  ##  ##   ##  ##  ##    ####    ##   ##  ### ###   ##   #            ## ##    ##   #  ##   ##           ##   ##  ### ###   ##  ##   ##  ##   ##   #  ##   ## |\n");

    move(x + 3, START_COL);
    printw("|  ##  ##  ##   ##  ##  ##   ##  ##   ##   ##  #######   ## #              ##  ##   ## #    #                 ##   ##  #######   ##  ##   ##  ##   ## #    #       |\n");

    move(x + 4, START_COL);
    printw("|  #####   ##   ##   ####    ##  ##   ##   ##  #######   ####              ##  ##   ####     #####            ##   ##  #######   #####    #####    ####     #####  |\n");

    move(x + 5, START_COL);
    printw("|  ## ##   ##   ##    ##     ######   ##   ##  ## # ##   ## #              ##  ##   ## #         ##           ##   ##  ## # ##   ##  ##   ## ##    ## #         ## |\n");

    move(x + 6, START_COL);
    printw("|  ##  ##  ##   ##    ##     ##  ##   ##   ##  ##   ##   ##   #            ## ##    ##   #  ##   ##           ##   ##  ##   ##   ##  ##   ##  ##   ##   #  ##   ## |\n");

    move(x + 7, START_COL);
    printw("| #### ##   #####    ####    ##  ##    #####   ##   ##  #######           #####    #######   #####             #####   ##   ##  ######   #### ##  #######   #####  |\n");

    move(x + 8, START_COL);
//     printw("%s\n\n", BORDER);
}

// void box(){
//     box(0, 0);
// }

void color(){
    // Démarrer le mode couleur
    start_color();
    init_pair(1, COLOR_MAGENTA, COLOR_BLACK);  // Définir une paire de couleurs (texte rouge sur fond noir)
    init_pair(2, COLOR_BLACK, COLOR_WHITE);
    // Utiliser la couleur pour afficher un message
    attron(COLOR_PAIR(1));
}
