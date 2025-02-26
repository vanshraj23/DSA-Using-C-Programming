/*
    Author : Vansh Raj Bir.
    Date   : 21-02-2025
    Topic  : Queue implementation using Linked List.
*/

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define DATA_TYPE int      // For desired data type.
#define GARBAGE -9999      // For garbage value.

// Structure for the node.
typedef struct NODE {
    DATA_TYPE data;        // to hold the value.
    struct NODE* link;     // pointer to next node.
} node;

// Structure for the Queue.
typedef struct QUEUE {
    node* front;           // to keep the track of front side of the queue. 
    node* rear;            // to keep the track of rear side of the queue. 
} queue;

// Function prototypes.
node* createNode(DATA_TYPE);
queue* createQueue(void);
bool isEmptyQueue(const queue*);
bool enQueue(queue*,DATA_TYPE);
bool deQueue(queue*);
DATA_TYPE peekFront(const queue*);
void deleteQueue(queue**);

int main(void)
{
    // dynamic createion of queue.
    queue* newQueue = createQueue();

    if (!newQueue)
    {
        fprintf(stderr,"Memory Allcation for the Queue failed!\n");
        exit(EXIT_FAILURE);  // Exit when queue memory allocation failed.
    }
    
    // Enqueuing the values to the queue.
    for (int i = 1; i <= 10; i++)
    {
        if (!enQueue(newQueue,i))
        {
            fprintf(stderr,"Couldn't enqueue %d into the queue!\n",i);
            break;
        }
    }
    
    // printing elements until queue is empty.
    while (!isEmptyQueue(newQueue))
    {
        fprintf(stdout,"%d ",peekFront(newQueue));

        if (!deQueue(newQueue))
        {
            fprintf(stderr,"Couldn't dequeue from the queue!\n");
            break;
        }   
    }

    // deleting the queue.
    deleteQueue(&newQueue);

    return EXIT_SUCCESS;
}

// Function to create the node dynamically.
node* createNode(DATA_TYPE value)
{
    node* newNode = (node*)malloc(sizeof(node));
    
    if (newNode)   // Initializing the node. 
    {
        newNode->data = value;
        newNode->link = NULL;
        
        return newNode;
    }
    return NULL;
}

// Fuction to create the Queue dynamicallly.
queue* createQueue(void)
{
    queue* newQueue = (queue*)malloc(sizeof(queue));
    
    if (newQueue)   // Initializing the Queue.
    {
        newQueue->front = NULL;
        newQueue->rear  = NULL;
        
        return newQueue;
    }
    return NULL;
}

// Function to check Queue is empty or not.
bool isEmptyQueue(const queue* currentQueue)
{
    return currentQueue->front == NULL & currentQueue->rear == NULL;
}

// Function to enqueue an element into the queue.
bool enQueue(queue* currentQueue,DATA_TYPE value)
{
    node* newNode = createNode(value);

    if (!newNode)
    {
        fprintf(stderr,"Memory allocation for node failed!\n");
        return false;
    }
    
    if (isEmptyQueue(currentQueue))
    {
        currentQueue->front = newNode;
    }
    else
    {
        currentQueue->rear->link = newNode;
    }
    currentQueue->rear = newNode;
    
    return true;
}

// Function to dequeue an element from the queue.
bool deQueue(queue* currentQueue)
{
    if (isEmptyQueue(currentQueue))
    {
        fprintf(stderr,"Can't dequeue from the empty queue!\n");
        return false;
    }
    
    node* tempNode = currentQueue->front;
    currentQueue->front = tempNode->link;

    if (!currentQueue->front)
    {
        currentQueue->rear = NULL;
    }
    
    free(tempNode);

    return true;
}

// Function to return the value in the front of the queue.
DATA_TYPE peekFront(const queue* currentQueue)
{
    if (!isEmptyQueue(currentQueue))
    {
        return currentQueue->front->data;
    }
    return GARBAGE;
}

// Function to delete the queue located dynamically.
void deleteQueue(queue** queue_Ptr)
{
    if (*queue_Ptr)
    {
        while (!isEmptyQueue(*queue_Ptr))
        {
            deQueue(*queue_Ptr);
        }
        free(*queue_Ptr);
    }
    *queue_Ptr = NULL;
}