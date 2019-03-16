#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <queue>
using namespace std;
const int MAXM=52;///单个模式串最多多少个字符
const int MAXN=10004;///多少个模式串
const int tot=26;///匹配串中多少个连续字符
const char chx='a';
char str[MAXN][MAXM];
struct Trie
{
    int next[MAXN*MAXM][tot],fail[MAXN*MAXM],end[MAXN*MAXM];
    int root,L;
    int newnode()
    {
        for(int i = 0;i < tot;i++)
            next[L][i] = -1;
        end[L++] = -1;
        return L-1;
    }
    void init()
    {
        L = 0;
        root = newnode();
    }
    void insert(char s[],int id)
    {
        int len = strlen(s);
        int now = root;
        for(int i = 0;i < len;i++)
        {
            if(next[now][s[i]-chx] == -1)
                next[now][s[i]-chx] = newnode();
            now = next[now][s[i]-chx];
        }
        end[now] = id;///记录每个串的ID
    }
    void build()
    {
        queue<int>Q;
        fail[root] = root;
        for(int i = 0;i < tot;i++)
            if(next[root][i] == -1)
                next[root][i] = root;
            else
            {
                fail[next[root][i]] = root;
                Q.push(next[root][i]);
            }
        while(!Q.empty())
        {
            int now = Q.front();
            Q.pop();
            for(int i = 0;i < tot;i++)
                if(next[now][i] == -1)
                    next[now][i]=next[fail[now]][i];
                else
                {
                    fail[next[now][i]]=next[fail[now]][i];
                    Q.push(next[now][i]);
                }
        }
    }
    int ans=0;
    void query(char buf[],int n)
    {
        ans=0;
        int len=strlen(buf);
        int now=root;
        for(int i=0;i<len;i++)
        {
            now=next[now][buf[i]-chx];
            int temp = now;
            while( temp != root )
            {
                if(end[temp] != -1)
                    ans++;
                temp = fail[temp];
            }
        }
        printf("%d\n",ans);
    }
};

char buf[1000009]; ///匹配串，模式串
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
        for(int i = 0;i < n;i++)
        {
            scanf("%s",str[i]);
            ac.insert(str[i],i);
        }
        ac.build();
        scanf("%s",buf);
        ac.query(buf,n);
    }
    return 0;
}
