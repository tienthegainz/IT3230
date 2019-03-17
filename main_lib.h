#include<stdio.h>
#ifndef _lib_h
#define _lib_h
typedef struct du_lieu{
  int num;
}el_type;
struct list{
  el_type data;
  struct list *next;
};
typedef struct list node;
#endif
