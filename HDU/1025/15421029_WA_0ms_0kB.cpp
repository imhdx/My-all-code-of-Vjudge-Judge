#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<vector>
using namespace std;
vector<pair<int,int> > v;
int b[500010];
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
            v.push_back({x,y});
        }
        int ans=0;
        b[0]=v[0].second;
        for (i=1;i<n;i++)
        {
            if (v[i].second>b[ans])
            {
                b[++ans]=v[i].second;
            }
            else
            {
                int pos=lower_bound(b,b+ans+1,v[i].second)-b;
                b[pos]=v[i].second;
            }
        }
        printf("Case %d:\n",t++);
        printf("My king, at most %d road can be built.\n\n",ans+1);
    }

    return 0;
}
