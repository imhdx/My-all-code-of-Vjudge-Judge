#include <bits/stdc++.h>
using namespace std;

const int maxn = 1000 + 5;
const int rndcnt = 10;
const double eps = 1e-5;
struct Point{
	double x, y;
};

struct Line{
	Point s, e;
};

Line ll[maxn];
double p[rndcnt];

double dot(Point x, Point y) {
	return x.x * y.x + x.y * y.y;
}

double det(Point a, Point b) {
	return a.x * b.y - a.y * b.x;
}

double dist(Point a, Point b) {
	return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

Point sub(Point a, Point b) {
	return Point{a.x - b.x, a.y - b.y};
}

double point2seg(double x, const Line &l) {
	Point P{x, 0};
	Point v = sub(l.e, l.s);
	Point w = sub(P, l.s);
	double c1, c2;
	if ((c1 = dot(w, v)) < eps) {
		return dist(P, l.s);
	}
	if ((c2 = dot(v, v)) < c1 + eps) {
		return dist(P, l.e);
	}
	double b = c1 / c2;
	return dist(P, Point{l.s.x + b * v.x, l.s.y + b * v.y});
}
mt19937 rng((unsigned long long)new char);

double myrand()
{
    return 1.0*rng()/INT_MAX-0.5;
}
void sol() {
	int n, L;
	double ans = 0;
	double step = 100;
	scanf("%d%d", &n, &L);
	step = 2*L;
	for (int i = 0; i < n; i++) {
		scanf("%lf%lf%lf%lf", &ll[i].s.x, &ll[i].s.y, &ll[i].e.x, &ll[i].e.y);
	}
	double rans = 0;
	double qq=L/2.0;
	while (step > eps) {
        //printf("hi\n");
        double a=myrand();
        double tmp=qq+a*step;
        //printf("%.10f\n",tmp);
        if (tmp<0||tmp>L) continue;
        //printf("%.10f\n",tmp);
        double dis=1e30;
        for (int i=0;i<n;i++)
        {
            dis=min(dis,point2seg(tmp,ll[i]));
        }
        double sub=dis-ans;
        if (sub>=0)
        {
            ans=dis;
            qq=tmp;
        }
		step = step * 0.99;
	}
	printf("%.3f\n", ans);
}

int main() {
	int t;
	srand(time(NULL));
	scanf("%d", &t);
	while (t--) sol();
	return 0;
}
