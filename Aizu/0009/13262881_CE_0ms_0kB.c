#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstdlib>
#include<cstring>
using namespace std;
int pri[1000000];
int main()
{
    int i,j;
    memset(pri,0,1000000*sizeof(int));
    for (i=2;i<=1000;i++)
    {
        for (j=i*i;j<1000000;j=j+i)
        {
            pri[j]=1;
        }
    }
    int n;
    while (scanf("%d",&n)!=EOF)
    {
        int sum=0;
        for (i=2;i<=n;i++)
            if (pri[i]==0) sum++;
        printf("%d\n",sum);
    }
    return 0;
}
