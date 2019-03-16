#include<bits/stdc++.h>
using namespace std;
int a[10005];
int n, k;

bool ok(int m)
{
    int cnt = 0;
    for(int i = 0; i < n; i++)
        cnt += a[i] / m;
    return cnt >= k;
}

int main()
{
    while(scanf("%d %d", &n, &k) != EOF)
    {
        int ma = 0;
        for(int i = 0; i < n; i++)
        {
            double tmp;
            scanf("%lf", &tmp);
            a[i] = (int)(tmp * 100);
            ma = max(ma, a[i]);
        }
        int r = ma, l = 1;
        while(l <= r)
        {
            int mid = (l + r) / 2;
            if(ok(mid))
                l = mid + 1;
            else
                r = mid - 1;
        }
        //注意这里答案是r不是l，因为cnt比k小是符合条件的，大于k就不符合条件了
        printf("%.2f\n"
, (double)r / 100.0);
}

}
