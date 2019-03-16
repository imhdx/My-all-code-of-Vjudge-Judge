#include<bits/stdc++.h>
using namespace std;
const int MAX_N = 400 + 10;
const long long INF = 1e18;

int N;
long long flag;
long long w[MAX_N][MAX_N];
long long fx[MAX_N], fy[MAX_N], lx[MAX_N], ly[MAX_N], slk[MAX_N], mat[MAX_N];

int DFS(int x) {
    fx[x] = flag;
    for(int i = 1; i <= N; ++ i)
    	if (lx[x] + ly[i] != w[x][i])
        	slk[i] = min(slk[i], lx[x] + ly[i] - w[x][i]);
    	else if (fy[i] != flag) {
        	fy[i] = flag;
        	if (mat[i] < 0 || DFS(mat[i])) {
        	    mat[i] = x;
        	    return true;
        	}
    	}
    return false;
}

long long KM() {
	for(int i = 1; i <= N; ++ i) {
        mat[i] = -1;
        fx[i] = 0; fy[i] = 0;
        ly[i] = 0; lx[i] = -INF;
        for(int j = 1; j <= N; ++ j)
            lx[i] = max(lx[i], w[i][j]);
    }
    for(int now = 1; now <= N; ++ now) {
        ++ flag; for(int i = 1; i <= N; ++ i) slk[i] = INF;
        while (! DFS(now)) {
            long long int p(INF); for(int i = 1; i <= N; ++ i)
                if (fy[i] != flag) p = min(p, slk[i]);
            for(int i = 1; i <= N; ++ i) {
                if (fx[i] == flag) lx[i] -= p;
                if (fy[i] == flag) ly[i] += p;
                slk[i] = INF;
            }
            ++ flag;
        }
    }
    long long ans = 0;
    for(int i = 1; i <= N; ++ i) ans += lx[i], ans += ly[i];
    return ans;
}
int main()
{
    int t=1;
    int T;
    scanf("%d",&T);
    while (T--)
    {
        scanf("%d",&N);
        for (int i=1;i<=N;i++) for (int j=1;j<=N;j++) scanf("%lld",&w[i][j]);
        printf("Case #%d: %lld\n",t++,KM());
    }
    return 0;
}
