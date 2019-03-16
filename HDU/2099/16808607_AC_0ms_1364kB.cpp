#include<bits/stdc++.h>
using namespace std;
int k[102];
int main()
{
    int a,b;
    while (scanf("%d%d",&a,&b)!=EOF)
    {
        if (a==0&&b==0) return 0;
        int cnt=0;
        for (int i=0;i<100;i++)
        {
            if ((a*100+i)%b==0) k[cnt++]=i;
        }
        for (int i=0;i<cnt;i++)
        {
            printf("%02d%c",k[i]," \n"[i==cnt-1]);
        }
    }
    return 0;
}
