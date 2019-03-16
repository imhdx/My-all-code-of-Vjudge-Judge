#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    scanf("%d",&t);
    while (t--)
    {
        int n;
        int cnt=0;
        scanf("%d",&n);
        while (n!=0)
        {
            if (n%2==0)
                n=n/2;
            else
            {
                n--;
                cnt++;
            }
        }
        printf("%d\n",cnt);
    }

    return 0;
}
