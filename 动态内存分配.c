//
// Created by 王庆 on 2019-08-03.
//

#include "printf.h"
#include "stdlib.h"

void function();
int  function2();
int main() {
//    function();
function2();
    return -1;
}
void function()
{
    int len;
    printf("请输入首次分配的内存大小：");
    scanf("%d", &len);
    int *p = (int *) malloc(len * sizeof(int));
    int i = 0;
    for (; i < len; i++){
        p[i]=rand()%100;
        printf("array[%d] =%d ,%d\n",i,p[i],*(p+i));
    }
    //在原有内存上面，重新分配内存大小，
    printf("请输入增加的内存大小： ");
    int add;
    scanf("%d", &add);

    //1.重新申请内存大小，2.传入申请的内存指针，3.申请内存总大小，一定要注意realloc 本质上有3种意思：
    int* p2 = (int*)realloc(p,(len+add)* sizeof(int));

    //给新申请的内存空间赋值
    int j =len;
    printf("len = %d, add = %d\n",len, add);
    for(; j<len+add;j++)
    {
        p2[j] =rand()%200;
    }

    //打印 %#x 带格式输出效果为输出前加0x
    j=0;
    for(;j<len;j++)
    {
        printf("array[%d] = %d %#x\n",j,p2[j],&p2[j]);

    }
    //回收申请的动态内存
    if (p2 !=NULL){
        free(p2);
        p2=NULL;
    }

}
int  function2()
{
    int i,n;
    int *pData;
    printf("Amount of numbers to be entered:");
    scanf("%d",&i);
    pData =(int*) calloc(i, sizeof(int));
    if (pData==NULL) exit(1);
    for(n=0;n<i;n++)
    {
        printf("Enter number #%d: ",n+1);
        scanf("%d",&pData[n]);
    }
    printf ("You have entered: ");
    for(n=0;n<i;n++)
    {
        printf("%d ",pData[n]);
    }
    //释放指针
    if(pData!=NULL)
    {
        free(pData);
        pData=NULL;
    }

    return 0;


}
