#include<bits/stdc++.h>
using namespace std;
int a[100005];
bool cmp(int q,int p){return q>p;}
int dp[100010];
int main()
{
    int sum=0;
    int n;scanf("%d",&n);
    for (int i=0;i<n;i++) scanf("%d",&a[i]),sum+=a[i];
    sort(a,a+n);
    int l=0,r=-1;
    int ans=0;
    int cnt=0;
    int cc=1000;
    while (cc--){
        int flag=0;
        for (r++;r<n;r++)
        {
            flag=1;
            cnt+=a[r];
            if (2*cnt>sum) break;
        }
        for (;l<=r;l++)
        {
            
            if (2*(cnt-a[l])>sum) flag=1,cnt-=a[l];
            else break;
        }
        //printf("%d %d\n",l,r);
        ans=max(ans,cnt);
        if (flag==0) break;
    }
    printf("%d\n",ans);

    return 0;
}
