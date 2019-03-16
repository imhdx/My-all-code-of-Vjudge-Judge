#include<bits/stdc++.h>
using namespace std;
int a[100005];
void qs(int left,int right)
{
	int temp,i,j,t;
	if(left>right)
	return;

	temp=a[left];
	i=left;
	j=right;

	while(i!=j)
	{
		while(a[j]>=temp&&i<j)
		j--;
		while(a[i]<=temp&&i<j)
		i++;

		if(i<j)
		{
			t=a[i];
			a[i]=a[j];
			a[j]=t;
		}
	}

	a[left]=a[i];
	a[i]=temp;
	qs(left,i-1);
	qs(i+1,right);

}
int main()
{
	int n=1;
	int i=0,m;

	while(scanf("%d",&m)!=EOF)
	a[n++]=m;
	n--;
	sort(a+1,a+1+n);
	printf("%d",a[1]);
	for(i=2;i<=n;i++)
	printf(" %d",a[i]);
	printf("\n");

	return 0;
}
