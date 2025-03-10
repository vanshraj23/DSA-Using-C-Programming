/*
    Author : Vansh Raj Bir.
    Date   : 21-02-2025
    Topic  : Single Linked List Implementation.
*/

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

// For desired data type.
#define DATA_TYPE int

// Structure for the node.
typedef struct NODE {
    DATA_TYPE data;        // to hold the value.
    struct NODE* link;     // pointer to next node.
} node;

// structure for the Single linked list.
typedef struct SingleLinkedList {
    node* head;            // to keep the track of head of the list.
} sll;

// Functions prototypes
node* createNode(DATA_TYPE);
bool initNode(node*,DATA_TYPE);
sll* createList(void);
bool initList(sll*);
bool addAtHead(sll*,DATA_TYPE);
bool addAtTail(sll*,DATA_TYPE);
bool deleteAtHead(sll*);
bool deleteAtTail(sll*);
bool isEmptyList(const sll*);
bool traverseList(const sll*);
void deleteList(sll**);

int main(void)
{
    // dyanmic list creation.
    sll* newList = createList();
    
    if (!newList)
    {
        fprintf(stderr,"Memory allocation failed for the List!\n");
        exit(EXIT_FAILURE);  // Exit the program.
    }
    
    // adding at the head of the list.
    for (int i = 5; i >= 0; --i)
    {
        if (!addAtHead(newList,i))
        {
            fprintf(stderr,"Couldn't add %d at head of the list!\n",i);
            break;
        }
    }
    
    // adding at the tail of the list.
    for (int i = 6; i <= 11; i++)
    {
        if (!addAtTail(newList,i))
        {
            fprintf(stderr,"Couldn't add %d at tail of the list!\n",i);
            break;
        }
    }
    
    // list traversing.
    traverseList(newList);
    
    // deleting at the head of the list.
    deleteAtHead(newList);
    // deleting at the tail of the list.
    deleteAtTail(newList);
    
    // list traversing.
    traverseList(newList);
    
    // deleting entire list.
    deleteList(&newList);
    
    return EXIT_SUCCESS;
}

// Function to create node dynamically.
node* createNode(DATA_TYPE value)
{
    node* newNode = (node*)malloc(sizeof(node));
    
    if (initNode(newNode,value))
    {
        return newNode;
    }
    return NULL;
}

// Function to initialise the node.
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

// Function to create list dynamically.
sll* createList(void)
{
    sll* newList = (sll*)malloc(sizeof(sll));
    
    if (initList(newList))
    {        
        return newList;
    }
    return NULL;
}

// Function to initialise the List.
bool initList(sll* currentList)
{
    if (currentList)
    {
        currentList->head = NULL;

        return true;
    }
    return false;
}

// Function to add at the head of the list.
bool addAtHead(sll* currentList,DATA_TYPE value)
{
    node* newNode = createNode(value);
    
    if (!newNode) return false;
    
    newNode->link = currentList->head;
    currentList->head = newNode;
    
    return true;
}

// Function to add at the tail of the list.
bool addAtTail(sll* currentList,DATA_TYPE value)
{
    node* newNode = createNode(value);
    
    if (!newNode) return false;

    node* nodePtr = currentList->head;

    if (isEmptyList(currentList))
    {
        currentList->head = newNode;
    }
    else
    {
        while (nodePtr->link)         // Traversing to the last node.
        {
            nodePtr = nodePtr->link;
        }
        nodePtr->link = newNode;
    }

    return true;
}

// Function to delete at the head of the list.
bool deleteAtHead(sll* currentList)
{
    if (isEmptyList(currentList)) return false;
    
    node* tempNode = currentList->head;
    currentList->head = tempNode->link;
    
    free(tempNode);
    
    return true;
}

// Function to delete at the tail of the list.
bool deleteAtTail(sll* currentList)
{
    if (isEmptyList(currentList)) return false;
    
    node* tempNode = NULL;
    
    if (!currentList->head->link)         // For atleast one node.
    {
        tempNode = currentList->head;
        currentList->head = NULL;
    }
    else
    {
        node* nodePtr = currentList->head;
    
        while (nodePtr->link->link)       // For the second last node.
        {
            nodePtr = nodePtr->link;
        }
    
        tempNode = nodePtr->link;
        nodePtr->link = NULL;
    }
    free(tempNode);

    return true;
}

// Function to check list is empty or not.
bool isEmptyList(const sll* currentList)
{
    return currentList->head == NULL;
}

// Function to traverse the list. 
bool traverseList(const sll* currentList)
{
    if (currentList)
    {
        node* nodePtr = currentList->head;

        fprintf(stdout,"List : ");
        
        while (nodePtr)
        {
            fprintf(stdout,"%d->",nodePtr->data);
            nodePtr = nodePtr->link;
        }
        
        fprintf(stdout,"NULL\n");

        return true;
    }
    return false;
}

// Function to delete the entire list.
void deleteList(sll** list_Ptr) 
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