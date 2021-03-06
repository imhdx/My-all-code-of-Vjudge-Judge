#include <iostream>
using namespace std;

const int _max = 400;
// c1是保存各项质量砝码可以组合的数目
// c2是中间量，保存没一次的情况
int c1[_max], c2[_max];
int main()
{
    //int n,i,j,k;
    int nNum=_max-2;   //
    int i, j, k;
    for(i=0; i<=nNum; ++i)   // ---- ①
    {
        c1[i] = 1;
        c2[i] = 0;
    }
    for(i=2; i<=17; ++i)   // ----- ②
    {
        int tmp=i*i;
        for(j=0; j<=nNum; ++j)   // ----- ③
            for(k=0; k+j<=nNum; k+=tmp)  // ---- ④
            {
                c2[j+k] += c1[j];
            }
        for(j=0; j<=nNum; ++j)     // ---- ⑤
        {
            c1[j] = c2[j];
            c2[j] = 0;
        }
    }
    int n;
    while(scanf("%d",&n)!=EOF&&n)
    {
        printf("%d\n",c1[n]);
    }
    return 0;
}

