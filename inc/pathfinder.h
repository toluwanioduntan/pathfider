#pragma once

#include "../libmx/inc/libmx.h"

typedef struct  s_path {
    int idPath;
    int distPath;
    int index;
    struct s_path *nextConnect;
    struct s_path *nextPath;
}		        t_path;

typedef struct  s_island {
    int indexIslnd;
    int distTo;
    struct s_path *path;
    struct s_island *next;
}		        t_island;

typedef struct  s_char {
    char *p;
    char *r;
    char *d;
    int s;
}		        t_char;

typedef struct  s_int {
    int size;
    int root;
}		        t_int;

typedef struct  s_md {
    int isl1;
    int isl2;
    int mat;
}		        t_md;

typedef struct  s_li{
    t_island *un;
    t_island *v;
    t_island *cur;
    t_island *sh;
}		        t_li;

//errors
void err_dublicate_bridges();
void err_file_empty(char *filename);
void err_file_not_exist(char *filename);
void err_first_line_invalid();
void err_invalid_args();
void err_invalid_line(int number_of_line);
void err_invalid_number_of_islands();
void err_length_of_bridges_big();

//nessesary functions
void test_err(int argc, char *file, char **argv);
void parsing(char *fd, int ***matrix, char ***set);
int **create_matrix(char **set, char ***arrarr);
void print_matrix(int **matrix, char **set);
void algoritm(int **matrix, char **set);
void check_spaces(char **src, char *file);
void create_arr(char **src, char ***arrarr);
void create_set(char ***set, char ***arrarr, char *numOfIsland);
void delete_mat(int ***matrix, char **set);
t_island *shortest_distance(t_island **unvisited);
t_path *create_path(int isl, int dist);
void path_push_back(t_path **path, t_path **previous, int isl, int dist);
void add_link(t_path **cur, t_path **new);
t_path *add_path(t_path **previous, int isl, int dist);
void delete_path(t_path **head);
t_path *copy_path(t_path **data);
int unique_path(t_path **new, t_path **pre);
void join(char **res, char *s2);
void print_output(t_island **visited, int root, int size, char **set);
void add_link(t_path **cur, t_path **new);
t_path *add_one_path(t_path **previous, int isl, int dist);
t_island *create_island(int isl, int dist);
void pbi(t_island **island, t_path **path, int isl, int dist);
void island_pop_front(t_island **head);
void island_pop_middle(t_island **unvisited, int index);
void sort_path(t_path **disp, int sizeP);
int add_index_pathes(t_path **path);
t_li *create_l();

