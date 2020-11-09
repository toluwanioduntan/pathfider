#include "../inc/pathfinder.h"

void err_invalid_line(int number_of_line) {
    mx_printerr("error: line ");
    mx_printerr(mx_itoa(number_of_line));
    mx_printerr(" is not valid\n");
    exit(0);
}
