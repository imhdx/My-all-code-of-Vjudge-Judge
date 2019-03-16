#include<bits/stdc++.h>
using namespace std;
int gcd(int x,int y)
{
    y==0?x:gcd(y,x%y);
}
int main()
{
    int n;
    while (scanf("%d",&n)!=EOF)
    {
        int x;
        int y;
        scanf("%d",&x);
        for (int i=1;i<n;i++)
        {
            scanf("%d",&y);
            x=x/gcd(x,y)*y;
        }
        printf("%d\n",x);
    }
    return 0;
}
