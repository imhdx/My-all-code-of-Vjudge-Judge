#include<bits/stdc++.h>
using namespace std;
int a[32010];
int lowbit(int x)
{
    return x&(-x);
}
void add(int x)
{
    while (x<32010)
    {
        a[x]+=1;
        x+=lowbit(x);
    }
}
int ask(int x)
{
    int sum=0;
    while (x>0)
    {
        sum+=a[x];
        x-=lowbit(x);
    }
    return sum;
}
int cnt[15010];
int main()
{
    int n;
    while (scanf("%d",&n)!=EOF)
    {
        memset(a,0,sizeof(a));
        memset(cnt,0,sizeof(cnt));
        int x,y;
        for (int i=0;i<n;i++)
        {
            scanf("%d%d",&x,&y);
            x++;
            y++;
            cnt[ask(x)]++;
            add(x);
        }
        for (int i=0;i<n;i++)
        {
            printf("%d\n",cnt[i]);
        }
    }
    return 0;
}
