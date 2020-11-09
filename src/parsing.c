#include "../inc/pathfinder.h"

void parsing(char *fd, int ***matrix, char ***set) {
    char **arrarr = NULL;
    char **src = mx_strsplit(fd, '\n');

    create_arr(src, &arrarr);
    create_set(&(*set), &arrarr, src[0]);
    *matrix = create_matrix(*set, &arrarr);
    mx_del_strarr(&src);
    mx_del_strarr(&arrarr);
}
