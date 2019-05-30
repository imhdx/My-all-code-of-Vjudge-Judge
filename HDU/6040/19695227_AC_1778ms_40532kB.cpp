//
// Created by mhdx on 2019/5/11.
//

#include<bits/stdc++.h>
using namespace std;
unsigned x,y,z;
unsigned rng61() {
    unsigned t;
    x ^= x << 16;
    x ^= x >> 5;
    x ^= x << 1;
    t = x;
    x = y;
    y = z;
    z = t ^ x ^ y;
    return z;
}
unsigned a[10000007];
struct node
{
    int num,pos;
    bool operator<(const node &b)const{return num>b.num;}
}b[120];
unsigned ans[120];
int main()
{
    int n,m;
    unsigned A,B,C;
    int tt=1;
    while (scanf("%d%d%u%u%u",&n,&m,&A,&B,&C)!=EOF)
    {
        x = A, y = B, z = C;
        for (int i=0;i<n;i++) a[i]=rng61();
        for (int i=0;i<m;i++) scanf("%d",&b[i].num),b[i].pos=i;
        sort(b,b+m);
        /// 从大到小
        /*
         * nth_element(first,nth,last);
         * [first,last) 中a[nth]放的是nth-first+1大的数
         */
        for (int i=0;i<m;i++)
        {
            if (i==0)
            {
                nth_element(a,a+b[i].num,a+n);
                ans[b[i].pos]=a[b[i].num];
            }
            else{
                nth_element(a,a+b[i].num,a+b[i-1].num);
                ans[b[i].pos]=a[b[i].num];
            }
        }
        printf("Case #%d:",tt++);
        for (int i=0;i<m;i++) printf(" %u",ans[i]);
        puts("");

    }
    return 0;
}//