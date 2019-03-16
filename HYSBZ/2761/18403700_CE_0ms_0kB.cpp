#include<bits/stdc++.h>
using namespace std;
int ans[100005];
int a[100005];
int cnt=0;
unordered_map<int,bool> m;
int main()
{
    int T;scanf("%d",&T);
    while (T--)
    {
        m.clear();
        cnt=0;
        int n;scanf("%d",&n);
        for (int i=0;i<n;i++) scanf("%d",&a[i]);
        for (int i=0;i<n;i++)
        {
            if (m[a[i]]==0)
                ans[cnt++]=a[i];
            m[a[i]]=1;
        }
        for (int i=0;i<cnt;i++)
            printf("%d%c",ans[i]," \n"[i==cnt-1]);

    }
    return 0;
}
