#include "../inc/pathfinder.h"

int add_index_pathes(t_path **path) 
{
    t_path *indexed = *path;
    t_path *bonds = NULL;
    int i = 0;

    for (; indexed; indexed = indexed->nextPath) 
    {
        bonds = indexed;
        while (bonds) 
        {
            bonds->index = i;
            bonds = bonds->nextConnect;
        }
        i++;
    }
    return i;
}
