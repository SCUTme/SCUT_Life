#include<iostream>
using namespace std;
int main()
{
	int a[2][2]={1,2,3,4};
	cout<<"a="<<a<<"\n";
	int *p=&a[0][0];
	int **p1=&p;
	cout<<"&a="<<&a<<"\n";
	cout<<"*a="<<*a<<"\n";
	cout<<"(*(a+1)+1)="<<(*(a+1)+1)<<"\n";
	cout<<"&a[1][1]="<<&a[1][1]<<"\n";
	cout<<"*(*(a+1)+1)="<<*(*(a+1)+1)<<"\n";
	/*堆区
	int *p2=new int(10);
	cout<<"*p2="<<*p2<<endl;*/
	cout<<"a[0]="<<a[0]<<"\n";
	cout<<"&a[0][0]="<<&a[0][0]<<"\n";
	cout<<"*(p+2)="<<*(p+2)<<endl;
	cout<<"p1="<<p1<<endl;
	cout<<"*p1="<<*p1<<endl;
	cout<<"**p1="<<**p1<<endl;
	getchar();
}