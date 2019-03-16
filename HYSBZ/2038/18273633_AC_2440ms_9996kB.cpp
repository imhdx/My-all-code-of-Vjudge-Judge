//Tsinsen A1206; 小Z的袜子; Modui Algorithm
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#define N 50000
#define Q 50000
#define INFI 123456789
 
typedef long long ll;
struct edge
{
	int next, node;
}e[Q << 1 | 1];
int head[N + 1], tot = 0;
struct point
{
	int x, y, n;
	bool operator < (const point &p) const
	{ return x == p.x ? y < p.y : x < p.x; }
}qt[Q + 1], p[Q + 1];
struct inedge
{
	int a, b, w;
	bool operator < (const inedge &x) const
	{ return w < x.w; }
}ie[Q << 3 | 1];
int cnt = 0;
struct BITnode
{
	int w, p;
}arr[Q + 1];
int n, q, col[N + 1], a[Q + 1], *l[Q + 1], f[N + 1], c[N + 1];
ll cur, ans[Q + 1];
bool v[Q + 1];
 
template <typename T>
inline T abs(T x)
{ return x < (T)0 ? -x : x; }
 
inline int dist(const point &a, const point &b)
{ return abs(a.x - b.x) + abs(a.y - b.y); }
 
inline void addinedge(int a, int b, int w)
{
	++cnt;
	ie[cnt].a = a, ie[cnt].b = b, ie[cnt].w = w;
}
 
inline void addedge(int a, int b)
{
	e[++tot].next = head[a];
	head[a] = tot, e[tot].node = b;
}
 
inline bool cmp(int *a, int *b)
{ return *a < *b; }
 
inline int query(int x)
{
	int r = INFI, p = -1;
	for (; x <= q; x += x & -x)
		if (arr[x].w < r) r = arr[x].w, p = arr[x].p;
	return p;
}
 
inline void modify(int x, int w, int p)
{
	for (; x > 0; x -= x & -x)
		if (arr[x].w > w) arr[x].w = w, arr[x].p = p;
}
 
int find(int x)
{ return x == f[x] ? x : f[x] = find(f[x]); }
 
inline ll calc(int x)
{ return (ll)x * (x - 1); }
 
inline void add(int l, int r)
{
	for (int i = l; i <= r; ++i)
	{
		cur -= calc(c[col[i]]);
		cur += calc(++c[col[i]]);
	}
}
 
inline void remove(int l, int r)
{
	for (int i = l; i <= r; ++i)
	{
		cur -= calc(c[col[i]]);
		cur += calc(--c[col[i]]);
	}
}
 
void dfs(int x, int l, int r)
{
	v[x] = true;
	//Process right bound
	if (r < qt[x].y)
		add(r + 1, qt[x].y);
	else if (r > qt[x].y)
		remove(qt[x].y + 1, r);
	//Process left bound
	if (l < qt[x].x)
		remove(l, qt[x].x - 1);
	else if (l > qt[x].x)
		add(qt[x].x, l - 1);
	ans[x] = cur;
	//Moving on to next query
	for (int i = head[x]; i; i = e[i].next)
	{
		if (v[e[i].node]) continue;
		dfs(e[i].node, qt[x].x, qt[x].y);
	}
	//Revert changes
	//Process right bound
	if (r < qt[x].y)
		remove(r + 1, qt[x].y);
	else if (r > qt[x].y)
		add(qt[x].y + 1, r);
	//Process left bound
	if (l < qt[x].x)
		add(l, qt[x].x - 1);
	else if (l > qt[x].x)
		remove(qt[x].x, l - 1);
}
 
ll gcd(ll a, ll b)
{ return !b ? a : gcd(b, a % b); }
 
int main()
{
	//Initialize
	scanf("%d%d", &n, &q);
	for (int i = 1; i <= n; ++i) scanf("%d", col + i);
	for (int i = 1; i <= q; ++i) scanf("%d%d", &qt[i].x, &qt[i].y);
 
	//Manhattan MST
	for (int i = 1; i <= q; ++i) p[i] = qt[i], p[i].n = i;
	for (int dir = 1; dir <= 4; ++dir)
	{
		//Coordinate transform
		if (dir == 2 || dir == 4)
			for (int i = 1; i <= q; ++i) std::swap(p[i].x, p[i].y);
		else if (dir == 3)
			for (int i = 1; i <= q; ++i) p[i].x = -p[i].x;
		//Sort by x-coordinate
		std::sort(p + 1, p + q + 1);
		//Discretize
		for (int i = 1; i <= q; ++i) a[i] = p[i].y - p[i].x, l[i] = &a[i];
		std::sort(l + 1, l + q + 1, cmp);
		int cnt = 1;
		for (int i = 2; i <= q; ++i)
			if (*l[i] == *l[i - 1]) *l[i - 1] = cnt;
			else *l[i - 1] = cnt++;
		*l[q] = cnt;
		//Initialize BIT
		for (int i = 1; i <= q; ++i) arr[i].w = INFI, arr[i].p = -1;
		//Find points and add edges
		for (int i = q; i > 0; --i)
		{
			int pos = query(a[i]);
			if (pos != -1)
				addinedge(p[i].n, p[pos].n, dist(p[i], p[pos]));
			modify(a[i], p[i].x + p[i].y, i);
		}
	}
	//Kruskal
	std::sort(ie + 1, ie + cnt + 1);
	//Initialize disjoint set
	for (int i = 1; i <= q; ++i) f[i] = i;
	//Add edges
	for (int i = 1; i <= cnt; ++i)
		if (find(ie[i].a) != find(ie[i].b))
		{
			f[find(ie[i].a)] = find(ie[i].b);
			addedge(ie[i].a, ie[i].b), addedge(ie[i].b, ie[i].a);
		}
 
	//Modui Algorithm
	++c[col[1]];
	dfs(1, 1, 1);
	
	//Output
	for (int i = 1; i <= q; ++i)
	{
		ll x = ans[i], y = calc(qt[i].y - qt[i].x + 1);
		if (!x) printf("0/1\n");
		else
		{
			ll g = gcd(x, y);
			printf("%lld/%lld\n", x / g, y / g);
		}
	}
 
	return 0;
}