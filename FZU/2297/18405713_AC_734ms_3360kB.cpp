#include <cmath>
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
#include <vector>
#include <stack>
#include <set>
#include <map>
#include <cctype>
#define eps 1e-8
#define INF 0x3f3f3f3f
#define PI acos(-1)
#define lson l,mid,rt<<1
#define rson mid+1,r,(rt<<1)+1
#define CLR(x,y) memset((x),y,sizeof(x))
#define fuck(x) cerr << #x << "=" << x << endl
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int seed = 131;
const int maxn = 1e5 + 5;
ll sum[maxn << 2];
ll mod;
void push_up(int rt)
{
    sum[rt] = sum[rt << 1] * sum[rt << 1 | 1] % mod;
}
void build(int l, int r, int rt)
{
    sum[rt] = 1;
    if (l == r)
        return ;
    int mid = (l + r) >> 1;
    build(lson);
    build(rson);
    push_up(rt);
}
void updata(int flag, int p, int v, int l, int r, int rt)   //flag==1 表示D操作 //flag==2 表示M操作
{
    if (l == r)
    {
        if (flag == 1)
            sum[rt] = 1;
        else
            sum[rt] *= v;
        sum[rt] %= mod;
        return;
    }
    int mid = (l + r) >> 1;
    if (p <= mid)
        updata(flag, p, v, lson);
    else
        updata(flag, p, v, rson);
    push_up(rt);
}
ll t, q;
int main()
{
    scanf("%I64d", &t);
    while (t--)
    {
        scanf("%I64d%I64d", &q, &mod);
        build(1, q, 1);
        for (int i = 1; i <= q; i++)
        {
            char op[10];
            ll x;
            scanf("%s%I64d", op, &x);
            if (op[0] == 'M')
            {
                updata(2, i, x, 1, q, 1);
                printf("%I64d\n", sum[1]);
            }
            else
            {
                updata(1, x, 1, 1, q, 1);
                printf("%I64d\n", sum[1]);
            }
        }
    }
    return 0;
}