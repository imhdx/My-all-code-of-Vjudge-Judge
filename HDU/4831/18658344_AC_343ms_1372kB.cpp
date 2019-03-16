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
const int inf=1e9+7;
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
                    int pos0=ac[ac[i].l].x;
                    int pos1=ac[i].x;
                    int pos2=ac[ac[i].r].x;
                    int h=inf;
                    if (pos1-pos0==pos2-pos1){
                        if (pos1!=pos0) h=max(ac[ac[i].l].h,ac[ac[i].r].h);
                    }
                    else if (pos1-pos0<pos2-pos1)
                    {
                        if (pos1!=pos0)
                        {
                            h=ac[ac[i].l].h;
                        }
                        else h=ac[ac[i].r].h;
                    }
                    else if (pos1-pos0>pos2-pos1){
                        if (pos2!=pos1)
                            h=ac[ac[i].r].h;
                        else h=ac[ac[i].l].h;
                    }
                    printf("");
                    if (h<=xx) ans++;
                }
                printf("%d\n",ans);
            }
        }
    }
    return 0;
}
