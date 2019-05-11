#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    scanf("%d",&n);
    int cnt1=0;
    int cnt2=0;
    int cnt3=0;
    for (int i=1;i<=n;i++)
    {
        int x;
        scanf("%d",&x);
        if (x==25)
        {
            cnt1++;
        }
        else if (x==50)
        {
            if (cnt1>=1)
            {
                cnt1--;
                cnt2++;
            }
            else return 0*printf("NO\n");
        }
        else if (x==100)
        {
            if (cnt2>=1&&cnt1>=1)
            {
                cnt1--;
                cnt2--;
                cnt3++;
            }
            else if (cnt1>=3)
            {
                cnt1-=3;
                cnt3++;
            }
            else return 0*printf("NO\n");
        }
    }
    printf("YES\n");
    return 0;
}
