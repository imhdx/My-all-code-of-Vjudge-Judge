#include<bits/stdc++.h>
using namespace std;
int f(int n,int m)
{
    if (n<0) return 0;
    if (m==1) return 1;
    if (n==0) return 1;
    return f(n,m-1)+f(n-m,m);
}
int main()
{
    int T;scanf("%d",&T);
    while (T--)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        printf("%d\n",f(n,m));
    }
    return 0;
}
