#include<stdio.h>
#include"main_lib.h"
#include<stdlib.h>
 typedef node* Pnode;
void print_list(Pnode Root);
void make_list(Pnode *Root);
void add_first(Pnode *Root,el_type y);
void delete_first(Pnode *Root,el_type *y);
void seach_delete(Pnode *Root,el_type y);
Pnode search_list(Pnode Root,el_type y);
