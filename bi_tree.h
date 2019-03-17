#include<stdio.h>
#include<stdlib.h>
#include"main_lib.h"
typedef struct bi_tree{
  el_type data;
  struct bi_tree *left,*right;
}tree_type;
typedef tree_type *tree;
void make_null_tree(tree *Root);
void insert_tree(tree *Root,el_type y);
tree search_tree(tree Root,int y);
el_type delete_min(tree *Root);
void delete_tree(tree *Root,int y);
void inorder_print(tree Root);
void postorder_print(tree Root);
void preorder_print(tree Root);
