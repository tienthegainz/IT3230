#include<stdio.h>
#include"queue.h"
#include<string.h>
#include<stdlib.h>
void initial_queue(queue *q){
  (*q).front=NULL;
  (*q).rear=NULL;
}
int isEmpty_queue(queue q){
  return (q.front==NULL);
  }
void push_queue(queue *q,el_type tmp){
  node *new=(node*) malloc(sizeof(node));
  /*Day rear len truoc roi nhet du lieu*/
  //(*q).rear=(*q).rear->next;
  strcpy(new->data.name,tmp.name);
  strcpy(new->data.tele,tmp.tele);
  if((*q).front==NULL) (*q).front=(*q).rear=new;
  else{
    (*q).rear->next=new;
    (*q).rear=new;
  }
}
void pop_queue(queue *q,el_type *tmp){
  /*tranh viec pop ra ngoai du lieu NULL*/
  if((*q).front!=NULL){
    node *temp;
    /*thuc hien viec xoa bo nho cua du lieu hang front*/
    temp=(*q).front;
    (*q).front=(*q).front->next;
     /*Luu du lieu chuan bi pop ra vao con tro value*/
    strcpy((*tmp).name,temp->data.name);
    strcpy((*tmp).tele,temp->data.tele);
    free(temp);
  }
  else{
    printf("Your queue is empty, nothing was popped out\n");
  }
}
void push_front_queue(queue *q,el_type tmp){
  node *new=(node*)malloc(sizeof(node));
  strcpy(new->data.name,tmp.name);
  strcpy(new->data.tele,tmp.tele);
  if((*q).front==NULL) (*q).front=(*q).rear=new;
  else{
    new->next=(*q).front;
    (*q).front=new;
  }
}
