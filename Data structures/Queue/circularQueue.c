/*
    Author : Vansh Raj Bir.
    Date   : 26-02-2025
    Topic  : Circular Queue Implementation using an array.  
*/

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define DATA_TYPE int           // For desired data type.
#define MAX_SIZE 10             // Maximum size of the Queue.
#define DEFAULT_VALUE 0         // Default value for Queue.
#define INITIAL_INDEX -1        // Initaial index for front and rear.
#define GARBAGE -9999           // Garbage value to retuen from queue.

// Structure of the Queue
typedef struct QUEUE {
    DATA_TYPE data[MAX_SIZE];   // to hold the values in queue.
    int front;                  // to keep the track of the front of the queue.
    int rear;                   // to keep the track of the front of the queue.
} queue;

// Function Prototypes.
queue* createQueue(void);
bool initQueue(queue*);
bool isEmptyQueue(const queue*);
bool isFullQueue(const queue*);
bool enQueue(queue*, DATA_TYPE);
bool deQueue(queue*);
DATA_TYPE peekFront(const queue*);
void deleteQueue(queue**);

int main(void)
{
    // dynamic queue allocation.
    queue* newQueue = createQueue();
    
    if (!newQueue)
    {
        fprintf(stderr, "Memory Allocation for the Queue failed!\n");
        exit(EXIT_FAILURE);  // Exit the program when queue memory allocation failed.
    }
    
    // Enqueueing 10 elements into the queue
    for (int i = 1; i <= 10; i++)
    {
        if (!enQueue(newQueue, i))
        {
            fprintf(stderr, "Couldn't enqueue %d into the queue!\n", i);
            break;
        }
    }
    
    // Dequeuing all elements
    while (!isEmptyQueue(newQueue))
    {
        fprintf(stdout, "%d ", peekFront(newQueue));
        
        if (!deQueue(newQueue))
        {
            fprintf(stderr, "Couldn't dequeue from the queue!\n");
            break;
        }   
    }
    
    // deleting entire queue.
    deleteQueue(&newQueue);
    
    return EXIT_SUCCESS;
}

// Fuction to create the Queue dynamicallly.
queue* createQueue(void)
{
    queue* newQueue = (queue*)malloc(sizeof(queue));
    
    if (initQueue(newQueue))   // Initializing the Queue.
    {
        return newQueue;
    }
    
    return NULL;
}

// Function to initialize the Queue.
bool initQueue(queue* currentQueue)
{
    if (currentQueue)
    {
        for (int i = 0; i < MAX_SIZE; i++)
        {
            currentQueue->data[i] = DEFAULT_VALUE;
        }
        currentQueue->front = INITIAL_INDEX;
        currentQueue->rear  = INITIAL_INDEX;

        return true;
    }
    return false;
}

// Function to check Queue is empty or not.
bool isEmptyQueue(const queue* currentQueue)
{
    return currentQueue->front == INITIAL_INDEX;
}

// Function to check queue is full or not.
bool isFullQueue(const queue* currentQueue)
{
    // Queue is full if the next rear position is equal to front
    return (currentQueue->rear + 1) % MAX_SIZE == currentQueue->front;
}

// Function to enqueue an element into the queue.
bool enQueue(queue* currentQueue, DATA_TYPE value)
{
    if (isFullQueue(currentQueue))
    {
        fprintf(stderr, "Queue is full!\n");
        return false;
    }
    
    if (isEmptyQueue(currentQueue))
    {
        currentQueue->front = 0;
    }
    
    currentQueue->rear = (currentQueue->rear + 1) % MAX_SIZE;  // Wrap around
    currentQueue->data[currentQueue->rear] = value;

    return true;
}

// Function to dequeue an element from the queue.
bool deQueue(queue* currentQueue)
{
    if (isEmptyQueue(currentQueue))
    {
        fprintf(stderr, "Can't dequeue from the empty queue!\n");
        return false;
    }
    
    if (currentQueue->front == currentQueue->rear)
    {
        currentQueue->front = INITIAL_INDEX;  // Reset the queue
        currentQueue->rear = INITIAL_INDEX;
    }
    else
    {
        currentQueue->front = (currentQueue->front + 1) % MAX_SIZE;  // Wrap around
    }

    return true;
}

// Function to return the value in the front of the queue.
DATA_TYPE peekFront(const queue* currentQueue)
{
    if (!isEmptyQueue(currentQueue))
    {
        return currentQueue->data[currentQueue->front];
    }
    return GARBAGE;
}

// Function to delete the queue located dynamically.
void deleteQueue(queue** queue_Ptr)
{
    if (*queue_Ptr)
    {
        free(*queue_Ptr);
    }
    *queue_Ptr = NULL;
}