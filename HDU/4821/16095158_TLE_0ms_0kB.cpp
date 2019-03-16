#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
ull base=131;
char s[100100];
ull hashs(int st,int la)
{
    ull ans=0;
    for (int i=st;i<=la;i++)
        ans=ans*base+(ull)s[i];
    return ans&0x7fffffff;
}

int main()
{
    int m,l;
    while (scanf("%d%d",&m,&l)!=EOF)
    {
        scanf("%s",s);
        int ans=0;
        int len=strlen(s);
        for (int i=0;i<len;i++)
        {
            if (i+m*l-1<len)
            {
                set<ull> s;
                int j;
                for (j=0;j<m;j++)
                {
                    ull k=hashs(i+j*l,i+j*l+l-1);
                    if (s.count(k)!=0)
                    {
                        break;
                    }
                    else
                    {
                        s.insert(k);
                    }
                }
                if (j==m)
                {
                    //printf("%d\n",i);
                    ans++;
                }
            }
            else
                break;
        }
        printf("%d\n",ans);
    }

    return 0;
}
