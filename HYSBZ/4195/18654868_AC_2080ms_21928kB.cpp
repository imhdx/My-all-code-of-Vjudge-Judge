#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;
vector<int> v;
int x[1000006];
int y[1000006];
int op[1000006];
int pre[2000006];
int getx(int x)
{
    if (pre[x]==x) return x;
    return pre[x]=getx(pre[x]);
}
void nian(int x,int y)
{
    x=getx(x);
    y=getx(y);
    if (x!=y) pre[x]=y;
}

int find(int x)
{
    return lower_bound(v.begin(),v.end(),x)-v.begin();
}
int main()
{
    int T;scanf("%d",&T);
    while (T--){
        v.clear();
        int n;scanf("%d",&n);
        for (int i=0;i<=2*n+5;i++) pre[i]=i;
        for (int i=0;i<n;i++)
        {
            scanf("%d%d%d",&x[i],&y[i],&op[i]);
            v.push_back(x[i]);
            v.push_back(y[i]);
        }
        sort(v.begin(),v.end());

        v.resize(unique(v.begin(),v.end())-v.begin());
        int flag=0;
        for (int i=0;i<n;i++) if (op[i]) nian(find(x[i]),find(y[i]));
        for (int i=0;i<n;i++)
        {
            if (op[i]==0)
            {
                int xx=find(x[i]);
                int yy=find(y[i]);
                if (getx(xx)==getx(yy)){
                    flag=1;
                    break;
                }
            }
        }
        if (flag==0) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
