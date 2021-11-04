#include <stdio.h>
#include <stdlib.h> 
void Merge(int a[],int l1,int r1,int l2,int r2);
void Msort(int a[],int left,int right);

int main()
{
	int a[]={1,8,6,4,10,5,3,2,22};
	Msort(a,0,8);
	for(int i=0;i<sizeof(a)/sizeof(int);i++)
	printf("%d\t",a[i]);
	return 0;
}
//划分 
void Msort(int a[],int left,int right){
	if(left<right){
	int mid=(left+right)/2;
	Msort(a,left,mid);
	Msort(a,mid+1,right);
	//合并
	Merge(a,left,mid,mid+1,right);	
	}	
}
//归并
void Merge(int a[],int l1,int r1,int l2,int r2){
	int i=l1;int j=l2;
	int *temp,index=0;
	temp=(int *)malloc(sizeof(a));
	while(i<=r1&&j<=r2){
		if(a[i]<=a[j]){
		  temp[index++]=a[i++];	
		}else{
		  temp[index++]=a[j++];	
		}
	}
	while(i<=r1){
	   temp[index++]=a[i++];
	}
	while(j<=r2){
	   temp[index++]=a[j++]	;
	}
	for(int i=0;i<index;i++){
		a[l1+i]=temp[i];	
	}
	free(temp);	
} 
