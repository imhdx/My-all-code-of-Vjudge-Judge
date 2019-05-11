//
// Created by mhdx on 2019/5/6.
//

#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    int t;
    scanf("%d",&t);
    while (t--){
        int x;
        scanf("%d",&x);
        int cnt[4];
        int bit[4];
        int flag=0;
        for (int i=0;i<(1<<4);i++){
            for (int j=0;j<4;j++) bit[j]=(i>>j)&1;
            cnt[0]=cnt[2]=m;
            cnt[1]=cnt[3]=n;
            if (bit[0]==0) cnt[0]--;
            else cnt[3]--;
            if (bit[1]==0) cnt[3]--;
            else cnt[2]--;
            if (bit[2]==0) cnt[2]--;
            else cnt[1]--;
            if (bit[3]==0) cnt[1]--;
            else cnt[0]--;
            if (cnt[0]%x==0&&cnt[1]%x==0
            &&cnt[2]%x==0&&cnt[3]%x==0) flag=1;
        }
        if (flag) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}