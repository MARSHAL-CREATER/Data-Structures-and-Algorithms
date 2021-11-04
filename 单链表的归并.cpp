#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Node
{
	int data;
	struct Node *next;
 } LNode,*LinkList;
 
 void Create2(LinkList &L,int n);
 void Print(LinkList L,int m);
LNode* MergeList(LinkList L,LinkList M);


struct Node *p= NULL; 
 int main()
 {
 	LinkList L,M,N;
 	//L=(LinkList)malloc(sizeof(Node));
 	//M=(LinkList)malloc(sizeof(Node));
 	
 	int m,n;
 	
 	printf("请输入需要创建的节点数："); 
    scanf("%d",&m);
    printf("请输入各个节点的数值：");
    Create2(L,m);
    printf("当前LA链表的值为：");
 	Print(L,m);
 	
    printf("\n请输入需要创建的节点数："); 
    scanf("%d",&n);
    printf("请输入各个节点的数值：");
	Create2(M,n);
	printf("\n当前LB链表的值为：");
 	Print(M,n);
 	
 	//Create2(N,n+m,0);
	
	printf("\n合并后LC链表的值为：");
 	Print(MergeList( L, M),m+n); 
 
 
 system("pause"); 
 }
 //单链表的创建（头插法，逆序输出） 
 void Create2(LinkList &L,int n)
 {  
    L=(LinkList)malloc(sizeof(Node));
 	L->next=NULL;//建立一个带头节点的单链表 
 	for(int i=0;i<n;++i)
 	{
 	LNode *s=NULL;
	s=(LinkList)malloc(sizeof(Node));
	scanf("%d",&(s->data));
    s->next=L->next;
    L->next=s; 
	}
 }
 //归并两个有序单链表 
LNode* MergeList(LinkList L,LinkList M)
{
 LNode* N=(LinkList)malloc(sizeof(Node));
 N->next =NULL;
 LNode* pa=L->next;LNode* pb=M->next;
 LNode* pc=N;
 while(pa&&pb)
 {
   if(pa->data  >=pb->data )	
   {pc->next =pa;pc=pc->next ;pa=pa->next ;}
   else
   {pc->next =pb;pc=pc->next ;pb=pb->next ;} 
 	
 }
 pc->next =pa?pa:pb; 
return N;
} 
 //单链表的遍历输出
 void Print(LinkList L,int m)
 {
   p=L->next;//L是头节点，这里让p指向首节点 
   for(int i=0;i<m;i++)	
   {
   	printf("%d\t",p->data );
   	p=p->next ;
   }	
 }


  
