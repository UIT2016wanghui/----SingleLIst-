/*
�������б�ͷ���׽ڵ㣺������û��ֵ��ֻ��һ��ָ����
---->�ṹ��
1.������
2.�������
3.���루��ͷ��ָ��λ�ã���β��
4.ɾ������ͷ��ָ��λ�ã���β��
5.�ж��Ƿ�Ϊ��
6.��ӡ
*/
#include <iostream>
using namespace std;
/*
�������ṹ��
*/
typedef struct SingleList
{
	//������--->�洢����������
	int data;
	//ָ����--->�ṹ�����͵�ָ��
	struct SingleList* next;
}SINGLELIST, *LPSINGLELIST;
//typedef: �������
//struct SingleList  :SINGLELSIT
//struct SingleList* :*LPSINGLELIST
/*
������Ҫ��������
*/
//����һ����---->����һ����
LPSINGLELIST CreateList();//ʵ���Ǵ���û��data�Ľڵ�
//�����ڵ�---->����һ��Node
LPSINGLELIST CreateNode(int data);//�������Ҫ��������
//�ж��Ƿ�Ϊ��
int IsEmptyList(LPSINGLELIST L);//Ϊ�շ���1����Ϊ�շ���0
//��ӡ
void PrintList(LPSINGLELIST L);//ѭ��������ӡ
//����
void InsertListHeadNode(LPSINGLELIST L, int data);
void InsertListTailNode(LPSINGLELIST L, int data);
void InsertListAppoinNode(LPSINGLELIST L, int data, int item);
//ɾ��
void DeleteListHeadNode(LPSINGLELIST L);
void DeleteListTailNode(LPSINGLELIST L);
void DeleteListAppoinNode(LPSINGLELIST L, int item);

int main()
{
	//��������L
	LPSINGLELIST L = CreateList();
	//����ͷ�巨 3 2 1
	InsertListHeadNode(L, 1);
	InsertListHeadNode(L, 2);
	InsertListHeadNode(L, 3);
	//���Ա�λ���� 5 6 7
	InsertListTailNode(L, 5);
	InsertListTailNode(L, 6);
	InsertListTailNode(L, 7);
	//����ָ��λ�ò��� 3  2  1 4 5 6 7
	InsertListAppoinNode(L, 4, 5);

	//ɾ��ͷ
	DeleteListHeadNode(L);
	PrintList(L);

	//ɾ��β��
	DeleteListTailNode(L);
	PrintList(L);

	DeleteListAppoinNode(L, 4);
	PrintList(L);
	return 0;
}
//-------------->������
LPSINGLELIST CreateList()
{
	//Ϊ�������ռ�
	LPSINGLELIST L = (LPSINGLELIST)malloc(sizeof(SINGLELIST));//��ҵ��new
	//ָ�����ÿ�
	if (L == NULL)
	{
		cout << "�ڴ����ʧ��" << endl;
		return NULL;
	}
	//��ͷû������
	L->next = NULL;
	return L;
}
//-------------->�����ڵ�
LPSINGLELIST CreateNode(int data)
{
	//ΪNode����ռ�
	LPSINGLELIST Node = (LPSINGLELIST)malloc(sizeof(SINGLELIST));//��ҵ��new
	//ָ�����ÿ�
	if (Node == NULL)
	{
		cout << "�ڴ����ʧ��" << endl;
		return NULL;
	}
	//�ڵ�������ĳ�ʼ��
	Node->data = data;
	//�ڵ�ָ����ĳ�ʼ��
	Node->next = NULL;
	return Node;
}

int IsEmptyList(LPSINGLELIST L)
{
	//ֻ�б�ͷ�ڵ��ʱ�� Ϊ��
	if (L->next == NULL)//���׳�������Щ��ֵ���ʽ
		return 1;//����1Ϊ��
	else
		return 0;//����0��Ϊ��
}
//CreateList��CreateNode�������ж��Ƿ�Ϊ��
//�����ʹ�ӡ
void PrintList(LPSINGLELIST L)
{
	//�ж��Ƿ�Ϊ��
	if (IsEmptyList(L))
		throw 1;
	LPSINGLELIST p = L->next;//��Ϊ��ͷû������
	while (p)
	{
		cout << " " << p->data;
		p = p->next;	//���� i=i+1��һ��
	}
	cout << endl;
}

//----------->�����ͷ
void InsertListHeadNode(LPSINGLELIST L, int data)
{
	//�����ڵ�
	LPSINGLELIST Node = CreateNode(data);
	//�������ڴ��
	Node->next = L->next;
	L->next = Node;
}
//---------->��λ����
void InsertListTailNode(LPSINGLELIST L, int data)
{
	//�����ڵ�
	LPSINGLELIST Node = CreateNode(data);
	//�ҵ�β�ڵ�
	//���������һ����㲻��ָNULL��ָNULL����һ�����
	LPSINGLELIST p = L;
	while (p->next != NULL)
		p = p->next;
	p->next = Node;
}
//----------->ָ��λ�ò���
void InsertListAppoinNode(LPSINGLELIST L, int data, int item)
{
	//�����ڵ�
	LPSINGLELIST Node = CreateNode(data);
	//������2��ָ��
	//��ȥ����һ��ָ��
	LPSINGLELIST q = L;
	LPSINGLELIST k = L->next;
	while (k->data != item)
	{
		//q��kһֱ�������ڣ�
		q = k;
		k = q->next;

		//δ�ҵ�
		if (k == NULL)
		{
			cout << "δ�ҵ�����λ��" << endl;
			return;
		}
	}
	//list �����н������ 1 3 5 7 9   2 4 6   ===1 2 3 4 5 6 7 9
	q->next = Node;
	Node->next = k;
}
//----------->ɾ��ͷ
void DeleteListHeadNode(LPSINGLELIST L)
{
	//�ж��Ƿ�Ϊ��
	if (IsEmptyList(L))
		exit(0);
	LPSINGLELIST p = L->next;
	L->next = p->next;
	free(p);
}
//------------>ɾ��β�ڵ�
void DeleteListTailNode(LPSINGLELIST L)
{
	//�ж��Ƿ�Ϊ��
	if (IsEmptyList(L))
		exit(0);
	LPSINGLELIST q = L;
	LPSINGLELIST p = q->next;
	while (p->next)
	{
		q = p;
		p = q->next;
	}
	q->next = NULL;
	free(p);
}
void DeleteListAppoinNode(LPSINGLELIST L, int item)
{
	//�ж��Ƿ�Ϊ��
	if (IsEmptyList(L))
		exit(0);
	LPSINGLELIST q = L;
	LPSINGLELIST p = L->next;
	//�ҵ�ɾ���Ľڵ�p��
	while (p->data != item)
	{
		q = p;
		p = q->next;
		if (p == NULL)
		{
			cout << "δ�ҵ�ָ��λ��" << endl;
			return;
		}
	}
	q->next = p->next;
	free(p);
}
