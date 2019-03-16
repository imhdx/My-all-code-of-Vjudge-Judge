#include<bits/stdc++.h>
using namespace std;
int a[220][220];
int main()
{
    int T;scanf("%d",&T);
    while (T--){
        int n;scanf("%d",&n);
        int flag=0;
        for (int i=1;i<=n;i++){
            for (int j=1;j<=n;j++)
                scanf("%d",&a[i][j]);
        }
        for (int i=1;i<=n;i++){
            int sum=0;
            for (int j=1;j<=n;j++){
                sum+=a[i][j];
            }
            if (sum==0) flag=1;
        }
        for (int j=1;j<=n;j++){
            int sum=0;
            for (int i=1;i<=n;i++){
                sum+=a[i][j];
            }
            if (sum==0) flag=1;
        }
        if (flag) printf("No\n");
        else printf("Yes\n");
    }
    return 0;
}
