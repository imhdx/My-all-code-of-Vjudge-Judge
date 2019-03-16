#include<bits/stdc++.h>
using namespace std;
int num=0;
int flag=0;
char a[31];
int n;
/*
int check()
{
    int tmp=0;
    if (a[0]==a[1]&&a[1]==a[2]&&a[2]==a[3]) tmp++;
    if (a[4]==a[5]&&a[5]==a[10]&&a[10]==a[11]) tmp++;
    if (a[6]==a[7]&&a[7]==a[12]&&a[12]==a[13]) tmp++;
    if (a[8]==a[9]&&a[9]==a[15]&&a[15]==a[14]) tmp++;
    if (a[16]==a[17]&&a[17]==a[18]&&a[18]==a[19]) tmp++;
    if (a[20]==a[21]&&a[21]==a[22]&&a[22]==a[23]) tmp++;
    return tmp;
}
*/
int check()
{
	int res=0;
	int tmp=a[0];
	if(tmp==a[1]&&tmp==a[2]&&tmp==a[3])res++;
	tmp=a[4];
	if(tmp==a[5]&&tmp==a[10]&&tmp==a[11])res++;
	tmp=a[6];
	if(tmp==a[7]&&tmp==a[12]&&tmp==a[13])res++;
    tmp=a[8];
	if(tmp==a[9]&&tmp==a[14]&&tmp==a[15])res++;
    tmp=a[16];
	if(tmp==a[17]&&tmp==a[18]&&tmp==a[19])res++;
    tmp=a[20];
	if(tmp==a[21]&&tmp==a[22]&&tmp==a[23])res++;
    return res;
}
void fan(int oper)
{
    int a1,b1,c1;
    oper++;
    if(oper==1)
	{
		a1=a[1];
		b1=a[3];
		c1=a[9];
		a[1]=a[7];
		a[3]=a[13];
		a[7]=a[17];
		a[13]=a[19];
		a[17]=a[21];
		a[19]=a[23];
		a[21]=a1;
		a[23]=b1;
		a[9]=a[8];
		a[8]=a[14];
        a[14]=a[15];
		a[15]=c1;
	}
	else if(oper==6)
    {
		a1=a[7];
		b1=a[13];
		c1=a[14];
		a[7]=a[1];
		a[13]=a[3];
		a[1]=a[21];
		a[3]=a[23];
		a[21]=a[17];
		a[23]=a[19];
		a[17]=a1;
		a[19]=b1;
		a[14]=a[8];
		a[8]=a[9];
        a[9]=a[15];
		a[15]=c1;
	}
    else if(oper==2)
    {
		a1=a[8];
		b1=a[14];
		c1=a[7];
		a[8]=a[17];
		a[14]=a[16];
		a[17]=a[11];
		a[16]=a[5];
		a[11]=a[2];
		a[5]=a[3];
		a[2]=a1;
		a[3]=b1;
		a[7]=a[13];
		a[13]=a[12];
        a[12]=a[6];
		a[6]=c1;
	}
    else if(oper==5)
    {
		a1=a[16];
		b1=a[17];
		c1=a[12];
		a[17]=a[8];
		a[16]=a[14];
		a[8]=a[2];
		a[14]=a[3];
		a[2]=a[11];
		a[3]=a[5];
		a[11]=b1;
		a[5]=a1;
		a[12]=a[13];
		a[13]=a[7];
        a[7]=a[6];
		a[6]=c1;
	}
    else if(oper==3)
    {
		a1=a[12];
		b1=a[13];
		c1=a[16];
		a[12]=a[14];
		a[13]=a[15];
		a[14]=a[21];
		a[15]=a[20];
		a[21]=a[10];
		a[20]=a[11];
		a[10]=a1;
		a[11]=b1;
		a[16]=a[17];
		a[17]=a[19];
        a[19]=a[18];
		a[18]=c1;
	}
	else
    {
		a1=a[12];
		b1=a[13];
		c1=a[16];
		a[12]=a[10];
		a[13]=a[11];
		a[10]=a[21];
		a[11]=a[20];
		a[20]=a[15];
		a[21]=a[14];
		a[14]=a1;
		a[15]=b1;
		a[16]=a[18];
		a[18]=a[19];
        a[19]=a[17];
		a[17]=c1;
	}
}
/*
void fan(int i)
{
    if (i==0)
        {
            int t=a[0];
            int p=a[1];
            a[0]=a[1];
            a[1]=a[3];
            a[1]=a[3];
            a[3]=a[2];
            a[3]=a[2];
            a[2]=a[0];
            a[2]=t;
            a[0]=p;

            t=a[6];
            p=a[7];
            a[6]=a[4];
            a[7]=a[5];
            a[4]=a[23];
            a[5]=a[22];
            a[23]=a[8];
            a[22]=a[9];
            a[8]=t;
            a[9]=p;
        }
        else if (i==1)
        {
            int t=a[1];
            a[1]=a[0];
            a[0]=a[2];
            a[2]=a[3];
            a[3]=t;
            t=a[4];
            int p=a[5];
            a[4]=a[6];
            a[5]=a[7];
            a[6]=a[8];
            a[7]=a[9];
            a[8]=a[22];
            a[9]=a[23];
            a[23]=t;
            a[22]=p;
        }
        else if (i==2)
        {
            int t=a[6];
            a[6]=a[7];
            a[7]=a[13];
            a[13]=a[12];
            a[12]=t;
            t=a[2];
            int p=a[3];
            a[2]=a[8];
            a[3]=a[14];
            a[14]=a[16];
            a[8]=a[17];
            a[16]=a[5];
            a[17]=a[11];
            a[5]=p;
            a[11]=t;
        }
        else if (i==3)
        {
            int t=a[7];
            a[7]=a[6];
            a[6]=a[12];
            a[12]=a[13];
            a[13]=t;
            t=a[8];
            int p=a[14];
            a[8]=a[2];
            a[14]=a[3];
            a[2]=a[11];
            a[3]=a[5];
            a[5]=a[16];
            a[11]=a[17];
            a[17]=t;
            a[16]=p;
        }
        else if (i==4)
        {
            int t=a[4];
            a[4]=a[5];
            a[5]=a[11];
            a[11]=a[10];
            a[10]=t;
            t=a[0];
            int p=a[2];
            a[0]=a[6];
            a[2]=a[12];
            a[6]=a[16];
            a[12]=a[18];
            a[16]=a[20];
            a[18]=a[22];
            a[20]=t;
            a[22]=p;
        }
        else
        {
            int t=a[5];
            a[5]=a[4];
            a[4]=a[10];
            a[10]=a[11];
            a[11]=t;
            t=a[6];
            int p=a[12];
            a[6]=a[0];
            a[12]=a[2];
            a[0]=a[20];
            a[2]=a[22];
            a[20]=a[16];
            a[22]=a[18];
            a[16]=t;
            a[18]=p;
        }
}
*/
void dfs(int k)
{
    num=max(num,check());
    //if (num==6) return ;
    if (k==n) return ;
    for (int i=0;i<6;i++)
    {
        fan(i);
        dfs(k+1);
        fan(5-i);
        //if (num==6) return ;
    }
}
int main()
{
    while (scanf("%d",&n)!=EOF)
    {
        num=0;
        flag=0;
        for (int i=0;i<24;i++) scanf("%d",&a[i]);
        dfs(0);
        printf("%d\n",num);
    }
    return 0;
}
