struct ArrayQueue{
    int front,rear;
    int capacity;
    int *array;

}

struct ArrayQueue create queue(int cap)
{
    struct ArrayQueue *q=malloc(sizeof(ArrayQueue));
    if(!q)  return (NULL);
    q->capacity=capacity;
    q->front=q->rear=-1;
    q->array=malloc(sizeof(int)*array);
    if(!q->array)   
        return(NUll);
    return (q);
}

int isEmptyQueue(ArrayQueue *q)
{
    return (q->front==-1);
}

int isFullQueue(Struct ArrayQueue *q)  // most imp
{
     return((q->rear+1)%q->capacity==q->front);                                      
} 

int QueueSize()  // actual the element is present
{
    return((q->capacity-q->front+q->rear+1)%q->capacity);
}

void enQueue(struct ArrayQueue *q, int data)
{
    if(isFullQueue(q))
        printf("overflow");
    else
    {
        q->rear=(q->rear+1)%q->capacity; // suppose we habve to put the valiue at index no 1 so traet as it circular 
        q->array[q->rear]=data;
        if(q->front==-1)
            q->front=q->rear;
    }
}

int deQueue(struct Arrayqueue *q)
{
    int data=-1;
    if(isEmtyQueue(q))  // data is not available
    {
        printf("queue is empty");
        return(-1);
    }
    else
    {
        data=q->array[q->front];
        if(q->front==q->rear)   // if there is only one element
            q->front=q->rear=-1;
        else                    // if there is more than one element
            q->front=(q->front+1)%q->capacity;
    }
    return data;
}

void deleteQueue(struct ArrayQueue *q)   // whole queue will delete means structure will destroyed
{
    if(q)
    {
        if(q->array)
        {
            free(q->array);  // memory of array released
        }
        free(q);            // whole structure memory released.
    }
}