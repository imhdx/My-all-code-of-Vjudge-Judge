#include<stdio.h>
long long ans[60];
int main()
{
    ans[0]=1;
    ans[1]=1;
    ans[2]=2;
    for (int i=3;i<60;i++) ans[i]=ans[i-1]+ans[i-2];
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        b=b-a;
        printf("%lld\n",ans[b]);
    }
    return 0;
}
