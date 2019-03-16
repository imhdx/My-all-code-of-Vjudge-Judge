#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
long long int n;
long long best;
long long maxn;
int prim[30]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47};
void dfs(ll sum,ll cur,int k,int t)
{
    if (maxn<sum)
    {
        maxn=sum;
        best=cur;
    }
    if (maxn==sum&&cur<best)
    {
        best=cur;
    }
    if (k>14) return ;
    ll tmp=cur;
    for (int i=1;i<=t;i++)
    {
        if (tmp*prim[k]>n)
            break;
        tmp=tmp*prim[k];///相当于cur*prim[k]^i;  在尝试次数
        dfs(sum*(i+1),tmp,k+1,i);
    }
}
int main()
{
    while (scanf("%lld",&n)!=EOF)
    {
        best=1;
        maxn=1;
        dfs(1,1,0,50);
        printf("%lld\n",best);
    }
    return 0;
}
