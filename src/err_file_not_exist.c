#include "../inc/pathfinder.h"

void err_file_not_exist(char *filename) {
    mx_printerr("error: file ");
    mx_printerr(filename);
    mx_printerr(" does not exist\n");
    exit(0);
}
