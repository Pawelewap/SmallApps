/* INCLUDES */
#include <stdio.h>
#include <stdint.h>

/* CONSTS */
static const ARRAY_SIZE = 5;
static const NOT_FOUND = -1;

/* @ Bubble sort function
 * void function
 * par0: pointer to an array (with integer values)
 * size of array given by static const
*/
void sort(int8_t arr[])
{
    for(int8_t i = 0; i < ARRAY_SIZE; i++)
    {
        for(int8_t j = 0; j < (ARRAY_SIZE - 1); j++)
        {
            if(arr[j] > arr[j + 1])
            {
                arr[j]     ^= arr[j + 1];
                arr[j + 1] ^= arr[j];
                arr[j]     ^= arr[j + 1];
            }
        }
    }
}

/* @ Binary search function
 * par0: pointer to an array (with integer values)
 * par1: number to find in array
 * returns the position of searched number if found
 * returns NOT_FOUND (-1) if not found
 * size of the array given by static const
*/
int8_t binarySearch(const int8_t arr[], int8_t find)
{
    int8_t start = 0;
    int8_t end = ARRAY_SIZE - 1;
    int8_t ret = NOT_FOUND;

    do
    {
       int8_t mid = ((start + end) / 2);

       if(arr[mid] == find)
       {
           ret = mid;
           break;
       }
       else if(arr[mid] > find)
       {
           end = mid - 1;
       }
       else if(arr[mid] < find)
       {
           start = mid + 1;
       }
    }while(start <= end);

    return ret;
}


int main()
{
    int8_t arr[] = {0,9,4,7,2};
    int8_t find = 7;

    sort(arr); /* execute sort before binarySearch */
    int8_t position = binarySearch(arr, find);

    if(position != NOT_FOUND)
    {
        printf("Found on position %d\n", position);
    }
    else
    {
        printf("NOT FOUND!\n");
    }

    return 0;
}
