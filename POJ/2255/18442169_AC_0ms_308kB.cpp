#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
using namespace std;
char a[100],b[100];
void build(int n,char a[],char b[])
{
    if (n<=0) return ;
    int pos=strchr(b,a[0])-b;
    build(pos,a+1,b);
    build(n-1-pos,a+pos+1,b+pos+1);
    printf("%c",a[0]);
}
int main()
{
    while (scanf("%s%s",a,b)!=EOF)
    {
        int len=strlen(a);
        build(len,a,b);
        printf("\n");
    }

    return 0;
}
