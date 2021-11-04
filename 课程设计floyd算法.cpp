#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXN 20 
#define inf  1000
int load[17][17]={{inf,12,inf,inf,18,inf,inf,inf,inf,inf,inf,inf,inf,inf,inf,inf,inf},
                  {12,inf,3,3,inf,inf,inf,inf,inf,inf,inf,inf,inf,inf,inf,inf,inf},
				  {inf,3,inf,4,inf,inf,19,inf,inf,inf,inf,inf,inf,inf,inf,inf,inf},
				  {inf,3,4,inf,7,inf,inf,21,inf,inf,inf,inf,inf,inf,inf,inf,inf},
				  {18,inf,inf,7,inf,18,inf,inf,inf,31,inf,inf,inf,inf,inf,inf,inf},
				  {inf,inf,inf,inf,18,inf,inf,inf,3,12,inf,inf,inf,inf,inf,inf,inf},
				  {inf,inf,19,inf,inf,inf,inf,4,inf,inf,inf,7,inf,inf,inf,inf,inf},
				  {inf,inf,inf,21,inf,inf,4,inf,13,inf,6,inf,inf,inf,inf,inf,inf},
				  {inf,inf,inf,inf,inf,3,inf,13,inf,inf,inf,inf,inf,9,inf,inf,inf},
				  {inf,inf,inf,inf,31,12,inf,inf,inf,inf,inf,inf,inf,inf,inf,inf,35},
				  {inf,inf,inf,inf,inf,inf,inf,6,inf,inf,inf,5,6,inf,inf,inf,inf},
				  {inf,inf,inf,inf,inf,inf,7,inf,inf,inf,5,inf,inf,inf,inf,14,inf},
				  {inf,inf,inf,inf,inf,inf,inf,inf,inf,inf,6,inf,inf,9,6,inf,inf},
				  {inf,inf,inf,inf,inf,inf,inf,inf,9,inf,inf,inf,9,inf,inf,inf,24},
				  {inf,inf,inf,inf,inf,inf,inf,inf,inf,inf,inf,inf,6,inf,inf,6,8},
				  {inf,inf,inf,inf,inf,inf,inf,inf,inf,inf,inf,14,inf,inf,6,inf,7},
				  {inf,inf,inf,inf,inf,inf,inf,inf,inf,35,inf,inf,inf,24,8,7,inf}};
const char* vex[]={"Sm RmPhezz","Dmss","Daly cu","San Franclsco","Oakland","Sm larcnro",
                   "Cross B","Maleo","Hnyward","Dublan","Rcdwood City","Cross C",
		           "Pakr Alao","Frocknom","Mtm View","Cupenin","San Jose"};
typedef struct struct_graph{
    const char* vex[];
    int vexnum;//顶点数 
    int edgnum;//边数 
    int matirx[MAXN][MAXN];//邻接矩阵 
} Graph;

int pathmatirx[MAXN][MAXN];//记录对应点的最小路径的前驱点
int shortPath[MAXN][MAXN];//记录顶点间的最小路径值
//floyd算法 
void floyd(Graph G, int P[MAXN][MAXN], int D[MAXN][MAXN]){
    int v, w, k;
    //初始化floyd算法的两个矩阵 
    for(v = 0; v < G.vexnum; v++){
        for(w = 0; w < G.vexnum; w++){
            D[v][w] = G.matirx[v][w];
            P[v][w] = w;
        }
    }

    //更新floyd算法的两个矩阵 
    //k为中间点 
    for(k = 0; k < G.vexnum; k++){
        //v为起点 
        for(v = 0 ; v < G.vexnum; v++){
            //w为终点 
            for(w =0; w < G.vexnum; w++){
                if(D[v][w] > (D[v][k] + D[k][w])){
                    D[v][w] = D[v][k] + D[k][w];//更新最小路径 
                    P[v][w] = P[v][k];//更新最小路径中间顶点 
                }
            }
        }
    }
}
//与用户交互，输出最短路径 
void Interact(Graph G, int P[MAXN][MAXN], int D[MAXN][MAXN])
{
	int v, w, k;
    printf("请输入起始街道名称或编号：\n");
    char aa[10],bb[5];
    gets(aa); 
    for(int i=0;i<G.vexnum;i++)
    {
    	if(!strcmp(aa,*(vex+i)))
        v=i;
        sprintf(bb,"%d",i);//数字转字符 
        if(!strcmp(aa,bb))
        v=i;
	} 
    printf("请输入最终街道名称或编号：\n");
    gets(aa); 
    for(int i=0;i<G.vexnum;i++)
     {
    	if(!strcmp(aa,*(vex+i)))
        w=i;
        sprintf(bb,"%d",i);//数字转字符
        if(!strcmp(aa,bb))
        w=i;
	}
    printf("\n编号%d ->编号%d 的最小路径为：%d\n", v, w, D[v][w]);
    k = P[v][w];
    printf("path: %s", *(vex+v));//打印起点
    while(k != w){
        printf("-> %s", *(vex+k));//打印中间点
        k = P[k][w]; 
    }
    printf("-> %s\n", *(vex+w));
}
//初始化邻接矩阵 
void Init_matirx(Graph &G)
{
    int v, w;
    G.vexnum=17;
    for(v = 0; v < G.vexnum; v++){
        for(w = 0; w < G.vexnum; w++){
            G.matirx[v][w]=load[v][w];
        }
    }	
 } 
int main(){
     Graph G;
     Init_matirx(G);
     floyd(G, pathmatirx, shortPath);
     Interact(G, pathmatirx, shortPath);
}

