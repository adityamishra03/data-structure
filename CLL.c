struct node  // self referencial structure since it has pointer which is pointing to its  
{
    int data;
    struct node *next;
}
struct node * createList(struct node *last);
void display(struct node *last);
struct node *addtoepmty(struct node *last, int last);
struct node* addatbeg(struct node *last, int value);
struct node * addatend(struct node *last, int value);
struct node * addafter(struct node *last ,int value,int item);
struct node * del(struct node *last,int value);

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
struct node *addtoepmty(struct node *last, int last)
{
    struct node *n=
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