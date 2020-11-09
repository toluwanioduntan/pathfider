#include "../inc/pathfinder.h"

void island_pop_front(t_island **head) {
    t_island *p = NULL;
    
    if (!head || !(*head)) 
        return;
    if ((*head)->next == NULL) {
        free(*head);
        *head = NULL;
        return;
    }
    else {
        p = (*head)->next;
        free(*head);
        *head = p;
    }
}
