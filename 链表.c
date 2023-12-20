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
	List* pTemp = (List*)malloc(sizeof(List));        //堆区开辟List型大小
	pTemp->id = id;                                    //分别赋值
	pTemp->name = name;
	pTemp->pNext = NULL;                       //指针赋空
	return pTemp;                                       //返回指针（地址）
};

void AddNode(List** ppHead, List** ppEnd, List* pNode)
{
	
	

	
	if (*ppHead == NULL)//判断链表中是否存在结点
	{
		*ppHead = pNode;//不存在结点
	                                   //头指针指向新来的结点
	                                   //尾指针指向新来的结点，与else共有步骤，移到判断外

	}
	else                                           //存在结点
	{
		(*ppEnd)->pNext = pNode;//尾节点中next指针指向新来的结点
	                                                //尾指针指向新来的结点，与if共有步骤，移到判断外
	}
	*ppEnd = pNode;
};
void InsertNode(List** ppHead, List** ppEnd, List* ppNode, int n)
{
	//头添加
	if (n == ((*ppHead)->id))
	{
		ppNode->pNext = *ppHead;
		*ppHead = ppNode;
		return;
	}
	//中间添加
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

	//尾添加
	(*ppEnd)->pNext = ppNode;
	*ppEnd = ppNode;
	return;
}
void DeleteNode(List** ppHead, List** ppEnd, int n)
{
	List* pMark = NULL;
	//头删除
		//删除标记指向头节点
		// 头指针指向下一个节点
		// 删除标记释放
	if (n == (*ppHead)->id)
	{
		List* pMark = *ppHead;
		*ppHead = (*ppHead)->pNext;
		free(pMark);
		return;
	}
	//中间删除
	pMark = *ppHead;
	while (pMark->pNext != NULL)
	{
		if (((pMark->pNext->id == n)) && (pMark->pNext->id != (*ppEnd)->id))
		{
			List* pMark2 = pMark->pNext;//建立新的中间标记点为删除点
			pMark->pNext = pMark->pNext->pNext;
			free(pMark2);
			return;
		}
		//尾删除(是中间删除的一种特殊情况
		else if ((pMark->pNext->id == (*ppEnd)->id)&&((*ppEnd)->id==n))
		{
			List* pMark2 = pMark->pNext;//建立新的中间标记点为删除点
			*ppEnd = pMark;
			pMark->pNext = pMark->pNext->pNext;
			free(pMark2);
			return;
		}
		pMark = pMark->pNext;
	}
	//尾删除(是中间删除的一种特殊情况
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

	//插入
	//头插入
	List* pNode1;
	pNode1 = GetNode(7, "HHH");
	int n1 = 1;
	InsertNode(&pHead, &pEnd, pNode1, n1);
	//中间插入
	List* pNode2;
	pNode2 = GetNode(6, "YYY");
	int n2 = 3;
	InsertNode(&pHead, &pEnd, pNode2, n2);
	//尾插入
	List* pNode3;
	pNode3 = GetNode(12, "ZZZ");
	int n3 = 100;
	InsertNode(&pHead, &pEnd, pNode3, n3);

	//目前结果
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

	//删除
	//头删除
	int d1 = 7;
	DeleteNode(&pHead, &pEnd, d1);
	//中间删除
	int d2 = 4;
	DeleteNode(&pHead, &pEnd, d2);
	//尾删除(是中间删除的一种特殊情况)
	int d3 = 12;
	DeleteNode(&pHead, &pEnd, d3);

	//目前结果
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