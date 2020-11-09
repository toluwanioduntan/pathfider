#include "../inc/pathfinder.h"

void path_push_back(t_path **path, t_path **previous, int isl, int dist) {
    t_path *last = *path;
    t_path *cur = *previous;
    t_path *new = NULL;
    
    while (last->nextPath != NULL)
        last = last->nextPath;
    while (cur) {
        new = add_one_path(&cur, isl, dist);
        if (unique_path(&new, &(*path)) == 1) {
            add_link(&last, &new);
            last = last->nextPath;
        }
        cur = cur->nextPath;
    }
}
