#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int N=200010;
int tree[N*4];
int n,h,w;


void maketree(int l,int r,int rt)
{
    if(l==r)
    {
        tree[rt]=w;
        return;
    }
    int mid=(l+r)/2;
    maketree(l,mid,rt*2);
    maketree(mid+1,r,rt*2+1);
    tree[rt]=max(tree[rt*2],tree[rt*2+1]);
}

///单点修改，a[p]=x
int gai(int l,int r,int rt,int x)
{
    if(l==r)
    {
        tree[rt]-=x;
        return l;
    }
    int mid=(l+r)/2;
    int ans;
    if(tree[rt*2]>=x)
        ans=gai(l,mid,rt*2,x);
    else
        ans=gai(mid+1,r,rt*2+1,x);
    tree[rt]=max(tree[rt*2],tree[rt*2+1]);
    return ans;
}


int main()
{
    while (scanf("%d%d%d",&h,&w,&n)!=EOF)
    {
        int i;
        maketree(1,min(h,n),1);
        for (i=0; i<n; i++)
        {
            int a;
            scanf("%d",&a);
            if (a>tree[1])
                printf("-1\n");
            else
            {
                printf("%d\n",gai(1,min(h,n),1,a));
            }
        }
    }
    return 0;
}