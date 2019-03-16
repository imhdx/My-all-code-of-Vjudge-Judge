#include<bits/stdc++.h>
using namespace std;
int f(int n,int m)
{
    int tmp=1;
    int res;
    for (int i=0;i<m;i++)
    {
        res=tmp;
        if (tmp*10<=n) tmp*=10;
        else{
            if (tmp>=n) tmp/=10;
            tmp++;
            while (tmp%10==0) tmp/=10;
        }
    }
    return res;
}
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n,k;
        scanf("%d%d",&n,&k);
        printf("%d\n",f(n,k));
    }
    return 0;
}
