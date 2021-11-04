#include <stdlib.h>
#include <iostream>
using namespace std;

//单链表
typedef struct LNode
{
	int data;
	struct LNode *next;
}LNode;

//输出单链表
void outputList(LNode *C) 
{
	LNode *list = C->next;
	while (list->next != NULL)
	{
		//加上endl就表示换行
		cout << list->data << "->";
		list = list -> next;
	}
	cout << list->data;
}


//尾插法建立单链表
//*&C的意思是传入的是一个对L节点引用的指针
void createListByTail(LNode *&L, int a[], int n)
{
	LNode *node, *last;	//n用来指向新申请的节点,last始终指向C的终端节点
	L = (LNode *)malloc(sizeof(LNode));	//申请C的头结点空间
	L->next = NULL;
	last = L;
	for (int i = 0; i < n; i++)	//创建顺序表
	{
		node = (LNode *)malloc(sizeof(LNode));
		node->data = a[i];
		last->next = node;	
		last = last->next;	//last指针始终指向尾节点
	}
	last->next = NULL;	//尾节点的next始终为空
}

//头插法建立单链表
void createListByHead(LNode *&L, int a[], int n)
{
	LNode *head, *node;	//head是始终指向头结点的指针，node是指向新节点的指针
	L = (LNode *)malloc(sizeof(LNode));
	L->next = NULL;
	head = L;
	for (int i = 0; i < n; i++)
	{
		node = (LNode *)malloc(sizeof(LNode));
		node->data = a[i];
		node->next = head->next;
		head->next = node;
	}
}

//按照递增顺序归并链表
LNode* mergeList(LNode *L1, LNode *L2)
{
	//建立第三方链表的头结点
	LNode *C = (LNode *)malloc(sizeof(LNode));
	C->next = NULL;
	LNode *p = L1->next, *q = L2->next;
	//建立节点指针，其始终指向第三方头节点的终端节点，类似于尾插法
	LNode *r = C;
	while (p != NULL && q !=NULL)
	{
		//比较两指针当前指向元素的大小，小的就构成第三方链表，指针后移一位
		//如果二者相等，选取任一链表的值加入第三方链表
		if (p->data < q->data)
		{
			r->next = p;
			r = r->next;	//始终指向尾节点
			p = p->next;
		}
		else if (p->data == q->data)
		{
			r->next = p;
			r = r->next;
			p = p->next;
			q = q->next;
		}
		else
		{
			r->next = q;
			r = r->next;
			q = q->next;
		}
		if (p != NULL)	r->next = p;
		if (q != NULL) r->next = q;
	}
	return C;
}

int main()
{
	int a[5] = { 1,5,7,9,10 };
	int b[6] = { 8,6,5,3,2,1 };
	LNode *L1;	//尾插法建立链表
	LNode *L2;	//头插法建立链表
	createListByTail(L1, a, 5);
	cout << "尾插法建立的链表：";
	outputList(L1);
	createListByHead(L2, b,6);
	cout <<"\n头插法建立的链表：";
	outputList(L2);
	cout << "\n归并后的结果为：";
	outputList(mergeList(L1, L2));
	return 0;
}

