#include "../inc/pathfinder.h"

static void st(t_island **un, t_island **cur, t_island **v, t_int *in) {
    *un = NULL;
    *v = NULL;
    for (int i = 0; i < in->size; i++)
        pbi(&(*un), NULL, i, 0);
    *cur = *un;
    while ((*cur)->indexIslnd != in->root)
        *cur = (*cur)->next;
    (*cur)->path = create_path(in->root, 0);
    pbi(&(*v), &(*cur)->path, (*cur)->indexIslnd, (*cur)->distTo);
    island_pop_middle(&(*un), in->root);
    *cur = *v;
}

static void md (t_island **un, t_island **cur, int **mat, t_md **m) {
    t_island *h = *un;
    int sum = 0;
    while (h != NULL) {
        (*m)->isl1 = (*cur)->indexIslnd;
        (*m)->isl2 = h->indexIslnd;
        (*m)->mat = mat[(*m)->isl1][(*m)->isl2];
        if ((*m)->mat != 0 && h->distTo == 0) {
            h->distTo = (*cur)->distTo + (*m)->mat;

            sum += h->distTo;
            if (sum < 0) { 
                err_length_of_bridges_big();
            } 

            h->path = add_path(&(*cur)->path, (*m)->isl2, (*m)->mat);
        } else if ((*m)->mat != 0) {
            if ((*cur)->distTo + (*m)->mat == h->distTo)
            path_push_back(&h->path, &(*cur)->path, (*m)->isl2, (*m)->mat);
            if ((*cur)->distTo + (*m)->mat < h->distTo) {
                h->distTo = (*cur)->distTo + (*m)->mat;
                delete_path(&h->path);
                h->path = add_path(&(*cur)->path, (*m)->isl2, (*m)->mat);
            }
        }
        h = h->next;
    }
}

static void lt(t_li **l, int **matrix, char **set) {
    (*l)->sh = shortest_distance(&(*l)->un);
    pbi(&(*l)->v, &(*l)->sh->path, (*l)->sh->indexIslnd, (*l)->sh->distTo);
    island_pop_middle(&(*l)->un, (*l)->sh->indexIslnd);
    (*l)->cur = (*l)->cur->next;
    if ((*l)->cur->path == NULL) {
        delete_mat(&matrix, set);
        err_invalid_number_of_islands();
        exit(0);
    }
}

static void main_algo(int **matrix, char **set, t_int *in) {
    t_li *l = create_l();
    t_md *m	= NULL;

    st(&l->un, &l->cur, &l->v, in);
    while (l->un && l->un != NULL) {
        m = malloc(sizeof(t_md));
        md(&l->un, &l->cur, matrix, &m);
        free(m);
        m = NULL;
        lt(&l, matrix, set);
    }
    print_output(&l->v, in->root+1, in->size, set);
    while (l->v != NULL) {
        delete_path(&l->v->path);
        island_pop_front(&l->v);
    }
    free(l);
    l = NULL;
}

void algoritm(int **matrix, char **set) {
    int size = 0;
    int i = 0;
    t_int *in = malloc(sizeof(t_int));

    while (set[size]) 
        size++;
    in->size = size;
    while (i < size - 1) {
        in->root = i;
        main_algo(matrix, set, in);
        i++;
    }
    free(in);
    in = NULL;
}
