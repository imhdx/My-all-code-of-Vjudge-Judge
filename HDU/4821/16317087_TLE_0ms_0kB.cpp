#include<bits/stdc++.h>
using namespace std;
string str;
typedef unsigned long long ull;
typedef long long ll;
const int mod=1e9+7;
ull has[100005];
ull poww[100005];
ull gethas(int l,int r)
{
    if (l==0) return has[r];
    return has[r]-has[l-1]*poww[r-l+1];
}
map<ull,int> M;
int main()
{
    int l,m;
    ull base=131;
    poww[0]=1;
    for (int i=1;i<100005;i++)
        poww[i]=poww[i-1]*base;
    //printf("%llu\n",poww[2]);
    while (scanf("%d%d",&m,&l)!=EOF)
    {
        cin>>str;
        has[0]=(ull)str[0];
        for (int i=1;str[i];i++)
        {
            has[i]=has[i-1]*base+(ull)str[i];
        }
        //for (int i=0;i<str.size();i++)
        //    printf("%llu%c",has[i]," \n"[i==str.size()-1]);
        //printf("%llu %llu %llu\n",gethas(0,2),gethas(3,5),gethas(9,11));

        int len=str.size();
        int cnt=0;
        for (int i=0;i<len;i++)
        {
            M.clear();
            int j=0;
            if (i+l*m<=len)
                for (j=0;j<m;j++)
                {
                    ull k=gethas(i+j*l,i+j*l+l-1);
                    //printf("%d %d %d\n",i,i+j*l,i+j*l+l-1);
                    if (M[k]!=0)
                    {
                        break;
                    }
                    else
                        M[k]=1;
                }
            else
                break;
            if (j==m)
            {
                cnt++;
                //printf("i=%d\n",i);
            }
        }
        printf("%d\n",cnt);

    }

    return 0;
}
