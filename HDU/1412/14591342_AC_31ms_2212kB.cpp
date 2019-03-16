#include<stdio.h>
#include<set>
#include<algorithm>
using namespace std;
int main()
{
    set<int> a;
    int n,m;
    while (scanf("%d%d",&n,&m)!=EOF)
    {
        a.clear();
        int i,j;
        for (i=0;i<n+m;i++)
        {
            int x;
            scanf("%d",&x);
            a.insert(x);
        }
        set<int>::iterator it;
        for (it=a.begin();it!=a.end();)
        {
            printf("%d",(*it));
            if ((++it)!=a.end()) printf(" ");
        }
        printf("\n");
    }
    return 0;
}
