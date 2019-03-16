#include<bits/stdc++.h>
using namespace std;
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n,m,k;
        scanf("%d%d%d",&n,&m,&k);
        if (m-k>n) printf("advertise\n");
        else if (m-k<n) printf("do not advertise\n");
        else
            printf("does not matter\n");
    }

    return 0;
}
