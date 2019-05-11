//
// Created by mhdx on 2019/5/6.
//

#include<bits/stdc++.h>
using namespace std;

int n;
int ans=0;
char str[20][20];
void dfs(int line,int hen,int zhu,int fu)/// 三条
{
    if (line==n){
        ans++;
        return ;
    }
    for (int i=0;i<n;i++){
        if (str[line][i]=='.'){
            if ((hen>>i)&1) continue;
            if ((zhu>>(line+i))&1) continue;
            if ((fu>>(n+line-i))&1) continue;
            dfs(line+1,(hen|(1<<i)),(zhu|(1<<(line+i))),(fu|(1<<(n+line-i))));
        }
    }
}
int main()
{
    int tt=1;
    while (scanf("%d",&n)!=EOF&&n)
    {
        for (int i=0;i<n;i++) scanf("%s",str[i]);
        ans=0;
        dfs(0,0,0,0);
        printf("Case %d: ",tt++);
        printf("%d\n",ans);
    }
    return 0;
}