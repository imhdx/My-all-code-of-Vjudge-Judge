#include<cstdlib>
#include<cstring>
#include<cstdio>
using namespace std;
int sum[1000010];
int pri[1000010];
int f(int a)
{
    int summ=0;
    while (a!=0)
    {
        summ=summ+a%10;
        a=a/10;
    }
    return summ;
}
int main()
{
    int i,j;
    int n,m;
    int t;
    memset(sum,0,1000010*sizeof(int));
    memset(pri,0,1000010*sizeof(int));
    pri[1]=1;
    pri[0]=1;
    for (i=2;i<=1002;i++)
    {
        for (j=i*i;j<1000010;j=j+i)
            pri[j]=1;
    }
    for (i=1;i<=1000000;i++)
    {
        if (pri[i]==0&&pri[f(i)]==0)
        {
            sum[i]=sum[i-1]+1;
        }
        else
        {
            sum[i]=sum[i-1];
        }
    }
    scanf("%d",&t);
    for (int k=0;k<t;k++)
    {
        scanf("%d%d",&n,&m);
        printf("Case #%d: ",k+1);
        printf("%d\n",sum[m]-sum[n-1]);
    }
    return 0;
}