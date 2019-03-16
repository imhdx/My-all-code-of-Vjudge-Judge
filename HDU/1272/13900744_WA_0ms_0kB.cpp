#include<cstdio>

using namespace std;
int pre[100010];
int get(int n)
{
    if (pre[n]==n) return n;
    return get(pre[n]);
}
void jie(int n,int m)
{
    int x=get(n);
    int y=get(m);
    if (x!=y) pre[x]=y;
}
int main()
{
    int i;
    int a,b;
    int flag;
    while (scanf("%d%d",&a,&b)!=EOF)
    {
        if (a==0&&b==0) {printf("Yes\n");continue;}
        if (a==-1&&b==-1) break;
        for (i=0;i<=100000;i++)
            pre[i]=i;
        flag=0;
        jie(a,b);
        while (scanf("%d%d",&a,&b)!=EOF)
        {
            if (a==0&&b==0) break;
            if (get(a)==get(b))
            {
                if (flag==0)
                printf("No\n");
                flag=1;
                continue;
            }
            else
            {
                jie(a,b);
            }
        }
        if (flag==0)
        {
            int ans;
            for (i=1;i<=100000;i++)
            {
                if (pre[i]!=i) {ans=pre[i];break;}
            }
            for (i=1;i<=100000;i++)
            {
                if (!(pre[i]==i||pre[i]==ans)) {printf("No\n");break;}
            }
            if (i==100000+1) printf("Yes\n");
        }
    }

    return 0;
}
