#include "../inc/pathfinder.h"

t_path *add_one_path(t_path **previous, int isl, int dist) 
{
    t_path *new = NULL;
    t_path *last = *previous;
    t_path *res = NULL;

    if (!last) return res = create_path(isl, dist);

    res = create_path(last->idPath, last->distPath);
    new = res;
    last = last->nextConnect;
    while (last) 
    {
        new->nextConnect = create_path(last->idPath, last->distPath);
        last = last->nextConnect;
        new = new->nextConnect;
    }
    new->nextConnect = create_path(isl, dist);

    return res;
}
