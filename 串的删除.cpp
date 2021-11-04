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
  void DelString(String &S,int pos,int len); //串的删除
 int main()
 {
  String S,T;int pos,len;
  CreatNullString(S);
  CreatNullString(T);
  char ch[MAXSIZE];
  printf("请输入串:\n");
  gets(ch);
  AssignString(S,ch);
  printf("%s\n",S.ch);
  printf("请输入删除起始位置："); 
  scanf("%d",&pos) ;
  printf("\n请输入删除长度：") ;
  scanf("%d",&len) ;
  DelString(S,pos,len);
  printf("\n删除后的串为：");
  printf("%s\n",S.ch);
  //puts(S.ch);	
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
 //串的删除
 void DelString(String &S,int pos,int len)
 {
 	if(pos+len-1>S.length ) exit(1);
 	int i;
 	for( i=pos+len;i<=S.length;i++)
 	S.ch[i-len-1]=S.ch [i-1];
 	S.ch[S.length-len]='\0';
	S.length=S.length -len;	
  }
 

