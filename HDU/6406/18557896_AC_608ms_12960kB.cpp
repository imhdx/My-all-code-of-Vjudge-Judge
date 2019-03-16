#include<bits/stdc++.h>
using namespace std;
const int maxn=100010;
int a[maxn];
int pre[maxn];
int prea[maxn];
int st[maxn][25];
int Log2[maxn];
int la[maxn];
int n;
void init()
{
    for (int i=1;i<=n;i++) st[i][0]=a[i];
    for (int j=1;(1<<j)<=n;j++){
        for (int i=1;i+(1<<j)-1<=n;i++){
            st[i][j]=max(st[i][j-1],st[i+(1<<(j-1))][j-1]);
        }
    }
}
int ask(int l,int r)
{
    int len=0;
    while (1<<(len+1)<=(r-l+1)) len++;
    return max(st[l][len],st[r-(1<<len)+1][len]);
}

int main()
{
    int T;scanf("%d",&T);
    while (T--){
        int m;
        scanf("%d%d",&n,&m);
        for (int i=1;i<=n;i++) scanf("%d",&a[i]);
        for (int i=1;i<=n;i++){
            if (a[i]>prea[i-1]) pre[i]=pre[i-1]+1;
            else pre[i]=pre[i-1];
            prea[i]=max(prea[i-1],a[i]);
        }
        stack<int> s;
        while (!s.empty()) s.pop();

        for (int i=n;i>=1;i--){
            while (!s.empty()&&s.top()<=a[i]) s.pop();
            s.push(a[i]);
            la[i]=s.size();
        }
        init();
        for (int i=0;i<m;i++){
            int pos,x;scanf("%d%d",&pos,&x);
            int ans=pre[pos-1];
            if (prea[pos-1]<x) ans++;
            else x=prea[pos-1];
            int l=pos+1;
            int r=n;
            int pp=-1;
            while (l<=r){
                int m=(l+r)>>1;
                if (ask(l,m)>x){
                    pp=m;
                    r=m-1;
                }
                else l=m+1;
            }
            if (pp!=-1){
                ans+=la[pp];
            }
            printf("%d\n",ans);
        }


    }
    return 0;
}
