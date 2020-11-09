#include "../inc/pathfinder.h"

static void print_line(t_char **prd) {
    char *string = mx_strdup("========================================");

    mx_printstr(string);
    mx_printchar('\n');
    mx_printstr((*prd)->p);
    mx_printstr((*prd)->r);
    mx_printstr((*prd)->d);
    mx_printstr(string);
    mx_printchar('\n');
    mx_strdel(&(*prd)->p);
    mx_strdel(&(*prd)->r);
    mx_strdel(&(*prd)->d);
    mx_strdel(&string);
    free(*prd);
    *prd = NULL;
}

static t_char *createprd(t_path *bond, char **set) {
    t_char *prd = malloc(1 * sizeof(t_char));
    int i = 0;

    prd->p = mx_strdup("Path: ");
    join(&(*prd).p, set[bond->idPath]);
    prd->r = mx_strdup("Route: ");
    join(&(*prd).r, set[bond->idPath]);
    prd->d = mx_strdup("Distance: ");
    for (; bond; bond = bond->nextConnect)
        i++;
    prd->s = i;
    return prd;
}

static void add_next_bond(t_char **prd, t_path *bond, char *distTo, char **set) {
    char *dist = mx_itoa(bond->distPath);
    
    join(&(*prd)->r, " -> ");
    join(&(*prd)->r, set[bond->idPath]);
    if (mx_strlen((*prd)->d) != 10)
        join(&(*prd)->d, " + ");
    join(&(*prd)->d, dist);
    mx_strdel(&dist);
    if (bond->nextConnect == NULL) {
        join(&(*prd)->p, " -> ");
        join(&(*prd)->p, set[bond->idPath]);
        if ((*prd)->s != 2) {
            join(&(*prd)->d, " = ");
            join(&(*prd)->d, distTo);
        }
        join(&(*prd)->r, "\n");
        join(&(*prd)->p, "\n");
        join(&(*prd)->d, "\n");
    }
}

static void display_path(t_path **disp, int distTo, char **set) {
    t_path *bond = *disp;
    t_char *prd = NULL;
    char *dist = mx_itoa(distTo);

    while (bond) {
        prd = createprd(bond, set);
        bond = bond->nextConnect;
        while (bond->nextConnect) {
            add_next_bond(&prd, bond, dist, set);
            bond = bond->nextConnect;
        }
        add_next_bond(&prd, bond, dist, set);
        print_line(&prd);
        bond = bond->nextPath;
    }
    mx_strdel(&dist);
}

void print_output(t_island **visited, int root, int size, char **set) {
    t_island *current = NULL;
    int sizeP;

    for (; root < size; root++) {
        current = *visited;
        while (current->indexIslnd != root)
            current = current->next;
        sizeP = add_index_pathes(&current->path);
        sort_path(&current->path, sizeP);
        display_path(&current->path, current->distTo, set);
    }
}
