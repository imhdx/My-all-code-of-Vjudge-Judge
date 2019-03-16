#include<bits/stdc++.h>
using namespace std;
int a[1000011];
long long int num[10000011];
int main()
{
    int m;
    int n;
    scanf("%d",&n);
    int i;
    for (i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        for (int j=2;j<=a[i];j++)
        {
            if (a[i]%j==0)
            {
                num[j]++;
                a[i]=a[i]/j;
                while (a[i]%j==0) a[i]=a[i]/j;
            }
        }
    }
    for (i=1;i<10000010;i++)
        num[i]+=num[i-1];
    scanf("%d",&m);
    for (i=0;i<m;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        printf("%d\n",num[min(10000010-1,y)]-num[x-1]);
    }
    return 0;
}
