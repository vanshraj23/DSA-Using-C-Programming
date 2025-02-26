/*
    Author : Vansh Raj Bir.
    Dtae   : 19-02-2025
    Topic  : Binary Search Algorithm Using Recursion.
*/

#include<stdio.h>

// Function to find the target in given array.
int search(const int*,int,int,int);

int main(void)
{
    int array[] = {0,1,2,3,4,5,6,7,8,9};
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
time complexity O(logn).
space complexity O(logn).
where n is length of array.
*/

int search(const int* array,int lowRange,int length,int target)
{
    int highRange = length;

    if (lowRange <= highRange)
    {
        int mid = lowRange + (highRange - lowRange) / 2;

        if (array[mid] == target)
        {
            return mid;                  // Returns mid if target found. 
        }
        else if (array[mid] > target)
        {
            highRange = mid - 1;        // Setting Left section array for search.
        }
        else
        {
            lowRange  = mid + 1;        // Setting right section array for search. 
        }
        return search(array,lowRange,highRange,target);
    }
    
    return -1;  // Returns -1 if target found.
}