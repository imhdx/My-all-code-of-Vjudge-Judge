#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<vector>
using namespace std;
vector<pair<int,int> > v;
int main()
{
    int t=1;
    int n;
    while (scanf("%d",&n)!=EOF)
    {
        int i;
        v.clear();
        for (i=0;i<n;i++)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            v.push_back({min(x,y),max(x,y)});
        }
        sort(v.begin(),v.end());
        int ans=0;
        int last=0;
        for (i=0;i<n;i++)
        {
            if (v[i].second>last)
            {
                ans++;
                last=v[i].second;
            }
        }
        printf("Case %d:\n",t++);
        printf("My king, at most %d road can be built.\n",ans);
        printf("\n",ans);
    }

    return 0;
}
