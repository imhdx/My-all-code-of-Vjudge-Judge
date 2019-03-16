#include<bits/stdc++.h>
using namespace std;
int pre[3010];
int cnt[3010];
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
        for (int i=0;i<=n;i++) pre[i]=i,cnt[i]=0;
        for (int i=0;i<n-1;i++)
        {
            int x;
            for (int j=0;j<n-i-1;j++)
            {
                scanf("%d",&x);
                nian(i,i+x);
            }
        }
        int flag=0;
        int cc=0;
        for (int i=0;i<n;i++)
        {
            if (i==getx(i)) cc++;
            cnt[getx(i)]++;
            if (cnt[getx(i)]>=3)
            {
                flag=1;
                break;
            }
        }
        if (flag==1||cc>=3)
            printf("Bad Team!\n");
        else
            printf("Great Team!\n");
    }
    return 0;
}
