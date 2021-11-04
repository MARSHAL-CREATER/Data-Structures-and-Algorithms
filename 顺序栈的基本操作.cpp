#include <stdio.h>
#include <stdlib.h>

#define STACK_INIT_SIZE 100//初始存储容量 
#define STACKINCREMENT  10//存储分配增量
#define OVERFLOW 1
#define ERROR    1
#define OK       0

typedef int SElemType;
typedef int Status;
typedef struct{
SElemType *base;//在栈构造之前与销毁之后，base值为null 
SElemType *top;//栈顶指针 
int stacksize;//当前已分配的存储容量 
} SqStack;

 Status InitStack(SqStack &S);//构建一个空栈
 Status Push(SqStack &S,SElemType e); //PUSH进栈
 Status PrintStack(SqStack S);  //遍历输出栈中元素
 Status GetTop(SqStack S,SElemType &e); //读取栈顶元素,并将值赋给e 
 Status ClearStack(SqStack &S); //置空栈
 Status Pop(SqStack &S,SElemType &e);//删除栈顶元素 
 
int main()
{
  SElemType top;
  SqStack S;
  InitStack(S);
  Push(S,100);
  Push(S,120);
  Push(S,160); 	
  PrintStack(S);
  GetTop( S,top);
  printf("\n%d\n",top);	
  Pop(S,top);	
  PrintStack(S);
  ClearStack(S);
  	
  system("pause");
  return 0;
 }
 //构建一个空栈
 Status InitStack(SqStack &S)
 {
 	S.base=(SElemType*)malloc(STACK_INIT_SIZE*sizeof(SElemType));
 	if(!S.base ) exit(OVERFLOW);//存储分配失败
	 S.top =S.base ;
	 S.stacksize =STACK_INIT_SIZE; 
 	 return OK;
  } 
  //PUSH进栈
  Status Push(SqStack &S,SElemType e) 
  {
  if(S.top -S.base >=S.stacksize ){
  	S.base =(SElemType*)realloc(S.base ,(STACK_INIT_SIZE+STACKINCREMENT )*sizeof(SElemType));
  	if(!S.base ) exit(OVERFLOW);//存储分配失败
  	S.top=S.base +S.stacksize ;
  	S.stacksize+=STACKINCREMENT;
  }	
  *S.top ++=e;
  return OK;
  }
  //遍历输出栈中元素
  Status PrintStack(SqStack S)
  {
  	while(S.top !=S.base )
  	{
  		printf("%d\t",*S.base );
  		S.base++;
	  }
  	return OK;
   } 
   //读取栈顶元素,并将值赋给e 
   Status GetTop(SqStack S,SElemType &e)
   {
   	 if(S.top ==S.base) return ERROR;
   	 e=*(S.top-1);
   	 return OK;	
   } 
   //置空栈
   Status ClearStack(SqStack &S)
   {
   	if(S.base==NULL) return ERROR;
    else 
    while(S.top !=S.base)
    {
    	*(S.top-1)=0;
    	S.top--;
	}
	*(S.base )=0;
	return OK;
	} 
	//删除栈顶元素 
	Status Pop(SqStack &S,SElemType &e)
	{
	 if(S.top ==S.base) return ERROR;
	 e=*--S.top;
	 return OK;		
	 } 
	
  
  	
  	
  	
  	
  	
 
