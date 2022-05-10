#include <stdio.h>
#include <stdlib.h>
#include "pqueue.h"

heap init (int size, bool(*cmp)(int,int)) {
	heap p;
    p.root = (pair*)malloc(sizeof(pair)*(size+1));
    p.capacity = size + 1;
    p.size = 0;
    p.f = cmp;
    return p;
}
void swap (pair * r, int i, int j) {
    pair temp = r[i];
    r[i] = r[j];
    r[j] = temp;
}
void push (heap * h, pair value) {
	pair * root = h->root; 
    int i = h->size + 1, limit = h->capacity;
   	if (i < limit) {
    	root[i] = value;
        while (i/2 && h->f(root[i].a, root[i/2].a)) {
        	swap(root, i, i/2);
            i = i/2;
        } h->size++;
    } 
}

int pop (heap * h) {
	pair * root = h->root;
    int i = 1;
	if (h->size) {
    	int value = root[1].b;
        h->root[1] = root[h->size];
        h->size--; i*=2;
        while ( i <= h->size ) {
        	i += (i < h->size && h->f(root[i+1].a,root[i].a));
            if (h->f(root[i/2].a,root[i].a)) break;
            swap(root, i, i/2);
            i*=2;
            } 
            return value;
    } 
    printf("%s","Error: Removing from an empty queue\n");
    exit(EXIT_FAILURE);
}

void clear(heap * p) {
    p->size = 0;
}

void destroy(heap * p) {
    free(p->root);
    p->size = p->capacity = 0;
}

void printQ (heap * p) {
    for (int i = 1; i <= p->size; i++)
        printf("(k = %d,v = %d)\n", p->root[i].a,p->root[i].b);
    printf("\n");
}