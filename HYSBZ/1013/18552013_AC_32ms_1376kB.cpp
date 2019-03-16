#include<bits/stdc++.h>
using namespace std;
double a[105][105];
int n;
const double eps=1e-7;
///a[0][0]到a[n-1][n-1] 存的是n*n的系数矩阵
///a[i][n]存的是第i个方程等号右边的值
bool gauss()
{
    for (int i=0;i<n;i++){
        int t=i;
        for (int j=i;j<n;j++)
            if (fabs(a[j][i])>fabs(a[t][i])) t=j;///找当前列的最大值，保证精度
        if (fabs(a[t][i])<eps) return 0;///当前列的值都为0 说明第i个未知数可以任意取，无解
        if (i!=t)
            for (int j=i;j<=n;j++) swap(a[i][j],a[t][j]);
        for (int j=n;j>=i;j--)
            a[i][j]/=a[i][i];
        for (int j=0;j<n;j++)///使上下三角都变成0  最后结果直接存在a[i][n]
            if (j!=i)
                for (int k=n;k>=i;k--)
                    a[j][k]-=a[j][i]*a[i][k];
    }
    return 1;
}
double tmp[12][12];
int main()
{
    scanf("%d",&n);
    for (int j=0;j<n;j++) scanf("%lf",&tmp[0][j]);
    for (int i=1;i<n+1;i++){
        for (int j=0;j<n;j++) scanf("%lf",&tmp[i][j]);

        for (int j=0;j<n;j++){
            a[i-1][j]=2*(tmp[i-1][j]-tmp[i][j]);
            a[i-1][n]+=tmp[i-1][j]*tmp[i-1][j]-tmp[i][j]*tmp[i][j];
        }
    }
    gauss();
    for (int i=0;i<n;i++)
        printf("%.3f%c",a[i][n]," \n"[i==n-1]);
    return 0;
}
