 
#include<stdio.h> 

#define NUM_OFFSET 48
#define LETT_OFFSET 55
#define ARR_BUFFER 100
#define HEX_BASE 16
#define MAX_NUMBER 9

void decToHex(int toHex) 
{    
    char hexNum[ARR_BUFFER];  
    int i = 0; 
	
    while(toHex!=0) 
    {    
        int temp  = 0; 
        temp = toHex % HEX_BASE; 
           
        if(temp <= MAX_NUMBER) // numbers 0 to 9 | 48 to 57 ASCII
        { 
            hexNum[i] = temp + NUM_OFFSET; 
            i++; 
        } 
        else // letters A to F | 65 to 70 ASCII
        { 
            hexNum[i] = temp + LETT_OFFSET;
            i++; 
        } 
          
        toHex = (toHex / HEX_BASE); 
    } 

    printf("0x");  

    for(int j = (i - 1); j >= 0; j--) 
        printf("%c", hexNum[j]);
} 

int main() 
{ 
    int toHex = 255; 
      
    decToHex(toHex); 
      
    return 0; 
} 