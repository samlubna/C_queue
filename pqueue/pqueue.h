#ifndef P_QUEUE
#define P_QUEUE
#include <stdbool.h>
typedef struct p {
	int a,b;
} pair;
typedef struct h {
	pair * root;
    int size, capacity;
    bool(*f)(int,int);
} heap;
heap init (int, bool(*)(int,int));
void push (heap*, pair);
int pop(heap*);
void clear(heap*);
void destroy(heap*);
void printQ(heap*);
#endif