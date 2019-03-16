#include<bits/stdc++.h>
using namespace std;
long long aa[50020];
long long  a[50010];
int n;
int lowbit(int x)
{
    return x&(-x);
}
long long query(int x)
{
    long long int res=0;
    while (x>=1)
    {
        res+=a[x];
        x-=lowbit(x);
    }
    return res;
}
void add(int x,int v)
{
    while (x<=n)
    {
        a[x]+=v;
        x+=lowbit(x);
    }
}

int main()
{
    int T;
    int t=1;
    scanf("%d",&T);
    while (T--)
    {
        printf("Case %d:\n",t++);
        scanf("%d",&n);
        for (int i=0;i<=n;i++)
            a[i]=0;
        for (int i=1;i<=n;i++)
        {
            scanf("%lld",&aa[i]);
            add(i,aa[i]);
        }
        getchar();
        char str[12];
        for (;;)
        {
            scanf("%s",str);
            if (str[0]=='E') break;
            else if (str[0]=='A')
            {
                int x,y;
                scanf("%d%d",&x,&y);
                add(x,y);
            }
            else if (str[0]=='S')
            {
                int x,y;
                scanf("%d%d",&x,&y);
                add(x,-y);
            }
            else if (str[0]=='Q')
            {
                int x,y;
                scanf("%d%d",&x,&y);
                printf("%d\n",query(y)-query(x-1));
            }
        }
    }
    return 0;
}