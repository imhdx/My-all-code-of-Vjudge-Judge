#include<bits/stdc++.h>
using namespace std;
#define LL long long
const int inf = 0x3f3f3f3f;
const LL INF = 0x3f3f3f3f3f3f3f3f;
const int N = 210;
int val[N][N];
LL lx[N],ly[N];
int linky[N];
LL pre[N];
bool vis[N];
bool visx[N],visy[N];
LL slack[N];
int n;
void bfs(int k)
{
    LL px, py = 0,yy = 0, d;
    memset(pre, 0, sizeof(LL) * (n+2));
    memset(slack, inf, sizeof(LL) * (n+2));
    linky[py]=k;
    do
    {
        px = linky[py],d = INF, vis[py] = 1;
        for(int i = 1; i <= n; i++)
            if(!vis[i])
            {
                if(slack[i] > lx[px] + ly[i] - val[px][i])
                    slack[i] = lx[px] + ly[i] -val[px][i], pre[i]=py;
                if(slack[i]<d)
                    d=slack[i],yy=i;
            }
        for(int i = 0; i <= n; i++)
            if(vis[i])
                lx[linky[i]] -= d, ly[i] += d;
            else
                slack[i] -= d;
        py = yy;
    }
    while(linky[py]);
    while(py)
        linky[py] = linky[pre[py]], py=pre[py];
//
}
void KM()
{
    memset(lx, 0, sizeof(int)*(n+2));
    memset(ly, 0, sizeof(int)*(n+2));
    memset(linky, 0, sizeof(int)*(n+2));
    for(int i = 1; i <= n; i++)
        memset(vis, 0, sizeof(bool)*(n+2)), bfs(i);
}
struct ios
{
    inline char read()
    {
        static const int IN_LEN=1<<18|1;
        static char buf[IN_LEN],*s,*t;
        return (s==t)&&(t=(s=buf)+fread(buf,1,IN_LEN,stdin)),s==t?-1:*s++;
    } template <typename _Tp> inline ios & operator >> (_Tp&x)
    {
        static char c11,boo;
        for(c11=read(),boo=0; !isdigit(c11); c11=read())
        {
            if(c11==-1)
                return *this;
            boo|=c11=='-';
        }
        for(x=0; isdigit(c11); c11=read())
            x=x*10+(c11^'0');
        boo&&(x=-x);
        return *this;
    }
} io;
int main()
{
    int T;
    io>>T;
    for(int _i = 1; _i <= T; _i++)
    {
        io>>n;
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= n; j++)
            {
                io>>val[i][j];
                val[i][j] = -val[i][j];
            }
        }
        KM();
        LL ans = 0;
        for(int i = 1; i <= n; ++i)
            ans += lx[i] + ly[i];
        printf("Case #%d: %I64d\n", _i, -ans);
    }
    return 0;
}
