#include<iostream>
#include<cstring>
#include<cstdlib>
#include<cstdio>
using namespace std;
int prime[10000];
int main()
{
    memset(prime,0,10000*sizeof(int));
    int i,j;
    for (i=2;i<10000;i++)
    {
        if (prime[i]==0)
        {
            for (j=i*i;j<10000;j=j+i)
                prime[j]=1;
        }
    }
    int n;
    while (scanf("%d",&n)!=EOF)
    {
        for (i=n/2;i>=2;i--)
        {
            if (prime[i]==0&&prime[n-i]==0)
            {
                printf("%d %d\n",i,n-i);
                break;
            }
        }
    }
    return 0;
}
