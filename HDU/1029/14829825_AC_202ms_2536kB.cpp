#include<bits/stdc++.h>
using namespace std;
int a[999999+9];
int main()
{
    int n;
    while (scanf("%d",&n)!=EOF)
    {
        int i;
        for (i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
        }
        sort(a,a+n);
        int m=(n+1)/2;
        int j;
        for (i=0;i<n;i=j)
        {
            int cnt=0;
            j=i;
            while (a[i]==a[j++]) cnt++;
            if (cnt>=m)
            {
                printf("%d\n",a[i]);
                break;
            }
        }

    }
    return 0;
}
