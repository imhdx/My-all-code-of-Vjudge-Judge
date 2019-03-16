#include<bits/stdc++.h>
using namespace std;
int f[10010];
int bit[100010];
int a[100010];
void get(int x)
{
    int temp=x*10+4;
    if (temp<10010)
    {
        f[temp]=1;
        get(temp);
    }
    temp=x*10+7;
    if (temp<10010)
    {
        f[temp]=1;
        get(temp);
    }
}
void add(int x,int w)
{
    while (x<100010)
    {
        bit[x]+=w;
        x+=x&(-x);
    }
}
int ask(int x)
{
    int s=0;
    while (x>0)
    {
        s+=bit[x];
        x-=x&(-x);
    }
    return s;
}
int main()
{
    int n,m;
    get(0);
    scanf("%d%d",&n,&m);
    for (int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        if (f[a[i]])
        {
            add(i,1);
        }
    }
    for (int i=0;i<m;i++)
    {
        char str[10];
        scanf("%s",str);
        if (str[0]=='c')
        {
            int x,y;
            scanf("%d%d",&x,&y);
            printf("%d\n",ask(y)-ask(x-1));
        }
        else if (str[0]=='a')
        {
            int x,y;
            int w;
            scanf("%d%d%d",&x,&y,&w);
            for (int j=x;j<=y;j++)
            {
                if (f[a[j]+w])
                {
                    if (!f[a[j]])
                    {
                        add(j,1);
                    }
                }
                else
                {
                    if (f[a[j]])
                    {
                        add(j,-1);
                    }
                }
                a[j]+=w;
            }
        }
    }
    return 0;
}
