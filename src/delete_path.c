#include "../inc/pathfinder.h"

static void pop_all_bond(t_path **head) {
    t_path *p = NULL;

    if (!head || !(*head)) 
        return;
    while ((*head)->nextConnect) {
        p = (*head)->nextConnect;
        free(*head);
        *head = p;
    }
    if (!(*head)->nextConnect && !(*head)->nextPath) {
        free(*head);
        *head = NULL;
        return;
    }

}

static void pop_next_path(t_path **head) {
    t_path *p = NULL;

    if (!head || !(*head)) 
        return;
    if ((*head)->nextPath == NULL) {
        free(*head);
        *head = NULL;
        return;
    }
    else {
        p = (*head)->nextPath;
        free(*head);
        *head = p;
    }
}

void delete_path(t_path **head) {
    if (!head || !(*head)) 
        return;
    while(*head) {
        pop_all_bond(&(*head));
        pop_next_path(&(*head));
    }
}
