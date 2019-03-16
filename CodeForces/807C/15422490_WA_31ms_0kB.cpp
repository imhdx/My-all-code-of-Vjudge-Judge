#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int a,b,p,q;
        scanf("%d%d%d%d",&a,&b,&p,&q);
        if (p==q)
        {
            if (a==b)
                printf("0\n");
            else
                printf("-1\n");
        }
        else if (p==0)
        {
            if (a==0)
                printf("0\n");
            else
                printf("-1\n");
        }
        else
        {
            int tmp=max((int)ceil(1.0*a/p),(int)ceil(1.0*b/q));
            tmp=max(tmp,(int)ceil(1.0*(b-a)/(q-p)));
            //printf("tmp=%d\n",tmp);
            int ans=tmp*q-b;
            printf("%d\n",ans);
        }
    }
    return 0;
}
