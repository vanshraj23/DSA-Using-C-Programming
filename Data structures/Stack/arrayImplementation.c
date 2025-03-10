/*
    Author : Vandh Raj Bir.
    Date   : 21-02-2025
    Topic  : Stack implementation using an array.
*/

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define DATA_TYPE int      // For desired data type.
#define MAX_SIZE 10        // Maximum size of a stack.
#define INITIAL_INDEX -1   // Initail index for top.
#define DEFAULT_VALUE 0    // Default value for stack
#define GARBAGE -9999      // Garbage value.


// Structure for the Stack.
typedef struct STACK {
    DATA_TYPE data[MAX_SIZE];  // to hold the data.
    int top;                   // to track the top most element. 
} stack;

// Function prototypes.
stack* createStack(void);
bool initStack(stack*);
bool isEmptyStack(const stack*);
bool isFullStack(const stack*);
bool push(stack*,DATA_TYPE);
bool pop(stack*);
DATA_TYPE peek(const stack*);
void deleteStack(stack**);

int main(void)
{
    // dynamic create of the stack.
    stack* newStack = createStack();
    
    if (!newStack)
    {
        fprintf(stderr,"Memory allocation for stack failed!\n");
        exit(EXIT_FAILURE);  // Exit when stack memory allocation failed.
    }
    
    // Pushing element in the stack.
    for (int i = MAX_SIZE; i > 0; --i)
    {
        if (!push(newStack,i))
        {
            fprintf(stderr,"Couldn't push %d onto the stack!\n",i);
            break;
        }
    }
    
    // printing elements until stack is empty.
    while (!isEmptyStack(newStack))
    {
        fprintf(stdout,"%d\n",peek(newStack));
        
        if (!pop(newStack))
        {
            fprintf(stderr,"Couldn't pop %d out from the stack!\n",peek(newStack));
            break;
        }
    }
    
    // deleting the stack.
    deleteStack(&newStack);
    
    return EXIT_SUCCESS;
}

// Fuction to create the stack dynamicallly.
stack* createStack(void)
{
    stack* newStack = (stack*)malloc(sizeof(stack));
    
    if (initStack(newStack))  // Initalizing the stack.
    {
        return newStack;
    } 
    return NULL;
}

bool initStack(stack* currentStack)
{
    if (currentStack)
    {
        for (int i = 0; i < MAX_SIZE; ++i)
        {
            currentStack->data[i] = DEFAULT_VALUE;
        }
        currentStack->top = INITIAL_INDEX;

        return true;
    }
    return false;
}

// Function to check stack is empty or not.
bool isEmptyStack(const stack* currentStack)
{
    return currentStack->top == INITIAL_INDEX;
}

// Function to check stack is full or not.
bool isFullStack(const stack* currentStack)
{
    return currentStack->top == MAX_SIZE - 1;
}

// Function to push an element onto the stack.
bool push(stack* currentStack,DATA_TYPE value)
{
    if (isFullStack(currentStack))
    {
        fprintf(stderr,"Stack OverFlow!\n");
        return false;
    }
    
    currentStack->data[++currentStack->top] = value;
    
    return true;
}

// Function to pop out the top most value form the stack.
bool pop(stack* currentStack)
{
    if (isEmptyStack(currentStack))
    {
        fprintf(stderr,"Stack UnderFlow!\n");
        return false;
    }
    
    --currentStack->top;
    
    return true;
}

// Function to return the top most value in the stack.
DATA_TYPE peek(const stack* currentStack)
{
    if (!isEmptyStack(currentStack))
    {
        return currentStack->data[currentStack->top];
    }
    return GARBAGE;
}

// Funbction to delete stack located dynamically.
void deleteStack(stack** stack_Ptr)
{
    if (*stack_Ptr)
    {
        free(*stack_Ptr);
    }
    *stack_Ptr = NULL;
}