// function that we have  to made
//  insertion- start, end, after a node
// // deletion - start,particular, last node
// // traversing
// // getfirst
// // getlast
// // search

strut node{
    struct node *prev;
    int info;
    struct node *next;
};

void insertstart(struct node **s, int data);
void insertLast(struct node **s, int data);
void insertAfter(struct node **s, struct node *ptr ,int data);



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
void insertAfter(struct node **s, struct node *ptr ,int data);
{
    struct node *p;
    if(ptr=NULL)
        printf("invlid insertion");
    else   // in this before disturbing the node in actual list , asign the value to the next node after that change in the list
    {
         p=(struct node*)malloc(sizeof(struct node));
         p->info=data;
         p->prev=ptr;
         p->next=ptr->next;
        
        if(ptr->next!=NULL) // if the  3rd node that is lats node is  availanle that is it is not null
              ptr->next->prev=p;
            ptr->next=p;
}


main()
{
    struct node *ptr;
    struct node *start=NULL;
    insertstart(&start,10);
    insertLast(&start, 20);
    ptr=search(&startt,20);             // search function for finding the addrees of the element and we passing the start means pointer that pionting to the list
    insertafter(&start,ptr 30)  // ptr is the adrees of that particular node after which we whic we have to insert the value 
}