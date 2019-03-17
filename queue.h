#include<stdio.h>
#include"main_lib.h"
typedef struct queue_{
  node *front,*rear;
}queue;
void initial_queue(queue *q);
int isEmpty_queue(queue q);
void push_queue(queue *q,el_type tmp);
void pop_queue(queue *q,el_type *value);
