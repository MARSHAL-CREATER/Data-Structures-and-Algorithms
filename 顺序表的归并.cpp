#include <stdio.h>
#include <stdlib.h>
#define List_Init_Size 100
#define ListIncrement 10
typedef struct {
int *elem;//存储基地址 
int length;//当前表长 
int listsize;//当前存储容量 

} SqList;
void InitList(SqList &L,int m);// void InitList(SqList *L,int m)前面利用引用对实参进行操作，后面利用指针实现同样效果，但是方法不同 
SqList MergeList(SqList L,SqList M,SqList N); 
	void PrintList(SqList L);

int main() 
{ int m,n;
  SqList L;// SqList *L=(SqList*)malloc(List_Init_Size*sizeof(int)); 
  printf("\n请输入初始要创建顺序表长度;");
  scanf("%d",&m);
  printf("请输入初始顺序表值：");
  InitList( L,m);//InitList( &L,m); 
  printf("当前LA顺序表的值为：");
  PrintList( L);
  
  SqList M;
  printf("\n请输入初始要创建顺序表长度;");
  scanf("%d",&n);
  printf("请输入初始顺序表值：");
  InitList( M,n);//InitList( &M,m); 
  printf("当前LB顺序表的值为：");
  PrintList( M);
  
  SqList N;
  //MergeList(L,M,N);
  printf("\n归并后LC顺序表为："); 
  PrintList(MergeList(L,M,N) );
  		
  system("pause");
}
//创建顺序表 
void InitList(SqList &L,int m)// void InitList(SqList *L,int m)
{
 L .elem=(int*)malloc(List_Init_Size *sizeof(int));
 if(!L .elem) exit(1);//存储分配失败
 L .length =0;        //空表长度为0 
 L .listsize =List_Init_Size;//初始存储容量
 for (int i=1;i<=m;i++)
 {
 	scanf("%d",&L .elem[i-1] );//有这个必须得传址 ，因而形参必须为指针 
 	L .length++;
 
  }
 return ; 	
 }
 	//遍历输出顺序表
	void PrintList(SqList L)
	{
	 int i;

	 for(i=1;i<=L .length ;i++)
	 {
	 	printf("\t%d\t",L .elem[i-1]);
	 }
	 }
	 //归并有序顺序表 
SqList MergeList(SqList L,SqList M,SqList N)
	 {
	 	 if(!L .elem ||! M .elem){
         exit(1);
        }
	 	N .listsize=N .length=L .length+M .length ;
	 	N .elem =(int*)malloc(N .listsize*sizeof(int));
	 	int* pa=L .elem  ;
	 	int* pb=M .elem  ;
	 	int* pc=N .elem  ;
		if(!N .elem )exit(1);
		 int* pa_last=L .elem +L .length -1;
		 int* pb_last=M .elem +M .length-1;
		 while(pa<=pa_last&&pb<=pb_last){
		 	if(*pa>=*pb ) *pc++=*pa++;
		 	else *pc++=*pb++;	
		 }
	 while(pa<=pa_last)	*pc++=*pa++;
	 while(pb<=pb_last)	*pc++=*pb++;
	 return N;	
	 
	 }

