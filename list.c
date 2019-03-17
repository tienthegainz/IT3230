#include<stdio.h>
#include"main_lib.h"
#include"list.h"
#include<stdlib.h>
#include<string.h>
void print_list(Pnode Root){
  while(Root!=NULL){
    printf("%d\n",Root->data.num);
    Root=Root->next;
  }
  return;
}
void make_list(Pnode *Root){
  *Root==NULL;
}
void add_first(Pnode *Root,el_type y){
  node *new=(node*) malloc(sizeof(node));
  new->data.num=y.num;
  if(*Root==NULL) (*Root)=new;
  else{
    new->next=(*Root);
    (*Root)=new;
  }
}
void delete_first(Pnode *Root,el_type *y){
  node *cur;
  if(*Root==NULL) printf("Danh sach trong\n");
  else{
    cur=*Root;
    (*Root)=(*Root)->next;
    (*y).num=cur->data.num;
    free(cur);
  }
}
void seach_delete(Pnode *Root,el_type y){
  Pnode cur,prev;
  if(*Root==NULL){
    printf("Danh sach trong\n");
    return;
  }
  if((*Root)->data.num==y.num){
    cur=*Root;
    (*Root)=(*Root)->next;
    free(cur);
  }
  else{
    cur=(*Root);
    while(cur->next!=NULL){
      prev=cur;
      cur=cur->next;
      if(cur->data.num==y.num) break;
    }
    prev->next=cur->next;
    printf("Xoa: %d\n",cur->data.num);
    free(cur);
  }
}
Pnode search_list(Pnode Root,el_type y){
  if(Root==NULL){
    printf("Danh sach trong\n");
    return NULL;
  }
  while(Root!=NULL){
    if(Root->data.num==y.num) return Root;
    Root=Root->next;
  }
  return NULL;
}
