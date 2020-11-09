#include "../inc/pathfinder.h"

static void crfill(char **set, char **arrarr, int ***matrix, t_int *in) {
    int **mat = *matrix;
    int k = 0;
    int i = in->size;
    int j = in->root;

    if (mx_isdigit(arrarr[j + 1][0])) {
        while (mx_strcmp(set[k], arrarr[j - 1]) != 0)
            k++;
        if (!mat[i][k] || mat[i][k] > mx_atoi(arrarr[j + 1]))
            mat[i][k] = mx_atoi(arrarr[j + 1]);
    } 
    else {
        while (mx_strcmp(set[k], arrarr[j + 1]) != 0)
            k++;
        if (!mat[i][k] || mat[i][k] > mx_atoi(arrarr[j + 2]))
            mat[i][k] = mx_atoi(arrarr[j + 2]);
    }
}

static void mx_mat(char **set, char **arrarr, int ***matrix) {
    t_int *i = malloc(sizeof(t_int));
    
    i->size = 0;
    while (set[i->size]) {
        i->root = 0;
        while (arrarr[i->root]) {
            if (mx_strcmp(set[i->size], arrarr[i->root]) == 0) {
                crfill(set, arrarr, &(*matrix), i);
            }
            i->root += 1;
        }
        i->size += 1;
    }
    free(i);
    i = NULL;
}

int **create_matrix(char **set, char ***arrarr) {
    int **matrix = NULL;
    int i = 0;
    int k = 0;

    while (set[i]) 
        i++;
    k = i;
    matrix = malloc(sizeof(int*) * i);
    while (k >= 0) {
        matrix[k] = malloc(sizeof(int) * i);
        k--;
    }
    mx_mat(set, *arrarr, &matrix);
    return matrix;
}
