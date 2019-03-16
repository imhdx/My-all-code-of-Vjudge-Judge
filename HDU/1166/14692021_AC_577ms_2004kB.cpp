

#include<bits/stdc++.h>
using namespace std;
const int MAXN=50005;
int belong[MAXN],num,block,l[MAXN],r[MAXN];
int a[MAXN];
int n;
int v[MAXN];
void build()
{
    block=sqrt(n);
    num=n/block;
    if (n%block)
        num++;
    int i;
    for (i=1; i<=num; i++)
        l[i]=(i-1)*block+1,r[i]=i*block;
    r[num]=n;
    for (i=1; i<=n; i++)
        belong[i]=(i-1)/block+1;
}
void gai(int tl,int x)
{
    a[tl]+=x;
    v[belong[tl]]+=x;
}
int ask(int tl,int tr)
{
    int i;
    int ans=0;
    if (belong[tl]==belong[tr])
    {
        for (i=tl; i<=tr; i++)
        {
            ans+=a[i];
        }
        return ans;
    }
    for (i=tl; i<=r[belong[tl]]; i++)
        ans+=a[i];
    for (i=belong[tl]+1; i<belong[tr]; i++)
    {
        ans+=v[i];
    }
    for (i=l[belong[tr]]; i<=tr; i++)
        ans+=a[i];
    return ans;
}
int main()
{
    memset(v,0,sizeof(v));
    int i;
    int TT;
    scanf("%d",&TT);
    int cccc=1;
    while (TT--)
    {
        scanf("%d",&n);
        build();
        memset(v,0,sizeof(v));
        for (int i=1; i<=n; i++)
        {
            scanf("%d",&a[i]);
            v[belong[i]]+=a[i];
        }
        printf("Case %d:\n",cccc++);
        string str;
        while (cin>>str)
        {
            if (str=="Query")
            {
                int x,y;
                scanf("%d%d",&x,&y);
                printf("%d\n",ask(x,y));
            }
            else if (str=="End") break;
            else if (str=="Add")
            {
                int x,y;
                scanf("%d%d",&x,&y);
                gai(x,y);
            }
            else if (str=="Sub")
            {
                int x,y;
                scanf("%d%d",&x,&y);
                gai(x,-y);
            }
        }

    }
    return 0;
}
