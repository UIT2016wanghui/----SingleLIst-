/*
单链表：有表头：首节点：数据域没有值，只有一个指针域
---->结构体
1.创建表
2.创建结点
3.插入（表头，指定位置，表尾）
4.删除（表头，指定位置，表尾）
5.判断是否为空
6.打印
*/
#include <iostream>
using namespace std;
/*
创建结点结构体
*/
typedef struct SingleList
{
	//数据域--->存储的数据类型
	int data;
	//指针域--->结构体类型的指针
	struct SingleList* next;
}SINGLELIST, *LPSINGLELIST;
//typedef: 定义别名
//struct SingleList  :SINGLELSIT
//struct SingleList* :*LPSINGLELIST
/*
声明你要做的事情
*/
//创建一个表---->返回一个表
LPSINGLELIST CreateList();//实质是创建没有data的节点
//创建节点---->返回一个Node
LPSINGLELIST CreateNode(int data);//创建结点要传入数据
//判断是否为空
int IsEmptyList(LPSINGLELIST L);//为空返回1，不为空返回0
//打印
void PrintList(LPSINGLELIST L);//循环遍历打印
//插入
void InsertListHeadNode(LPSINGLELIST L, int data);
void InsertListTailNode(LPSINGLELIST L, int data);
void InsertListAppoinNode(LPSINGLELIST L, int data, int item);
//删除
void DeleteListHeadNode(LPSINGLELIST L);
void DeleteListTailNode(LPSINGLELIST L);
void DeleteListAppoinNode(LPSINGLELIST L, int item);

int main()
{
	//创建链表L
	LPSINGLELIST L = CreateList();
	//测试头插法 3 2 1
	InsertListHeadNode(L, 1);
	InsertListHeadNode(L, 2);
	InsertListHeadNode(L, 3);
	//测试表位插入 5 6 7
	InsertListTailNode(L, 5);
	InsertListTailNode(L, 6);
	InsertListTailNode(L, 7);
	//测试指定位置插入 3  2  1 4 5 6 7
	InsertListAppoinNode(L, 4, 5);

	//删除头
	DeleteListHeadNode(L);
	PrintList(L);

	//删除尾部
	DeleteListTailNode(L);
	PrintList(L);

	DeleteListAppoinNode(L, 4);
	PrintList(L);
	return 0;
}
//-------------->创建表
LPSINGLELIST CreateList()
{
	//为链表分配空间
	LPSINGLELIST L = (LPSINGLELIST)malloc(sizeof(SINGLELIST));//作业用new
	//指针域置空
	if (L == NULL)
	{
		cout << "内存分配失败" << endl;
		return NULL;
	}
	//表头没有数据
	L->next = NULL;
	return L;
}
//-------------->创建节点
LPSINGLELIST CreateNode(int data)
{
	//为Node分配空间
	LPSINGLELIST Node = (LPSINGLELIST)malloc(sizeof(SINGLELIST));//作业用new
	//指针域置空
	if (Node == NULL)
	{
		cout << "内存分配失败" << endl;
		return NULL;
	}
	//节点数据域的初始化
	Node->data = data;
	//节点指针域的初始化
	Node->next = NULL;
	return Node;
}

int IsEmptyList(LPSINGLELIST L)
{
	//只有表头节点的时候， 为空
	if (L->next == NULL)//容易出错，容易些赋值表达式
		return 1;//返回1为空
	else
		return 0;//返回0不为空
}
//CreateList和CreateNode都必须判断是否为空
//遍历和打印
void PrintList(LPSINGLELIST L)
{
	//判断是否为空
	if (IsEmptyList(L))
		throw 1;
	LPSINGLELIST p = L->next;//因为表头没有数据
	while (p)
	{
		cout << " " << p->data;
		p = p->next;	//递推 i=i+1是一样
	}
	cout << endl;
}

//----------->插入表头
void InsertListHeadNode(LPSINGLELIST L, int data)
{
	//创建节点
	LPSINGLELIST Node = CreateNode(data);
	//先连接在打断
	Node->next = L->next;
	L->next = Node;
}
//---------->表位插入
void InsertListTailNode(LPSINGLELIST L, int data)
{
	//创建节点
	LPSINGLELIST Node = CreateNode(data);
	//找到尾节点
	//误区：最后一个结点不是指NULL，指NULL的上一个结点
	LPSINGLELIST p = L;
	while (p->next != NULL)
		p = p->next;
	p->next = Node;
}
//----------->指定位置插入
void InsertListAppoinNode(LPSINGLELIST L, int data, int item)
{
	//创建节点
	LPSINGLELIST Node = CreateNode(data);
	//讲的是2个指针
	//回去尝试一个指针
	LPSINGLELIST q = L;
	LPSINGLELIST k = L->next;
	while (k->data != item)
	{
		//q和k一直保持相邻，
		q = k;
		k = q->next;

		//未找到
		if (k == NULL)
		{
			cout << "未找到插入位置" << endl;
			return;
		}
	}
	//list 排序，有交叉插入 1 3 5 7 9   2 4 6   ===1 2 3 4 5 6 7 9
	q->next = Node;
	Node->next = k;
}
//----------->删除头
void DeleteListHeadNode(LPSINGLELIST L)
{
	//判断是否为空
	if (IsEmptyList(L))
		exit(0);
	LPSINGLELIST p = L->next;
	L->next = p->next;
	free(p);
}
//------------>删除尾节点
void DeleteListTailNode(LPSINGLELIST L)
{
	//判断是否为空
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
	//判断是否为空
	if (IsEmptyList(L))
		exit(0);
	LPSINGLELIST q = L;
	LPSINGLELIST p = L->next;
	//找到删除的节点p；
	while (p->data != item)
	{
		q = p;
		p = q->next;
		if (p == NULL)
		{
			cout << "未找到指定位置" << endl;
			return;
		}
	}
	q->next = p->next;
	free(p);
}
