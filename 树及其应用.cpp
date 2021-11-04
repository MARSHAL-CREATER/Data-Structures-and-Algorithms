#include <stdio.h> 
#include <stdlib.h>
#define OVERFLOW -1
#define OK 1
#define ERROR -1
typedef struct BiTNode{       //树的二叉链表存储结构 
	char data;
	struct BiTNode *lchild,*rchild;
}BiTNode,*BiTree;
//按先序遍历的递归算法创建树 
int CreateBiTree(BiTree &T)   
{
  char ch;
  ch=getchar(); 
  if (ch==' ') T = NULL; 
  else {
  if (!(T = (BiTNode *)malloc(sizeof(BiTNode))))
  exit(OVERFLOW);
  T->data = ch; // 生成根结点
  CreateBiTree(T->lchild); // 构造左子树
  CreateBiTree(T->rchild); // 构造右子树
}
  return 0;
} 
//输出当前节点字符 
int Display(char e)
{
printf("%c\t",e);
return OK ;
}
//先序遍历二叉树
int PreOrder (BiTree T, int ( *visit)(char e))
{ 
if (T) {
  if (visit(T->data))            // 访问根结点
     if(PreOrder(T->lchild, visit)) // 遍历左子树
        if(PreOrder(T->rchild, visit))// 遍历右子树
              return OK ;
              return ERROR;
		}
		else
	return OK; 
} 
//中序遍历二叉树
int InOrder (BiTree T, int ( *visit)(char e))
{ 
if (T) {
  if (InOrder(T->lchild, visit))             // 遍历左子树
     if(visit(T->data))              // 访问根结点
        if(InOrder(T->rchild, visit))// 遍历右子树
              return OK ;
              return ERROR;
		}
		else
	return OK; 
}
//后序遍历二叉树
int PostOrder (BiTree T, int ( *visit)(char e))
{ 
if (T) {
  if (PostOrder(T->lchild, visit))             // 遍历左子树
        if(PostOrder(T->rchild, visit))// 遍历右子树
             if(visit(T->data))              // 访问根结点
              return OK ;
              return ERROR;
		}
		else
	return OK; 
}
//求二叉树高度
int GetHeight(BiTree T)
{
	int m,n;
	if(T==NULL) return 0;
	m=GetHeight(T->lchild );
	n=GetHeight(T->rchild );
	if(m>n) return m+1;
	else return n+1;
 } 
//交换二叉树的左右子树
void change(BiTree T)
{
	BiTNode *temp=(BiTNode *)malloc(sizeof(BiTNode));//或者	BiTNode *temp=NULL; 
	if(T)
	{
		if(T==NULL) return ;
		temp=T->lchild ;
		T->lchild=T->rchild;
		T->rchild=temp;
		change(T->lchild);
		change(T->rchild);
	}
}
//统计叶子节点数
void CountLeaf(BiTree T,int &count)
{
	if(T)
	if(!T->lchild&&!T->rchild ) count++;
	else{
		CountLeaf(T->lchild ,count);//统计左子树叶子数 
		CountLeaf(T->rchild ,count);//统计右子树叶子数 
	}
 } 
  //菜单界面 
 void menu()
{
    printf ("\t    树及其应用\n");
    printf ("========================================\n");
    printf ("\t1.树的创建\n");
    printf ("\t2.输出二叉树的先序序列\n");
    printf ("\t3.输出二叉树的中序序列\n");
    printf ("\t4.输出二叉树的后序序列\n");
    printf ("\t5.输出二叉树的高\n");
    printf ("\t6.输出二叉树的叶子数\n");
    printf ("\t7.交换二叉树的叶左右子树\n");
    printf ("\t0.退出系统\n");
    printf ("========================================\n");
} 
int main()
{
	int operation;
	BiTree T;int leafs,height;
	while(1){
	system("cls"); 
    menu(); 
	printf("请输入需要操作的对应序号：");
    scanf("%d", &operation);
    if(operation==0) {
	printf ("谢谢使用\n");break;}
    switch(operation){
    case 1:
	    while(getchar()!='\n');
	    //消除先前scanf函数在缓冲区写入的‘\n‘对 CreateBiTree（）中getchar()的影响 
        printf("输入带空指针标记的先序序列:\n");
	    CreateBiTree(T);
        break;
    case 2:
        printf("该二叉树的先序序列为:\n");
	    PreOrder (T,Display);
        break;
    case 3:
        printf("该二叉树的中序序列为:\n");
	    InOrder (T,Display); 
        break;
    case 4:
    	printf("该二叉树的后序序列为:\n");
	    PostOrder (T,Display);
 	    break;
 	case 5:
	    height=GetHeight( T);
	    printf("该二叉树的高度为:%d",height);
		break;
	case 6:
	    CountLeaf(T,leafs);
	    printf("该二叉树的叶子数为:%d",leafs);
	    leafs=0;//计数器清零 
	    break;
	case 7:
        change(T); 
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

