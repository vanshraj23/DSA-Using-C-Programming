/*
    Author : Vansh Raj Bir.
    Date   : 21-02-2025
    Topic  : Double Linked List Implementation. 
*/

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

// For desided data type.
#define DATA_TYPE int

// Structure for the node.
typedef struct NODE {
    struct NODE* prev;       // pointer to previous node.
    DATA_TYPE data;          // to hold the value.
    struct NODE* next;       // pointer to next node.  
} node;

// Structure for the List.
typedef struct DoubleLinkedList {
    node* head;             // to keep the track of head of the list. 
    node* tail;             // to keep the track of head of the list.  
} dll;

// Funbction protoypes.
node* createNode(DATA_TYPE);
bool initList(dll*);
dll* createList(void);
bool initNode(node*,DATA_TYPE);
bool addAtHead(dll*,DATA_TYPE);
bool addAtTail(dll*,DATA_TYPE);
bool deleteAtHead(dll*);
bool deleteAtTail(dll*);
bool isEmptyList(const dll*);
bool traverseListForward(const dll*);
bool traverseListBackward(const dll*);
void deleteList(dll**);

int main(void)
{
    // dybamic creation of list.
    dll* newList = createList();

    if (!newList)
    {
        fprintf(stderr,"Memory allocation failed for the List!\n");
        exit(EXIT_FAILURE); // Exit when list failed to allocate.
    }
    
    // adding at head of the list.
    for (int i = 5; i >= 0; --i)
    {
        if (!addAtHead(newList,i))
        {
            fprintf(stderr,"Couldn't add %d at head of the list!\n",i);
            break;
        }
    }
    
    // adding at tail of the list.
    for (int i = 6; i <= 11; i++)
    {
        if (!addAtTail(newList,i))
        {
            fprintf(stderr,"Couldn't add %d at tail of the list!\n",i);
            break;
        }
    }
    
    // list travesing forwar and backward.
    traverseListForward(newList);
    traverseListBackward(newList);
    
    // deleting at the head of the list.
    deleteAtHead(newList);
    
    // deleting at the tail of the list.
    deleteAtTail(newList);
    
    // list travesing forwar and backward.
    traverseListForward(newList);
    traverseListBackward(newList);
    
    // deleting the entire list.
    deleteList(&newList);

    return EXIT_SUCCESS;
}

// Function to create node dynamically.
node* createNode(DATA_TYPE value)
{
    node* newNode = (node*)malloc(sizeof(node));
    
    if (newNode)   // Initializing the node.
    {
        newNode->data = value;
        newNode->prev = NULL;
        newNode->next = NULL;
        
        return newNode;
    }
    return NULL;
}

// Function to initialize the node
bool initNode(node* currentNode,DATA_TYPE value)
{
    if (currentNode)
    {
        currentNode->prev = NULL;
        currentNode->data = value;
        currentNode->next = NULL;

        return true;
    }
    return false;
}

// Function to create list dynamically.
dll* createList(void)
{
    dll* newList = (dll*)malloc(sizeof(dll));
    
    if (initList(newList))  // Initializing the list.
    {
        return newList;
    }
    return NULL;
}

// Finction to initialize the list
bool initList(dll* currentList)
{
    if (currentList)
    {
        currentList->head = NULL;
        currentList->tail = NULL;

        return true;
    }
    return false;
}

// Function to add at the head of list.
bool addAtHead(dll* currentList,DATA_TYPE value)
{
    node* newNode = createNode(value);
    
    if (!newNode) 
    {
        fprintf(stderr,"Memory allocation for node failed!\n");
        return false;
    }
    
    if (isEmptyList(currentList))
    {
        currentList->tail = newNode;
    }
    else
    {
        newNode->next = currentList->head;
        currentList->head->prev = newNode;
    }
    currentList->head = newNode;
    
    return true;
}

// Function to add at the head of list.
bool addAtTail(dll* currentList,DATA_TYPE value)
{
    node* newNode = createNode(value);
    
    if (!newNode)
    {
        fprintf(stderr,"Memory allocation for node failed!\n");
        return false;
    }
    
    if (isEmptyList(currentList))
    {
        currentList->head = newNode;
    }
    else
    {
        newNode->prev = currentList->tail;
        currentList->tail->next = newNode;
    }
    currentList->tail = newNode;
    
    return true;
}

// Function to delete at the head of the list.
bool deleteAtHead(dll* currentList)
{
    if (isEmptyList(currentList)) 
    {
        fprintf(stderr,"Can't delete from Empty List\n");
        return false;
    }
    
    node* tempNode = currentList->head;
    
    currentList->head = tempNode->next;
    
    if (!currentList->head)
    {
        currentList->tail = NULL;
    }
    else
    {
        currentList->head->prev = NULL;
    }
    free(tempNode);
    
    return true;
}

// Function to delete at the tail of the list.
bool deleteAtTail(dll* currentList)
{
    if (isEmptyList(currentList)) 
    {
        fprintf(stderr,"Can't delete from Empty List\n");
        return false;
    }
    
    node* tempNode = currentList->tail;
    
    currentList->tail = tempNode->prev;
    
    if (!currentList->tail)
    {
        currentList->head = NULL;
    }
    else 
    {
        currentList->tail->next = NULL;
    }
    free(tempNode);
    
    return true;
}

// Function to check list is empty or not.
bool isEmptyList(const dll* currentList)
{
    return currentList->head == NULL && currentList->tail == NULL;
}

// Function to traverse the list in forward manner.
bool traverseListForward(const dll* currentList)
{
    if (isEmptyList(currentList))
    {
        fprintf(stderr,"Can't traverse empty List!\n");
        return false;
    }
    
    node* nodePtr = currentList->head;
    
    fprintf(stdout,"List (Forwardsie) : NULL <-> ");
    
    while (nodePtr)
    {
        fprintf(stdout,"%d <-> ",nodePtr->data);
        nodePtr = nodePtr->next;
    }
    
    fprintf(stdout,"NULL\n");
    
    return true;
}

// Function to traverse the list in backward manner.
bool traverseListBackward(const dll* currentList)
{
    if (isEmptyList(currentList))
    {
        fprintf(stderr,"Can't traverse empty List!\n");
        return false;
    }
    
    node* nodePtr = currentList->tail;
    
    fprintf(stdout,"List (Backwarwise) : NULL <-> ");
    
    while (nodePtr)
    {
        fprintf(stdout,"%d <-> ",nodePtr->data);
        nodePtr = nodePtr->prev;
    }
    
    fprintf(stdout,"NULL\n");
    
    return true;
}

// Function to delete entire dynamically located list.
void deleteList(dll** list_Ptr) 
{
    if (*list_Ptr)
    {
        while (!isEmptyList(*list_Ptr))
        {
            deleteAtHead(*list_Ptr);
        }
        free(*list_Ptr);
    }
    *list_Ptr = NULL;
}