#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
    
};
struct node *last=NULL;
struct node* createlist(struct node* last);
struct node* insertatbeg(struct node *last,int value);
struct node* insertlast(struct node *last,int value);
struct node* addafter(struct node *last,int item,int value);
struct node* delete(struct node *last, int value);
void display(struct node *last);
struct node* addtoempty(struct node *last,int value);

void display(struct node *last)
{
    struct node *t;
    if(last==NULL)
    {
        printf("list is empty");
    }
    else
    {   t=last->next;
        
        do
        {
        printf("%d ",t->data);
        t=t->next;
        }while(t!=last->next);
        
    }
    
}

struct node* insertatbeg(struct node *last,int value)
{
    struct node *t;
    t=malloc(sizeof(struct node));
    t->data=value;
    /*if(last==NULL)
    {
        last=t;
        last->next=last;
    }*/
    //else
   // {
        t->next=last->next;
        last->next=t;
        return(last);
    //}
}

struct node * addtoempty(struct node *last,int value)
{
    struct node *t;
    t=malloc(sizeof(struct node));
    t->data=value;
    last=t;
    last->next=last;
    return(last);
}

struct node* insertlast(struct node *last, int value)
{
 struct node *n;
 n=malloc(sizeof(struct node));
 n->data=value;
 n->next=last->next;
 last->next=n;
 last=n;
 return(last);
}

struct node *  addafter(struct node *last,int item,int value)
{
    struct node *t,*n;
    t=last->next;
    
    do {

        if(t->data==item)
        {
            n=malloc(sizeof(struct node));
            n->data=value;
            n->next=t->next;
            t->next=n;
            if(t==last)
                last=n;
            return(last);
        }
        t=t->next;
    }while(t!=last->next);
    printf("%d not in the list",item);
    return(last);
}

struct node* delete(struct node *last, int value)
{
    struct node *t,*p;
    if(last==NULL){  // if there is no node

        printf("list is empty");
        return(last);
    }
    
    if(last==last->next &&last->data==value) // if it has one node
    {
        t=last;
        last=NULL;
        free(t);
        return(last);
    }

    if(last->next->data==value)  // if we have to delete a node which is 1st node
    {
        t=last->next;
        last->next=t->next;
        free(t);
        return(last);
    }

    p=last->next;
    while(p->next!=last)
    {
        if(p->next->data==value) //2nd node since 1st node is already checked
       {
           t=p->next;
        p->next=t->next;
        free(t);
        return(last);
       }
       p=p->next;
     }
    
    if(last->data==value)
    {
        t=last;
        p->next=last->next;// 1st node  address, p is containing 2nd last address 
        last=p;
        free(t);
        return(last);
    }
    printf("%d is not found");
    return(last);
}

 struct node* createlist(struct node* last)
 {
     int i,n , value,item;
     printf("how  many values u wnat to enter");
     scanf("%d",&n);
     printf("enter first data for the list");
     scanf("%d",&value);
     last=addtoempty(last,value);
    for(i=2;i<=n;i++)
    {
        printf("enter data for the list");
        scanf("%d",&value);
        last=insertlast(last,value);
    }
    return(last);
 }

int main()
{
    int choice,value,item;
    struct node *last=NULL;

    while(1)
    { 
        //system("cls");// to clear screen
        printf("\n 1. create list");
        printf("\n 2. display list");
        printf("\n 3. add to empty");
        printf("\n 4. insert at beg");
        printf("\n 5. insert at last");
        printf("\n 6. add after");
        printf("\n 7. delete");
        printf("\n 8.exit");

        printf("\nenter your choice");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                    last=createlist(last);
                    break;
            case 2:display(last);
                    break;
            case 3:
                printf("enter a number for the list");
                scanf("%d",&value);
                last=addtoempty(last,value);
                break;
            case 4:
                printf("enter the no for the list");
                scanf("%d",&value);
                last=insertatbeg(last,value);
                break;
            case 5:
                printf("enter the for thew list");
                scanf("%d",&value);
                last=insertlast(last,value);
                break;
            case 6: 
                printf("enter the no for the list");
                scanf("%d",&value);
                printf("enter item vlaue aftre new value to be inserted ");
                scanf("%d",&item);
                last=addafter(last,value,item);
                break;
            case 7:
                printf("enter element to be deletd");
                scanf("%d",&value);
                last=delete(last,value);
                break;
            case 8:
                    exit(0);
            default:
                printf("invalid choice");
         }
    }
} 

 