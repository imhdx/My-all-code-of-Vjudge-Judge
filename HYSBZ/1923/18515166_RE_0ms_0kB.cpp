#include<bits/stdc++.h>
using namespace std;
bitset<1010> a[1010];
///a[1-m][1-n+1]
///m个方程  n个未知数
int ans=-1;
int n,m;
void gauss()
{
    for (int i=1;i<=n;i++){
        int t=i;
        int j;
        for (j=i;j<=m;j++){
            if (a[j][i]==1){t=j;break;}
        }
        if (j==m+1){ans=-1;return ;}
        else ans=max(ans,j);///最多用到了第几个方程
        if (t!=i) swap(a[t],a[i]);
        for (int k=1;k<=m;k++)
            if (i!=k&&a[k][i]) a[k]^=a[i];
    }
}
char ch[10000];
int main()
{
    scanf("%d%d",&n,&m);

    for (int i=1;i<=m;i++){
        scanf("%s",ch+1);
		for(int j=1;j<=n;j++) a[i][j]=ch[j]-'0';
		scanf("%s",ch+1);
		a[i][n+1]=ch[1]-'0';
    }
    gauss();
    if (ans==-1) printf("Cannot Determine\n");
    else{
        printf("%d\n",ans);
        for (int i=1;i<=n;i++)
            if (a[i][n+1])
                printf("?y7M#\n");
            else printf("Earth\n");
    }
    return 0;
}
