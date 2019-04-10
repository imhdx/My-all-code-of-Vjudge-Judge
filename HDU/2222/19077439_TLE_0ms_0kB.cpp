#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdio.h>
#include<queue>
using namespace std;
#define endl '\n'
#define end cjlac
const int maxm=52;
const int maxn=10004;
const int tot=26;
const char chx='a';
char str[maxm];
int t[maxn*maxm][tot];
int fail[maxn*maxm];
int end[maxn*maxm];
int cnt=0;
void init()
{
    cnt=0;
    memset(t,0,sizeof(t));
    memset(fail,0,sizeof(fail));
    memset(end,0,sizeof(end));
}
void insert(char s[])
{
    int len=strlen(s);
    int root=0;
    for (int i=0;i<len;i++)
    {
        int k=s[i]-'a';
        if (t[root][k]==0) t[root][k]=++cnt;
        root=t[root][k];
    }
    end[root]++;
}
void build()
{
    queue<int> que;
    for (int i=0;i<26;i++)
        if (t[0][i])
            que.push(t[0][i]);
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
int ask(char s[])
{
    int ans=0;
    int len=strlen(s);
    int root=0;
    for (int i=0;i<len;i++)
    {
        int k=s[i]-'a';
        root=t[root][k];
        int temp=root;
        while (temp)
        {
            ans+=end[temp];
            end[temp]=0;
            temp=fail[temp];
        }
    }
    return ans;
}
int main()
{
    int T;scanf("%d",&T);
    while (T--)
    {
        int n;scanf("%d",&n);
        init();
        for (int i=0;i<n;i++)
        {
            scanf("%s",str);
            insert(str);
        }
        build();
        scanf("%s",str);
        printf("%d\n",ask(str));
    }
    return 0;
}
