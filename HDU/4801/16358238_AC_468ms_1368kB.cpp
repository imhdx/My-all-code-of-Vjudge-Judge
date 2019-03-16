#include<bits/stdc++.h>
using namespace std;
int n;
int a[30];

int t[6][24]=
{
    {2,0,3,1,6,7,8,9,23,22,10,11,12,13,14,15,16,17,18,19,20,21,5,4},
    {1,3,0,2,23,22,4,5,6,7,10,11,12,13,14,15,16,17,18,19,20,21,9,8},
    {0,1,11,5,4,16,12,6,2,9,10,17,13,7,3,15,14,8,18,19,20,21,22,23},
    {0,1,8,14,4,3,7,13,17,9,10,2,6,12,16,15,5,11,18,19,20,21,22,23},
    {20,1,22,3,10,4,0,7,8,9,11,5,2,13,14,15,6,17,12,19,16,21,18,23},
    {6,1,12,3,5,11,16,7,8,9,4,10,18,13,14,15,20,17,22,19,0,21,2,23}
};
int num=0;
int check()
{
    int tmp=0;
    if (a[0]==a[1]&&a[1]==a[2]&&a[2]==a[3]) tmp++;
    if (a[4]==a[5]&&a[5]==a[10]&&a[10]==a[11]) tmp++;
    if (a[6]==a[7]&&a[7]==a[12]&&a[12]==a[13]) tmp++;
    if (a[8]==a[9]&&a[9]==a[14]&&a[14]==a[15]) tmp++;
    if (a[16]==a[17]&&a[17]==a[18]&&a[18]==a[19]) tmp++;
    if (a[20]==a[21]&&a[21]==a[22]&&a[22]==a[23]) tmp++;
    return tmp;
}
void dfs(int k)
{
    num=max(num,check());
    if (num==6) return ;
    if (k>=n) return ;
    for (int i=0;i<6;i++)
    {
        int b[30];
        for (int j=0;j<24;j++) b[j]=a[j];
        for (int j=0;j<24;j++) a[j]=b[t[i][j]];
        dfs(k+1);
        for (int j=0;j<24;j++) b[j]=a[j];
        int l;
        if (i&1) l=i-1;
        else l=i+1;
        for (int j=0;j<24;j++) a[j]=b[t[l][j]];

    }

}
int main()
{
    while (scanf("%d",&n)!=EOF)
    {
        num=0;
        for (int i=0;i<24;i++) scanf("%d",&a[i]);
        dfs(0);
        printf("%d\n",num);
    }
    return 0;
}
