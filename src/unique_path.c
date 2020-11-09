#include "../inc/pathfinder.h"

static void compare(t_path **newOne, t_path **curOne, int *flag) 
{
    if (*newOne && *curOne) {
        if ((*newOne)->idPath != (*curOne)->idPath)
            *flag = 1;
        if ((*newOne)->distPath != (*curOne)->distPath)
            *flag = 1;
    }
    if (!(*newOne) || !(*curOne))
        *flag = 1;
}

static void step(t_path **oldOne, t_path **path, t_path **new) 
{
    *path = *new;
    *oldOne = (*oldOne)->nextPath;
}

int unique_path(t_path **new, t_path **current) 
{
    t_path *path = *new;
    t_path *oldOne = *current;
    int flag = -1;

    while (oldOne) {
        if (oldOne->nextConnect == NULL || !path) 
        {
            compare(&path, &oldOne, &flag);
            step(&oldOne, &path, &(*new));
            if (flag == -1)
                return -1;
            if (oldOne)
                flag = -1;
            continue;
        }
        compare(&path, &oldOne, &flag);
        path = path->nextConnect;
        oldOne = oldOne->nextConnect;
    }
    return flag;
}
