#include "../inc/pathfinder.h"

void pbi(t_island **island, t_path **path, int isl, int dist) {
    t_island *new = create_island(isl, dist);
    t_island *last = *island;

    if (path && *path)
        new->path = copy_path(&(*path));
    if (*island == NULL) {
        *island = new;
        return;
    }
    while (last->next != NULL)
        last = last->next;
    last->next = new;
    return;
}
