#include<bits/stdc++.h>
using namespace std;
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n;
        scanf("%d",&n);
        int tmp=n/150;
        int mmp=n-150*tmp;
        if (mmp/50<=tmp)
            printf("%d\n",mmp%50);
        else
            printf("%d\n",mmp-tmp*50);
    }
    return 0;
}
