#include<cstdio>
#include<cstring>
#include<cstdlib>
using namespace std;
const int MAXN=5000010;
long long  a[MAXN];
int n;
int lowbit(int x)
{
    return x&(-x);
}
long long query(int x)
{
    long long int res=0;
    while (x>0)
    {
        res+=a[x];
        x-=lowbit(x);
    }
    return res;
}
void add(int x,int v)
{
    while (x<MAXN)
    {
        a[x]+=v;
        x+=lowbit(x);
    }
}

int main()
{
    while (scanf("%d",&n)!=EOF&&n)
    {
        memset(a,0,sizeof(a));
        long long int sum=0;
        int i;
        for (i=0;i<n;i++)
        {
            int x;
            scanf("%d",&x);
            // printf("hi\n");
            sum+=i-query(x+1);
            //printf("hh\n");
            add(x+1,1);
            //printf("ii\n");
        }
        printf("%lld\n",sum);
    }
    return 0;
}

