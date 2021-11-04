#include<stdio.h>  

#define  MAX_VERNUM  20                  //最大存储顶点数  

typedef char VexType;                 //图中元素的目标数据类型   

typedef struct      
{                    
    VexType vertexArr[MAX_VERNUM];        //顶点元素位序数组   

    int arcArr[MAX_VERNUM][MAX_VERNUM];   //弧矩阵二维数组   
    int VexNum;                              //顶点数目 

}ArrayGraph;  

void InitArrayGraph(ArrayGraph &A,int num);
void CreateArrayGraph(ArrayGraph  &A,int num) ;
void PrintArrayGraph(ArrayGraph &A) ;

int main()  
{   int vexnum;
    printf("输入要创建图顶点数：\n");
	scanf(" %d",&vexnum);
    ArrayGraph A;  
    InitArrayGraph(A,vexnum);
    CreateArrayGraph(A,vexnum) ;
    PrintArrayGraph(A) ;
    return 0;  
}  

//初始化为一个只有顶点的图   
void InitArrayGraph(ArrayGraph &A,int num)  
{  
    for (int i = 0; i < MAX_VERNUM; i++)  
    A.arcArr[i][i] = 0;  
}  

void CreateArrayGraph(ArrayGraph  &A,int num)  
{   
    //存储顶点数组 
	A.VexNum=num ;    
    for (int i = 0; i < num; ++i)  //填充顶点数组  
    {  
        printf("输入第%d个顶点值\n",i+1);  
        scanf(" %c",&(A.vertexArr[i]));   
    }
    //存储弧矩阵二维数组
    for (int j = 0; j <num; ++j)   //填充边关系   
    {  
        for (int i = j+1; i < num; ++i)  
        {  

            printf("若%c与%c之间有弧，则输入1，否则输入0\t",A.vertexArr[i],A.vertexArr[j]);  
            scanf("%d",&(A.arcArr[i][j]));  
            if(A.arcArr[i][j]==1)
			A.arcArr[j][i]=1;
			else A.arcArr[j][i]=0;
            /*  变为有向图，只要删除if else, 加上以下代码 
			printf("若元素%c有指向%c的弧，则输入1，否则输入0\t",A.vertexArr[j],A.vertexArr[i]]);  
            scanf("%d",&( A.arcArr[j][i]));
            */
        }  
    }  
}  


void PrintArrayGraph(ArrayGraph &A)  
{   //顶点输出 
    printf("\n\n顶点元素如下\n");  
    for (int i = 0; i < A.VexNum; ++i)  
    {  
        printf("%-5c", A.vertexArr[i]);  
    }  
    printf("\n\n");  
    puts("弧矩阵如下\n\n");   
    printf("%-2c",' '); 
	 
    for(int i=0;i<A.VexNum;++i)  
      printf("%-5c",A.vertexArr[i]);  
    putchar('\n');    

    for (int i = 0; i <A.VexNum; ++i)  
    {  
        printf("%-2c",A.vertexArr[i]);  
        for (int j = 0; j < A.VexNum; ++j)  
        {  
            printf("%-5d",A.arcArr[i][j]);  

        }  
        putchar('\n');  
    }  
    putchar('\n');    
}  
