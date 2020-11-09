#include "../inc/pathfinder.h"

static void check_island12(char *island1, char *island2, char *dis, int nline) {
    if (mx_strcmp(island1,island2) == 0 && mx_atoi(dis) != 0) {
        nline++;
        err_invalid_line(nline);
    }
}

static void linearr(char *line, char **island1, char **island2, char **dis) {
    int i = 0;
    char *str = line;
    
    while(str[i] != '-') {
        i++;
    }
    *island1 = mx_strndup(str, i);
    str += i + 1;
    i = 0;
    while(str[i] != ',') {
        i++;
    }
    *island2 = mx_strndup(str, i);
    str += i + 1;
    i = 0;
    while(str[i] != '\0') {
        i++;
    }
    *dis = mx_strndup(str, i);
}

static void fill_islands(char ***arrarr, char **lines, int line) {
    char **arr = *arrarr;
    char *island1 = NULL;
    char *island2 = NULL;
    char *dist = NULL;


    int arr_indicator = 0;
    while(lines[line]) {
        linearr(lines[line], &island1, &island2, &dist);
        check_island12(island1, island2, dist, line);

        //write first island
        arr[arr_indicator++] = mx_strdup(island1);
        mx_strdel(&island1);

        //write second island
        arr[arr_indicator++] = mx_strdup(island2);
        mx_strdel(&island2);

        //write distance
        arr[arr_indicator++] = mx_strdup(dist);
        mx_strdel(&dist);

        //check for dublicate bridges
        for (int i = 0; i < arr_indicator - 3; i += 3) {
            if (mx_strcmp(arr[arr_indicator - 3], arr[i]) == 0 && 
                    mx_strcmp(arr[arr_indicator - 2], arr[i + 1]) == 0) {
                err_dublicate_bridges();
            }
            if (mx_strcmp(arr[arr_indicator - 2], arr[i]) == 0 && 
                    mx_strcmp(arr[arr_indicator - 3], arr[i + 1]) == 0) {
                err_dublicate_bridges();
            }
        }
        
        line++;
    }
}


void create_arr(char **lines, char ***arrarr) {
    int line = 1;

    while (lines[line]) {
        line++;
    }
    *arrarr = (char **)malloc((line * 3 + 1) * sizeof(char *));
    fill_islands(&(*arrarr), lines, 1);
}
