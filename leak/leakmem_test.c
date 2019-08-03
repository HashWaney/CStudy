//
// Created by 王庆 on 2019-08-03.
// 没有及时的进行内存的释放操作，分配内存空间的时候，要记住程序结束前释放申请的内存
//

#include "stdio.h"
#include "leakmem.h"
void f()
{
    MALLOC(100);

}
int main()
{
    int* p1 =(int*)MALLOC(3* sizeof(int));
    int* p2 =(int*)MALLOC(3* sizeof(int));

    f();
    p1[0]=1;
    p1[1]=2;
    p1[2]=3;
//    p2[0]=3;
//    p2[1]=2;
//    p2[2]=1;


    //内存泄漏
    FREE(p1);
    PRINT_LEAK_INFO();
    return 0;

}