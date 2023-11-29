
seqlist.h ˳���

#define MAXSIZE 100 //���Ԫ�ظ���

typedef int ElemType;  //����Ԫ������

enum Status{Ok,Error};  //״̬��ö������

typedef struct
{
	Elemtype *elem;   //ָ�룬�洢�ռ䶯̬����
	int length;       //��ǰ˳���ĳ���
}SeqList;


Status InitSeqList(SeqList &L); //˳���ĳ�ʼ��
Status SeqListInsert(SeqList &L, int i, ElemType e); //��������Ԫ��
Status SeqListDelete(SeqList &L, int i); //ɾ��λ��i��Ԫ��
void TraverseSeqList(SeqList L); //����˳���
Status ClearList(SeqList &L);  //������Ա�
Status DestroySeqList(SeqList &L); //�������Ա�
Status ListEmpty(SeqList &L);   //�ж����Ա��Ƿ�Ϊ��
int ListLength(SeqList &L);    //���Ա���
Status GetElem(SeqList &L,int i,ElemType &e); //��e����L�е�i������Ԫ�ص�ֵ
int LocateElem(SeqList &L,ElemType &e);   //��ѯ���ݵ�λ�� 
Status PriorElem(SeqList &L, ElemType cur_e, ElemType &pre_e); //��cur_e��L������Ԫ�أ��Ҳ��ǵ�һ��������pre_e������ǰ�����������ʧ�ܣ�pre_e�޶��� 
Status NextElem(SeqList &L, ElemType cur_e, ElemType &next_e);