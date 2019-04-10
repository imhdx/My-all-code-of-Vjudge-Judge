#include<bits/stdc++.h>
using namespace std;
int a[1000006];
int read()
{
    int s=0,f=1;
    char c=getchar();
    while (c<'0'||c>'9')
    {
        if (c=='-') f=-1;
        c=getchar();
    }
    while (c<='9'&&c>='0')
    {
        s=s*10+c-'0';
        c=getchar();
    }
    return s*f;
}
int main()
{
    int n;
    while (scanf("%d",&n)!=EOF)
    {
        for (int i=0;i<n;i++) a[i]=read();
        int cnt=0;
        long long s=0;
        for (int i=n-1;i>=0;i--)
        {
            s+=a[i];
            if (s>=0)
            {
                s=0;
                cnt++;
            }
        }
        printf("%d\n",cnt);
    }
    return 0;
}
