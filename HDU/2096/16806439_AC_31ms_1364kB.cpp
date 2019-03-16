#include<bits/stdc++.h>
using namespace std;
const double PI=4*atan(1.0);
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        printf("%d\n",(a%100+b%100)%100);
    }

    return 0;
}
