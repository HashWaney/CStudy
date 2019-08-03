//
// Created by Hash on 2019-08-03.
// Copyright (c) 2019 @https://github.com/HashWaney All rights reserved.
//
#include "stdio.h"
#include "string.h"
#include "stdlib.h"
#define MaxLine 2048
//写文件
int writeFile(const char* fileName, const char* key,const char* value)
{
    int     rv=0,iTag=0,length=0;
    FILE    *fp =NULL;
    char    lineBuf[MaxLine];
    char    *pTmp=NULL,*pBegin=NULL,*pEnd=NULL;
    char    filebuf[1024*8]={0};
    //1. null
    if(fileName==NULL || key==NULL || value==NULL)
    {
        rv=-1;
        printf("SetCfgItem() err .param err\n");
        goto End;

    }

    //2. open file
    fp = fopen(fileName,"r+");
    if(fp==NULL)
    {
        rv=-2;
        printf("fopen() err.\n");
    }
    if


    End:
    if (fp!=NULL)
    {
        fclose(fp);

    }
    return rv;

}


//读文件
int readFile(const char* fileName, const char* key, const char** value)
{



}