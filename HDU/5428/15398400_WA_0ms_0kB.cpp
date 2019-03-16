#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;
const int MAXN=1e6;
bool check[MAXN];
int prim[MAXN];
int cnt=0;
void init()
{
    int i;
    long long j;
    cnt=0;
    for (i=2; i<MAXN; i++)
    {
        if (check[i]==0)
        {
            for (j=1ll*i*i; j<MAXN; j=j+i)
                check[j]=1;
            prim[cnt++]=i;
        }
    }
}
vector<int> v;
int main()
{
    init();
    int T;
    scanf("%d",&T);
    while (T--)
    {
        v.clear();
        int n;
        scanf("%d",&n);
        int i,j;
        for (i=0; i<n; i++)
        {
            int x;
            scanf("%d",&x);
            if (x==1)
                continue;
            int k=0;
            for (k=0; k<cnt&&prim[k]<x; k++)
            {
                if (x%prim[k]==0)
                {
                    v.push_back(prim[k]);
                    while (x%prim[k]==0)
                    {
                        x=x/prim[k];
                    }
                }

            }
            if (x!=1)
                v.push_back(x);
        }

        if (v.size()<2)
            printf("-1\n");
        else
        {
            sort(v.begin(),v.end());
            printf("%lld\n",1ll*v[0]*v[1]);
        }

    }
    return 0;
}
