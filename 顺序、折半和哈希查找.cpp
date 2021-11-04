#include <stdio.h>
#include <stdlib.h>
#define Init_SSTable_Num 100
#define LEN 10
int hash[LEN]={0};   //哈希表初始化为0
 
typedef struct{
	int *elem;
	int length;
}SSTable;
int InitSSTable(int a[],SSTable &List,int len)
{
	List.elem=(int*)malloc(Init_SSTable_Num*sizeof(int));
	if(!List.elem) exit(1);
	List.length=0;
	for(int i=1;i<=len;i++)
	{
		List.elem[i]=a[i-1];
		List.length ++;
	}
	return 0;
}
//顺序查找 
int Search_Seq(SSTable List,int key) 
{
	List.elem[0]=key;               //设置监视哨 
	int i=0;
	for( i=List.length;List.elem[i]!=key;i--);
		return i;
	
}
//折半查找
int Search_Bin(SSTable List,int key)
{
	int mid,low=1;
	int high=List.length;
	while(low<= high){
	    mid=(low+high)/2;
		if(List.elem[mid]==key) return mid;
		else if(List.elem [mid]<key) low=mid+1;
		else high=mid-1;
	} 
	return 0;
 } 
 //哈希表的插入 
 void InsertHash(int data[])
{
	for(int i=0;i<LEN;i++)  
	{
		//将关键字插入到哈希表hash中；
		int j=data[i]%10;       //计算哈希地址
		while(hash[j])          //元素位置已被占用
			j=(++j)%LEN;        //线性探测法解决冲突
		hash[j]=data[i];
	}
}
//哈希表查找 
int Search_Haxi(int key)
{
	int i=key%LEN;  //计算哈希地址；
	while(hash[i]&&hash[i]!=key)   //判断是否冲突
		i=(++i)%LEN;   //线性探测法解决冲突
	if(hash[i]==0)  //查找到开放单元，表示查找失败
		return -1; 
	else
		return i;   //返回对应的元素下标
}
 //菜单界面 
 void menu()
{
    printf ("\t  顺序、折半和哈希查找操作的实现\n");
    printf ("========================================\n");
    printf ("\t1.顺序查找\n");
    printf ("\t2.折半查找\n");
    printf ("\t3.哈希查找\n");
    printf ("\t4.输出顺序表\n");
    printf ("\t5.输出哈希表\n");
    printf ("\t0.退出系统\n");
    printf ("========================================\n");
}
int main()
{
	SSTable List;
	int key,operation,t;
	printf("输入查找的关键字:");
	scanf("%d",&key);
	int b[10]={23,45,46,55,76,89,100,110,568,600};
	InitSSTable(b,List,10);  //顺序表赋值 
	InsertHash(b);           //哈希表赋值 
    while(1){
	system("cls"); 
    menu(); 
	printf("请输入需要操作的对应序号：");
    scanf("%d", &operation);
    if(operation==0) {
	printf ("谢谢使用\n");break;}
    switch(operation){
    case 1:
	    t= Search_Seq( List, key);
        printf("顺序查找的结果为：%d",t) ;
        break;
    case 2:
        t=Search_Bin( List,key);
        printf("折半查找的结果为：%d",t) ;
        break;
    case 3:
    	t=Search_Haxi(key); 
        printf("查找成功，该关键字在哈希表中的下标为 %d !!!",t); 
        break; 
    case 4:
    	printf("顺序表中各元素的值:\n");
    	for(int i=1;i<=10;i++)
	    printf("%d\t",List.elem[i]);
	    break;
	case 5:
		printf("哈希表中各元素的值:\n");
	    for(int i=0;i<LEN;i++)
		printf("%d\t",hash[i]);
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


