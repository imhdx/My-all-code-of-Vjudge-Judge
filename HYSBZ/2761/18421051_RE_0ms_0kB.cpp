#include<bits/stdc++.h>
using namespace std;
vector<int> v[100000];
bool insert(int x)
{
    int y=x%100000;

    for (int i=0;i<v[y].size();i++)
        if (v[y][i]==x) return 1;
    v[y].push_back(x);
    return 0;
}
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        for (int i=0;i<100000;i++) v[i].clear();
        int n;
        scanf("%d",&n);
        for (int i=0;i<n;i++)
        {
            int x;
            scanf("%d",&x);
            bool flag=insert(x);
            if (i==0) printf("%d",x);
            else if (flag==0) printf(" %d",x);
        }
        printf("\n");
    }
    return 0;
}
