#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
using namespace std;
const int maxn=10004;
struct ac
{
    int x,h;
    int l,r;
}ac[maxn];
int main()
{
    int tt=1;
    int T;scanf("%d",&T);
    while (T--){
        printf("Case #%d:\n",tt++);
        int n;scanf("%d",&n);
        for (int i=1;i<=n;i++){
            scanf("%d%d",&ac[i].x,&ac[i].h);
            ac[i].l=ac[i].r=i;
        }
        for (int i=2;i<=n;i++){
            if (ac[i].h==0){
                if (ac[i-1].h==0)
                {
                    if (ac[i-1].l!=i-1) ac[i].l=ac[i-1].l;
                }
                else ac[i].l=i-1;
            }
        }
        for (int i=n-1;i>=1;i--){
            if (ac[i].h==0)
            {
                if (ac[i+1].h==0){
                    if (ac[i+1].r!=i+1) ac[i].r=ac[i+1].r;
                }else ac[i].r=i+1;
            }
        }
        int m;scanf("%d",&m);
        char op[10];
        while (m--){
            scanf("%s",op);
            if (op[0]=='U'){
                int xx,yy;scanf("%d%d",&xx,&yy);
                xx++;
                ac[xx].h=yy;
            }
            else{
                int xx;scanf("%d",&xx);
                int ans=0;
                for (int i=1;i<=n;i++){
                    if (ac[i].h!=0){if (ac[i].h<=xx) ans++;continue;}
                    if (i-ac[i].l==ac[i].r-i)
                    {
                        int h=max(ac[ac[i].l].h,ac[ac[i].r].h);
                        if (h<=xx) ans++;
                    }
                    else if (i-ac[i].l<ac[i].r-i&&ac[i].l!=i)
                    {
                        int h=ac[ac[i].l].h;
                        if (h<=xx) ans++;
                    }
                    else{
                        int h=ac[ac[i].r].h;
                        if (h<=xx) ans++;
                    }
                }
                printf("%d\n",ans);
            }
        }
    }
    return 0;
}
