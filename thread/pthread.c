//
// Created by Hash on 2019-08-17.
// Copyright (c) 2019 @https://github.com/HashWaney All rights reserved.
//
#include "stdio.h"
#include "pthread.h"
#include "unistd.h"

void* fun(void* arg)
{
    char* str =(char*) arg;
    int p=0;
    for(;p<10;p++)
    {
        printf("\n%s线程的数据是，p是%d\n",str,p);

    }
    return 1;
}
void main()
{
    printf("main thread");
    pthread_t* ptd;
    pthread_create(&ptd,NULL,fun,"0007");
    sleep(100);
    int* rval;
    pthread_join(ptd,&rval);
}