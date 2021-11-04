#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Node
{
	int data;
	struct Node *next;
 } LNode,*LinkList;


struct Node *p= NULL;//一个还没确定指向的节点指针 
int GetData (LinkList L,int i,int e);
void Insert1(LinkList L,int i,int e);
void Insert2(LinkList L,int i,int e);
void Delete(LinkList L,int i);
void Create1(LinkList &L,int n);
void Create2(LinkList &L,int n);
void Print(LinkList L,int m);
void menu(); 

 int main()
 { 
    int operation;
    int m,n,o,q,l,tmp;
	LinkList L;
	while(1){
	system("cls"); 
    menu(); 
	printf("请输入需要操作的对应序号：");
    scanf("%d", &operation);
    if(operation==0) {
	printf ("谢谢使用\n");break;}
    switch(operation){
    case 1: 
        printf("请输入需要创建的节点数："); 
        scanf("%d",&m);
        printf("请输入各个节点的数值："); 
 	    Create1(L, m);
        break;
    case 2:
        printf("\n请输入需要查找哪个位置数字：");
 	    scanf("%d",&o);
 	    tmp=GetData(L,o,tmp);
 	    printf("\n当前节点的值为：%d",tmp);
        break;
    case 3:
        printf("\n请输入需要哪个节点后插入：");
	    scanf("%d",&n);
	    printf("\n请输入需要插入的数字：");
	    scanf("%d",&l); 
 	    Insert1(L,n,l);
 	    m+=1; 
        break;
    case 4:
    	printf("\n请输入需要删除哪个位置数字：");
 	    scanf("%d",&q);
 	    Delete(L,q);
 	    m-=1; 
 	    break;
 	case 5:
	    printf("当前链表的值为：");
 	    Print(L,m);
		break; 
    case 0:
        break;
    default:
        printf ("输入错误\n");
        break;
    }
    system("pause"); 
   }
 	return 0; 
 }
 //查找-----按位序查找 
 int GetData (LinkList L,int i,int e)
 {
 	p=L->next;
	int j=1;
 	while(p&&j<i)
 	{
 	p=p->next ;++j;	
	 }
 if(!p||j>i) exit(1);
	 e=p->data ;
	 return e;
 }
 //插入-----在第i个元素后插入（插入的数变成i+1个位置） 
void Insert1(LinkList L,int i,int e)
 {
 	p=L;
 	int j=0;
 	while(p&&j<i)
 	{
	 p=p->next ;++j; 
	 } //寻找第i个节点 
	if(!p||j>i)  exit(1);
	
	LNode *s=NULL;
	s=(LinkList)malloc(sizeof(Node)); //生成新节点 
	s->data =e;
	s->next =p->next; 
	p->next =s;
 }
 
//插入-----在第i个元素前插入（插入的数变成i个位置） 
void Insert2(LinkList L,int i,int e)
 {
 	p=L;
 	int j=0;
 	while(p&&j<i-1)
 	{
	 p=p->next ;++j; 
	 } //寻找第i-1个节点 
	if(!p||j>i-1)  exit(1);
	
	LNode *s=NULL;
	s=(LinkList)malloc(sizeof(Node)); //生成新节点 
	s->data =e;
	s->next =p->next ;
	p->next =s;
 } 
 
 //删除第i个元素 
 void Delete(LinkList L,int i)
 {
 	p=L;
 	int j=0;int e;
 	while(p->next&&j<i-1)
 	{
 		p=p->next ;++j;
	 }//令p指向第i-1个节点
	 if (!(p->next )||j>i-1) exit(1);
	 LNode *s= NULL;//LinkList s=NULL;
	 s=(LinkList)malloc(sizeof(Node));
	 s=p->next;p->next =s->next;
	 e=s->data ;free(s);   
 }
 //单链表的创建（尾插法，顺序输出） 
 void Create1(LinkList &L,int n)
 {  
    L=(LinkList)malloc(sizeof(Node));
	LinkList T=(LinkList)malloc(sizeof(Node));
	T=L;//令T指向头节点	
 	L->next=NULL;//建立一个带头节点的单链表 
 	for(int i=0;i<n;++i)
 	{
 	LNode *s=NULL;
	s=(LinkList)malloc(sizeof(Node));
	scanf("%d",&(s->data));
    s->next=NULL;
	T->next=s;
	T=s; 
	}
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
 //菜单界面 
 void menu()
{
    printf ("\t    单链表基本操作的实现\n");
    printf ("========================================\n");
    printf ("\t1.单链表的创建（尾插法）\n");
    printf ("\t2.查找第i个节点的值\n");
    printf ("\t3.在第i个元素后插入一个新节点\n");
    printf ("\t4.删除第i个节点\n");
    printf ("\t5.遍历输出各个节点值\n");
    printf ("\t0.退出系统\n");
    printf ("========================================\n");
} 
 
 
 
