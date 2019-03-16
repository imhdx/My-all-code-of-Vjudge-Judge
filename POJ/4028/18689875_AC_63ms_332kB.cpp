#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
using namespace std;
int pri[10000];
bool check[10000];
int main()
{
    int n;
    while (scanf("%d",&n)!=EOF)
    {
    int cnt=0;
    for (int i=2;i<=n;i++)
    {
        if (check[i]==0)
        {
            pri[cnt++]=i;
            for (int j=i*i;j<=n;j+=i) check[j]=1;
        }
    }
    //for (int i=0;i<cnt;i++) printf("%d ",pri[i]);
    //printf("\n");
    int ans=0;
    int i=0;
    int j=cnt-1;
    while (i<=j)
    {
        ans++;
        if (pri[i]*pri[j]<=n) i++,j--;
        else j--;
    }
    printf("%d\n",ans);
    }
    return 0;
}
