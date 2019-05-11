#include<cstdio>
#include<cstring>
#include<queue>
#include <algorithm>
#include<set>
using namespace std;
struct vii { int a, b, c, d, e, f;
vii(int _a = 0, int _b = 0, int _c = 0, int _d = 0, int _e = 0, int _f = 0)
	:a(_a), b(_b), c(_c), d(_d), e(_e), f(_f) {}
bool operator <(const vii &r)const
{
	if (a == r.a&&b == r.b&&c == r.c&&d == r.d&&e == r.e) return f < r.f;
	if (a == r.a&&b == r.b&&c == r.c&&d == r.d) return e < r.e;
	if (a == r.a&&b == r.b&&c == r.c) return d < r.d;
	if (a == r.a&&b == r.b) return c < r.c;
	if (a == r.a) return b < r.b;
	return a < r.a;
}
};
set<vii>viia;
int main()
{
	int n, i, mp[6];
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		scanf("%d%d%d%d%d%d", mp, mp + 1, mp + 2, mp + 3, mp + 4, mp + 5);
		sort(mp, mp + 6);
		if (viia.find(vii(mp[0], mp[1], mp[2], mp[3], mp[4], mp[5])) != viia.end())
			break;
		viia.insert(vii(mp[0], mp[1], mp[2], mp[3], mp[4], mp[5]));
	}
	puts(i == n ? "No two snowflakes are alike." : "Twin snowflakes found.");
}//