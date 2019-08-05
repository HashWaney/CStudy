//
// Created by Hash on 2019-08-05.
// Copyright (c) 2019 @https://github.com/HashWaney All rights reserved.
//

#include "stdlib.h"
#include "stdio.h"
#include "stdbool.h"
#include "string.h"

void readFileData(FILE *pFile,int num,char **pString);
void printData(char **pString,int num);
void freeSpace(char **pString,int num);
int getFilelineNum(FILE* file)
{
    if (file==NULL)
    {
        printf("文件打开失败");
        return -1;
    }
    int num =0;
    char buffer[1024];
    while (fgets(buffer,1024,file)!=NULL)
    {
        printf("%s",buffer);
        num++;
    }
    //文件光标处理，放置头部
    fseek(file,0,SEEK_SET);
    return num;
}

void readFileData(FILE *pFile,int num,char **pString) {
    if (pFile == NULL || num < 0 || pString == NULL){
        printf("参数错误");
        return;
    }
    int index=0;
    char buffer[1024];
    while (fgets(buffer,1024,pFile)!=NULL)
    {
        int currentLen = strlen(buffer)+1;
        char *current =malloc(sizeof(char*)*currentLen);
        strcpy(current,buffer);
        pString[index++] =current;//把从file 里面读取的数据通过二级指针pString存放在堆区
        //清空缓冲区
        memset(buffer,0,1024);
    }

}

void printData(char **pString,int num)
{
    for (int i = 0; i < num; i++) {
        printf("\n第%d行的数据是%s",i+1,pString[i]);

    }
}

void freeSpace(char **pString,int num)
{
    for(int i =0;i<num;i++)
    {
        if(pString[i]!=NULL)
        {
            free(pString[i]);
            pString[i]=NULL;
        }
    }
    free(pString);
    pString=NULL;
}

int main()
{
    printf("===begin===\n");
    FILE* file =fopen("../text.txt","r");
    if (file==NULL)
    {
        printf("文件打开失败");
        return-1;

    }
    int num =getFilelineNum(file);
    char** pArrays=malloc(sizeof(char*)*num);
    readFileData(file,num,pArrays);
    printData(pArrays,num);
    freeSpace(pArrays,num);
    pArrays=NULL;

}