#include<stdio.h>
#include<stdlib.h>
struct node{
    int node;
    struct node *link;
};

struct node *START=NULL;
 struct node * createnode()   // createing node
 {
     struct node *n;
     n=(struct node*)malloc(sizeof(struct node));
    return(n);
 }

 void insertnode()    // inserting node  at the end the of  the list
 {
     struct node *temp,*t; //  creating t because we need to access the last node so we can use t to traverse  the chain if  we use start then chain wil break 
      temp=createnode();
     printf("\nenter a no");
     scanf("%d",&temp->node);
     temp->link=NULL;
     
     if(START==NULL)        // if there is no node
        START=temp;
    else                // if ther is multiple node already exit in the list
        {
            t=START;
            while(t->link!=NULL)  // 
                t=t->link;
            t->link=temp;        
        }

}


void deletenode() // deletion  of 1st node  
{
     struct node *r;             // r is creating so that we can store the addaress of 1st node 
     if(START==NULL)                // we don"t want to disturb the purpose of startb of we can create another pointer r
        printf("\n list is empty");
    else
    {
        r=START;
        START=START->link;
        free(r);
    }
}


void viewlist()           // accessing the list
{
    struct node *t; // we don"t wnat to disturb the purpose of strat so we use another pointer p
    if(START==NULL)
        printf("list is empty");
    
    else
    {
        t=START;
        while(t!=NULL)
        {   printf("%d",t->link);
            t=t->link;
        }
    }
}

int menu()
{
    int choice;
    printf("\n1.add value");
    printf("\n2.delete value");
    printf("\n3.traversevalue");
    printf("\n4.exit");
    printf("enter choice");
    scanf("%d", &choice);
    return(choice);
}


void main()
{

while(1)
{
    
    switch(menu())
    {
        case 1: insertnode();
                break;
        case 2: deletenode();
                break;
        case 3: viewlist();
                break;
        case 4: exit(0);
        default: 
        printf("invalid choice");
    }
}
}