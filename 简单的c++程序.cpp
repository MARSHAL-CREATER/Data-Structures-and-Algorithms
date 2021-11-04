#include <iostream>
void change(int &x,int &y)
{
	int t;
	t=x;x=y;y=t;
 } 
 int main()
 {
 	int a=3,b=5;
 	change(a,b);
 	std::cout<<a<<'\t'<<b<<std::endl;
 	getchar();
 }
