#include <iostream>
#include <cstring>
using namespace std;

const int _max = 8010;
// c1是保存各项质量砝码可以组合的数目
// c2是中间量，保存没一次的情况
int c1[_max], c2[_max];
int a[4]= {0,1,2,5};
int b[4];
int main()
{
    int i, j, k;
    while (scanf("%d%d%d",&b[1],&b[2],&b[3]),b[1]|b[2]|b[3])
    {
        memset(c1,0,sizeof(c1));
        int nNum=1*b[1]+2*b[2]+5*b[3]+1;
        for(i=0; i<=b[1]; ++i)   // ---- ①
        {
            c1[i] = 1;
            c2[i] = 0;
        }
        for(i=2; i<=3; ++i)   // ----- ②
        {
            for(j=0; j<=nNum; ++j)   // ----- ③
                for(k=0; k+j<=nNum&&k/a[i]<=b[i]; k+=a[i])  // ---- ④
                {
                    c2[j+k] += c1[j];
                }
            for(j=0; j<=nNum; ++j)     // ---- ⑤
            {
                c1[j] = c2[j];
                c2[j] = 0;
            }
        }
        for (i=1;;i++)
        {
            if (c1[i]==0) break;
        }
        printf("%d\n",i);
    }
    return 0;
}

