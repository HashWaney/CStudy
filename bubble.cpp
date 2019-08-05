//
// Created by Hash on 2019-08-05.
// Copyright (c) 2019 @https://github.com/HashWaney All rights reserved.
//
#include "iostream"
using namespace std;

int main()
{
    int n,a[1000];

    cout<<"请输入排序个数："<<endl;
    cin>>n;//input n num
    cout<<"请依次输入你想要排序的数字："<<endl;
    for (int i = 0; i < n; i++) {
        cin>>a[i];

    }
    //冒泡 不断的比较相邻的两个数，如果顺序错了，就交换
    for (int i= 0; i < n; i++) {
        for (int j = 1; j < n-i; j++) {
            //升序排序
            if (a[j-1]>a[j]){
                int temp = a[j];
                a[j]=a[j-1];
                a[j-1]=temp;
            }
        }
    }
    //依次输出
    cout<<"冒泡排序输出"<<endl;
    for (int i = 0; i < n;i++) {
        cout<<a[i]<<endl;

    }
    return 0;
}
