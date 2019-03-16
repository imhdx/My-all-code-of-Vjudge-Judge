#include<bits/stdc++.h>
using namespace std;


int main()
{
    int n;
    scanf("%d",&n);
    int i,j;
    int cnt=0;
    for (j=1; j<=n; j++)
    {
        for (i=1; i<=j&&(i*i+i*i)<=j*j; i++)
        {
            int tmp=j*j-i*i;
            int t=sqrt(tmp);
            if (t*t==tmp)
            {
                cnt++;

            }
        }
    }

    printf("%d\n",cnt);
    return 0;
}
