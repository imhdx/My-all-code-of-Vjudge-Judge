#include<bits/stdc++.h>
using namespace std;
vector<int>v;
vector<long long int>v1;
vector<long long int>v2;
long long int poww(long long int a,long long int b)
{
    long long int res=1;
    while(b>0)
    {
        if (b&1)
        {
            res=res*a;
        }
        a=a*a;
        b>>=1;
    }
    return res;
}
int main()
{
    int n;
    while (scanf("%d",&n)!=EOF)
    {
        v1.clear();
        v2.clear();
        v.clear();
        if (n==0)
        {
            printf("0\n0\n");
            continue;
        }
        while (n!=0)
        {
            v.push_back(n%3);
            n=n/3;
        }
        int i;
        for (i=0;i<v.size();i++)
        {
            if (v[i]==2)
            {
                v[i]=0;
                if (i+1>=v.size())
                    v.push_back(1);
                else
                    v[i+1]++;
                v1.push_back(poww(3,i));
            }
            else if (v[i]==3)
            {
                v[i]=1;
                if (i+1>=v.size())
                    v.push_back(1);
                else
                    v[i+1]++;
                v1.push_back(poww(3,i));
            }
        }

        for (i=0;i<v.size();i++)
        {
            if (v[i]==1)
            {
                v2.push_back(poww(3,i));
            }
        }
        printf("%d",v1.size());

        for (i=0;i<v1.size();i++)
            printf(" %lld",v1[i]);

        printf("\n%d",v2.size());

        for (i=0;i<v2.size();i++)
            printf(" %lld",v2[i]);
        printf("\n");
    }
    return 0;
}
