#include<bits/stdc++.h>
using namespace std;
const int maxn=30010;
int n;
int pre[maxn];
int down[maxn];
int up[maxn];
int getx(int x)
{
    if (pre[x]==x) return x;
    int fa=pre[x];
    pre[x]=getx(pre[x]);
    down[x]+=down[fa];
    
    return pre[x];
}
void nian(int x,int y)
{
    x=getx(x);
    y=getx(y);
    if (x!=y){
        down[x]=up[y];
        up[y]+=up[x];
        pre[x]=y;
    }

}
int main()
{
    for (int i=0;i<maxn;i++){
        pre[i]=i;down[i]=0;up[i]=1;
    }
    int n;scanf("%d",&n);
    for (int i=1;i<=n;i++){
        char op[10];
        scanf("%s",op);
        if (op[0]=='M')
        {
            int x,y;scanf("%d%d",&x,&y);
            nian(x,y);
        }
        else{
            int x;scanf("%d",&x);
            getx(x);
            printf("%d\n",down[x]);
        }
    }
    return 0;
}
