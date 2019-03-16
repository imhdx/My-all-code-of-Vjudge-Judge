#include <set>
#include <map>
#include <list>
#include <deque>
#include <cmath>
#include <queue>
#include <stack>
#include <bitset>
#include <vector>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <iomanip>
#include <cstring>
#include <fstream>
#include <iostream>
#include <algorithm>
#pragma comment(linker, "/STACK:1024000000,1024000000")
using namespace std;

const int maxn=1e6+5;
int mn[maxn<<2];
int c[maxn];
int b[maxn];

void pushup(int rt)
{
    mn[rt]=min(mn[rt<<1],mn[rt<<1|1]);
}
void build(int l,int r,int rt)
{
    if(l==r)
    {
        if(l==1)
            mn[rt]=0;
        else
            mn[rt]=-1;
        return;
    }
    int m=l+(r-l)/2;
    build(l,m,rt<<1);
    build(m+1,r,rt<<1|1);
    pushup(rt);
}
void update(int pos,int be,int l,int r,int rt)
{
    if(l==r)
    {
        mn[rt]=be;
        return;
    }
    int m=l+(r-l)/2;
    if(pos<=m)
        update(pos,be,l,m,rt<<1);
    else
        update(pos,be,m+1,r,rt<<1|1);
    pushup(rt);
}
int query(int l,int r,int rt,int tr)
{
    if(l==r)
    {
        return l;
    }
    int m=l+(r-l)/2;
    if(mn[rt<<1]<tr)
        return query(l,m,rt<<1,tr);
    else
        return query(m+1,r,rt<<1|1,tr);
}
int main()
{
    int n;
    scanf("%d",&n);
    build(1,n,1);
    for(int i=1; i<=n; i++)
    {
        scanf("%d",&c[i]);
        int ans=query(1,n,1,i-c[i]);
        printf("%d",ans);
        if(i!=n)
            printf(" ");
        update(ans,i,1,n,1);
    }
    printf("\n");
    return 0;
}
