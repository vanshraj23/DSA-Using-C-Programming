/*
    Author : Vansh Raj Bir.
    Date   : 10-03-2025
    Topic  : Insertion Sort Algorithm Implementation. 
*/

#include<stdio.h>

#define DATA_TYPE int   // For desired data types.

// Function prototypes.
void insertionSort(DATA_TYPE*,int);
void printArrayf(const DATA_TYPE*,int);

int main(void)
{
    DATA_TYPE array[] = {9,8,7,6,5,4,3,2,1,0};
    int length = sizeof(array) / sizeof(*array);
    
    fprintf(stdout,"Array before sorting...\n");
    printArrayf(array,length);

    insertionSort(array,length);

    fprintf(stdout,"Array after sorting...\n");
    printArrayf(array,length);
    
    return 0;
}

// Function to sort an array using insertion sort algorithm.
void insertionSort(DATA_TYPE* array, int length)
{
    if (!array || length <= 1) return;
    
    for (int i = 1; i < length; i++) 
    {
        int hole = i; 
        int keyValue = array[i];

        while (hole > 0 && array[hole - 1] > keyValue)
        {
            array[hole] = array[hole - 1];
            hole--;
        }

        array[hole] = keyValue;
    }
}

// Function to print an array in formatted manner.
void printArrayf(const DATA_TYPE* array,int length)
{
    if (!array || length <= 0) return;
    
    fprintf(stdout,"Array (%d) : {",length);
    
    for (int index = 0; index < length; ++index)
    {
        fprintf(stdout,"%d",array[index]);
        
        if (index != length - 1)
        {
            fprintf(stdout,", ");
        }
    }
    
    fprintf(stdout,"}\n");
}