#include<bits/stdc++.h>
using namespace std;
int a[220][220];
int n;
bool gauss()
{
    for (int i=1;i<=n;i++){
        int t=i;
        int j;
        for (j=i;j<=n;j++){
            if (a[j][i]){
                t=j;
                break;
            }
        }
        if (j==n+1) return 0;
        for (int j=1;j<=n;j++) swap(a[i][j],a[t][j]);
    }
    return 1;
}
int main()
{
    int T;scanf("%d",&T);
    while (T--){
        scanf("%d",&n);
        for (int i=1;i<=n;i++){
            for (int j=1;j<=n;j++){
                scanf("%d",&a[i][j]);
            }
        }
        if (gauss())
            printf("Yes\n");
        else printf("No\n");

    }
    return 0;
}
