#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 100  //存储容量 

typedef int SElemType;
typedef int Status;
typedef struct {
int front;//队头指针 
int rear;//队尾指针	
SElemType* data;//存储基地址	
}SqQueue;

Status InitQueue(SqQueue &S);//初始化为空队列 
Status EmptyQueue(SqQueue S);//判断队列是否为空
Status EnterQueue(SqQueue &S,SElemType e); //元素入队
Status DeQueue(SqQueue &S,SElemType &e); //元素出队，并用e返回出队元素
Status GetFront(SqQueue &S,SElemType &e);//取队头元素,并用e返回队头元素 
Status PrintQueue(SqQueue S);//遍历队列
int QueueLength(SqQueue S); //求队长
 
int main()
{
	SqQueue S;
	int front;
	InitQueue(S);
	EmptyQueue(S);
	EnterQueue(S,100);
	EnterQueue(S,120);
	EnterQueue(S,170);
	PrintQueue(S);
	EmptyQueue(S);
	GetFront(S,front);
	DeQueue(S,front);
	EnterQueue(S,300);
	PrintQueue(S);
	
	system("pause");
	return 0;
}
//初始化
Status InitQueue(SqQueue &S)
{
  S.data=(SElemType*)malloc(MAXSIZE *sizeof(SElemType));	
  if(!S .data) exit(1);
  S.front=S.rear=0;
  return 0;	
}
//判断队列是否为空
Status EmptyQueue(SqQueue S)
{
   	if(S.front==S.rear )
	printf("队列为空\n");
	else
	printf("队列不为为空\n");
	return 0; 
 }
 //元素入队
 Status EnterQueue(SqQueue &S,SElemType e)
 {
 	if((S.rear+1)%MAXSIZE==S.front ) exit(1);//队尾的下一个是队头，则队满 
  	S.data[S.rear]=e;
  	S.rear=(S.rear+1)%MAXSIZE;//构建循环队列 
  	return 0;	
  } 
  //元素出队，并用e返回出队元素 
  Status DeQueue(SqQueue &S,SElemType &e)
  {
  	if(S.front==S.rear ) exit(1);
  	e=S.data[S.front];
	S.data[S.front]=0; 
  	S.front=(S.front+1)%MAXSIZE;//构建循环队列 
  	return 0;	
   }
 //取队头元素,并用e返回队头元素 
 Status GetFront(SqQueue &S,SElemType &e)
 {
   if(S.front==S.rear ) exit(1);	
   else
   printf("对头元素为%d\n",S.data[S.front]);
   e=S.data[S.front];	
   return 0;	
  } 
//遍历队列
Status PrintQueue(SqQueue S)
{
  if(S.front==S.rear ) exit(1);
  for(int i=S.front;i<=S.rear-1;i++)	
  printf(" %d\t",S.data[i]);		
 } 
 //求队长 
int QueueLength(SqQueue S) 
{
 return(S.rear -S.front +MAXSIZE)%MAXSIZE;	
	
}
