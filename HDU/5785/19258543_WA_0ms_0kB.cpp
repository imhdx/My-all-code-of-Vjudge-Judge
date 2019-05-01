#include<bits/stdc++.h>
using namespace std;
char s[1000006];
int d1[1000006];
int d2[1000006];
const int mod=1e9+7;
void manacher(char s[]) {
    int n=strlen(s);
    memset(d1,0,sizeof(d1));
    memset(d2,0,sizeof(d2));
    for (int i = 0, l = 0, r = -1; i < n; i++) {
        int k = (i > r) ? 1 : min(d1[l + r - i], r - i);
        while (0 <= i - k && i + k < n && s[i - k] == s[i + k]) {
            k++;
        }
        d1[i] = k--;
        if (i + k > r) {
            l = i - k;
            r = i + k;
        }
    }
    for (int i = 0, l = 0, r = -1; i < n; i++) {
        int k = (i > r) ? 0 : min(d2[l + r - i + 1], r - i + 1);
        while (0 <= i - k - 1 && i + k < n && s[i - k - 1] == s[i + k]) {
            k++;
        }
        d2[i] = k--;
        if (i + k > r) {
            l = i - k - 1;
            r = i + k;
        }
    }
}
long long sum1[1000006];
long long tmp1[1000006];
long long sum2[1000006];
long long tmp2[1000006];
void add(long long sum[],long long tmp[],int l,int r,int x,int y) { ///区间[l,r]首项为x公差为y
    sum[l]+=x;
    if (sum[l]>=mod)
        sum[l]-=mod;
    sum[r+1]-=x+(r-l)*y;
    if (sum[r+1]>=mod)
        sum[r+1]-=mod;
    tmp[l+1]+=y;
    if (tmp[l+1]>=mod)
        tmp[l+1]-=mod;
    tmp[r+1]-=y;
    if (tmp[r]>=mod)
        tmp[r]-=mod;
}
int main() {
    while (scanf("%s",s)!=EOF) {
        manacher(s);
        int n=strlen(s);
        memset(sum1,0,sizeof(sum1));
        memset(tmp1,0,sizeof(tmp1));
        memset(sum2,0,sizeof(sum2));
        memset(tmp2,0,sizeof(tmp2));
        for (int i=0; i<n; i++) {
            int l=i-d1[i]+1;
            int r=i+d1[i]-1;
            add(sum1,tmp1,i+1,r+1,i+1,-1);
            add(sum2,tmp2,l+1,i+1,r+1,-1);
        }
        for (int i=1; i<n; i++) {
            int l=i-d2[i];
            int r=i+d2[i]-1;
            add(sum1,tmp1,i+1,r+1,i-1+1,-1);
            add(sum2,tmp2,l+1,i-1+1,r+1,-1);
        }
        for (int i=2; i<=n; i++) {
            tmp1[i]+=tmp1[i-1];
            sum1[i]+=sum1[i-1]+tmp1[i];
            tmp2[i]+=tmp2[i-1];
            sum2[i]+=sum2[i-1]+tmp2[i];
        }
        long long ans=0;
        for (int i=1;i+1<=n;i++)
        {
            ans+=sum1[i]*sum2[i+1]%mod;
            ans%=mod;
        }
        printf("%lld\n",ans);
    }
    return 0;
}
