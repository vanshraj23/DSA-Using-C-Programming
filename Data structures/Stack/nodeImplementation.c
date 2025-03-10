/*
    Author : Vandh Raj Bir.
    Date   : 21-02-2025
    Topic  : Stack implementation using Linked list.
*/

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define DATA_TYPE int        // For desired data type.
#define INITIAL_INDEX NULL   // Initail index for top.
#define GARBAGE -9999        // Garbage value.

// Structure for the node.
typedef struct NODE {
    DATA_TYPE data;     // to hold the data.
    struct NODE* link;  // pointer to next node.
} node;

// Struct for the stack.
typedef struct STACK {
    node* top;
} stack;

// Function prototypes. 
node* createNode(DATA_TYPE);
bool initNode(node*,DATA_TYPE);
stack* createStack(void);
bool initStack(stack*);
bool isEmptyStack(const stack*);
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
    for (int i = 10; i > 0; --i)
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

// Function to create the node dynamically.
node* createNode(DATA_TYPE value)
{
    node* newNode = (node*)malloc(sizeof(node));

    if (initNode(newNode,value))  // Initializing the node. 
    {
        return newNode;
    }
    return NULL;
}

// Function to initialize the node.
bool initNode(node* currentNode,DATA_TYPE value)
{   
    if (currentNode)
    {
        currentNode->data = value;
        currentNode->link = NULL;

        return true;
    }
    return false;
}


// Fuction to create the stack dynamicallly.
stack* createStack(void)
{
    stack* newStack = (stack*)malloc(sizeof(stack));
    
    if (initStack(newStack))  // Initializing the stack.
    {        
        return newStack;
    }  
    return NULL;
}

// Function to initialize the stack.
bool initStack(stack* currentStack)
{
    if (currentStack)
    {
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

// Function to push an element onto the stack.
bool push(stack* currentStack,DATA_TYPE value)
{
    node* newNode = createNode(value);
    
    if (!newNode)
    {
        fprintf(stderr,"Might Stack OverFlow!\n");
        return false;
    }
    
    newNode->link = currentStack->top;
    currentStack->top = newNode;

    return true;
}

// Function to pop out the top most value form the stack.
bool pop(stack* currentStack)
{
    if (isEmptyStack(currentStack))
    {
        fprintf(stderr, "Stack Underflow!\n");
        return false;
    }
    
    node* tempNode = currentStack->top;
    currentStack->top = tempNode->link;  
    
    free(tempNode);  

    return true;
}

// Function to return the top most value in the stack.
DATA_TYPE peek(const stack* currentStack)
{
    if (!isEmptyStack(currentStack))
    {
        return currentStack->top->data;
    }
    return GARBAGE;
}

// Funbction to delete stack located dynamically.
void deleteStack(stack** stack_Ptr)
{
    if (*stack_Ptr)
    {
        while (!isEmptyStack(*stack_Ptr))
        {
            pop(*stack_Ptr);
        }
        free(*stack_Ptr);
    }
    *stack_Ptr = NULL;
}