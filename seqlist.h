
seqlist.h 顺序表

#define MAXSIZE 100 //最大元素个数

typedef int ElemType;  //定义元素类型

enum Status{Ok,Error};  //状态，枚举类型

typedef struct
{
	Elemtype *elem;   //指针，存储空间动态申请
	int length;       //当前顺序表的长度
}SeqList;


Status InitSeqList(SeqList &L); //顺序表的初始化
Status SeqListInsert(SeqList &L, int i, ElemType e); //插入数据元素
Status SeqListDelete(SeqList &L, int i); //删除位置i处元素
void TraverseSeqList(SeqList L); //遍历顺序表
Status ClearList(SeqList &L);  //清空线性表
Status DestroySeqList(SeqList &L); //销毁线性表
Status ListEmpty(SeqList &L);   //判断线性表是否为空
int ListLength(SeqList &L);    //线性表长度
Status GetElem(SeqList &L,int i,ElemType &e); //用e返回L中第i个数据元素的值
int LocateElem(SeqList &L,ElemType &e);   //查询数据的位置 
Status PriorElem(SeqList &L, ElemType cur_e, ElemType &pre_e); //若cur_e是L的数据元素，且不是第一个，则用pre_e返回其前驱，否则操作失败，pre_e无定义 
Status NextElem(SeqList &L, ElemType cur_e, ElemType &next_e);