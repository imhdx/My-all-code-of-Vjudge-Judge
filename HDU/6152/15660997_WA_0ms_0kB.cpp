#include<bits/stdc++.h>
using namespace std;
int pre[3010];
int getx(int x)
{
    if (pre[x]==x) return x;
    return pre[x]=getx(pre[x]);
}
void nian(int x,int y)
{
    x=getx(x);
    y=getx(y);
    if (x!=y)
        pre[x]=y;
}
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n;
        scanf("%d",&n);
        int i;
        for (int i=0;i<=n;i++) pre[i]=i;
        for (int i=0;i<n-1;i++)
        {
            int x;
            for (int j=0;j<n-i-1;j++)
            {
                scanf("%d",&x);
                nian(i,i+x);
            }
        }
        int cnt=0;
        for (int i=0;i<n;i++)
        {
            if (getx(i)!=getx(0)) cnt++;
        }
        if (cnt>=3||n-cnt>=3)
            printf("Bad Team!\n");
        else
            printf("Great Team!\n");
    }
    return 0;
}
