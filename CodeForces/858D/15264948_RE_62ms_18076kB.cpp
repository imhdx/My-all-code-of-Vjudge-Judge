#include<bits/stdc++.h>
using namespace std;
int n;
struct note
{
    note *nxt[12];
    set<int> flag;
    node()
    {
        for (int i=0;i<12;i++)
            nxt[i]=NULL;
        flag.clear();
    }
};
note *root;
void init(){root = new note(); }
char str[7005][12];
void ins(int st,int len,int kai)
{
    int l=kai;
    int r=len+kai;
    note *now=root;
    for (int i=l;i<=r;i++)
    {
        int to=str[st][i]-'0';
        if (now->nxt[to]==NULL) now->nxt[to]=new note();
        now=now->nxt[to];
    }
    (now->flag).insert(st);
    //printf("hh\n");
}

int cha(int st,int len,int kai)
{
    int l=kai;
    int r=len+kai;
    note *now=root;
    for (int i=l;i<=r;i++)
    {
        int to=str[st][i]-'0';
        if (now->nxt[to]==NULL)
        {
            return 0;
        }
        now=now->nxt[to];
    }
    return (now->flag).size();
}
void print(int st,int len,int kai)
{
    int l=kai;
    int r=len+kai;
    for (int i=l;i<=r;i++)
        printf("%c",str[st][i]);
    printf("\n");
}
int main()
{
    init();
    int i,j,k;
    scanf("%d",&n);
    getchar();
    for (i=0;i<n;i++)
    {
        scanf("%s",str[i]);
        for (j=0;j<=9;j++)
        {
            for (k=0;k+j<9;k++)
            {
                //printf("hi\n");
                ins(i,j,k);
            }
        }
    }
    for (i=0;i<n;i++)
    {
        int flag=0;
        for (j=0;j<=9;j++)
        {
            for (k=0;k+j<9;k++)
            {
                if (cha(i,j,k)==1)
                {
                    flag=1;
                    print(i,j,k);
                    break;
                }
            }
            if (flag==1) break;
        }
    }
    return 0;
}
