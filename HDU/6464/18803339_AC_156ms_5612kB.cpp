#include<bits/stdc++.h>
using namespace std;
#define int long long
vector<int> v;
const int mod=1000000007;
int find(int x)
{
    return lower_bound(v.begin(),v.end(),x)-v.begin();
}
int bitn[1000005];
int bits[1000005];
void add(int x,int y,int num)///x表示原始数，y表示离散化后的数，num表示数量
{
    while (y<1000005)
    {
        bitn[y]+=num;
        bits[y]+=x*num%mod;
        bits[y]%=mod;
        y+=y&(-y);
    }
}
int askn(int x)
{
    int ans=0;
    while (x>0)
    {
        ans+=bitn[x];
        //ans%=mod;
        x-=x&(-x);
    }
    return ans;
}
int asks(int x)
{
    int ans=0;
    while (x>0)
    {
        ans+=bits[x];
        ans%=mod;
        x-=x&(-x);
    }
    return ans;
}
struct ac
{
    int op,l,r;
}que[1000005];
signed main()
{
    v.push_back(-2);
    v.push_back(-1);
    int n;
    scanf("%lld",&n);
    for (int i=0;i<n;i++)
    {
        scanf("%lld%lld%lld",&que[i].op,&que[i].l,&que[i].r);
        if (que[i].op==1)
        {
            v.push_back(que[i].r);
        }
    }
    sort(v.begin(),v.end());
    v.resize(unique(v.begin(),v.end())-v.begin());

    for (int i=0;i<n;i++)
    {
        if (que[i].op==1)
        {
            add(que[i].r,find(que[i].r),que[i].l);
        }
        else{
            int ll=0;
            int rr=1000004;
            int pos1=0;///最后一个小于
            while (ll<=rr)
            {
                int mid=ll+rr>>1;
                //printf("%d %d\n",mid,askn(mid));
                if (askn(mid)<que[i].l)
                {
                    pos1=mid;
                    ll=mid+1;
                }
                else rr=mid-1;
            }
            //printf("hi  %d ",pos1);

            ll=0;
            rr=1000004;
            int pos2=0;
            while (ll<=rr)
            {
                int mid=ll+rr>>1;
                //printf("%d %d\n",mid,askn(mid));
                if (askn(mid)<que[i].r)
                {
                    pos2=mid;
                    ll=mid+1;
                }
                else rr=mid-1;
            }
            //printf("%d\n",pos2);
            int ans=0;
            if (pos1==pos2)
            {
                ans+=(que[i].r-que[i].l+1)*v[pos1+1]%mod;
            }
            else{
                ans+=(askn(pos1+1)-que[i].l+1)*v[pos1+1]%mod;
                ans%=mod;
                //printf("ans1=%d\n",ans);
                ans+=(que[i].r-askn(pos2))*v[pos2+1]%mod;
                ans%=mod;
                //printf("ans2=%d\n",ans);
                ans+=asks(pos2)-asks(pos1+1);
                //ans%=mod;
            }
            ans%=mod;
            ans+=mod;
            ans%=mod;
            printf("%lld\n",ans);

        }
    }
    return 0;
}
