#include<bits/stdc++.h>
using namespace std;
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int l1,l2,r1,r2,p1,p2,d1,d2;
        scanf("%d%d%d%d",&l1,&r1,&p1,&d1);
        scanf("%d%d%d%d",&l2,&r2,&p2,&d2);
        int cnt=0;
        int k;
        scanf("%d",&k);
        int i,j;
        if (p1==p2) cnt++;
        for (i=1;i<k;i++)
        {
            if (d1==0)
            {
                p1--;
                if (p1<l1)
                {
                    p1=l1+1;
                    d1=1;
                }
            }
            else
            {
                p1++;
                if (p1>r1)
                {
                    p1=r1-1;
                    d1=0;
                }
            }
            if (d2==0)
            {
                p2--;
                if (p2<l2)
                {
                    p2=l2+1;
                    d2=1;
                }
            }
            else
            {
                p2++;
                if (p2>r2)
                {
                    p2=r2-1;
                    d2=0;
                }
            }
            if (p1==p2) cnt++;
        }
        printf("%d\n",cnt);
    }
    return 0;
}
