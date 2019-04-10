#include<bits/stdc++.h>
using namespace std;
const int maxn=100005;
string str[maxn];
int cnt;
int t[maxn][30];
int fail[maxn];
int vis[maxn];
int len[maxn];
void init()
{
    cnt=0;
    memset(t,0,sizeof(t));
    memset(fail,0,sizeof(fail));
    memset(vis,0,sizeof(vis));
}
void insert(string &s)
{
    int root=0;
    int slen=s.size();
    for (int i=0;i<slen;i++)
    {
        int k=s[i]-'a';
        if (t[root][k]==0)
            t[root][k]=++cnt;
        root=t[root][k];
        len[root]=i+1;
    }
}
void build()
{
    queue<int> que;
    for (int i=0;i<26;i++) if (t[0][i]) que.push(t[0][i]);
    while (!que.empty())
    {
        int k=que.front();que.pop();
        for (int i=0;i<26;i++)
        {
            if (t[k][i])
            {
                fail[t[k][i]]=t[fail[k]][i];
                que.push(t[k][i]);
            }
            else t[k][i]=t[fail[k]][i];
        }
    }
}
int check(int pos,int a,int b)
{
    int root=0;
    int lena=str[a].size();
    for (int i=0;i<lena;i++)
    {
        int k=str[a][i]-'a';
        root=t[root][k];
        int temp=root;
        while (temp)
        {
            vis[temp]=pos;
            temp=fail[temp];
        }
    }
    int ans=0;
    root=0;
    int lenb=str[b].size();
    for (int i=0;i<lenb;i++)
    {
        int k=str[b][i]-'a';
        root=t[root][k];
        int temp=root;
        while (temp)
        {
            if (vis[temp]==pos) ans=max(ans,len[temp]);
            temp=fail[temp];
        }
    }
    return ans;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int T;cin>>T;
    while (T--)
    {
        init();
        int n;cin>>n;
        for (int i=0;i<n;i++)
        {
            cin>>str[i];
            insert(str[i]);
        }
        build();
        int m;cin>>m;
        for (int i=1;i<=m;i++)
        {
            int a,b;cin>>a>>b;
            a--;b--;
            printf("%d\n",check(i,a,b));
        }

    }
    return 0;
}
