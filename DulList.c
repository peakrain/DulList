#include"DulList.h"
#include<stdlib.h>
int DulList_create(DulList **L)
{
	DulList *p=*L;
	p=(DulList *)malloc(sizeof(DulList));
	if(!p)
		return -1;
	p->data=-1;
	p->prior=NULL;
	p->next=NULL;
	return 0;
}
int DulList_insert(DulList **L,int index,ElemType e)
{
	DulList *p=*L;
	if(!p)
		return -2;
	if(index<-1)
		return -3;
	if(index!=-1)	
	{
		int y=0;
		while(p&&y<index)
		{
			p=p->next;
			y++;
		}
		if(!p||y!=index)
			return -1;
		if(p->next==NULL)
		{
			DulList *s=(DulList *)malloc(sizeof(DulList));
			if(!s)
				return -1;
			s->data=e;
			s->next=p->next;
			p->next=s;
			s->prior=p;
			return 0;
		}
		else
		{
			p=p->next;
			DulList *s=(DulList *)malloc(sizeof(DulList));
			if(!s)
				return -1;
			s->data=e;
			s->prior=p->prior;
			p->prior->next=s;
			s->next=p;
			p->prior=s;
			return 0;
		}
	}
	else
	{
		while(p->next!=NULL)
			p=p->next;
		DulList *s=(DulList *)malloc(sizeof(DulList));
		if(!s)
			return -1;
		s->data=e;
		s->next=p->next;
		p->next=s;
		s->prior=p;
		return 0;	
	}
}
int DulList_delete(DulList **L,int index,ElemType *e)
{
	DulList *p=*L;
	if(!p)
		return -2;
	if(index<1)
		return -3;
	int y=0;
	while(p&&y<index)
	{
		p=p->next;
		y++;
	}
	if(!p||y!=index)
		return -1;
	if(p->next==NULL)
	{
		*e=p->data;
		p->prior->next=NULL;
	}
	else
	{
		*e=p->data;
		p->next->prior=p->prior;
		p->prior->next=p->next;
	}
	return 0;
}
int DulList_visit(DulList *L)
{
	DulList *p=L;
	if(!p)
		return -1;
	printf("List Data:\n");
	p=p->next;
	if(p)
		printf("%d",p->data);
	while(p->next)
	{
		p=p->next;
		printf("->%d",p->data);
	}
	printf("\n");
	return 0;
}
int DulList_length(DulList *L)
{
	DulList *p=L;
	if(!p)
		return -1;
	int length=0;
	while(p->next!=NULL)
	{
		length++;
		p=p->next;
	}
	return length;
}
