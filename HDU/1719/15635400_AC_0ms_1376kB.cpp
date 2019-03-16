#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long n;
    while (scanf("%lld",&n)!=EOF)
    {
        if (n==0)
            printf("NO!\n");
        else
        {
            n++;
            while (n%2==0) n/=2;
            while (n%3==0) n/=3;
            if (n==1)
                printf("YES!\n");
            else
                printf("NO!\n");
        }
    }

    return 0;
}
