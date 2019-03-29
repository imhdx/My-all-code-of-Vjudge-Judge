#include<bits/stdc++.h>
using namespace std;
struct ac
{
    int x,y;
}que[100005];
bool cmp(ac q,ac p)
{
    if (q.x==p.x) return q.y<p.y;
    return q.x<p.x;
}
multiset<int> s;
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        s.clear();
        int n;
        scanf("%d",&n);
        for (int i=0;i<n;i++) scanf("%d%d",&que[i].x,&que[i].y);
        sort(que,que+n,cmp);
        long long sum=0;
        int cnt=0;
        for (int i=0;i<n;i++)
        {
            if (s.size()==0)
            {
                sum+=que[i].y-que[i].x;
                cnt++;
                s.insert(que[i].y);
            }
            else{
                auto it=s.upper_bound(que[i].x);
                if (it==s.begin())
                {
                    sum+=que[i].y-que[i].x;
                    cnt++;
                    s.insert(que[i].y);
                }
                else{
                    --it;
                    sum+=que[i].y-*it;
                    s.erase(it);
                    s.insert(que[i].y);
                }
            }
        }
        printf("%d %lld\n",cnt,sum);

    }
    return 0;
}