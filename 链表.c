#include <stdio.h>
#include <stdlib.h>
typedef struct Node
{
	int id;
	char* name;
	struct Node* pNext;
}List;

List* GetNode(int id, char* name)
{
	List* pTemp = (List*)malloc(sizeof(List));        //��������List�ʹ�С
	pTemp->id = id;                                    //�ֱ�ֵ
	pTemp->name = name;
	pTemp->pNext = NULL;                       //ָ�븳��
	return pTemp;                                       //����ָ�루��ַ��
};

void AddNode(List** ppHead, List** ppEnd, List* pNode)
{
	
	

	
	if (*ppHead == NULL)//�ж��������Ƿ���ڽ��
	{
		*ppHead = pNode;//�����ڽ��
	                                   //ͷָ��ָ�������Ľ��
	                                   //βָ��ָ�������Ľ�㣬��else���в��裬�Ƶ��ж���

	}
	else                                           //���ڽ��
	{
		(*ppEnd)->pNext = pNode;//β�ڵ���nextָ��ָ�������Ľ��
	                                                //βָ��ָ�������Ľ�㣬��if���в��裬�Ƶ��ж���
	}
	*ppEnd = pNode;
};
void InsertNode(List** ppHead, List** ppEnd, List* ppNode, int n)
{
	//ͷ���
	if (n == ((*ppHead)->id))
	{
		ppNode->pNext = *ppHead;
		*ppHead = ppNode;
		return;
	}
	//�м����
	List* pMark = *ppHead;

	while (pMark->pNext != NULL)
	{
		if (pMark->pNext->id == n)
		{
			ppNode->pNext = pMark->pNext;
			pMark->pNext = ppNode;
			return;
		}

		pMark = pMark->pNext;
	}

	//β���
	(*ppEnd)->pNext = ppNode;
	*ppEnd = ppNode;
	return;
}
void DeleteNode(List** ppHead, List** ppEnd, int n)
{
	List* pMark = NULL;
	//ͷɾ��
		//ɾ�����ָ��ͷ�ڵ�
		// ͷָ��ָ����һ���ڵ�
		// ɾ������ͷ�
	if (n == (*ppHead)->id)
	{
		List* pMark = *ppHead;
		*ppHead = (*ppHead)->pNext;
		free(pMark);
		return;
	}
	//�м�ɾ��
	pMark = *ppHead;
	while (pMark->pNext != NULL)
	{
		if (((pMark->pNext->id == n)) && (pMark->pNext->id != (*ppEnd)->id))
		{
			List* pMark2 = pMark->pNext;//�����µ��м��ǵ�Ϊɾ����
			pMark->pNext = pMark->pNext->pNext;
			free(pMark2);
			return;
		}
		//βɾ��(���м�ɾ����һ���������
		else if ((pMark->pNext->id == (*ppEnd)->id)&&((*ppEnd)->id==n))
		{
			List* pMark2 = pMark->pNext;//�����µ��м��ǵ�Ϊɾ����
			*ppEnd = pMark;
			pMark->pNext = pMark->pNext->pNext;
			free(pMark2);
			return;
		}
		pMark = pMark->pNext;
	}
	//βɾ��(���м�ɾ����һ���������
}
int main()
{
	List* pHead = NULL;
	List* pEnd = NULL;
	AddNode(&pHead, &pEnd, GetNode(1, "aaa"));
	AddNode(&pHead, &pEnd, GetNode(2, "bbb"));
	AddNode(&pHead, &pEnd, GetNode(3, "ccc"));
	AddNode(&pHead, &pEnd, GetNode(4, "ddd"));
	AddNode(&pHead, &pEnd, GetNode(5, "eee"));

	//����
	//ͷ����
	List* pNode1;
	pNode1 = GetNode(7, "HHH");
	int n1 = 1;
	InsertNode(&pHead, &pEnd, pNode1, n1);
	//�м����
	List* pNode2;
	pNode2 = GetNode(6, "YYY");
	int n2 = 3;
	InsertNode(&pHead, &pEnd, pNode2, n2);
	//β����
	List* pNode3;
	pNode3 = GetNode(12, "ZZZ");
	int n3 = 100;
	InsertNode(&pHead, &pEnd, pNode3, n3);

	//Ŀǰ���
	/*
	7HHH
	1aaa
	2bbb
	6YYY
	3ccc
	4ddd
	5eee
	12ZZZ
	*/

	//ɾ��
	//ͷɾ��
	int d1 = 7;
	DeleteNode(&pHead, &pEnd, d1);
	//�м�ɾ��
	int d2 = 4;
	DeleteNode(&pHead, &pEnd, d2);
	//βɾ��(���м�ɾ����һ���������)
	int d3 = 12;
	DeleteNode(&pHead, &pEnd, d3);

	//Ŀǰ���
	/*
	1aaa
    2bbb
    6YYY
    3ccc
    5eee
	*/

	while (pHead != NULL)
	{
		printf("%d%s\n", pHead->id, pHead->name);
		pHead = (*pHead).pNext;
	}
	return 0;
}