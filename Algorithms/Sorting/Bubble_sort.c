/*
    Author : Vansh Raj Bir.
    Date   : 26-02-2025
    Topic  : Bubble sort Algorithm
*/

#include<stdio.h>

#define DATA_TYPE int           // For desired data type.

// Function prototypes.
void bubbleSort(DATA_TYPE*,int);
void swap(DATA_TYPE*,DATA_TYPE*);
void printArrayf(const DATA_TYPE*,int);

int main(void)
{
    DATA_TYPE array[] = {9,8,7,6,5,4,3,2,1,0};
    int length = sizeof(array) / sizeof(*array);
    
    fprintf(stdout,"Array before sorting...\n");
    printArrayf(array,length);

    bubbleSort(array,length);

    fprintf(stdout,"Array after sorting...\n");
    printArrayf(array,length);
    
    return 0;
}

// Function to sort an array using bubble sort algorithm.
void bubbleSort(DATA_TYPE* array,int length)
{
    if (!array || length < 0) return;
    
    for (int i = 0; i < length - 1; ++i)
    {
        int isSwapped = 0;  // For already sorted array.
        
        for (int j = 0; j < length - i - 1; ++j)
        {
            if (array[j] > array[j + 1])
            {
                swap(&array[j],&array[j + 1]);

                isSwapped = 1;
            }
        }
        
        if (!isSwapped) break;  // Break the outer loop if array is sorted.
    }
}

// Function to swap two numbers.
void swap(DATA_TYPE* value1,DATA_TYPE* value2)
{
    DATA_TYPE temp = *value1;
    *value1 = *value2;
    *value2 = temp;
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