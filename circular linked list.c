#include<stdio.h> // since null is  declared in this header file 
#include<stdlib.h>
struct node  // self referencial structure since it has pointer which is pointing to its  
{
    int data;
    struct node *next;
};
struct node * createList(struct node *last);
void display(struct node *last);
struct node* addtoempty(struct node *last, int value);
struct node* addatbeg(struct node *last, int value);
struct node * addatend(struct node *last, int value);
struct node * addafter(struct node *last ,int value,int item);
struct node * del(struct node *last,int value);



int main()
{
    int choice,value,item;
    struct node *last=NULL;
    while(1)
    {
        system("cls");
        printf("\n 1.createList");
        printf("\n 2.disply list");
        printf("\n 3. add to empty");
        printf("\n 4.add at begining");
        printf("\n 5.add at end");
        printf("\n 6.add after");
        printf("\n 7.delete");
        printf("\n 8.Exit");

        printf("\n\nenter your chice");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                last=createList(last);
            break;
            case 2:
                display(last);
                break;
            case 3:
                printf("enter a no for a list");
                scanf("%d",&value);
                last=addtoempty(last,value);
                break;
            case 4:
                printf("enter a no for the list");
                scanf("%d",&value);
                last=addatbeg(last, value);
                break;
            case 5:
                printf("enter a no for the list");
                scanf("%d",&value);
                last=addatend(last,value);
                break;
            case 6:

                printf("enter the no for the list");
                scanf("%d",&value);
                printf("enter item value after new value to be inserted");
                scanf("%d",&item);
                last=addafter(last,value,item);
                break;
            case 7:
                printf("enter value of element to be deleted");
                scanf("5d",&value);
                last=del(last,value);
                break;
            case 8:
                exit(0);
            default  :
                printf("invalid choice");  
        }// end of switch
        getch();

        
    }// end of while
}// end of main  

// display
void display(struct node *last)
{
     if(last==NULL)
     {
         printf("\nlist is empty");
     }
     else
     {
         struct node *t;
         t=last->next;   // it points 1st node 
         do
         {
             printf("%d",t->data);
             t=t->next;
         }while(t!=last->next); // 1st time while condition  , value of t is 2000 that is 2nd node addess
     }
}


// add at begining
struct node* addatbeg(struct node *last, int value)
{
    struct node *n;
    n=malloc(sizeof(struct node));
    n->data=value;
    n->next=last->next; // new node point to the 1st node
    last->next=n;   // last node point new created node
    return(last);
}


// add to empty
struct node* addtoempty(struct node *last, int value)
{
    struct node *n;
    n=malloc(sizeof(struct node));
    n->data=value;
    last=n;  // last having null so we assingning the created node  
    last->next=last;  // since it is 1st node so it will point to itself
    return(last);
}



//add at end
struct node * addatend(struct node *last, int value)
{
    struct node *n;
    n=malloc(sizeof(struct node));
    n->data=value;
    n->next=last->next; // new node point  1st node;
    last->next=n; // last node necome 2nd last nodf
    last=n;     // last node will point to new node
    return(last);
     
}

// add after
struct node * addafter(struct node *last ,int value,int item) // item is data after which we will add node
{
 struct node *t,*n;
 t=last->next;// t is pointing 1st node
 do
 {

    if(t->data==item)
    {
        n=malloc(sizeof(struct node));
        n->data=value;
        n->next=t->next;
        t->next=n;
        if(t==last) // if itme will find at last node so we add at last
            last=n;
        return(last); // node find  , new node add so we will return simply
    
    }
 t-t->next;
 }while(t!=last->next);
// there is possibility like if it will traverse whole list  and node will not found so
printf("%d is not in the list",item);
return(last); 
} 



// delete function
struct node * del(struct node *last,int value){
    struct node *t,*p;
    if(last==NULL)  // caes 1 : when ther is no node
    {
        printf("list is empty");
        return(last);
    }

    if (last==last->next && last->data==value){   // case2: when ther is one node and we have to match the value that we have to delete
        t=last;                 // assing the adrees in t
        last=NULL;              // since we have to return the last value
        free(t);
        return(last);                                            // if it is matched then it will delete otherwise no deletion will occur
    }

    //case3 if we have to release 1st node
    if(last->next->data==value)
    {
        t=last->next;   // we assigning 1st node address i.e. last->next  in t
        last->next=t->next;//  2nd node adress in last->>next
        free(t);
        return(last);  
    }            
    // all special case coverd till here
    // case 4: 
    p=last->next; // p is pointing to 1st node

    while(p->next!=last)     // loop will execute till @nd last node
    {
        if(p->next->data=value)// 1st node  already checked so we are checking freom 2nd node
        {
            t=p->next;
            p->next=t->next;
            free(t);
            return(last);  
        }
        p=p->next;
    }

    //case 5: if node will be last node
    // so till here p is pointing to laast node beacause uper loop will terminate so p has last node adress
    if(last->data==value)
    {
        t=last;
        p->next=last->next;
        last=p;  // last will point to the 2nd last node
        free(t);
        return(last);
    }

    //if data is not found isn any of the above case
    printf("%d is  not found");
    return(last);
}



// create list
struct node * createList(struct node *last)
{
    int i,n,value;
    printf("hpow many many valu es you wamt to enter");
    scanf("%d",&n);
    printf("enter first data for the list");
    scanf("%d", &value);
    last=addtoempty(last,value);  // fisrt data entered
    for(i=2;i<=n;i++)  // we ahve eneterd one value so we start loop from 2
    {
        printf("enetr data for the lsit");
        scanf("%d",&value);
        last=addatend(last,value);
    }
    return(last);

}