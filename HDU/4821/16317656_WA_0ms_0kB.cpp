#include<bits/stdc++.h>
using namespace std;
char str[100005];
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
        scanf("%s",str);
        has[0]=(ull)str[0];
        for (int i=1;str[i];i++)
        {
            has[i]=has[i-1]*base+(ull)str[i];
        }
        //for (int i=0;i<str.size();i++)
        //    printf("%llu%c",has[i]," \n"[i==str.size()-1]);
        //printf("%llu %llu %llu\n",gethas(0,2),gethas(3,5),gethas(9,11));

        int len=strlen(str);
        int cnt=0;


        for (int i=0;i<l&&i+m*l-1<len;i++)
        {
            M.clear();
            for(int j=i;j<i+m*l;j+=l)
                M[gethas(j,j+l-1)]++;
            if (M.size()==m)
                cnt++;
            for(int j=i;j<len-m*l-l+1;j+=l)
            {
                M[gethas(j,j+l-1)]--;
                if (M[gethas(j,j+l-1)]==0) M.erase(gethas(j,j+l-1));
                M[gethas(j+m*l-l,j+m*l-1)]++;
                if (M.size()==m) cnt++;
            }

        }
        printf("%d\n",cnt);
        /*

        for (int i=0;i<=l&&i+m*l<len;i++)
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
            if (j<m)
            {
                cnt++;
                //printf("i=%d\n",i);
            }
        }
        printf("%d\n",cnt);
        */
    }

    return 0;
}
