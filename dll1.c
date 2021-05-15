#include<stdio.h>
#include<stdlib.h>
struct node{
    struct node *next;
    struct node *pre;
    int info;
};
void insertstart(struct node **s,int data);
void insertlast(struct node **s,int data);
void insertafter(struct node **s,struct node *ptr,int data);
int deletefirst(struct node **s);
int deletelast(struct node **s);
int deleteafter(struct node **start,struct node *ptr);
void viewlist(struct node **s);
int getFirst(struct node **s);
int getlast(struct node **s);
struct node* find(struct node **s,int data);

void insertstart(struct node **s,int data)
{
    struct node*p;
    p=(struct node *)malloc(sizeof(struct node));
    p->info=data;
    p->pre=NULL;
    p->next=*s;
    *s=p;
}

void insertlast(struct node **s,int data)
{
    struct node *p,*t;
    p=(struct node*)malloc(sizeof(struct node));
    p->info=data;
    p->next=NULL;
    
    if(*s==NULL)
    {
        p->pre=NULL;
        *s=p;
    }
    else
    {
        t=*s;
        while(t->next!=NULL)
        t=t->next;
        p->pre=t;
        t->next=p;
        
    }
}

void insertafter(struct node **s,struct node *ptr,int data)
{
    struct node *p;
    if(ptr==NULL)
    {
        printf("invalid search");
    }
    else
    {
        p=(struct node*)malloc(sizeof(struct node));
        p->info=data;
        p->pre=ptr;
        p->next=ptr->next;
        if(ptr->next!=NULL)
            ptr->next->pre=p;
        ptr->next=p;
    }
    
}

struct node* find(struct node **s,int data)
{
    struct node *t;
    if(*s==NULL)
    {
        return(NULL);
    }
    else
    {
        t=*s;
        while(t!=NULL)
        {
            if(t->info==data)
                return(t);
            t=t->next;
        }
        return(NULL);
    }
    
}

int deletefirst(struct node **s)
{
    struct node *t;
    
    if(*s==NULL)
        return(0);
    else
    {
        t=*s;
        *s=(*s)->next;  //*s ki jgh start
        (*s)->pre=NULL;
        free(t);
        return(1);            
    }
    
}

int deletelast(struct node **s)
{
  struct node *t;
  if(*s==NULL)
  {
      return(0);
  }
  t=*s;
  while(t->next!=NULL)
    t=t->next;
  if((*s)->next==NULL)
    *s=NULL;
  else
  
      t->pre->next=NULL;
  free(t);
  return(1);
  
}

int deleteafter(struct node **start,struct node *ptr)
{
    if(*start==NULL)
        return(0);
    if(ptr->pre==NULL)
    {
        *start=ptr->next;
        free(ptr);
        return(1);
    }

    if(ptr->next=NULL)
    {
        ptr->pre->next=ptr->next;
        free(ptr);
        return(1);
    }
    ptr->pre->next=ptr->next;
    ptr->next->pre=ptr->pre;
    free(ptr);
    return(1);
}
 
 void viewlist(struct node **s)
 {
     struct node *t;
     if(*s==NULL)
        printf("list id empty");
    else
    {
        t=*s;
        while(t!=NULL)
        {
            printf("%d ",t->info);
            t=t->next;
        }
    }
    
 }

int getFirst(struct node **s)
{
    struct node *t;
    if(*s==NULL){

        printf("list is empty");
        return(-1);
    }
    else
    {
        return(*s)->info;
    }
}

int getlast(struct node **s)
{
    struct node *t;

    if(*s==NULL)
    {
        printf("list is empty");
        return(-1);
    }
    else
    {
        t==*s;
        while(t->next!=NULL)
            t=t->next;
        return(t->info);
    }
    
}

void main()
{
    struct node *ptr;
    struct node *start=NULL;
    insertstart(&start,10);
    insertlast(&start,20);
    ptr=find(&start,10);
    insertafter(&start,ptr,30); 
    
    printf("\nfirst value %d",getFirst(&start));
    printf("\nlast value %d",getlast(&start)); // only one printf is printing
    deleteafter(&start,find(&start,30)); // no output
    deletefirst(&start);
    deletelast(&start);
    viewlist(&start);
}


 