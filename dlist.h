#ifndef _dulList_h_
#define _dullist_h_

struct _DListNode;
typedef struct _DListNode dlist;

typedef void (*DListDataPrintFunc)(void *data);
void dlsit_print(dlist *thiz, DListDataPrintFunc print);

dlist *dlist_create();

void dlist_destroy(dlist *thiz);

/*index取-1插入到末尾,取大于等于0整数插入到第0位置后，插入成功返0，插入失败返-1*/
int dlist_insert(dlist **thiz,int index,void *e);

/*删除第index位置的数据并取出数据,index>=1*/
int dlist_delete(dlist **thiz, int index, void **e);

int dlist_length(dlist *thiz);
#endif
