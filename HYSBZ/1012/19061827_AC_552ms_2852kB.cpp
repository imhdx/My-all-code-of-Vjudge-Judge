#include<bits/stdc++.h>
using namespace std;
long long bit[200010];
void add(int pos,long long x)
{
    while (pos<200010)
    {
        bit[pos]=max(bit[pos],x);
        pos+=pos&(-pos);
    }
}
long long ask(int pos)
{
    long long ans=0;
    while (pos)
    {
        ans=max(ans,bit[pos]);
        pos-=pos&(-pos);
    }
    return ans;
}
int main()
{
    int m;
    long long d;
    scanf("%d%lld",&m,&d);
    int tot=200005;
    long long t=0;
    for (int i=0;i<m;i++)
    {
        //printf("hh\n");
        char op[3];
        long long l;
        scanf("%s%lld",op,&l);
        if (op[0]=='A')
        {
            l+=t;
            l%=d;
            //printf("l=%lld\n",l);
            add(tot,l);
            tot--;
            //for (int i=tot;i<=200005;i++) printf("hi %lld\n",bit[i]);
        }
        else{
            t=ask(tot+l);
            printf("%lld\n",t);
        }
    }
    return 0;
}
