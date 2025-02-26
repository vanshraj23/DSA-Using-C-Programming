/*
    Author : Vansh Raj Bir.
    Dtae   : 19-02-2025
    Topic  : Linear Search Algorithm Using Recusrion.
*/

#include<stdio.h>

// Function to find the target in given array.
int search(const int*,int,int,int);

int main(void)
{
    int array[] = {9,7,6,4,3,1,0,2,5,8};
    int length = sizeof(array) / sizeof(array[0]);
    
    int target;
    
    printf("Enter the target : ");
    scanf("%d",&target);
    
    int targetIndex = search(array,0,length,target);
    
    if (targetIndex != -1)
    {
        printf("%d found at index %d.\n",target,targetIndex);
    }
    else
    {
        printf("%d is not found in index!\n",target);
    }
    
    return 0;
}

/* 
time complexity O(n)
space complexity O(1) constant
where n is length of array. 
*/

int search(const int* array,int index,int length,int target)
{
    if (index <= length)
    {
        if (array[index] == target)
        {
            return index;      // Returns index if target found.                         
        }
        return search(array,index + 1,length,target);     // propels the search in the array.   
    }
    
    return -1;                 // Returns -1 if target not found.
}