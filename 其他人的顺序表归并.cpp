#include <stdio.h>
#include <stdlib.h>
#define ERROR 0
#define OK 1
#define OVERFLOW -2
#define INIT_LIST_SIZE 50
#define LISTINCREMENT 10

typedef int ElemType;
typedef int Status;
typedef struct{
ElemType *elem;
int length;
int listsize;
}SqList;


Status InitList(SqList &L){//初始化线性表。
L.elem = (ElemType *)malloc(INIT_LIST_SIZE*sizeof(ElemType));  //开辟内存空间。
if(!L.elem){
exit(OVERFLOW);
}
L.length = 0;
L.listsize = INIT_LIST_SIZE;
return OK;
}


Status InsertList(SqList &L, ElemType e){ //在线性表末端插入元素。
if(!L.elem){
return ERROR;
}
 if(L.length >= L.listsize){    //当前表的长度超过存储容量时，开辟新的内存空间。
  ElemType *newbase;
  newbase = (ElemType *)realloc(L.elem, (INIT_LIST_SIZE + LISTINCREMENT)*sizeof(ElemType));
  if(!newbase){
   exit(OVERFLOW);
  }
  L.elem = newbase;
  L.listsize += LISTINCREMENT;
 }
  ElemType *p_last = &(L.elem[0]) + L.length - 1;    //获取线性表最后一个元素的指针。
  *(p_last + 1) = e;    //将元素插到最后一个元素后面。
  ++ L.length;
 return OK;
}


Status MergeList(SqList La, SqList Lb, SqList &Lc){    //以非递减顺序合并La，Lb到新线性表Lc。Lc在此处初始化。
 if(!La.elem || !Lb.elem){
  return ERROR;
 }
 Lc.length = La.length + Lb.length;
 Lc.listsize = Lc.length;
 Lc.elem = (ElemType *)malloc(Lc.listsize*sizeof(ElemType));//init Lc.
 
 ElemType *pc = Lc.elem;
 ElemType *pa = La.elem;
 ElemType *pb = Lb.elem;
 
 ElemType *pa_last = La.elem + La.length - 1;
 ElemType *pb_last = Lb.elem + Lb.length - 1;
 
 while(pa <= pa_last && pb <= pb_last){
  if(*pa <= *pb){
   *pc ++ = *pa ++;
  }else{
   *pc ++ = *pb ++;
  }
 }
 while(pa <= pa_last){
  *pc ++ = *pa ++;
 }
 while(pb <= pb_last){
  *pc ++ = *pb ++;
 }
 return OK;
}

void PrintList(SqList L){    //打印线性表的所有元素。
 printf("List :");
 for(int i = 1; i <= L.length; i++){
  printf("%d ",L.elem[i-1]);
 }
 printf("\n");
}

Status DestoryList(SqList &L){    //销毁线性表，回收内存空间。
 if(!L.elem){
  return ERROR;
 }
 free(L.elem);
 L.elem = NULL;
 L.length = 0;
 L.listsize = 0;
 return OK;
}

int main(){    //测试
 SqList La;
 SqList Lb;
 SqList Lc;
 
 InitList(La);
 InitList(Lb);
 
 InsertList(La, 3);
 InsertList(La, 5);
 InsertList(La, 8);
 InsertList(La, 11);
 
 InsertList(Lb, 2);
 InsertList(Lb, 6);
 InsertList(Lb, 8);
 InsertList(Lb, 9);
 InsertList(Lb, 11);
 InsertList(Lb, 15);
 InsertList(Lb, 20);
 
 PrintList(La);
 PrintList(Lb);
/*  PrintList(Lc); *///not init,
 
 MergeList(La, Lb, Lc);
 
 PrintList(Lc);
 
 DestoryList(La);
 DestoryList(Lb);
 DestoryList(Lc);
 
}

