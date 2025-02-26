/*
    Author : Vansh Raj Bir.
    Date   : 26-02-2025
    Topic  : Selection sort Algorithm
*/

#include<stdio.h>

#define DATA_TYPE int           // For desired data type.

// Function prototypes.
void selectionSort(DATA_TYPE*,int);
void swap(DATA_TYPE*,DATA_TYPE*);
void printArrayf(const DATA_TYPE*,int);

int main(void)
{
    DATA_TYPE array[] = {9,8,7,6,5,4,3,2,1,0};
    int length = sizeof(array) / sizeof(*array);
    
    fprintf(stdout,"Array before sorting...\n");
    printArrayf(array,length);

    selectionSort(array,length);

    fprintf(stdout,"Array after sorting...\n");
    printArrayf(array,length);
    
    return 0;
}

// Function to sort an array using selection sort algorithm.
void selectionSort(DATA_TYPE* array,int length)
{
    if (!array || length <= 0) return;
    
    for (int i = 0; i < length - 1; ++i)
    {
        int min_Index = i;

        for (int j = i + 1; j < length; ++j)
        {
            if (array[min_Index] > array[j])
            {
                min_Index = j;
            }
        }
        
        if (i != min_Index)
        {
            swap(&array[i],&array[min_Index]);
        }
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