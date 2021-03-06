///照着kuangbin的板子敲得
#include<bits/stdc++.h>
using namespace std;
const int MAXN=502;
const int MAXM=202;
const int tot=128;
vector<int> v[1010];
struct Trie
{
    int next[MAXN*MAXM][tot],fail[MAXN*MAXM],end[MAXN*MAXM];
    int root,L;
    int newnode()
    {
        for (int i=0; i<tot; i++)
            next[L][i]=-1;
        end[L++]=-1;
        return L-1;
    }
    void init()
    {
        L=0;
        root=newnode();
    }
    void insert(char s[],int id)
    {
        int len=strlen(s);
        int now=root;
        for (int i=0; i<len; i++)
        {
            if (next[now][s[i]]==-1)
                next[now][s[i]]=newnode();
            now=next[now][s[i]];
        }
        end[now]=id;
        //printf("%d\n",end[now]);
    }
    void build()
    {
        queue<int>Q;
        fail[root]=root;
        for (int i=0; i<tot; i++)
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
            for (int i=0; i<tot; i++)
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
    bool vis[510];
    bool query(char buf[],int id)
    {
        memset(vis,0,sizeof(vis));
        //int ans=0;
        int len=strlen(buf);
        int now=root;
        for (int i=0; i<len; i++)
        {
            now=next[now][buf[i]];
            int temp=now;
            while (temp!=root)
            {
                if (end[temp]!=-1)
                {
                    if (vis[end[temp]]==0)
                    {
                        vis[end[temp]]=1;
                        v[id].push_back(end[temp]);
                    }
                }
                //ans+=end[temp];
                //end[temp]=0;
                temp=fail[temp];
            }
        }
        //printf("%d\n",ans);
        //return ans;
    }
};
char buf[10009];
Trie ac;
int main()
{
    int n;
    scanf("%d",&n);
    ac.init();
    for (int i=0; i<n; i++)
    {
        scanf("%s",buf);
        ac.insert(buf,i+1);
    }
    ac.build();
    int m;
    scanf("%d",&m);
    for (int i=0;i<m;i++)
    {
        scanf("%s",buf);
        ac.query(buf,i);
    }
    int total=0;
    for (int i=0;i<m;i++)
    {
        if (v[i].size()!=0)
        {
            total++;
            printf("web %d:",i+1);
            sort(v[i].begin(),v[i].end());
            for (int j=0;j<v[i].size();j++)
                printf(" %d",v[i][j]);
            printf("\n");
        }
    }
    printf("total: %d\n",total);
    return 0;
}
