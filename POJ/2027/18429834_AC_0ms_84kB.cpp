#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        if (a<b) printf("NO BRAINS\n");
        else printf("MMM BRAINS\n");
    }
    return 0;
}
