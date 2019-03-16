///照着kuangbin的板子敲得
#include<bits/stdc++.h>
using namespace std;
const int MAXN=10004;
const int MAXM=52;
const int tot=26;
char str[MAXN][MAXM];
struct Trie
{
    int next[MAXN*MAXM][tot],fail[MAXN*MAXM],end[MAXN*MAXM];
    int root,L;
    int newnode()
    {
        for (int i=0;i<tot;i++)
            next[L][i]=-1;
        end[L++]=-1;
        return L-1;
    }
    void init()
    {
        L=0;
        root=newnode();
    }
    void insert(char s[])
    {
        int len=strlen(s);
        int now=root;
        for (int i=0;i<len;i++)
        {
            if (next[now][s[i]-'a']==-1)
                next[now][s[i]-'a']=newnode();
            now=next[now][s[i]-'a'];
        }
        end[now]=0;
    }
    void build()
    {
        queue<int>Q;
        fail[root]=root;
        for (int i=0;i<tot;i++)
        {
            if (next[root][i]==-1)
                next[root][i]=root;
            else
            {
                fail[next[root][i]]=root;
                Q.push(next[root][i]);
            }
        }
        while (!Q.empty())
        {
            int now=Q.front();
            Q.pop();
            for (int i=0;i<tot;i++)
            {
                if (next[now][i]==-1)
                    next[now][i]=next[fail[now]][i];
                else
                {
                    fail[next[now][i]]=next[fail[now]][i];
                    Q.push(next[now][i]);
                }
            }
        }
    }
    void query(char buf[])
    {
        int ans=0;
        int len=strlen(buf);
        int now=root;
        for (int i=0;i<len;i++)
        {
            if (buf[i]<'a'||buf[i]>'z')
            {
                now=root;
                continue;
            }
            now=next[now][buf[i]-'a'];
            int temp=now;
            while (temp!=root)
            {
                if (end[temp]!=-1)
                {
                    end[temp]=-1;
                    ans++;
                }
                temp=fail[temp];
            }
        }
        printf("%d\n",ans);
        //return ans;
    }
};
char buf[1000006];
Trie ac;
int main()
{
    int n;
    int T;
    scanf("%d",&T);
    while (T--)
    {
        scanf("%d",&n);
        ac.init();
        for (int i=0;i<n;i++)
        {
            scanf("%s",str[i]);
            ac.insert(str[i]);
        }
        ac.build();
        scanf("%s",buf);
        ac.query(buf);
    }
    return 0;
}
