#include<bits/stdc++.h>
using namespace std;
vector<int> v[200010];
vector<int> ss;
int main()
{
    int n,m;
    while (scanf("%d%d",&n,&m)!=EOF)
    {
        int i,j;
        for (i=0; i<=n; i++)
            v[i].clear();
        ss.clear();
        for (i=0; i<n; i++)
        {
            for (j=0; j<m; j++)
            {
                int x;
                scanf("%d",&x);
                v[i].push_back(x);
            }
        }
        for (i=0; i<n; i++)
        {
            int a,b,c,d;
            a=v[i][0];
            b=0;
            c=a;
            d=b;
            for (j=1; j<m; j++)
            {
                a=v[i][j]+d;
                b=max(c,d);
                c=a;
                d=b;
            }
            ss.push_back(max(a,b));
        }
        int a,b,c,d;
        a=ss[0];
        b=0;
        c=a;
        d=b;
        for (i=1; i<n; i++)
        {
            a=ss[i]+d;
            b=max(c,d);
            c=a;
            d=b;
        }
        printf("%d\n",max(a,b));

    }
    return 0;
}
