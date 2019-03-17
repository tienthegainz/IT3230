#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"bi_tree.h"
void make_null_tree(tree *Root){
  *Root=NULL;
}
void insert_tree(tree *Root,el_type y){
  if (*Root == NULL){
     *Root = (tree) malloc(sizeof(tree_type));
     (*Root)->data.num=y.num;
     (*Root)->left=NULL;
     (*Root)->right=NULL;
  } 
  else if (y.num<(*Root)->data.num) insert_tree(&(*Root)->left,y);
  else if (y.num>(*Root)->data.num) insert_tree(&(*Root)->right,y);
  else if (y.num==(*Root)->data.num){
    printf("Da ton tai node tren\n");
  }
}
tree search_tree(tree Root,int y){
  if (Root == NULL) return NULL; // not found
  else if (Root->data.num==y) /* found y */ 
    return Root;
  else if (Root->data.num<y)
    //continue searching in the right sub tree 	
    return search_tree(Root->right,y); 
  else 
  // continue searching in the left sub tree 
    return search_tree(Root->left,y); 
}
el_type delete_min(tree *Root){
  el_type k; 
  if ((*Root)->left == NULL){ 
    k.num=(*Root)->data.num;
    (*Root) = (*Root)->right; 
    return k; 
  } 
  else return delete_min(&(*Root)->left);
}
void delete_tree(tree *Root,int y){
  if (*Root!=NULL)
    if ((*Root)->data.num>y) delete_tree(&(*Root)->left,y) ;
    else if ((*Root)->data.num<y) delete_tree(&(*Root)->right,y) ;
    else if 
      ((*Root)->left==NULL&&(*Root)->right==NULL) *Root=NULL; 
    else if ((*Root)->left == NULL)
      *Root = (*Root)->right; 
    else if ((*Root)->right==NULL) 
      *Root = (*Root)->left; 
    else (*Root)->data=delete_min(&(*Root)->right); 
}
void delete_tree_unsort(tree *Root,int y){
  if (*Root!=NULL){
    if ((*Root)->data.num<y) {
      printf("%s %d\n",(*Root)->data.code,(*Root)->data.num);
      if ((*Root)->left==NULL&&(*Root)->right==NULL) *Root=NULL;
      else if ((*Root)->left == NULL)
	{
	  *Root = (*Root)->right;
	  if((*Root)->data.num<y) delete_tree(Root,y);
	  delete_tree(&(*Root)->right,y);
	  delete_tree(&(*Root)->left,y);
	}
      else if ((*Root)->right==NULL){
	*Root = (*Root)->left;
	if((*Root)->data.num<y) delete_tree(Root,y);
	delete_tree(&(*Root)->right,y);
	delete_tree(&(*Root)->left,y);
      }
      else {
	do{
	  (*Root)->data=delete_min(&(*Root)->right);
	}
	while( (*Root)->data.num<y);
	delete_tree(&(*Root)->right,y);
	delete_tree(&(*Root)->left,y);
      }
    }
    else {
      delete_tree(&(*Root)->right,y);
      delete_tree(&(*Root)->left,y);
    }
  }
}
void inorder_print(tree Root){
  if(Root==NULL) return;
  inorder_print(Root->left);
  printf("%d\n",Root->data.num);
  inorder_print(Root->right);
}
void postorder_print(tree Root){
  if(Root==NULL) return;
  postorder_print(Root->left);
  postorder_print(Root->right);
  printf("%d\n",Root->data.num);
}
void preorder_print(tree Root){
  if(Root==NULL) return;
  printf("%d\n",Root->data.num);
  preorder_print(Root->left);
  preorder_print(Root->right);
}
