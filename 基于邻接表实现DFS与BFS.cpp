#include<stdio.h>
#include <stdlib.h>
#define MVNum 100
typedef int SElemType;
typedef int Status;
bool visited[MVNum]; 
typedef struct ArcNode // 边表结点
{
    int adjvex;    // 邻接点域,存储该顶点对应的下标(vertices中的位序)
    //int info;      //用于存储权值,对于非网图可以不需要
    struct ArcNode *nextarc; // 链域,指向下一个邻接点
}ArcNode;
typedef struct VNode // 顶点表结点
{
    char data; // 顶点域,存储顶点信息
    ArcNode *firstarc; // 边表头指针
}VNode, AdjList[MVNum];
typedef struct
{
    AdjList vertices;
    int vexnum,arcnum; // 图中当前顶点数和边数
}ALGraph;
//队列存储
typedef struct {
int front;//队头指针 
int rear;//队尾指针	
SElemType* data;//存储基地址	
}SqQueue; 

int LocateVex(ALGraph &G,char v);
void  CreateALGraph(ALGraph &G);
void DispGraphAdjList(ALGraph &G);
void DFS(ALGraph &G, int i);
void DFSTraverse(ALGraph &G);
Status InitQueue(SqQueue &S);
Status EmptyQueue(SqQueue S);
Status EnterQueue(SqQueue &S,SElemType e);
Status DeQueue(SqQueue &S,SElemType &e);
void BFSTraverse(ALGraph &G);

int main(void)
{
    ALGraph G;
    CreateALGraph(G);
    printf("\n邻接表为: \n");
    DispGraphAdjList(G);
    printf("\n\n图的深度优先遍历为: ");
    DFSTraverse(G);
	printf("\n图的广度优先遍历为: ");
    BFSTraverse(G); 
    return 0;
}
int LocateVex(ALGraph &G,char v)//找到v在邻接表G中的位置
{
    for(int i=0;i<G.vexnum;i++)
    {
        if(G.vertices[i].data==v)
            return i;
    }
    return -1;
}
void  CreateALGraph(ALGraph &G)
{
    int i,j,k,v;
    char v1,v2;
    ArcNode *p1,*p2;
    printf("请输入顶点(空格)边数：") ;
    scanf("%d%d",&G.vexnum,&G.arcnum); // 输入顶点数和边数
    printf("\n请输入顶点字母：\n") ;
    for(v = 0;v < G.vexnum;v++) // 读入顶点信息,建立顶点表
    {       
        scanf("%s",&G.vertices[v].data);     // 输入顶点信息
        G.vertices[v].firstarc=NULL;     // 将边表置为空表
    }
    getchar();
    printf("\n请输入相连的顶点序列（如：A B）：\n") ;
    for(k = 0;k < G.arcnum;k++)// 建立边表
    {
    	
        scanf("%c %c",&v1,&v2);
        getchar();
        i=LocateVex(G,v1);
        j=LocateVex(G,v2);
        p1=new ArcNode; // 向内存申请空间,生成边表结点
        p1->adjvex=j;    // 邻接序号为j
        p1->nextarc=G.vertices[i].firstarc;    //将e的指针指向当前顶点上指向的结点
        G.vertices[i].firstarc=p1;            // 将当前顶点的指针指向e

        p2=new ArcNode; // 向内存申请空间,生成边表结点
        p2->adjvex=i;    //邻接序号为i
        p2->nextarc=G.vertices[j].firstarc;    // 将e的指针指向当前顶点上指向的结点
        G.vertices[j].firstarc=p2;        // 将当前顶点的指针指向e
    }
}
void DispGraphAdjList(ALGraph &G)
{
    int i;
    ArcNode *p;
    for(i=0;i< G.vexnum;i++)
    {
        printf("%c",G.vertices[i].data);
        for(p=G.vertices[i].firstarc;p!=NULL;p=p->nextarc)
            printf("->%c",G.vertices[p->adjvex].data);
        printf("\n");
    }
}
// 深度优先遍历打印 
void DFS(ALGraph &G, int i){
    visited[i] = 1;  
    printf("%c ", G.vertices[i].data);  
    
    ArcNode *p = G.vertices[i].firstarc  ;
    while(p){
        if(!visited[p->adjvex ]){
            DFS(G,p->adjvex  ); //递归深度遍历
        }
        p= p->nextarc ;
    }
}
// 深度优先遍历
void DFSTraverse(ALGraph &G){
    int i;  
    for (i=0; i<G.vexnum ; ++i){ 
        visited[i] = 0;  //初始化访问数组visited的元素值为false
    }
    for (i=0; i<G.vexnum ; ++i){
        if(!visited[i]){ //节点尚未访问
            DFS(G,i);
        }
    }
}
//初始化
Status InitQueue(SqQueue &S)
{
  S.data=(SElemType*)malloc(MVNum *sizeof(SElemType));	
  if(!S .data) exit(1);
  S.front=S.rear=0;
  return 0;	
}
//判断队列是否为空
Status EmptyQueue(SqQueue S)
{
   	if(S.front==S.rear )
    return 1;
	else
	return 0; 
 }
 //元素入队
 Status EnterQueue(SqQueue &S,SElemType e)
 {
 	if((S.rear+1)%MVNum==S.front ) exit(1);//队尾的下一个是队头，则队满 
  	S.data[S.rear]=e;
  	S.rear=(S.rear+1)%MVNum;//构建循环队列 
  	return 0;	
}
  //元素出队，并用e返回出队元素 
  Status DeQueue(SqQueue &S,SElemType &e)
  {
  	if(S.front==S.rear ) exit(1);
  	e=S.data[S.front];
	S.data[S.front]=0; 
  	S.front=(S.front+1)%MVNum;//构建循环队列 
  	return 0;	
   }
//图的广度优先遍历   
void BFSTraverse(ALGraph &G){  
    int i;  
    SqQueue Q; 
    InitQueue(Q);
    for (i=0; i<G.vexnum ; ++i){  
        visited[i] = 0; 
    } 
    for (i=0; i<G.vexnum ; ++i){  
        if(!visited[i]){  
            visited[i] = 1;  
            printf("%c ", G.vertices[i].data);  
            EnterQueue(Q, i);  
            while (!EmptyQueue(Q)){  
                DeQueue(Q, i);  
                ArcNode *p = G.vertices[i].firstarc;  
                while (p){  
                    if (!visited[p->adjvex]){  
                        visited[p->adjvex] = 1;  
                        printf("%c ", G.vertices[p->adjvex].data );  
                        EnterQueue(Q, p->adjvex );  
                    }  
                    p = p->nextarc ;  
                }
            }
        }  
    }    
}
