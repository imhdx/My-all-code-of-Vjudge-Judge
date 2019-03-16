#include<bits/stdc++.h>
using namespace std;
vector<int> v[200010];
vector<int> ss;
int main()
{
    int n,m;
    while (scanf("%d%d",&n,&m)!=EOF)
    {
        for (i=0;i<=n;i++)
            v[i].clear();
        ss.clear();
        int i,j;
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
            int sum1=0;
            int sum2=0;
            for (j=0; j<m; j=j+2)
            {
                sum1+=v[i][j];
                if (j+1<m)
                    sum2+=v[i][j+1];
            }
            ss.push_back(max(sum1,sum2));
        }
        int ans1=0;
        int ans2=0;
        for (i=0; i<n; i=i+2)
        {
            ans1+=ss[i];
            if (i+1<n)
                ans2+=ss[i+1];
        }
        printf("%d\n",max(ans1,ans2));
    }


    return 0;
}
