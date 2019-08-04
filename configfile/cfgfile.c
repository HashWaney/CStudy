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
        fp =fopen(fileName,"w+t");
        if (fp==NULL)
        {
            rv=-3;
            printf("fopen() err.\n");
            goto End;
        }
    }
    fseek(fp,0L,SEEK_END);//把文件指针从0位置开始，移动到文件末尾
    //获取文件长度
    length =ftell(fp);
    fseek(fp,0L,SEEK_SET);
    if (length>1024*8)
    {
        rv=-3;
        printf("文件超过8m，不支持");
        goto End;
    }

    while(!feof(fp))
    {
        //读每一行
        memset(lineBuf,0, sizeof(lineBuf));
        //key关键字是否在本行
        pTmp = strstr(lineBuf,key);
        if(pTmp==NULL)
        {
            //key 不在本行，copy到filebuf中
            strcat(filebuf,lineBuf);
            continue;

        }else{
            //key在本行中，替换旧的行，在copy到filebuf中
            sprintf(lineBuf,"%s=%s\n",key,value);
            strcat(filebuf,lineBuf);
            //存在key
            iTag=1;

        }
    }

    //key关键字不存在，追加
    if (iTag==0)
    {
       fprintf(fp,"%s = %s\n",key,value);
    }else{//存在key关键字，则重新创建文件
        if (fp!=NULL)
        {
            fclose(fp);
            fp=NULL;//避免野指针
        }
        fp =fopen(fileName,"w+t");
        if (fp==NULL)
        {
            rv=-4;
            printf("fopen() err. \n");
            goto End;
        }
        fputs(filebuf,fp);

    }

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
    int   ret =0;
    FILE  *fp =NULL;
    char  *pTmp=NULL,*pEnd=NULL,*pBegin=NULL;
    char  lineBuf[MaxLine];

    fp = fopen(fileName,"r");
    if (fp==NULL)
    {
        ret =-1;
        return  ret;
    }
    while (!feof(fp))
    {
        memset(lineBuf,0, sizeof(lineBuf));
        fgets(lineBuf,MaxLine,fp);
        printf("--------->lineBuf:%s ",lineBuf);
        pTmp = strchr(lineBuf,'=');
        if (pTmp==NULL){//没有=号
            continue;
        }
        pTmp = strstr(lineBuf,key);
        if(pTmp==NULL)//判断所在行是否有key
        {
            continue;
        }
        pTmp =pTmp + strlen(key);
        pTmp =strchr(pTmp,'=');
        if (pTmp==NULL)//判断key是不是在所在行
        {
            continue;
        }
        pTmp =pTmp+1;
        printf("pTmp: %s ",pTmp);
        //获取value起点
        while (1)
        {
            if (*pTmp==' '){
                pTmp++;
            } else{
                pBegin=pTmp;
                if(*pBegin=='\n')
                {
                    printf("未配置value：%s",key);
                    goto End;
                }

                break;
            }
        }
        //获取value结束点
        while(1)
        {
            if((*pTmp == ' ' || *pTmp == "\n"))
            {
                break;
            } else{
                pTmp++;
            }
        }
        pEnd =pTmp;
        //赋值
        *value = pEnd-pBegin;
        memcpy(value,pBegin,pEnd-pBegin);

    }

    End:
    if(fp==NULL)
    {
        fclose(fp);
    }
    return 0;




}