#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 7;
vector<int> v;
int n, m, cnt, x, y, k;
int root[maxn], a[maxn];

struct Node {
    int l, r, sum;
    Node() {}
} T[maxn * 40];

int getid(int x) { return lower_bound(v.begin(), v.end(), x) - v.begin() + 1; }

void update(int l, int r, int &x, int y, int pos) {
    T[++cnt] = T[y], T[cnt].sum++, x = cnt;
    if (l == r)return;
    int mid = l + r >> 1;
    if (mid >= pos)update(l, mid, T[x].l, T[y].l, pos);
    else update(mid + 1, r, T[x].r, T[y].r, pos);
}

int query(int l, int r, int x, int y, int k) {
    if (l == r)return l;
    int mid = l + r >> 1;
    int sum = T[T[y].l].sum - T[T[x].l].sum;//T[T[y].l].sum  表示y这棵树中  l-mid的数字出现的次数
    if (sum >= k)return query(l, mid, T[x].l, T[y].l, k);
    return query(mid + 1, r, T[x].r, T[y].r, k - sum);
}

int main()//  [1,2,3]  (1,2,1) 返回1
{
    while (scanf("%d%d", &n, &m) != EOF) {
        /*
        v.clear();
        cnt = 0;
        root[0]=0;
        T[0].l=0;T[0].r=0;T[0].sum=0;
        */
        for (int i = 1; i <= n; i++) scanf("%d", &a[i]), v.push_back(a[i]);
        sort(v.begin(), v.end()), v.erase(unique(v.begin(), v.end()), v.end());
        for (int i = 1; i <= n; i++) update(1, n, root[i], root[i - 1], getid(a[i]));
        /*
        for (int i = 1; i <= m; i++) {
            scanf("%d%d", &x, &y);
            int l = 1, r = n;
            int ans = -1;
            while (l <= r) {
                int mid = l + r >> 1;
                k = y - x + 2 - mid;
                if (v[query(1, n, root[x - 1], root[y], k) - 1] >= mid) {
                    ans = mid;
                    l = mid + 1;
                } else r = mid - 1;
            }
            printf("%d\n", ans);
        }
        */
        for (int i=1;i<=m;i++)
        {
            scanf("%d%d%d",&x,&y,&k);
            printf("%d\n",v[query(1, n, root[x - 1], root[y], k) - 1]);

        }
    }
    return 0;
}