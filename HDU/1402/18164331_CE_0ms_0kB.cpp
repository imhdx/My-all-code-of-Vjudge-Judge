#include<bits/stdc++.h>
using namespace std;
typedef double lf;
const lf PI = acos(-1.0);
#define complex complex<double>
void change(complex y[],int len)
{
    for (int i=1,j<len/2;i<len-1;i++)
    {
        if (i<j) swap(y[i],y[j]);
        int k=len/2;
        while (j>=k)
            j-=k,k/=2;
        if (j<k) j+=k;
    }
}
void fft(complex y[],int len,int on)
{
    change(y,len);
    for(int h = 2; h <= len; h <<= 1)
    {
        complex wn(polar(1.0,-on*2*PI/h));
        for(int j = 0;j < len;j+=h)
        {
            complex w(1,0);
            for(int k = j;k < j+h/2;k++)
            {
                complex t=w*y[k+h/2];
                y[k+h/2]=y[k]-t;
                y[k]+=t;
                w*=wn;
            }
        }
    }
    if(on == -1)
        for(int i = 0;i < len;i++)
            y[i] /= len;
}
const int MAXN = 200010;
complex x1[MAXN],x2[MAXN];
char str1[MAXN/2],str2[MAXN/2];
int sum[MAXN];

int main()
{
    while(scanf("%s%s",str1,str2)==2)
    {
        int len1 = strlen(str1);
        int len2 = strlen(str2);
        int len = 1;
        while(len < len1*2 || len < len2*2)len<<=1;
        for(int i = 0;i < len1;i++)
            x1[i] = complex(str1[len1-1-i]-'0',0);
        for(int i = len1;i < len;i++)
            x1[i] = complex(0,0);
        for(int i = 0;i < len2;i++)
            x2[i] = complex(str2[len2-1-i]-'0',0);
        for(int i = len2;i < len;i++)
            x2[i] = complex(0,0);
        fft(x1,len,1);
        fft(x2,len,1);
        for(int i = 0;i < len;i++)
            x1[i]*=x2[i];
        fft(x1,len,-1);
        for(int i = 0;i < len;i++)
            sum[i] = (int)(x1[i].real()+0.5);
        for(int i = 0;i < len;i++)
            sum[i+1]+=sum[i]/10,sum[i]%=10;
        len = len1+len2-1;
        while(sum[len] <= 0 && len > 0)len--;
        for(int i = len;i >= 0;i--)
            printf("%c",sum[i]+'0');
        printf("\n");
    }
    return 0;
}
