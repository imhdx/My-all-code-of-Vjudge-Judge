
#include<string>
#include<stdio.h>


using namespace std;
int m[500010];
int vis[500010];
int pre[500010];

unsigned int hasha(char *url)
{
	unsigned int nn=0;
	char *b=(char *)&nn;
	for(int i=0;url[i];++i)
		b[i%4]^=url[i];
	return nn%500010;
}

int getx(int x)
{
    if (pre[x]==x) return x;
    return pre[x]=getx(pre[x]);
}
void nian(int x,int y)
{
    int xx=getx(x);
    int yy=getx(y);
    if (xx!=yy)
    {
        if (xx<yy)
            pre[xx]=yy;
        else
            pre[yy]=xx;
    }
}
int main()
{
    int cnt=1;
    char a[20];
    char b[20];
    for (int i=1;i<500010;i++)
    {
        pre[i]=i;
        vis[i]=0;
    }
    while (scanf("%s%s",a,b)!=EOF)
    {
        unsigned int x=hasha(a);
        unsigned int y=hasha(b);
        if (m[x]==0) m[x]=cnt++;
        if (m[y]==0) m[y]=cnt++;
        vis[m[x]]++;
        vis[m[y]]++;
        nian(m[x],m[y]);
    }
    int flag=0;
    int kkk=getx(1);
    for (int i=1;i<cnt;i++)
    {
        if (getx(i)!=kkk)
        {
            flag=3;
            break;
        }
        if (vis[i]%2==1) flag++;
    }
    if (flag==0||flag==1||flag==2) printf("Possible\n");
    else
        printf("Impossible\n");
    return 0;
}
