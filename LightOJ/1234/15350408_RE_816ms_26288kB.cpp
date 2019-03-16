#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cmath>

using namespace std;

const int maxn = 3150000;
double a[maxn] = {0.0, 1.0};

int main()
{
    int t, n, ca = 1;
    double s = 1.0;
    for(int i = 2; i < 100000001; i++)
    {
        s += (1.0 / i);
        if(i % 24 == 0) a[i/24] = s;
    }
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d", &n);
        int x = n / 24;
        s = a[x];
        for(int i = 24 * x + 1; i <= n; i++) s += (1.0 / i);
        printf("Case %d: %.10f\n", ca++, s);
    }
    return 0;
}