//
// Created by Hash on 2019-08-03.
// 一个简单的对称加解密算法
//
#include "stdio.h"
#include "string.h"
/**
 * 加密
 * @param nomarl_path
 * @param crpyt_path
 * @param password
 */
void crypt(char normal_path[],char crypt_path[],char password[]){
    //打开文件
    FILE *normal_fp =fopen(normal_path,"rb"); //read buffer
    FILE *crypt_fp =fopen(crypt_path,"wb");//writer buffer

    //一次读取一个字符
    int ch;
    int  i =0;//循环使用密码中的字母进行异或运算
    int pwd_len = strlen(password);//密码长度
    while((ch =fgetc(normal_fp))!=EOF)
    {
        //写入异或运算
        fputc(ch^password[i%pwd_len],crypt_fp);
        i++;
    }
    //关闭
    fclose(crypt_fp);
    fclose(normal_fp);
}
/**
 * 解密
 * @param crypt_path
 * @param decrypt_path
 * @param password
 */
void decrypt(char crypt_path[],char decrypt_path[],char password[])
{
    //打开文件
    FILE *normal_fp = fopen(crypt_path,"rb");
    FILE *crypt_fp=fopen(decrypt_path,"wb");

    //一次读取一个字符
    int ch;
    int i =0;
    int pwd_len= strlen(password);
    while((ch = fgetc(normal_fp))!=EOF)
    {
        //写入（异或运算）
        fputc(ch^password[i%pwd_len],crypt_fp);
        i++;

    }
    //关闭
    fclose(crypt_fp);
    fclose(normal_fp);
}


int  main(){
    char *normal_path="/Users/wangqing/Desktop/C:C++/Demo/encryption/cfg.ini";
    char *crypt_path="/Users/wangqing/Desktop/C:C++/Demo/encryption/cfg_crypt.ini";
    char *decrypt_path="/Users/wangqing/Desktop/C:C++/Demo/encryption/cfg_decrypt.ini";

    //加密
    char* str="1234567890abcdefghijklmnopqrstuvwxyz";
    crypt(normal_path,crypt_path,str);
    //解密
    decrypt(crypt_path,decrypt_path,str);
    return   getchar();


}