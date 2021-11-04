#include <stdio.h>
#include <stdlib.h>
#define List_Init_Size 100
#define ListIncrement 10
typedef struct {
int *elem;//存储基地址 
int length;//当前表长 
int listsize;//当前存储容量 

} SqList;
int* p=NULL;int* q=NULL;
void InitList(SqList *L,int m);
void PrintList(SqList *L,int m);
void ListIinsert(SqList *L,int i,int e);
void ListDelete(SqList *L,int i);
void menu();

int LocateElem(SqList *L,int e);

int main()
{   int m,n,e;int a,b,tmp;
    SqList *L=(SqList*)malloc(List_Init_Size*sizeof(int));//由printf("%D",sizeof(L));得到为8 
    int operation;
    while(1){
	system("cls"); 
    menu(); 
	printf("请输入需要操作的对应序号：");
    scanf("%d", &operation);
    if(operation==0) {
	printf ("谢谢使用\n");break;}
    switch(operation){
    case 1: 
        printf("请输入初始要创建顺序表长度;");
        scanf("%d",&m);
        printf("请输入初始要顺序表;");
	    InitList( L,m);
        break;
    case 2:
        printf("请输入需要查找的值;");
	    scanf("%d",&b);
	    tmp=LocateElem(L, b);
	    printf("当前要求的值在第%d位上",tmp);
        break;
    case 3:
        printf("请输入需要插入位置;");
	    scanf("%d",&n);
	    printf("请输入需要插入位置的值;");
	    scanf("%d",&e);
	    ListIinsert(L,n,e);
        break;
    case 4:
    	printf("请输入需要删除位置;");
	    scanf("%d",&a);
	    ListDelete(L,a);
 	    break;
 	case 5:
	    printf("当前顺序表的值为：");
 	    PrintList( L,m);
		break; 
    case 0:
        break;
    default:
        printf ("输入错误\n");
        break;
    }
    system("pause"); 
   }
    free(L);
	return 0;
}
//创建顺序表 
void InitList(SqList *L,int m)
{
 L->elem=(int*)malloc(List_Init_Size *sizeof(int));
 if(!L->elem) exit(1);//存储分配失败
 L->length =0;        //空表长度为0 
 L->listsize =List_Init_Size;//初始存储容量
 for (int i=1;i<=m;i++)
 {
 	scanf("%d",&L->elem[i-1] );
 	L->length++;
 
  }
 return ; 	
 }
 // 顺序表的插入 
 void ListIinsert(SqList *L,int i,int e)
 {
 	if(i<1||i>L->length+1) exit(1);//插入位置不合法
	if(L->length>L->listsize )
	{
	 int *newbase=NULL;
	 newbase=(int*)realloc(L->elem ,(L->listsize+ListIncrement)*sizeof(int));
	 if(!newbase) exit(1);
	 L->elem=newbase;//新基址
	 L->listsize+=ListIncrement;//增加容量 
	 } 
	 q=&(L->elem[i-1]);
	 for(p=&(L->elem[L->length]);p>=q;--p)
	 	*(p+1)=*p;//顺序表元素从后往前依次后移一个单位 
		*q=e;++L->length; 
	 	return ; 	
  } 
  //顺序表的删除
  void ListDelete(SqList *L,int i)
  {
  	if(i<1||i>L->length+1) exit(1);//删除位置不合法
  	p=&(L->elem[i-1]);
	q=L->elem+L->length ;
	for(++p;p<=q;++p)
		*(p-1)=*p;//被删除位置之后元素依次前移一个单位 
		--L->length;
		return;	
   } 
   //顺序表的查找
   int LocateElem(SqList *L,int e)
   {
   	int i=1;
   	p=L->elem;
   	while((i<=L->length )&&!(*p==e)) {++i;p++;} 
   	if(i<=L->length ) return i;
   	else exit(1);
	}

	//遍历输出顺序表
	void PrintList(SqList *L,int m)
	{
	 int i;
	 printf("当前顺序表的值为:\n");
	 for(i=1;i<=L->length ;i++)
	 {
	 	printf("\t%d\t",L->elem[i-1]);
	 }
	 }
	  //菜单界面 
 void menu()
{
    printf ("\t    顺序表基本操作的实现\n");
    printf ("========================================\n");
    printf ("\t1.顺序表的创建\n");
    printf ("\t2.查找第i个位置的值\n");
    printf ("\t3.在第i个元素之前插入一个新值\n");
    printf ("\t4.删除第i个位置\n");
    printf ("\t5.遍历输出各个节点值\n");
    printf ("\t0.退出系统\n");
    printf ("========================================\n");
}  
 
