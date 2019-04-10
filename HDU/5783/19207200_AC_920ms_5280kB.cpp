#include<bits/stdc++.h>
using namespace std;
int a[1000006];
int main()
{
    int n;
    while (scanf("%d",&n)!=EOF)
    {
        for (int i=0;i<n;i++) scanf("%d",&a[i]);
        int cnt=0;
        long long s=0;
        for (int i=n-1;i>=0;i--)
        {
            s+=a[i];
            if (s>=0)
            {
                s=0;
                cnt++;
            }
        }
        printf("%d\n",cnt);
    }
    return 0;
}
