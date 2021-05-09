#include<stdio.h>
#include<stdlib.h>
struct arrayqueue
{
    int front ,rear;
    int capacity;
    int *array;
};

struct arrayqueue* createqueue(int cap)
{
    struct arrayqueue *queue;
    queue=malloc(sizeof(struct arrayqueue));
    if(!queue)
    return (NULL);
    queue->front=queue->rear=-1;
    queue->capacity=cap;
    queue->array=malloc(queue->capacity*sizeof(int));
    if(!queue->array)
    return (NULL);
    return queue;
}

void main()
{
 int ch,data;
    struct arrayqueue *queue;
    queue=createqueue(5);
    while(1)
    {
        printf("enter choice\n");
        printf("1. enter\n");
        printf("2. delete\n");
        printf("3. queuesize\n");
        printf("4. exit\n");
        printf("enter your choice\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:  printf("\nenter data\n");
                    scanf("%d",&data);
                    enque(queue,data);
                    break;
            case 2: printf(" the deleted element is %d \n",dequeue(queue));
                    
                    break;
            case 3: printf(" the size of the queue is %d \n ",QueueSize(queue));
                    break;
            
            case 4: exit(0);
        }

        
    }
}

int isfullqueue(struct arrayqueue *queue)
{
    return((queue->rear+1)%queue->capacity==queue->front);
}

int isemptyqueue(struct arrayqueue *queue) // empty means there is noi data for delete so front==-1
 {
     return(queue->front==-1);
 }


int QueueSize( struct arrayqueue *queue)
{
    return((queue->capacity-queue->front+ queue->rear+1)%queue->capacity);
}

void enque(struct arrayqueue *queue, int data)
 {
     
     if(  isfullqueue(queue))
               printf("overflow"); 
     else                                                       //we are not going add directly ,we have to think like queue is circular
        {
            queue->rear=(queue->rear+1)%queue->capacity;
            queue->array[queue->rear]==data;

            if(queue->front==-1)
            queue->front=queue->rear;
         }  
     
 }


 int dequeue(struct arrayqueue *queue)
 {
     int data=-1;
     if (isemptyqueue(queue))
     {
         printf("queue is empty");
         return(-1);

     }
     else // either there is single or more element in queue so we have two case
     {
         data=queue->array[queue->front];

        if(queue->front==queue->rear)  // if q has only one element
           { queue->front=queue->rear=-1;}
        else
        {
            queue->front=(queue->front+1)%queue->capacity;  // if queue has more than one element so we have to update the value of front
        }
        return (data);
        
     }
 }
      
void deletequeue(struct arrayqueue *queue)
{
     if(queue)
     {
         if(queue->array)
         {
             free(queue->array);
         }           
          free(queue);
    }
    
     }

     
    