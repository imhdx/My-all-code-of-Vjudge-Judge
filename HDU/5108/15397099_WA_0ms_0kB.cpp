#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<queue>
#include<vector>
#include<iostream>
using namespace std;
const int MAXN=1e6;
bool check[MAXN];
int prim[MAXN];
int cnt;
void init()
{
    int i;
    long long j;
    cnt=0;
    for (i=2;i<MAXN;i++)
    {
        if (check[i]==0)
        {
            prim[cnt++]=i;
            for (j=1ll*i*i;j<MAXN;j=j+i)
                check[j]=1;
        }
    }
}
int main()
{
    init();
    int n;
    while (scanf("%d",&n)!=EOF)
    {
        int m=n;
        int i;
        int maxx=0;
        for (i=0;i<cnt&&prim[i]<n;i++)
        {
            while (n%prim[i]==0)
            {
                maxx=max(maxx,prim[i]);
                n=n/prim[i];
            }
        }
        maxx=max(maxx,n);
        if (maxx==0) printf("0\n");
        else
            printf("%d\n",m/maxx);
    }
    return 0;
}
