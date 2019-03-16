#include<stdio.h>
#include<iostream>
#include<string.h>
using namespace std;
int a[100005];
void quicksort(int b,int e){
   int i=b,j=e;
   int  mid=a[(i+j)/2],t;
    do{
        while(a[i]<mid) i++;
        while(a[j]>mid) j--;
        if(i<=j)
         {
              t=a[i],a[i]=a[j],a[j]=t;i++;j--;
         }
    }while(i<=j);
    if(i<e) quicksort(i,e);
    if(j>b) quicksort(b,j);
}
int main()
{
	int n=1;
	int i=0,m;
	
	while(scanf("%d",&m)!=EOF)
	a[n++]=m;
	n--;
	
	
	
	quicksort(1,n);
	
	printf("%d",a[1]);
	for(i=2;i<=n;i++)
	printf(" %d",a[i]);
	printf("\n");
    
	return 0;
}