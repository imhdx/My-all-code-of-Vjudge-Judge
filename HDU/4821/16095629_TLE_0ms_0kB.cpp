#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
ull base=131;
char s[100100];
ull hashh[100100];
ull poww[100100];
int main()
{
    int m,l;
    poww[0]=1;
    for (int i=1;i<100100;i++) poww[i]=poww[i-1]*base;
    while (scanf("%d%d",&m,&l)!=EOF)
    {
        scanf("%s",s+1);
        int ans=0;
        int len=strlen(s+1);
       // printf("len=%d\n",len);
        for (int i=1;i<=len;i++)
        {
            hashh[i]=hashh[i-1]*base+s[i]-'a';
        }
        for (int i=1;i<=len;i++)
        {
            if (i+m*l-1<=len)
            {
                set<ull> s;
                int j;
                for (j=0;j<m;j++)
                {
                    //ull k=hashs(i+j*l,i+j*l+l-1);
                    ull k=hashh[i+j*l+l-1]-hashh[i+j*l-1]*poww[l];
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
