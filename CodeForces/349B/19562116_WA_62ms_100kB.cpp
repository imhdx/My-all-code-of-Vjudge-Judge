#include<bits/stdc++.h>
using namespace std;
struct node
{
    int x,pos;
}ac[20];
bool cmp(node q,node p)
{
    if (q.x==p.x) return q.pos>p.pos;
    return q.x<p.x;
}
int main()
{
    int v;
    scanf("%d",&v);

    for (int i=1;i<=9;i++) scanf("%d",&ac[i].x),ac[i].pos=i;
    sort(ac+1,ac+10,cmp);

    string s="";
    for (int i=1;i<=9;i++)
    {
        int tmp=v/ac[i].x;
        v-=tmp*ac[i].x;
        while (tmp--) s+='0'+ac[i].pos;
        if (v==0) break;
    }
    if (s=="") printf("-1\n");
    else cout<<s<<'\n';
    return 0;
}
