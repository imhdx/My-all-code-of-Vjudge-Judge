#include<bits/stdc++.h>
using namespace std;
char str[100005];
bool ling[30];
int a[30][100005];
int pos[30];
bool cmp(int x,int y)
{
    for (int i=100004;i>=0;i--)
    {
        if (a[x][i]!=a[y][i]) return a[x][i]<a[y][i];
    }
    return 0;
}
const int mod=1e9+7;
int main()
{
    int n;
    int tt=1;
    while (scanf("%d",&n)!=EOF)
    {
        memset(ling,0,sizeof(ling));
        memset(a,0,sizeof(a));
        a[0][0]=0;
        for (int i=0;i<n;i++)
        {
            scanf("%s",str);
            int len=strlen(str);
            if (len>1) ling[str[0]-'a']=1;
            for (int k=0,j=len-1;j>=0;j--,k++)
            {
                a[str[j]-'a'][k]++;
                int pos=k;
                while (pos+1<100005 && a[str[j]-'a'][pos]==26)
                {
                    a[str[j]-'a'][pos]=0;
                    a[str[j]-'a'][pos+1]++;
                    pos++;
                }
            }

        }
        for (int i=0;i<26;i++) pos[i]=i;
        for (int i=1;i<26;i++)
        {
            for (int j=0;j+1<26;j++)
            {
                if (cmp(pos[j],pos[j+1])) swap(pos[j],pos[j+1]);
            }
        }
        for (int i=25;i>=0;i--)
        {
            if (ling[pos[i]]==0)
            {
                int tmp=pos[i];
                for (int j=i;j+1<26;j++) pos[j]=pos[j+1];
                pos[25]=tmp;
                break;
            }
        }
        long long ans=0;
        for (int i=0;i<26;i++)
        {
            long long po=1;
            for (int j=0;j<100005;j++)
            {
                (ans+=po*a[pos[i]][j]%mod*(25-i)%mod)%=mod;
                (po*=26)%=mod;
            }
        }
        printf("Case #%d: %lld\n",tt++,ans);
    }
    return 0;
}///