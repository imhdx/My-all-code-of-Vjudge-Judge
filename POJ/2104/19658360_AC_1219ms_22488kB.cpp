#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
const int maxn=1e5+7;
vector<int>v;
int n,m,cnt,x,y,k;
int root[maxn],a[maxn];
struct Node{
    int l,r,sum;
    Node(){}
}T[maxn*30];
int getid(int x){return lower_bound(v.begin(),v.end(),x)-v.begin()+1;}
void update(int l,int r,int &x,int y,int pos)
{
    T[++cnt]=T[y],T[cnt].sum++,x=cnt;
    if(l==r)return ;
    int mid=l+r>>1;
    if(mid>=pos)update(l,mid,T[x].l,T[y].l,pos);
    else update(mid+1,r,T[x].r,T[y].r,pos);
}
int query(int l,int r,int x,int y,int k)
{
    if(l==r)return l;
    int mid=l+r>>1;
    int sum=T[T[y].l].sum-T[T[x].l].sum;
    if(sum>=k)return query(l,mid,T[x].l,T[y].l,k);
    return query(mid+1,r,T[x].r,T[y].r,k-sum);
}
int read()
{
    register int s=0,f=1;
    char c=getchar();
    while (c<'0'||c>'9')
    {
        if (c=='-') f=-1;
        c=getchar();
    }
    while (c>='0'&&c<='9')
    {
        s=s*10+c-'0';
        c=getchar();
    }
    return s*f;
}
int main()
{
    n=read();m=read();
    for (int i=1;i<=n;i++) a[i]=read(),v.push_back(a[i]);
    sort(v.begin(),v.end()),v.erase(unique(v.begin(),v.end()),v.end());
    for (int i=1;i<=n;i++) update(1,n,root[i],root[i-1],getid(a[i]));
    for (int i=1;i<=m;i++) x=read(),y=read(),k=read(),printf("%d\n",v[query(1,n,root[x-1],root[y],k)-1]);
    return 0;
}