#define ElemType int
#define Status  int

#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 100
#define ERROR 1
#define OK 0
typedef struct 
{
	int i,j;
	ElemType e;
 } Triple;
 typedef struct{
 	Triple data[MAXSIZE+1];
 	int mu,nu,tu;
 }TSMatrix;
  void CreateTS(TSMatrix &M);
 void PrintMatrix(TSMatrix M); 
void Add(TSMatrix A, TSMatrix B, TSMatrix &C);
void Substra(TSMatrix M, TSMatrix N, TSMatrix &Q); 
void MultiplyTS(TSMatrix A, TSMatrix B, TSMatrix &C);
 void menu();
 int main()
 {
 	TSMatrix M,N,Q;
 	printf("请输入矩阵A：\n");
 	CreateTS(M);
 	PrintMatrix( M) ;
 	printf("请输入矩阵B：\n");
 	CreateTS(N);
 	PrintMatrix( N) ;
 	int operation;
	 while(1){
	system("cls"); 
    menu();
    printf("A=\n"); 
	PrintMatrix( M);
	printf("B=\n");
	PrintMatrix( N);
	printf("请输入需要操作的对应序号：");
    scanf("%d", &operation);
    if(operation==0) {
	printf ("谢谢使用\n");break;}
    switch(operation){
    case 1: 
	    Add( M, N, Q);
	    PrintMatrix( Q);
        break;
    case 2:
        Substra( M, N, Q);
	    PrintMatrix( Q);
        break;
    case 3:
    	MultiplyTS( M,  N, Q);
    	PrintMatrix( Q);
 	    break;
    case 0:
        break;
    default:
        printf ("输入错误\n");
        break;
    }
    system("pause"); 
   }
	return 0;
 }
 //矩阵建立
  void CreateTS(TSMatrix &M)
{
	int t, m, n;
	ElemType e;
	bool k;
	printf( "请输入矩阵的行数,列数,非零元个数：");
    scanf("%d,%d,%d", &M.mu, &M.nu, &M.tu);
	M.data[0].i = 0;
	for (t = 1; t<=M.tu; ++t)
	{
		do
		{
			printf("请按行序顺序输入第%d个非零元素所在的行（1~%d）,列（1~%d），元素值：", t, M.mu, M.nu);
			scanf("%d,%d,%d", &m, &n, &e);
			k = false;
			if (m<1 || m>M.mu || n<1 || n>M.nu)//行或列超出范围
				k = true;
			if (m < M.data[t - 1].i || m == M.data[t - 1].i&&n <= M.data[t - 1].j)//行或列的顺序有错
				k = true;
		} while (k);//输入错误则不断循环当前值的输入 
		M.data[t].i = m;
		M.data[t].j = n;
		M.data[t].e = e;
	}
}
 //矩阵打印
 void PrintMatrix(TSMatrix M)
 {
 	int i,j,k=1;//k用与计数当前非零值个数 
 	Triple *p=M.data ;
 	p++;//P指向第一个元素 
 	for(i=1;i<=M.mu;i++){
 		for(j=1;j<=M.nu;j++)
 		if(k<=M.tu &&p->i==i&&p->j==j)
 		{
 			printf("%3d",p->e);
 			p++;
 			k++;
		 }
		 else
		   printf("%3d",0);
		   printf("\n");
	 }
  } 
  //矩阵加法
void Add(TSMatrix A, TSMatrix B, TSMatrix &C)
{
	
	if(A.mu!=B.mu || A.nu!=B.nu)
    {
    printf("\n 不满足矩阵相加条件!");
    printf("\n 需满足两矩阵的行数、列数均对应相等方可进行加法运算！！");
    } 
	C.mu = A.mu;
	C.nu = A.nu;
	C.tu = 0;
    int i = 1, j = 1, m = 1;
    int sum;
    while(i<=A.tu && j<=B.tu)
    {//A和B都没有计算结束的时候
        if(A.data[i].i<B.data[j].i|| (A.data[i].i==B.data[j].i && A.data[i].j<B.data[j].j))
        {//A的元素在B元素的前面
            C.data[m].i = A.data[i].i;
            C.data[m].j = A.data[i].j;
            C.data[m].e = A.data[i].e;
            m++;
            i++;
        }
        else if(A.data[i].i==B.data[j].i && A.data[i].j==B.data[j].j)
        {//A和B的元素行号列号相等
            sum = A.data[i].e + B.data[j].e;
            if(sum != 0)//不等于0的时候才能赋值
            {
                C.data[m].i= A.data[i].i;
                C.data[m].j= A.data[i].j;
                C.data[m].e = sum;
                m++;
            }
            i++;
            j++;
        }
        else
        {//B元素在A元素前面
            C.data[m].i = B.data[j].i;
            C.data[m].j = B.data[j].j;
            C.data[m].e = B.data[j].e;
            m++;
            j++;
        }
    }
    while(i<=A.tu)
    {//A矩阵还没有输完
        C.data[m].i = A.data[i].i;
        C.data[m].j = A.data[i].j;
        C.data[m].e = A.data[i].e;
        i++;
        m++;
    }
    while(j<=B.tu)
    {//B矩阵还没有输完
        C.data[m].i = B.data[j].i;
        C.data[m].j = B.data[j].j;
        C.data[m].e = B.data[j].e;
        j++;
        m++;
    }
    C.tu = m;//C矩阵中非零元的个数
}
//减法 
void Substra(TSMatrix M, TSMatrix N, TSMatrix &Q)
{
	int i;
	if (M.mu != N.mu || M.nu != N.nu)
		exit(1);
	for (i = 1; i <= N.tu; ++i) /* 对于N的每一元素,其值乘以-1 */
		N.data[i].e *= -1;
	Add(M, N, Q); /* Q=M+(-N) */
}
//乘法
void MultiplyTS(TSMatrix A, TSMatrix B, TSMatrix &C)
{ //矩阵相乘
	int i, j, h = A.mu, l = B.nu, Cn = 0;
	//h,l为矩阵C的行,列值,Cn为矩阵C的非零元个数,初值为零
	ElemType *Ce;
	if (A.nu != B.mu)
		exit(1);
	C.mu = A.mu;
	C.nu= B.nu;
	Ce = new ElemType[h*l];
	for (i = 0; i<h*l; i++)
		*(Ce + i) = 0; //矩阵中所有元素初始化为零
	for (i = 1; i <= A.tu; i++)
		for (j = 1; j <= B.tu; j++)
			if (A.data[i].j == B.data[j].i)
				*(Ce + (A.data[i].i - 1)*l + B.data[j].j - 1) += (A.data[i].e)*(B.data[j].e);
	for (i = 1; i <= A.mu; i++)
	{
		for (j = 1; j <= B.nu; j++)
		{
			if (*(Ce + (i - 1)*l + j - 1))
			{
				Cn++;
				C.data[Cn].e = *(Ce + (i - 1)*l + j - 1);
				C.data[Cn].i = i;
				C.data[Cn].j = j;
			}
		}
	}
	delete Ce;
	C.tu = Cn;
}
 //菜单界面 
 void menu()
{
    printf ("\t    稀疏矩阵的基本运算\n");
    printf ("========================================\n");
    printf ("\t1.矩阵加法\n");
    printf ("\t2.矩阵减法\n");
    printf ("\t3.矩阵乘法\n");
    printf ("\t0.退出系统\n");
    printf ("========================================\n");
     
}
 


