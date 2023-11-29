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

//1.����˳���
Status InitList(SqList &L)
{
    L.elem = (ElemType*)malloc(LIST_INIT_SIZE * sizeof(ElemType));
    if (!L.elem)
        return ERROR;
    L.length = 0;
    L.listsize = LIST_INIT_SIZE;
    return OK;
}

//2.����˳���
Status DestroyList(SqList &L)
{
    if (L.elem)
        free(L.elem);
    if (L.elem == NULL)
        return OK;
    else
        return ERROR;
}
//3.���˳���
void ClearList(SqList &L)
{
    L.length = 0;
}
//4.�ж�˳����Ƿ�ձ�
Status ListEmpty(SqList L)
{
    if (L.length == 0)
        return ERROR;
    else
        return OK;
}
//5.˳������
Status ListLength(SqList L)
{
    return L.length;
}
//6.˳����ȡԪ��
Status GetElem(SqList L,int i,ElemType &e)
{
    //ȡ��˳����е�i��Ԫ��e
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

//7.˳���Ķ�λ
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

//8.����ǰ��
Status PriorElem(SqList L,ElemType cur_e,ElemType &pre_e)
{
    int *p;
    int i=1;
    p = L.elem + 1;//���ڶ���Ԫ�صĵ�ַ��ֵ��p
    while(i < L.length && compare(cur_e, L.elem[i - 1]))
    {
        p++;
        i++;
    }
    if (i > L.length)
        return ERROR;
    else
    {
        pre_e = L.elem[i];  //ע��i
        return pre_e;//����Ԫ�ط��ظ�Ҫ���õĺ���
    }
}
//9.���غ��
Status NextElem(SqList L,ElemType cur_e,ElemType &next_e)
{
    int i = 0;//i�ĳ�ֵ�ǵ�һ��Ԫ�ص�λ��
    int *p = L.elem;//��һ��Ԫ�صĵ�ַ��ֵ��p
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
        return next_e;//����Ԫ�ط��ظ�������
    }
}
//10.����Ԫ��
Status ListInsert(SqList &L,int i,ElemType e)
{
    ElemType *p, *q, *newbase;
    if (i<1 )
        return ERROR;
    if(L.length>=L.listsize)
    {

        if (!(newbase = (ElemType*)realloc(L.elem,(L.listsize+LISTINCREMENT)*sizeof(ElemType))))
            exit(0);//����洢�ռ�ʧ��
        L.elem = newbase;//�»�ַ
        L.listsize += LISTINCREMENT;//���Ӵ洢����
        cout<<"���·����ڴ�ɹ�";
    }
    q = L.elem + i - 1;//qΪ����λ��
    for (p = L.elem + L.length - 1; p >= q; --p)
    {
        *(p + 1) = *p;//������λ��֮���Ԫ�ظ�ֵ�ﵽ֮��Ԫ�غ���һλ��Ч��
    }
    *q = e;//����e
    ++L.length;
    return OK;
}
//11.ɾ��Ԫ��
Status ListDelete(SqList &L,int i,ElemType &e)
{
    if (i<1 || i>L.length)//iֵ���Ϸ�
        return ERROR;
    ElemType *p, *q;
    p = L.elem + i - 1;//pΪ��ɾ��Ԫ�ص�λ��
    e = *p;            //��ɾ��Ԫ�ص�ֵ����e
    q = L.elem + L.length - 1;//q�Ǳ�βԪ�ص�λ��
    p = p + 1;
    for ( ; p <= q; p++)
        *(p - 1) = *p;
    L.length--;  //����һ
    return OK;
}
//12.����
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
//��ʼ��L;
   InitList(L);
   printf("��ʼ��L��L.elem=%u L.length=%d L.listsize=%d\n",L.elem,L.length,L.listsize);
//��L�ı�ͷ���β���1��5����������Ļ���������5��Ԫ��
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
    //�ж�L�Ƿ�Ϊ��;
i=!ListEmpty(L);
   printf("L�Ƿ�գ�i=%d(1:�� 0:��)\n",i);
//���L;
ClearList(L);
   printf("���L��L.elem=%u L.length=%d L.listsize=%d\n",L.elem,L.length,L.listsize);
//�ж�L�Ƿ�Ϊ��;
i=!ListEmpty(L);
   printf("L�Ƿ�գ�i=%d(1:�� 0:��)\n",i);
//��L�ı�β���β���1��10,��������Ļ���������10��Ԫ��
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
//��L�ı�ͷ����0,��������Ļ���������11��Ԫ��
/*
    e=0;
    ListInsert(L,1,e);
    for(int j=1;j<=11;j++)
    {
        GetElem(L,j,e);
        cout<<e<<endl;
    }
*/


   printf("L.elem=%u(�п��ܸı�) L.length=%d(�ı�) L.listsize=%d(�ı�)\n",L.elem,L.length,L.listsize);
// ȡ���Ա��еĵ�5��Ԫ�أ���������Ļ�����
   // GetElem(L,5,e);
    //cout<<e<<endl;
   for(j=3;j<=4;j++)
   {  k=LocateElem(L,j,comp);
     if(k)
       printf("��%d��Ԫ�ص�ֵΪ%d��ƽ��\n",k,j);
     else
       printf("û��ֵΪ%d��ƽ����Ԫ��\n",j);
   }
   for(j=1;j<=2;j++) // ����ͷ��������
   {  // �ѵ�j�����ݸ���e0
       GetElem(L,j,e0);
      // ��e0��ǰ��
     if(i==INFEASIBLE)
       printf("Ԫ��%d��ǰ��\n",e0);
     else
       printf("Ԫ��%d��ǰ��Ϊ��%d\n",e0,e);
   }
   for(j=ListLength(L)-1;j<=ListLength(L);j++)
   {  // �ѵ�j�����ݸ���e0
      // ��e0�ĺ��
     if(i==INFEASIBLE)
       printf("Ԫ��%d�޺��\n",e0);
     else
       printf("Ԫ��%d�ĺ��Ϊ��%d\n",e0,e);
   }
   // ���k
   for(j=k+1;j>=k;j--)
   {  // ɾ����j������
     if(i==ERROR)
       printf("ɾ����%d������ʧ��\n",j);
     else
       printf("ɾ����Ԫ��ֵΪ��%d\n",e);
   }
   printf("�������L��Ԫ�أ�");
   // ���ζ�Ԫ�ص���visit()�����Ԫ�ص�ֵ
   printf("L��Ԫ��ֵ�ӱ���");
   // ���ζ�Ԫ�ص���dbl()��Ԫ��ֵ��2
  // ���ζ�Ԫ�ص���visit()�����Ԫ�ص�ֵ
 //����L
 DestroyList(L);
   printf("����L��L.elem=%u L.length=%d L.listsize=%d\n",L.elem,L.length,L.listsize);
   }

