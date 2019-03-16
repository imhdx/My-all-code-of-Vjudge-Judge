#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    while (scanf("%d",&n)!=EOF&&n)
    {
        int i;
        double sum=0;
        for (i=2;i<=n;i++)
        {
            sum+=1.0/i*(n-i+1);
        }
        sum=2*sum+n;
        printf("%.2f\n",sum);
    }
    return 0;
}
