#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAXSIZE 256
typedef struct//堆分配 
{
	char *ch;//存储起始位置 
	int length;//串长 
	int strsize;//分配空间大小 
 }String; 
  void CreatNullString (String &S);//创建空串
  void  AssignString(String &S,char *s2);  //为串赋值
  int index(String S,String T,int pos);//朴素算法实现串的模式匹配
 int main()
 {
  String S,T;
  CreatNullString(S);
  CreatNullString(T);
  char ch[MAXSIZE];
  printf("请输入主串:\n");
  gets(ch);
  AssignString(S,ch);
  printf("请输入子串:\n");
  gets(ch);
  AssignString(T,ch);
  int i= index(S,T,1);//pos=1，另函数从头查找		
  printf("相同字符串在主串的起始位置为：第%d位\n",i);	
  system("pause");
  return 0;	
  }
  
  //创建空串 
  void CreatNullString (String &S) 
 {
 S.ch =(char*)malloc(MAXSIZE*sizeof(char));
 S.length=0;
 S.strsize =MAXSIZE;
 } 
 
 
 //为串赋值
  void  AssignString(String &S,char *s2)
 {
   int i=0;
   //统计输入字符长度 
   while(s2[i]!='\0')
   {
   	i++;
	   }
	//空间不够，则realloc开辟新空间 
	if(i>S.strsize)
	{
		S.ch=(char*)realloc(S.ch,i*sizeof(char));
		S.strsize=i;
		}
		S.length =i;	
 	//赋值
	 for(i=0;i<S.length;i++)
	 {S.ch[i]=s2[i]; } 
 }
 
 
 //朴素算法实现串的模式匹配
 int index(String S,String T,int pos)//pos用与输入查找起始位置,T为要查找子串 
 {
  int i,j;
  //pos的错误输入判断 
  if(pos<1||S.length<pos||S.length-T.length+1<pos)
   exit(1);
   
   i=pos-1;//由于数组是从0开始存储的
   j=0;
   while(i<S.length&&j<T.length)
   {
   	 if(S.ch[i]==T.ch[j])
   {
   	i++;
   	j++;
	}
	else
	{
		i=i-j+1;//i的位置变为初始位置之后的一个位置 
		j=0;
	 }
   }
    if(j>=T.length)
	return i-T.length+1;
	else return 0;//匹配失败 
 	 	
  } 
