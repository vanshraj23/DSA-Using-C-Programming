/*
    Author : Vansh Raj Bir.
    Dtae   : 19-02-2025
    Topic  : Binary Search Algorithm.
*/

#include<stdio.h>

// Function to find the target in given array.
int search(const int*,int,int);

int main(void)
{
    int array[] = {10,11,12,13,14,15,16,17,18,19};
    int length = sizeof(array) / sizeof(array[0]);
    
    int target;
    
    printf("Enter the target : ");
    scanf("%d",&target);
    
    int targetIndex = search(array,length,target);
    
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

// time complexity O(logn), where n is length of array.
// space complexity O(1) constant.

int search(const int* array,int length,int target)
{
    int lowRange = 0;
    int highRange = length;

    while (lowRange <= highRange)
    {
        int mid = lowRange + (highRange - lowRange) / 2;   // Bisecting the array. 

        if (array[mid] == target)
        {
            return mid;                          // Returns mid fi target found.
        }
        else if (array[mid] > target)
        {
            highRange = mid - 1;                // Setting Left section array for search.
        }
        else
        {
            lowRange = mid + 1;                  // Setting right section array for search. 
        }
    }
    
    return -1;                                   // Returns -1 if taget not found. 
}