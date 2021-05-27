// function that we have  to made
//  insertion- start, end, after a node
// // deletion - start,particular, last node
// // traversing
// // getfirst
// // getlast
// // search
//viewlist
#include<stdio.h>
#include<stdlib.h>
struct node{
    struct node *prev;
    int info;
    struct node *next;
};

void insertstart(struct node **s, int data);
void insertLast(struct node **s, int data);
void insertAfter(struct node **s, struct node *ptr ,int data);
struct node* find(struct node **s,int data);
int deletefirst(struct node **s);
int deletelast(struct node **s);
int deleteintermediate(struct node **s, struct node *ptr);
void viewList(struct node **s);
int getFirst(struct node **s);
int getLast(struct node**s);

void insertstart(struct node **s, int data) // **s since it contain the address of another pointer start
{                   
    struct node *p;                         // s is representing start
    p=(struct node*)malloc(sizeof(struct node));
    p->prev=NULL;                           // in fisrt node prev is NULL
    p->info=data;
    p->next=*s;                             // if start is nULL so it will assign to the 1st node next 
                                            // or if start has the value of next address so it will assign to the 1st node next
        *s=p;                               // p is assigning to the start pointer 

}


void insertLast(struct node **s, int data)  // insert atlast
{
    struct node *p,*t;
    p=(struct node *)malloc(sizeof(struct node));
     p->info=data;
     p->next=NULL;   // since adding at the last so next is NULL
    
     if(*s==NULL){      // is s is NUll

        p->prev=NULL;
        *s=p;
     }
     else{
          t=*s ;
          while(t->next!=NULL)
            t=t->next;
            p->prev=t; // in prev of new node we need to add adress of previos node
             t->next=p;// assigning the addres of new node to last node next

     }
}


// insertion of a node after  a particular node
// void insertAfter(struct node **s, struct node *ptr ,int data)
// {
//     struct node *p;
//     if(ptr=NULL)
//         printf("invlid insertion");
//     else   // in this before disturbing the node in actual list , asign the value to the next node after that change in the list
//     {
//          p=(struct node*)malloc(sizeof(struct node));
//          p->info=data;
//          p->prev=ptr;
//          p->next=ptr->next;
        
//         if(ptr->next!=NULL) // if the  3rd node that is lats node is  availanle that is it is not null
//               ptr->next->prev=p;
//             ptr->next=p;
// }

// searching the element
struct node* find(struct node **s,int data)
{
     struct node *t;
     if(*s==NULL)       // if there is no list that s containg NULL
        return NULL;
    else
     t=*s;              // assign the s to t pointer yo traverse
     while(t!=NULL)    // loop will occur till t is having NULL
     {
         if(t->info==data)      // if the data will match return the address
            return(t);
        t=t->next;              // else assign the next node address
     } 
     return(NULL);              // if we donot get the match element in the list , loop will wnd so 
                                // we need to return the NULL vallue
}




// deletion of first node
int deletefirst(struct node **s)
{
    struct node *t;
    if(*s==NULL)
       return (0); // since there is no node so we return 0 
    else{
        t=*s;       // in t we assign start value ,t is pointing to 1st node
        *s=(*s)->next; // we are assigning the 2 node address to start pointer
        (*s)->prev=NULL; // 2nd node become fisrt node so in prev of !st node it shuould be nULL
        free(t);        // aftre adjustment we release the memory of 1st node that is contained by t;
        return(1);  // it shows successful deletion occur
    }
}


// deletion of last node
int deletelast(struct node **s)
{
    struct node *t;
    if(*s==NULL)
        return(0);// there is no node
   t=*s;
   while(t->next!=NULL)  // loop will execute and we will get last node 
          t=t->next;       // t has last node addres
   if((*s)->next=NULL)  // if there is only one node
        *s=NULL    ;     // so start will assign by NULL value
   
    else            // list havig more than 1 node
        t->prev->next=NULL; // so prev node become last so we have to assign NULL valueto its next 
    free(t);    // memory release
    return(1); // it shows we deleted successfully
}

// deletion of intermediate node
int deleteintermediate(struct node **s, struct node *ptr)
{
    if(*s==NULL)        // if there is no node
        return(0);
    if(ptr->prev==NULL)
    { // node wchich will delete is 1st node

      *s=ptr->next;  // assign start with 2nd node
    free(ptr);
    return(1);
    }
    if(ptr->next==NULL) // if it is last node
    {
        ptr->prev->next=ptr->next; // 2nd  last node me change   
        free(ptr);
        return(1);
    }
    // else it is normal case that is intermediate ppointer
    ptr->prev->next=ptr->next; // we adjusting the node address 2 to 4
    ptr->next->prev=ptr->prev; 
    free(ptr);
    return(1);


}


void viewList(struct node **s) // viewlist
{
    struct node *t;
    if(*s==NULL)
    {
        printf("list is empty");
    }
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

int getFirst(struct node **s){
    if(*s==NULL)
    {
        printf("list is empty");
        return(-1);
    }
    else{
        return((*s)->info);
    }
}

int getLast(struct node**s) // for last node
{
    struct node *t;
    if(*s==NULL)
    {
        printf("list is empty");
        return(-1);
    }
    else{
        t=*s;
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
    insertLast(&start,20);
   
    ptr=find(&start,10);
  //  insertAfter(&start,ptr,30);
    printf("\nfirst value is %d",getFirst(&start));
    printf("\n last value is %d\n",getLast(&start));
    deleteintermediate(&start,find(&start,30) );
    deletefirst(&start);
    deletelast(&start);
     viewList(&start);
}