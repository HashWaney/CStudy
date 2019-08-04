//
// Created by Hash on 2019-08-04.
// Copyright (c) 2019 @https://github.com/HashWaney All rights reserved.
//
/**
 *  指针数组 和 数组指针
 *  数组：内存中一组连续的空间；int a[5]->数组a是内存中连续的5个int类型的空间，数组名a就是这段连续空间的起始地址，同时也是第一个元素的地址-->&a[0]
 *  tips: 数据在内存中保存的基本形式，比如int a[100] int 4个字节，100*4
 *
 *  指针：指针是个地址，它是内存中一段数据的地址，
 */
#include "stdio.h"
#include "stdlib.h"
#include "unistd.h"
int main()
{
    int a[100]={0};
    printf("int 数组分配了内存空间大小：%d", sizeof(a));
    int array[2][3]={{1,2,3},{4,5,6}};
    //数组指针
    //int(*p)[n];p是一个指针，指向一个整型的一维数组，这个一维数组的长度是n
    int(*array_p)[3]=array;
    //取出5
    printf("%x\n",(unsigned int) array_p);
    printf("%x\n",(unsigned int)(array_p+1));
    printf("取出5元素 Location:%p  Size: %d\n",(*(array_p+1)+1),*(*(array_p+1)+1));
    //普通遍历
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 3; ++j) {
            printf("%d\n",array[i][j]);

        }
    }

    //求二维数组元素的最大值 *取内容（数值） &取地址
    int *p,max;
    for (p=array[0],max=*p; p<array[0]+6 ;p++)
        if (*p>max)
            max=*p;
    printf("Max=%d,array[0]数值=%d, array[0]地址=%p",max,*array[0],array[0]);





}

