#include<stdio.h>
#include<bits/stdc++.h>
#include<stdlib.h>
#include<string.h>
#include<malloc.h>
#include<stdio.h>
#define TRUE   1
#define FALSE  0
#define OK     1
#define ERROR  0
#define INFEASIBLE -1
#define OVERFLOW   -2
typedef  int   Status;
typedef  int ElemType;

#define LIST_INIT_SIZE 10
#define LISTINCREMENT   2
using namespace std;
typedef struct
{
    ElemType  *elem;
    int      length;
    int    listsize;
}SqList;

//1.构造顺序表
Status InitList(SqList &L)
{
    L.elem = (ElemType*)malloc(LIST_INIT_SIZE * sizeof(ElemType));
    if (!L.elem)
        return ERROR;
    L.length = 0;
    L.listsize = LIST_INIT_SIZE;
    return OK;
}

//2.销毁顺序表
Status DestroyList(SqList &L)
{
    if (L.elem)
        free(L.elem);
    if (L.elem == NULL)
        return OK;
    else
        return ERROR;
}
//3.清空顺序表
void ClearList(SqList &L)
{
    L.length = 0;
}
//4.判断顺序表是否空表
Status ListEmpty(SqList L)
{
    if (L.length == 0)
        return ERROR;
    else
        return OK;
}
//5.顺序表求表长
Status ListLength(SqList L)
{
    return L.length;
}
//6.顺序表的取元素
Status GetElem(SqList L,int i,ElemType &e)
{
    //取出顺序表中第i个元素e
    if (i<1 || i>L.length)
        return ERROR;
    else
        e = L.elem[i - 1];
    return OK;
}
//compare
Status compare(int e1, int e2)
{
    if (e1 == e2)
        return OK;
    else
        return ERROR;
}

//7.顺序表的定位
Status LocateElem(SqList L,ElemType e,Status(*compare)(ElemType,ElemType))
{
    int i = 1;
    while (i <= L.length&&L.elem[i - 1] != e)
    {
        i++;
    }
    if (i > L.length)
        return ERROR;
    else
        return i;
}

//8.返回前驱
Status PriorElem(SqList L,ElemType cur_e,ElemType &pre_e)
{
    int *p;
    int i=1;
    p = L.elem + 1;//将第二个元素的地址赋值给p
    while(i < L.length && compare(cur_e, L.elem[i - 1]))
    {
        p++;
        i++;
    }
    if (i > L.length)
        return ERROR;
    else
    {
        pre_e = L.elem[i];  //注意i
        return pre_e;//将此元素返回给要调用的函数
    }
}
//9.返回后继
Status NextElem(SqList L,ElemType cur_e,ElemType &next_e)
{
    int i = 0;//i的初值是第一个元素的位序
    int *p = L.elem;//第一个元素的地址赋值给p
    while (i < L.length && !compare(cur_e, L.elem[i]))
    {
        p++;
        i++;
    }
    if (i == L.length)
    {
        return ERROR;
    }
    else
    {
        next_e = *(++p);
        return next_e;//将此元素返回给主函数
    }
}
//10.插入元素
Status ListInsert(SqList &L,int i,ElemType e)
{
    ElemType *p, *q, *newbase;
    if (i<1 )
        return ERROR;
    if(L.length>=L.listsize)
    {

        if (!(newbase = (ElemType*)realloc(L.elem,(L.listsize+LISTINCREMENT)*sizeof(ElemType))))
            exit(0);//分配存储空间失败
        L.elem = newbase;//新基址
        L.listsize += LISTINCREMENT;//增加存储容量
        cout<<"重新分配内存成功";
    }
    q = L.elem + i - 1;//q为插入位置
    for (p = L.elem + L.length - 1; p >= q; --p)
    {
        *(p + 1) = *p;//给插入位置之后的元素赋值达到之后元素后移一位的效果
    }
    *q = e;//插入e
    ++L.length;
    return OK;
}
//11.删除元素
Status ListDelete(SqList &L,int i,ElemType &e)
{
    if (i<1 || i>L.length)//i值不合法
        return ERROR;
    ElemType *p, *q;
    p = L.elem + i - 1;//p为被删除元素的位置
    e = *p;            //被删除元素的值赋给e
    q = L.elem + L.length - 1;//q是表尾元素的位置
    p = p + 1;
    for ( ; p <= q; p++)
        *(p - 1) = *p;
    L.length--;  //表长减一
    return OK;
}
//12.遍历
Status ListTraverse(SqList L,void(*vi)(ElemType&))
{
    ElemType *p = L.elem;
    int i;
    for (i = 1; i <= L.length; i++)
        printf("%d ",*p++);
    printf("\n");
    return OK;
}
Status comp(ElemType c1,ElemType c2)
{
    if (c1 == (c2*c2))
        return TRUE;
    else
        return FALSE;
}
int main()
 {
     SqList L;
   ElemType e,e0;
   Status i;
   int j,k;
//初始化L;
   InitList(L);
   printf("初始化L后：L.elem=%u L.length=%d L.listsize=%d\n",L.elem,L.length,L.listsize);
//在L的表头依次插入1～5，并且在屏幕上依次输出5个元素
    e=1;
    ListInsert(L,1,e);
    GetElem(L,1,e);
    cout<<e<<endl;
    e=2;
  ListInsert(L,2,e);
  GetElem(L,2,e);
  cout<<e<<endl;
  e=3;
  ListInsert(L,3,e);
  GetElem(L,3,e);
  cout<<e<<endl;
  e=4;
  ListInsert(L,4,e);
  GetElem(L,4,e);
  cout<<e<<endl;
  e=5;
  ListInsert(L,5,e);
  GetElem(L,5,e);
  cout<<e<<endl;
  printf("L.elem=%u L.length=%d L.listsize=%d\n",L.elem,L.length,L.listsize);
    //判断L是否为空;
i=!ListEmpty(L);
   printf("L是否空：i=%d(1:是 0:否)\n",i);
//清空L;
ClearList(L);
   printf("清空L后：L.elem=%u L.length=%d L.listsize=%d\n",L.elem,L.length,L.listsize);
//判断L是否为空;
i=!ListEmpty(L);
   printf("L是否空：i=%d(1:是 0:否)\n",i);
//在L的表尾依次插入1～10,并且在屏幕上依次输出10个元素
e=10;
ListInsert(L,10,e);
GetElem(L,10,e);
cout<<e<<endl;
e=9;
ListInsert(L,9,e);
GetElem(L,9,e);
cout<<e<<endl;
e=8;
ListInsert(L,8,e);
GetElem(L,8,e);
cout<<e<<endl;
e=7;
ListInsert(L,7,e);
GetElem(L,7,e);
cout<<e<<endl;
e=6;
ListInsert(L,6,e);
GetElem(L,16,e);
cout<<e<<endl;
e=5;
ListInsert(L,5,e);
GetElem(L,5,e);
cout<<e<<endl;
e=4;
ListInsert(L,4,e);
GetElem(L,4,e);
cout<<e<<endl;
e=3;
ListInsert(L,3,e);
GetElem(L,3,e);
cout<<e<<endl;
e=2;
ListInsert(L,2,e);
GetElem(L,2,e);
cout<<e<<endl;
e=1;
ListInsert(L,1,e);
GetElem(L,1,e);
cout<<e<<endl;

printf("L.elem=%u L.length=%d L.listsize=%d\n",L.elem,L.length,L.listsize);
//在L的表头插入0,并且在屏幕上依次输出11个元素
/*
    e=0;
    ListInsert(L,1,e);
    for(int j=1;j<=11;j++)
    {
        GetElem(L,j,e);
        cout<<e<<endl;
    }
*/


   printf("L.elem=%u(有可能改变) L.length=%d(改变) L.listsize=%d(改变)\n",L.elem,L.length,L.listsize);
// 取线性表中的第5个元素，并且在屏幕上输出
   // GetElem(L,5,e);
    //cout<<e<<endl;
   for(j=3;j<=4;j++)
   {  k=LocateElem(L,j,comp);
     if(k)
       printf("第%d个元素的值为%d的平方\n",k,j);
     else
       printf("没有值为%d的平方的元素\n",j);
   }
   for(j=1;j<=2;j++) // 测试头两个数据
   {  // 把第j个数据赋给e0
       GetElem(L,j,e0);
      // 求e0的前驱
     if(i==INFEASIBLE)
       printf("元素%d无前驱\n",e0);
     else
       printf("元素%d的前驱为：%d\n",e0,e);
   }
   for(j=ListLength(L)-1;j<=ListLength(L);j++)
   {  // 把第j个数据赋给e0
      // 求e0的后继
     if(i==INFEASIBLE)
       printf("元素%d无后继\n",e0);
     else
       printf("元素%d的后继为：%d\n",e0,e);
   }
   // 求表长k
   for(j=k+1;j>=k;j--)
   {  // 删除第j个数据
     if(i==ERROR)
       printf("删除第%d个数据失败\n",j);
     else
       printf("删除的元素值为：%d\n",e);
   }
   printf("依次输出L的元素：");
   // 依次对元素调用visit()，输出元素的值
   printf("L的元素值加倍后：");
   // 依次对元素调用dbl()，元素值乘2
  // 依次对元素调用visit()，输出元素的值
 //销毁L
 DestroyList(L);
   printf("销毁L后：L.elem=%u L.length=%d L.listsize=%d\n",L.elem,L.length,L.listsize);
   }

