#include "../inc/pathfinder.h"

static t_path *add_one(t_path **previous) {
    t_path *new = NULL;
    t_path *last = *previous;
    t_path *res = NULL;

    res = create_path(last->idPath, last->distPath);
    new = res;
    last = last->nextConnect;
    while (last) {
        new->nextConnect = create_path(last->idPath, last->distPath);
        last = last->nextConnect;
        new = new->nextConnect;
    }
    return res;
}

t_path *copy_path(t_path **data) {
    t_path *cur = NULL;
    t_path *res = NULL;
    t_path *new = NULL;
    t_path *fast = NULL;

    if (*data)
        cur = *data;
    res = add_one(&cur);
    fast = res;
    cur = cur->nextPath;
    while (cur) {
        new = add_one(&cur);
        add_link(&fast, &new);
        fast = fast->nextPath;
        cur = cur->nextPath;
    }
    return res;
}
