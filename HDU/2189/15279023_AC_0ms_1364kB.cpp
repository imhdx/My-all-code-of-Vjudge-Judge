#include <iostream>
using namespace std;

const int _max = 161;
// c1是保存各项质量砝码可以组合的数目
// c2是中间量，保存没一次的情况
int c1[_max], c2[_max];
int prim[38]= {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,101,103,107,109,113,127,131,137,139,149,151,157};
int main()
{
    //int n,i,j,k;
    int nNum=159;   //
    int i, j, k;
    for(i=0; i<=nNum; i=i+2)   // ---- ①
    {
        c1[i] = 1;
        c2[i] = 0;
    }
    for(i=1; i<=36; ++i)   // ----- ②
    {
        //printf("000");
        for(j=0; j<=nNum; ++j)   // ----- ③
            for(k=0; k+j<=nNum; k+=prim[i])  // ---- ④
            {
                c2[j+k] += c1[j];
            }
        for(j=0; j<=nNum; ++j)     // ---- ⑤
        {
            c1[j] = c2[j];
            c2[j] = 0;
        }
    }
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n;
        scanf("%d",&n);
        printf("%d\n",c1[n]);
    }
    return 0;
}

