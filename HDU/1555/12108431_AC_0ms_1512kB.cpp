/*8600的手机每天消费1元，每消费K元就可以获赠1元，一开始8600有M元，问最多可以用多少天？ */
#include<stdio.h>
int main()
{
	int t,i,m,k;
	while (scanf("%d%d",&m,&k)!=EOF)
	{
		if (m==0&&k==0) break;
		t=0;
		for (i=1;m!=0;i++)
		{
			m--;
			t++;
			if (t==k) {m++;t=0;}
		}
		printf("%d\n",i-1);
	}
	return 0;
}