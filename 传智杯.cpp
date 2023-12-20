#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include <stdio.h>
#include <iostream>
using namespace std;
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2
typedef int Status;
typedef int ElemType;

#define LIST_INIT_SIZE 10
#define LISTINCREMENT 2
typedef struct
{
    ElemType *elem;
    int length;
    int listsize;
} SqList;

// 1.����˳���
Status InitList(SqList &L)
{
    L.elem = (ElemType *)malloc(LIST_INIT_SIZE * sizeof(ElemType));
    if (!L.elem)
        return ERROR;
    L.length = 0;
    L.listsize = LIST_INIT_SIZE;
    return OK;
}

// 2.����˳���
Status DestroyList(SqList &L)
{
    if (L.elem)
        free(L.elem);
    L.length = 0;
    L.listsize = 0;
    if (L.elem == NULL)
        return OK;
    else
        return ERROR;
}
// 3.���˳���
void ClearList(SqList &L)
{
    L.length = 0;
}
// 4.�ж�˳����Ƿ�ձ�
Status ListEmpty(SqList L)
{
    if (L.length == 0)
        return ERROR;
    else
        return OK;
}
// 5.˳������
Status ListLength(SqList L)
{
    return L.length;
}
// 6.˳����ȡԪ��
Status GetElem(SqList L, int i, ElemType &e)
{
    if (i < 1 || i > L.length)
        return ERROR;
    else
        e = L.elem[i - 1];
    return OK;
}
// �ȽϺ���
Status compare(int e1, int e2)
{
    if (e1 == e2)
        return OK;
    else
        return ERROR;
}

// 7.˳���Ķ�λ
Status LocateElem(SqList L, ElemType e, Status (*compare)(ElemType, ElemType))
{
    int i = 1;
    while (!compare(L.elem[i - 1], e))
    {
        i++;
    }
    e = L.elem[i - 1];
    if (i > L.length)
        return ERROR;
    else
        return i;
}

// 8.����ǰ��
Status PriorElem(SqList L, ElemType cur_e, ElemType &pre_e)
{
    int i = -1;
    while (i < L.length && !compare(cur_e, L.elem[i + 1]))
    {
        i++;
    }
    if (i > L.length || i < 0)
        return INFEASIBLE;
    else
    {
        pre_e = L.elem[i]; // ע��i
        return 1;          // ����Ԫ�ط��ظ�Ҫ���õĺ���
    }
}
// 9.���غ��
Status NextElem(SqList L, ElemType cur_e, ElemType &next_e)
{
    int i = 0;       // i�ĳ�ֵ�ǵ�һ��Ԫ�ص�λ��
    int *p = L.elem; // ��һ��Ԫ�صĵ�ַ��ֵ��p
    while (i < L.length && !compare(cur_e, L.elem[i]))
    {
        p++;
        i++;
    }
    if (i + 1 >= L.length)
    {
        return INFEASIBLE;
    }
    else
    {
        next_e = *(++p);
        return 1; // ����Ԫ�ط��ظ�������
    }
}
// 10.����Ԫ��
Status ListInsert(SqList &L, int i, ElemType e)
{
    ElemType *p, *q, *newbase;
    if (L.length >= L.listsize)
    {
        if (!(newbase = (ElemType *)realloc(L.elem, (L.listsize + LISTINCREMENT) * sizeof(ElemType))))
            exit(0);                 // ����洢�ռ�ʧ��
        L.elem = newbase;            // �»�ַ
        L.listsize += LISTINCREMENT; // ���Ӵ洢����
    }
    q = L.elem + i - 1; // qΪ����λ��
    for (p = L.elem + L.length - 1; p >= q; --p)
    {
        *(p + 1) = *p; // ������λ��֮���Ԫ�ظ�ֵ�ﵽ֮��Ԫ�غ���һλ��Ч��
    }
    *q = e; // ����e
    ++L.length;
    return OK;
}
// 11.ɾ��Ԫ��
Status ListDelete(SqList &L, int i, ElemType &e)
{
    if (i < 1 || i > L.length) // iֵ���Ϸ�
        return ERROR;
    ElemType *p, *q;
    p = L.elem + i - 1;        // pΪ��ɾ��Ԫ�ص�λ��
    e = *p;                    // ��ɾ��Ԫ�ص�ֵ����e
    q = L.elem + L.length - 1; // q�Ǳ�βԪ�ص�λ��
    p = p + 1;
    for (; p <= q; p++)
        *(p - 1) = *p;
    L.length--; // ����һ
    return OK;
}
// 12.����
Status ListTraverse(SqList L, void (*visit)(ElemType &))
{
    ElemType *p = L.elem;
    int i;
    for (i = 1; i <= L.length; i++)
        visit(*p++);
    printf("\n");
    return OK;
}
// �Ƚ�ƽ������
Status comp(ElemType c1, ElemType c2)
{

    if (c1 == c2 * c2)
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}
// ������
void dbl(ElemType &c)
{
    c *= 2;
}
void visit(ElemType &e)
{
    cout << e << "  ";
}
int main()
{
    SqList L;
    ElemType e, e0;
    Status i;
    int j, k;
    InitList(L);
    printf("��ʼ��L��L.elem=%u L.length=%d L.listsize=%d\n", L.elem, L.length, L.listsize);
    for (int i = 5; i >= 1; i--)
    {
        e = i;
        ListInsert(L, i, e);
    }
    printf("L.elem=%u L.length=%d L.listsize=%d\n", L.elem, L.length, L.listsize);
    i = !ListEmpty(L);
    printf("L�Ƿ�գ�i=%d(1:�� 0:��)\n", i);
    ClearList(L);
    printf("���L��L.elem=%u L.length=%d L.listsize=%d\n", L.elem, L.length, L.listsize);
    i = !ListEmpty(L);
    printf("L�Ƿ�գ�i=%d(1:�� 0:��)\n", i);
    for (int i = 1; i <= 10; i++)
    {
        e = 11 - i;
        ListInsert(L, i, e);
    }
    for (int i = 1; i <= 10; i++)
    {
        GetElem(L, i, e);
        printf("%d",e);
    }
    printf("\n");
    printf("L.elem=%u L.length=%d L.listsize=%d\n", L.elem, L.length, L.listsize);
    e = 0;
    ListInsert(L, 1, e);
    printf("L.elem=%u(�п��ܸı�) L.length=%d(�ı�) L.listsize=%d(�ı�)\n", L.elem, L.length, L.listsize);
    GetElem(L, 5, e);
    printf("%d\n",e);

    for (j = 3; j <= 4; j++)
    {
        k = LocateElem(L, j, comp);
        if (k)
            printf("��%d��Ԫ�ص�ֵΪ%d��ƽ��\n", k, j);
        else
        {
            GetElem(L, j, e);
            printf("û��ֵΪ%d��ƽ��Ԫ��\n", e);
        }
    }
    for (j = 1; j <= 2; j++)
    {
        GetElem(L, j, e0);
        i = PriorElem(L, e0, e);
        if (i == INFEASIBLE)
            printf("Ԫ��%d��ǰ��\n", e0);
        else
            printf("Ԫ��%d��ǰ��Ϊ��%d\n", e0, e);
    }
    for (j = ListLength(L) - 1; j <= ListLength(L); j++)
    {
        GetElem(L, j, e0);
        i = NextElem(L, e0, e);
        if (i == INFEASIBLE)
            printf("Ԫ��%d�޺��\n", e0);
        else
            printf("Ԫ��%d�ĺ��Ϊ��%d\n", e0, e);
    }
    k = ListLength(L);
    for (j = k + 1; j >= k; j--)
    {
        i = ListDelete(L, j, e);
        if (i == ERROR)
            printf("ɾ����%d������ʧ��\n", j);
        else
            printf("ɾ����Ԫ��ֵΪ��%d\n", e);
    }
    printf("�������L��Ԫ�أ�");
    for (int i = 1; i <= L.length; i++)
    {
        GetElem(L, i, e);
        visit(L.elem[i - 1]);
    }
    cout << endl;
    printf("L��Ԫ��ֵ�ӱ���");
    for (int i = 1; i <= L.length; i++)
    {
        dbl(L.elem[i - 1]);
    }
    for (int i = 1; i <= L.length; i++)
    {
        GetElem(L, i, e);
        visit(e);
    }
    cout << endl;
    DestroyList(L);
    printf("����L��L.elem=%u L.length=%d L.listsize=%d\n", L.elem, L.length, L.listsize);
}