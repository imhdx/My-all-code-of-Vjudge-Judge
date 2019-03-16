#include<bits/stdc++.h>
using namespace std;
int sum;
int n;
int flag=0;
int a[10000];
int ans[1000];
void dfs(int s,int b,int k) ///k为ans的索引
{
    if (s>sum) return ;
    if (b==n+1)
    {
        return ;
    }
    if (s==sum)
    {
        flag=1;
        printf("%d",ans[0]);
        for (int i=1;i<k;i++)
            printf("+%d",ans[i]);
        printf("\n");
        return ;
    }

    for (int i=b;i<n;i++)
    {
        ans[k]=a[i];
        dfs(s+a[i],i+1,k+1);
        while (i+1<n&&a[i]==a[i+1])
            i++;
    }
    return ;
}
int main()
{
    while (scanf("%d%d",&sum,&n)!=EOF)
    {
        flag=0;
        if (n==0) break;
        int i;
        for (i=0;i<n;i++)
            scanf("%d",&a[i]);


        printf("Sums of %d:\n",sum);
        dfs(0,0,0);
        if (flag==0)
            printf("NONE\n");
    }

    return 0;
}