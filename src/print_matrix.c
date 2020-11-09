#include "../inc/pathfinder.h"

void print_matrix(int **matrix, char **set) {
    int i = 0; 
    int k = 0;
    int j = 0;

    while (set[i]) 
        i++;
    while (k < i) {
        j = 0;
        while (j < i) {
            mx_printint(matrix[k][j]);
            mx_printchar('\t');
            j++;
        }
        mx_printchar('\n');
        k++;
    }
}
