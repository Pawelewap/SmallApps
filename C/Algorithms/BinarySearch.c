#include <stdio.h>

int main()
{
    int arr[5] = {0,1,2,3,4}; // sorted array [ ----- ]
    int find = 3;
    int minPos = 0;
    int maxPos = ((sizeof(arr) / sizeof(arr[0])) - 1); // last element in array [ ----(-) ]


    while(minPos <= maxPos)
    {
        int midPos = (maxPos + minPos) / 2; // define middle of an array [ --(-)-- ]
        if(arr[midPos] == find){
            printf("Found at position %d\n", midPos);
            break;} // if found, break the loop
        else if(find > arr[midPos])
            minPos = midPos + 1; // new minimum position [ xxx(-)- ]
        else if(find < arr[midPos])
            maxPos = midPos - 1; // new maximum position [ -(-)xxx ]

    }


    if(minPos > maxPos)
        printf("NOT FOUND! \n");
}
