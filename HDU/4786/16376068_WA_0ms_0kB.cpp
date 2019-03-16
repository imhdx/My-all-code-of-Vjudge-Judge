#include<bits/stdc++.h>
using namespace std;
int fib[1000];
int main()
{
    int T;
    fib[0]=1;
    fib[1]=2;
    for (int i=2;i<1000;i++)
    {
        fib[i]=fib[i-1]+fib[i-2];
    }
    scanf("%d",&T);
    int t=1;
    while (T--)
    {
        int n,m;
        int x;
        int cnt=0;
        scanf("%d%d",&n,&m);
        for (int i=0;i<m;i++)
        {
            scanf("%*d%*d%d",&x);
            if (x==1)
                cnt++;
        }
        printf("Case #%d: ",t++);
        int flag=0;
        for (int i=0;i<1000;i++)
        {
            if(fib[i]==cnt)
            {
                flag=1;
            }
            else if (fib[i]>cnt) break;
        }
        if (flag==1)
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}
