//
// Created by Hash on 2019-08-03.
// Copyright (c) 2019 @https://github.com/HashWaney All rights reserved.
//

#ifndef DEMO_FILE_H
#define DEMO_FILE_H

#ifdef __cplusplus
extern "C"{
#endif
//写文件
int writeFile(char* fileName, char* key, char* value,int* len);
//读文件
int readFile(char* fileName, char* key, char** value,int* len);

#ifdef __cplusplus
}
#endif


#endif //DEMO_FILE_H
