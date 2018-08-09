#include"dlist.h"
#include<stdio.h>
#include<stdlib.h>

struct _DListNode{
	struct _DListNode *prev;
	struct _DListNode *next;
	void *data;
};

dlist *dlist_create()
{
	dlist *p;
	p=(dlist *)malloc(sizeof(dlist));
	if(!p)
		return NULL;
	p->data=NULL;
	p->prev=NULL;
	p->next=NULL;
	return p;
}

void dlist_destroy(dlist *thiz)
{
	free(thiz);
}
int dlist_insert(dlist **thiz,int index,void *e)
{
	dlist *p=*thiz;
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
			dlist *s=(dlist *)malloc(sizeof(dlist));
			if(!s)
				return -1;
			s->data=e;
			s->next=p->next;
			p->next=s;
			s->prev=p;
			return 0;
		}
		else
		{
			p=p->next;
			dlist *s=(dlist *)malloc(sizeof(dlist));
			if(!s)
				return -1;
			s->data=e;
			s->prev=p->prev;
			p->prev->next=s;
			s->next=p;
			p->prev=s;
			return 0;
		}
	}
	else
	{
		while(p->next!=NULL)
			p=p->next;
		dlist *s=(dlist *)malloc(sizeof(dlist));
		if(!s)
			return -1;
		s->data=e;
		s->next=p->next;
		p->next=s;
		s->prev=p;
		return 0;	
	}
}

int dlist_delete(dlist **thiz,int index,void **e)
{
	dlist *p=*thiz;
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
		p->prev->next=NULL;
	}
	else
	{
		*e=p->data;
		p->next->prev=p->prev;
		p->prev->next=p->next;
	}
	return 0;
}

void  dlist_print(dlist *thiz,DListDataPrintFunc print)
{
	dlist *iter=thiz;
	if(!iter||!iter->next)
		exit(-1);
	
	iter=iter->next;
	print(iter->data);
	
	while(iter->next!=NULL)
	{
		printf("->");
		iter=iter->next;
		print(iter->data);
	}
	printf("\n");
}

int dlist_length(dlist *thiz)
{
	dlist *p=thiz;
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
