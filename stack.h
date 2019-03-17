#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"main_lib.h"
typedef struct stack_{
  node *top;
}stack;
void make_stack(stack *s);
int isEmpty_stack(stack s);
void push_stack(stack *s,el_type y);
void pop_stack(stack *s,el_type *y);
