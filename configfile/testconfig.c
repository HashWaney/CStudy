//
// Created by Hash on 2019-08-03.
// Copyright (c) 2019 @https://github.com/HashWaney All rights reserved.
//

#include "stdio.h"
#include "string.h"
#include "stdlib.h"
#include "file.h"
#define CONFIGFILENAME "/Users/wangqing/Desktop/C:C++/Demo/configfile/cfg.ini"

void print();

int WriteCfgFile();

int ReadCfgFile();

void main()
{
    int num=0;
//    for(;;)
//    {
//    //print（）；
//
//    }
    scanf("%d",&num);
    printf("输入的数字:%d\n",num);
    switch (num)
    {
        case 1:
            printf("1触发");
            ReadCfgFile();
            break;
        case 2:
            printf("2触发");
            WriteCfgFile();
            break;
        case 0:
        default:
            exit(0);
    }
}
int ReadCfgFile()
{
    int ret =0;
    //读取配置
    char name[1024] ={0};
    char value[1024]={0};

    int vlen=0;
    printf("\n请键入key：");
    scanf("%s",name);
    ret = readFile(CONFIGFILENAME,name,value,&vlen);
    if (ret!=0)
    {
        printf("func writeCfgFile err:%d\n",ret);
        return ret;
    }
    printf("value:%s \n",value);
}

int WriteCfgFile()
{
    int ret =0;
    //写配置项
    char name[1024] ={0};
    char value[1024]={0};

    printf("\n请键入key:");
    scanf("%s",&name);
    printf("\n请键入value：");
    scanf("%s",&value);
    ret = writeFile(CONFIGFILENAME,name,value,strlen(value));
    if (ret!=0)
    {
        printf("function writeCfg err:%d \n",ret);
        return ret;
    }
    printf("你输入的是:%s = %s\n",name,value);
    return ret;

}
void print()
{
    printf("-------读写配置文件------\n");
    printf("1--->写配置文件\n");
    printf("2--->读配置文件\n");
    printf("0--->退出\n");
    printf("----开始----\n");
}
