#include"dlist.h"
#include<stdio.h>
#include<stdlib.h>
static void print_int(void* data)
{
	printf("%d",(int)data);
}
int main()
{
	dlist *list=dlist_create();
	if(!list)
	{
		printf("dlist create failed!\n");
		exit(0);
	}
	int i;
	for(i=1;i<10;i++)
		dlist_insert(&list,-1,(void*)i);
	dlist_print(list,print_int);
	void *data;
	dlist_delete(&list,9,&data);
	dlist_print(list,print_int);
	int length=dlist_length(list);
	printf("length:%d\n",length);
	dlist_destroy(list);
	return 0;

}
