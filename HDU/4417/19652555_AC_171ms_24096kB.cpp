//
// Created by mhdx on 2019/5/8.
//

#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<vector>

using namespace std;
const int maxn = 1e5 + 7;
vector<int> v;
int n, m, cnt, x, y, k;
int root[maxn], a[maxn];

struct Node {
    int l, r, sum;
    Node() {}
} T[maxn * 30];

int getid(int x) { return lower_bound(v.begin(), v.end(), x) - v.begin() + 1; }

void update(int l, int r, int &x, int y, int pos) {
    T[++cnt] = T[y], T[cnt].sum++, x = cnt;
    if (l == r)return;
    int mid = l + r >> 1;
    if (mid >= pos)update(l, mid, T[x].l, T[y].l, pos);
    else update(mid + 1, r, T[x].r, T[y].r, pos);
}
///  x,y为两棵树    l,r 为区间  [1,h] 区间的和  对于两颗树求出来后做差
int query(int l, int r, int x, int y, int L,int R) {
    if (L<=l&&r<=R) return T[y].sum-T[x].sum;
    int ans=0;
    int mid = l + r >> 1;
    if (L<=mid) ans+=query(l, mid, T[x].l, T[y].l, L,R);
    if (R>mid) ans+=query(mid + 1, r, T[x].r, T[y].r, L,R);
    return ans;
}

int main()//  [1,2,3]  (1,2,1) 返回1
{
    int tt=1;
    int TT;
    scanf("%d",&TT);
    while (TT--)
    {
        scanf("%d%d",&n,&m);
        v.clear();
        cnt = 0;
        root[0]=0;
        T[0].l=0;T[0].r=0;T[0].sum=0;
        for (int i = 1; i <= n; i++) scanf("%d", &a[i]), v.push_back(a[i]);
        sort(v.begin(), v.end()), v.erase(unique(v.begin(), v.end()), v.end());
        for (int i = 1; i <= n; i++) update(1, n, root[i], root[i - 1], getid(a[i]));
        printf("Case %d:\n",tt++);
        for (int i=1;i<=m;i++)
        {
            int h;
            scanf("%d%d%d",&x,&y,&h);
            x++;y++;
            int k=upper_bound(v.begin(), v.end(), h)-v.begin()+1;
            k--;
            if (k==0) {printf("0\n");continue;}
            printf("%d\n",query(1, n, root[x - 1], root[y], 1,k));
        }
    }
    return 0;
}//