  #include "../inc/pathfinder.h"

static void print_invalid(int nline) 
{
    nline++;
    err_invalid_line(nline);
}

static void checkline(char **lines, int nline) 
{
    int i = 0;
    int copy_i = 0;

    for (int n = 1; n <= nline; n++) {
        i = 0;
        copy_i = 0;

        while (mx_isalpha(lines[n][i])) 
            i++;
        if (i == 0 || lines[n][i] != '-')
            print_invalid(n);
        i++;

        copy_i = i;
        while (mx_isalpha(lines[n][copy_i])) 
            copy_i++;
        if (copy_i - i == 0 || lines[n][copy_i] != ',')
            print_invalid(n);
        copy_i++;
        i = copy_i;

        while (mx_isdigit(lines[n][copy_i])) copy_i++;
        if (copy_i - i == 0 || lines[n][copy_i] != '\0') print_invalid(n);
    }
}

static void parserr(char *file) 
{
    char **lines = mx_strsplit(file, '\n');
    int nline = 0;
    int at = 0;
    
    while (lines[nline]) 
        nline++;
    if (lines[0][0] == '0') {
        err_invalid_number_of_islands();
    }
    while (lines[0][at]) 
    {
        if (!mx_isdigit(lines[0][at])) {
            err_first_line_invalid();
        }
        at++;
    }
    checkline(lines, nline - 1);
    check_spaces(lines, file);
    mx_del_strarr(&lines);
}

void test_err(int argc, char *file, char **argv) 
{
    if (argc != 2) {
        err_invalid_args();
    }
    if (!file) {
        err_file_not_exist(argv[1]);
    }
    if (mx_strlen(file) == 0) {
        err_file_empty(argv[1]);
    }
    parserr(file);
}
