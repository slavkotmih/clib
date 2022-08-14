#include "array.h"
#include "array_type_private.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct object
{
    int x;
    int y;
} object;

typedef struct worker 
{
	int id;
	char *first_name;
	char *name;
	char *surname;
	int sex;
	int age;
	double efficiency;
	double arr[1000];
	double arrr[1000000];
} worker;

void test_array_1();
void test_array_print(void *o);
void test_array_print(void *o)
{
    int *a = (int *)o;
    printf("%d", *a);
}
void test_array_dealloc_fn(void *o)
{
	int *a = (int *)o;
    free(a);
}

int main(int argc, char **args)
{
    test_array_1();
    return 0;
}

void test_array_1()
{
    int *b = malloc(sizeof(int)); *b = 1;
    int *r = malloc(sizeof(int)); *r = 2;
    int *g = malloc(sizeof(int)); *g = 6;
	worker *value = malloc(sizeof(worker));
	printf("%ld\n", sizeof(worker));
    int alloc_size = 1;
    int elem_size = sizeof(worker);
    array_t *a = array_create(2, alloc_size, elem_size, NULL, test_array_dealloc_fn, NULL, NULL);

/*	array_push_back(a, b);
	array_push_back(a, r);
	array_push_back(a, r);
	array_push_back(a, r);
	array_push_front(a, r);
	array_push_front(a, g);
	array_push_front(a, g);
	array_push_front(a, g);*/

	for(int i = 0; i < 1000; i++)
	{
		array_push_back(a, value);
//		printf("%.lf", value->arr[999]);
//		printf("%.lf", value->arrr[999999]);
	}

//    array_add_obj(a, b);
//    array_add_obj(a, r);
//    int *l = (int *)array_fnd_obj(a, r);
/*    void *c = (void *)a->data;
    int *k = (int *)c;
    printf("%d\n", *k);*/
//    array_print(a, test_array_print);

    array_delete(a);
	free(b);
	free(r);
	free(g);
}
