#include"DulList.h"
#include<stdlib.h>
int main()
{
	DulList *list;
	if(DulList_create(&list)!=0)
	{
		printf("DulList create failed!\n");
		exit(0);
	}
	int i;
	for(i=1;i<10;i++)
		DulList_insert(&list,-1,i);
	DulList_insert(&list,9,100);
	
	int length=DulList_length(list);
	printf("length:%d\n",length);
	DulList_visit(list);
	int data;
	if(DulList_delete(&list,1,&data)==0)
		printf("delete data:%d\n",data);
	
	length=DulList_length(list);
	printf("length:%d\n",length);
	DulList_visit(list);
	return 0;

}
