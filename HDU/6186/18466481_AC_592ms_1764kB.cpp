#include<bits/stdc++.h>
using namespace std;
int b[100005];
int a[33];
int main()
{
    int n,q;
    while (scanf("%d%d",&n,&q)!=EOF)
    {
        memset(a,0,sizeof(a));
    for (int i=1;i<=n;i++)
    {
        int x;scanf("%d",&x);b[i]=x;
        for (int j=0;j<32;j++) a[j]+=(x>>j)&1;
    }

    while (q--)
    {
        int id;scanf("%d",&id);
        for (int j=0;j<32;j++) a[j]-=(b[id]>>j)&1;
        int ans1=0,ans2=0,ans3=0;
        ///ans or xor
        for (int i=31;i>=0;i--)
        {
            ans1<<=1;
            ans2<<=1;
            ans3<<=1;
            if (a[i]==n-1) ans1+=1;
            if (a[i]) ans2+=1;
            if (a[i]&1) ans3+=1;
        }
        printf("%d %d %d\n",ans1,ans2,ans3);
        for (int j=0;j<32;j++) a[j]+=(b[id]>>j)&1;
    }
    }
    return 0;
}
