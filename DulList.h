#ifndef _dulList_h_
#define _dullist_h_

#include<stdio.h>

typedef int ElemType;
typedef struct DulNode{
	ElemType data;
	struct DulNode *prior;
	struct DulNode *next;
}DulList;


int DulList_create(DulList **L);
/*index取-1插入到末尾,取大于等于0整数插入到第0位置后，插入成功返0，插入失败返-1*/
int DulList_insert(DulList **L,int index,ElemType e);
/*删除第index位置的数据并取出数据,index>=1*/
int DulList_delete(DulList **L,int index,ElemType *e);
int DulList_visit(DulList *L);
int DulList_length(DulList *L);
#endif
