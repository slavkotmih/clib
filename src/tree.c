#include "tree.h"

#include <stdlib.h>
#include <string.h>
#include <assert.h>

tree *tree_new(void *obj, int (*compare_fn)(void *obj1, void *obj2))
{
    tree *t = (tree *)malloc(sizeof(tree));
    t->compare_fn = compare_fn;
    t->data = obj;
    t->left = t->right = NULL;
    return t;
}

void tree_insert(tree *t, void *obj)
{
    tree *tmp = NULL, *t1 = t, *t2 = t;
    int result = 0;

    while (t != NULL)
    {
        result = t->compare_fn(t->data, obj);

        if (result == -1 || result == 0)
        {
            tmp = t;
            t1 = tmp;
            t = t->left;
            tmp->left = t;
            tmp = t;
        }

        if (result == 1 || result == 0)
        {
            tmp = t;
            t1 = tmp;
            t = t->right;
            tmp->right = t;
            tmp = t;
        }
    }

    if (result == -1 || result == 0)
        t1->left = tree_new(obj, t2->compare_fn);

    if (result == 1 || result == 0)
        t1->right = tree_new(obj, t2->compare_fn);
}

void tree_print(tree *t, void (*print_fn)(void *obj))
{
    if (t == NULL)
        return;

    tree_print(t->right, print_fn);
    print_fn(t->data);
    tree_print(t->left, print_fn);
}

/*=========================================================*/
typedef struct knot_t knot_t;

typedef struct tree
{
    int elem_size;
    int (*cmp_fn)(void *o1, void *o2);
    void (*dealloc_fn)(void *elem);
    knot_t *knot;
};

typedef struct knot_t
{
    void *data;
    knot_t *l;
    knot_t *r;
};

static knot_t *knot_create(void *data);
static void knot_delete(knot_t *knot, void (*dealloc_fn)(void *data));
static void knot_add_l(knot_t *knot, void *elem);
static void knot_add_r(knot_t *knot, void *elem);

static knot_t *knot_traverse(knot_t *knot, void *elem, int (*cmp_fn)(void *, void *));

tree *tree_create(int elem_size, int (*cmp_fn)(void *, void *), void (*dealloc_fn)(void *))
{
    tree *t = (tree *)malloc(sizeof(tree));
    t->elem_size = elem_size;
    t->cmp_fn = cmp_fn;
    t->dealloc_fn = dealloc_fn;
    t->knot = NULL;
    return t;
}

void tree_add_elem(tree *t, void *elem)
{
    knot_t *knot = t->knot;
    knot_t *knot_to_add;
    knot_to_add = knot_traverse(knot, elem, t->compare_fn);
}

knot_t *knot_traverse(knot_t *knot, void *elem, int (*cmp_fn)(void *, void *))
{
    knot_t* knot_traverse = knot;
    int cmp_result;
    while (knot_traverse)
    {
        cmp_result = cmp_fn(knot->data, elem);
        if (cmp_result <=0 )
        {
            knot_traverse = knot_traverse->l;
        }
        else
        {
            knot_traverse = knot_traverse->r;
        }
    }
    return knot_traverse;
}