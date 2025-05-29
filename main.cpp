//#include <ncurses.h>
#include <curses.h>
#include <unistd.h>

static const int red = 1;
static const int green = 2;


// ------------------------------------------------------------------------------------------------
// Initialisiere NCurses
void start_ncurses() {
    initscr(); // Initialisierung von ncurses
    curs_set(false); // Keinen Cursor anzeigen
    noecho(); // Keine Eingabe in der Konsole
    nodelay(stdscr, true); // Nur Eingaben, keine Ausgaben
    keypad(stdscr, true); // Tastaturbefehle erkennen → für Pfeiltasten
    start_color(); // Farben aktivieren
    init_pair(red, COLOR_RED, COLOR_BLACK); // Farben definieren
    init_pair(green, COLOR_GREEN, COLOR_BLACK); // Farben definieren
}

// ------------------------------------------------------------------------------------------------
// Clean up ncurses
void end_ncurses() {
    endwin(); // Beenden von ncurses
}

// ------------------------------------------------------------------------------------------------
// Zeichne Rahmen
void draw_border() {
    int row = 0;
    int col = 0;

    int width = COLS;
    int height = LINES;
    attron(COLOR_PAIR(green));
    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {
            if (i == 0 || i == width - 1 || j == 0 || j == height - 1) {
                attron(A_REVERSE);
            } else {
                attroff(A_REVERSE);
            }
            mvprintw(j, i, " ");
        }
    }
}

int main() {
    // ------------------------------------------------------------------------------------------------
    start_ncurses();
    draw_border();
    int row = LINES / 2;
    int col = COLS / 2 - 20;
    int key;
    //mvprintw(row, col, "Press any key to end this impressive demo");
    attron(COLOR_PAIR(red));
    //TODO: Schreibe Code
    //TODO: Schreibe noch mehr Code
    //refresh();
    while (key != 27) {
        //attron(A_REVERSE);
        mvprintw(row, col, " ");
        //attroff(A_REVERSE);
        refresh();


        key = getch();
        if (key != ERR) {
            mvprintw(2, 2, "Key: %3d", key);
            refresh();
        }

        switch (key) {
            case KEY_UP: // Pfeil nach oben
                row--;
                break;
            case KEY_DOWN: // Pfeil nach unten
                row++;
                break;
            case KEY_LEFT: // Pfeil nach links
                col--;
                break;
            case KEY_RIGHT: // Pfeil nach rechts
                col++;
                break;
        }

        attron(A_REVERSE);
        mvprintw(row, col, " ");

        attroff(A_REVERSE);
        refresh();
        usleep(1'000);
    }

    //usleep(5'000'000);
    end_ncurses();
    return 0;
}
