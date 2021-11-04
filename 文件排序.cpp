/*要求使用两种不同的排序算法，将指定文件中的字符按行进行插入排序。
除了使用快速排序算法之外，要求再使用一个自己熟悉的排序算法来实现）*/
#include <stdio.h>  
#include  <string.h> 
char xx[50][80];
int maxline = 0 ;                      
void readtxt(void) ;                                 
void writetxt(void) ;
void SelectSort();
void quick_sort(char s[], int l, int r);
void UseQuick();                
int main() 
{  
   readtxt();
   SelectSort();
   //UseQuick();
   writetxt() ;
   return 0;   
  } 
void readtxt(void) {   
FILE *fp;
int i = 0 ; char *p ; 
fp = fopen("in.txt", "r");
while(fgets(xx[i], 80, fp) != NULL){   
  p = strchr(xx[i], '\n');//去除换行符 ，并置为null 
  if(p)  
     xx[i][p - xx[i]] = 0 ;
     i++;
  } 
  maxline = i ;
  fclose(fp);
}
void writetxt(void) {   
FILE *fp ;  
int i ; 
  fp = fopen("out.txt", "w") ;
  for(i = 0 ; i < maxline ; i++) 
  fprintf(fp, "%s\n", xx[i]) ;  
  fclose(fp) ;  
}
//直接选择 
void SelectSort()
{
	int n,i,j,len;char k;
	for(n=0;n<maxline;n++)
	{
		len=strlen(xx[n]);//确定各行长度 
		for(i=0;i<len;i++)//各行直接插入排序 
		{
			k=xx[n][i];j=i-1;  //k是哨兵
			while(k<xx[n][j])   //由后往前查找插入位置 
			{
				if(j<0) break;
				xx[n][j+1]=xx[n][j];j--;
			}
			xx[n][j+1]=k;  //将当前最小值哨兵插入合适位置 
		}
	 } 

}
//快速排序
void quick_sort(char s[], int l, int r)
{
    if (l < r)
    {
        int i = l, j = r, x = s[l];
        while (i < j)
        {
            while(i < j && s[j] >= x) // 从右向左找第一个小于x的数
                j--;  
            if(i < j) 
                s[i++] = s[j];//将s[j]填到s[i]中，s[j]就形成了一个新的坑
            
            while(i < j && s[i] < x) // 从左向右找第一个大于等于x的数
                i++;  
            if(i < j) 
                s[j--] = s[i];//将s[i]填到s[j]中，s[i]就形成了一个新的坑
        }
        s[i] = x;//退出时，i等于j。将x填到这个坑中。
        quick_sort(s, l, i - 1); // 递归调用 
        quick_sort(s, i + 1, r);
    }
}
void UseQuick()
{
	int len;
	for(int n=0;n<maxline;n++)
	{
		    len=strlen(xx[n]);//确定各行长度 
			quick_sort(xx[n],0,len-1);
	}	
 } 
