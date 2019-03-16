#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdlib>
using namespace std;
int a[6000];
int pri[30000];
int main()
{
    int i,j,n;
    memset(pri,0,30000*sizeof(int));
    for (i=2;i<200;i++)
    {
        for (j=i*i;j<30000;j=j+i)
            pri[j]=1;
    }
    while (scanf("%d",&n)!=EOF)
    {
        for (i=0;i<n;i++)
            scanf("%d",&a[i]);
        int flag=-1;
        int maxx=0;
        for (i=0;i<n;i++)
        {
            for (j=a[i];j>=1;j--)
            {
                if (pri[j]==0&&a[i]%j==0&&j>maxx)
                {
                    maxx=j;
                    flag=i;
                    break;
                }
            }
        }
        printf("%d\n",a[flag]);
    }
    return 0;
}
