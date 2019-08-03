//
// Created by Hash on 2019-08-03.
//


#include "stdlib.h"
#include "stdio.h"
#include "string.h"
#include "stdbool.h"

void testfunction();
void allocaMemory(int **pInt);
void printArray(int **pInt,int i);
/**
 *
 * ----begin----
0
0
0
0
-1249771504
32767
2108813718
32767
-1249758872
32767
 */

int main()
{
    
   printf("----begin----\n");
   testfunction();
    
}
void testfunction()
{
    int* p =NULL;
    allocaMemory(&p);
    printArray(&p,10);
}
void printArray(int **p,int i)
{
    for(int j=0;j<i;j++)
    {
        printf("%d\n",(*p)[j]);
    }
}

void allocaMemory(int **p)
{
    printf("get the size of value %d:", sizeof(int)*10);
    //int 4个字节 malloc（40）
    int* arr =malloc(sizeof(int)*10);
    for(int i=0;i<10;++i)
    {
        arr[i]=i+=100;
    }
    *p =arr;
}