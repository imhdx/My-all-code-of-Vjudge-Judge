#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<queue>
#include<vector>
#include<iostream>
using namespace std;
const int MAXN=1e6;

int main()
{
    int n;
    while (scanf("%d",&n)!=EOF)
    {
        int m=n;
        int i=2;
        int maxx=0;
        for (i=2;i<=n;i++)
        {
            while (n%i==0)
            {
                maxx=max(maxx,i);
                n=n/i;
            }
        }
        if (maxx==0) printf("0\n");
        else
            printf("%d\n",m/maxx);
    }
    return 0;
}
