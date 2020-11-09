#include "../inc/pathfinder.h"

static void print_invalid(int nline) {
    nline++;
    err_invalid_line(nline);
}

void check_spaces(char **lines, char *file) {
    char *fl = file;
    char **ln = lines;
    int i = 0;
    int len = 0;

    if (*fl == '\n')
        print_invalid(0);
    while (*fl) {
        if (*fl == '\n' && *(fl + 1) == '\n')
            while (ln[i]) {
                len = mx_strlen(ln[i]);
                if (mx_strncmp(fl - len, ln[i], mx_strlen(ln[i])) == 0)
                    print_invalid(i + 1);
                i++;
            }
        fl++;
    }
}
