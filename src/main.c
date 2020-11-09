#include "../inc/pathfinder.h"

int main (int argc, char *argv[]) 
{
    int **matrix = NULL;
    char **set = NULL;
    char *file = mx_file_to_str(argv[1]);

    test_err(argc, file, argv);
    parsing(file, &matrix, &set);
    algoritm(matrix, set);
    delete_mat(&matrix, set);
    mx_strdel(&file);
    mx_del_strarr(&set);
    return 0;
}
