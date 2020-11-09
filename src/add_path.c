#include "../inc/pathfinder.h"

t_path *add_path(t_path **previous, int isl, int dist) 
{
    t_path *cur = NULL;
    t_path *res = NULL;
    t_path *new = NULL;
    t_path *fast = NULL;

    if (*previous)
        cur = *previous;
    res = add_one_path(&cur, isl, dist);
    fast = res;
    if (cur)
        cur = cur->nextPath;
    while (cur) {
        new = add_one_path(&cur, isl, dist);
        add_link(&fast, &new);
        fast = fast->nextPath;
        cur = cur->nextPath;
    }
    return res;
}
