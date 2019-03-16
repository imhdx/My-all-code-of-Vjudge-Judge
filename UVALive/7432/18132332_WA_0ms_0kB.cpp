#include<bits/stdc++.h>
using namespace std;
int mmp[300];
int main()
{
    int i;
    for (i=0;i<256;i++) mmp[i^((i<<1)&255)]=i;
    int n;
    scanf("%d",&n);
    for (int i=0;i<n;i++)
    {
        int x;
        scanf("%d",&x);
        printf("%d\n",mmp[x]);
    }
    return 0;
}
