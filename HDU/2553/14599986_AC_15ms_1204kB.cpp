#include<stdio.h>
using namespace std;
int main()
{
	int a[]={0,1,0,0,2,10,4,40,92,352,724};
	int n; 
	while(~scanf("%d",&n)&&n){
		printf("%d\n",a[n]);
	}
	return 0;
}