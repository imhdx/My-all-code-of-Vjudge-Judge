#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
using namespace std;
int flag=0;
int ave;
int a[7];
void dfs(int sum,int k)
{
    if (flag==1) return ;
    if (k>6)
    {
        if (sum==ave)
        {
            flag=1;
            return ;
        }
    }
    if (sum>ave) return ;
    if (sum==ave)
    {
        flag=1;
        return ;
    }
    int i;
    for (i=0;i<=a[k];i++)
    {
        if (sum+k*i>ave) return ;
        dfs(sum+k*i,k+1);
        if (flag==1) return ;
    }
    return ;
}
int main()
{
    int i;
    int cnt=0;
    while (1)
    {
        flag=0;
        cnt++;
        int sum=0;
        for (i=1;i<=6;i++)
        {
            scanf("%d",&a[i]);
            sum=sum+i*a[i];
        }
        if (sum==0) break;
        printf("Collection #%d:\n",cnt);
        if (sum%2==1) {printf("Can't be divided.\n");continue;}
        ave=sum/2;
        dfs(0,1);
        if (flag==1) {printf("Can be divided.\n");}
        else
        {printf("Can't be divided.\n");}
        printf("\n");
    }
    return 0;
}
