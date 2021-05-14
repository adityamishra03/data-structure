#include<stdio.h>
#include<stdlib.h>

struct node
{
    int info;
    struct node *link;
};
struct node *Start=NULL;
struct node * createnode()
{
    struct node *n;
    n=(struct node *)malloc(sizeof(struct node));
    return (n);

}

void insertnode() //insertion at the end
{
    struct node *temp,*t; 
    temp=createnode();
    printf("enter the value\n");
    scanf("%d",&temp->info);
    temp->link=NULL;
    if(Start==NULL)
    {
        Start=temp;
    }
    else
    {
        t=Start;
        while(t->link!=NULL)
            t=t->link;
        t->link=temp;
    }
    
}

int deletenode() //deletion from front
{
    struct node *t;
    if (Start==NULL)
    {
        return(0);
    }
    else
    {
        t=Start;
        Start=Start->link;
        free(t);
        
    }
    
}
void traverse()
{
    struct node *t;
    if (Start==NULL)
    {
        printf("\n there is no element in the list");
    }
    else
    {
        t=Start;
        while(t!=NULL)
        {
            printf("%d\n",t->info);
            t=t->link;
        }
        printf("%d",t->info);
    }
    
}
//insertion at beg
void insertatbeg()
{
 struct node *t,*t1;
 t1=Start;
 t=createnode();
 printf("enter the value\n");
    scanf("%d",&t->info);
    t->link=NULL; 
    if(Start==NULL)
    {printf("list is empty\n");}
    else{
    Start=t;
    Start->link=t1;}  
}
void main()
{ int ch;
    while(1)
    {

    printf("\nenter the choice");
    printf("\n 1.for insert node");
    printf("\n 2. fordelete node");
    printf("\n 3. traverse");
    printf("\n 4. insertatbeg");
    printf("\n 5. exit\n");
    scanf("%d",&ch);

    
        switch(ch)
        {
            case 1: insertnode();
                    break;
            case 2: printf(" \nthe deleted node is :%d",deletenode());
                    break;
            case 3: traverse();
                    break;
            case 4: insertatbeg();
                    break;
            case 5: exit(0);
                    break;
            default: printf("\n invalid choice");
        }
    }

}