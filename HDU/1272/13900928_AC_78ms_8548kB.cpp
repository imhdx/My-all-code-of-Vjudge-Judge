#include<cstdio>

using namespace std;
int pre[100010];
int book[100010];

int get(int n)
{
    if (pre[n]==n) return n;
    return pre[n]=get(pre[n]);
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
        {
            pre[i]=i;
            book[i]=0;
        }
        book[a]=1;
        book[b]=1;
        flag=0;
        jie(a,b);
        while (scanf("%d%d",&a,&b)!=EOF)
        {
            if (a==0&&b==0) break;
            book[a]=1;
            book[b]=1;
            if (get(a)==get(b))
            {
                flag=1;
                continue;
            }
            else
            {
                jie(a,b);
            }
        }
        if (flag==1) printf("No\n");
        if (flag==0)
        {
            int ans;
            for (i=1;i<=100000;i++)
            {
                if (book[i]==1) {ans=get(i);break;}
            }
            for (i=1;i<=100000;i++)
            {
                if (book[i]==1&&get(i)!=ans) {printf("No\n");break;}
            }
            if (i==100000+1) printf("Yes\n");
        }
    }

    return 0;
}
