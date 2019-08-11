//
// Created by Hash on 2019-08-07.
// Copyright (c) 2019 @https://github.com/HashWaney All rights reserved.
//
#include "stdbool.h"
#include "string.h"
#include "stdio.h"
#include "stdlib.h"

#define BUFFSIZE 1024//缓冲区大小

void testBasicAPI();

bool cpyFile(const char* srcFile, const char* destFile){
    FILE *src,*dst;
    if (NULL==srcFile|| NULL==destFile){
        printf("cpyFile src or dest file null!");
        return  false;
    }
    src = fopen(srcFile,"rb");
    dst = fopen(destFile,"wb");
    if (NULL==src || NULL == dst){
        printf("cpyFile fopen failed");
        return  false;
    }

    char *buff = alloca(BUFFSIZE);
    int len;
    while (len =fread(buff, sizeof(char),1,src)!=0){//fos fis
        fwrite(buff,len,1,dst);
        printf("---%3d+++++++",len);
    }
    fclose(src);
    fclose(dst);
    return true;
}

void testBasicAPI()
{
    printf("开始测试file的api\n");
    const  char * filePath  ="/Users/wangqing/Desktop/C:C++/Demo/operatefile/test.txt";
    char ch;
    char out[] ={"abcdefg"};
    FILE* file = fopen(filePath,"r+");
    if (file!=NULL){
        while ((ch=fgetc(file))!=EOF){
            printf("start:%3c\n",ch);
        }
        //写入char字符串信息
        for (int i = 0; i <7; i++) {
            printf("返回值：%d\n",fputc(out[i],file));
        }
        //EOF end of file 文件结束
        while ((ch=fgetc(file))!=EOF){
            printf("end:%3c\n",ch);
        }
    }
}

void main()
{
    testBasicAPI();
  // cpyFile("/Users/wangqing/Desktop/C:C++/Demo/operatefile/src.txt","/Users/wangqing/Desktop/C:C++/Demo/operatefile/desc.txt");
}

