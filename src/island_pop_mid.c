#include "../inc/pathfinder.h"

static void firs_if(t_island *temp, t_island *leftOne, int index) {
    if (temp && temp->indexIslnd == index) {
            if (temp->next)
                leftOne->next = temp->next;
            else
                leftOne->next = NULL;
            delete_path(&temp->path);
            free(temp);
            temp = NULL;
        }
}

void island_pop_middle(t_island **unvisited, int index) {
    t_island *temp = NULL;
    t_island *leftOne = NULL;

    if (!unvisited || !(*unvisited)) 
        return;
    if ((*unvisited)->indexIslnd == index) {
        delete_path(&((*unvisited)->path));
        island_pop_front(&(*unvisited));
    }
    else {
        temp = *unvisited;
        leftOne = temp;
        while (temp != NULL && temp->indexIslnd != index) {
            leftOne = temp;
            temp = temp->next;
        }
        firs_if(temp, leftOne, index);
    }
}
