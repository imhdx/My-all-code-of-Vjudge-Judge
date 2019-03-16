#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double lf;
const lf PI=acos(-1);
struct Rader:vector<int>
{
    Rader(int n):vector<int>(1<<int(log2(n-1)+2))
    {
        for (int i=at(0)=0;i<size();i++)
            if (at(i)=at(i>>1)>>1,i&1)
                at(i)+=size()>>1;
    }
};
struct FFT:Rader
{
	vector<complex<lf> > w;
	FFT(int n):Rader(n),w(size(),polar(1.0,2*PI/size()))
	{
		w[0]=1;
		for(int i=2; i<size(); ++i)w[i]*=w[i-1];
	}
	vector<complex<lf> > fft(const vector<complex<lf> > &a)const
	{
		vector<complex<lf> > x(size());
		for(int i=0; i<a.size(); ++i)x[at(i)]=a[i];
		for(int i=1; i<size(); i<<=1)
			for(int j=0; j<i; ++j)
				for(int k=j; k<size(); k+=i<<1)
				{
					complex<lf> &l=x[k],&r=x[k+i],t=w[size()/(i<<1)*j]*r;
					r=l-t,l+=t;
				}
		return x;
	}
	vector<ll> ask(const vector<ll> &a,const vector<ll> &b)const
	{
		vector<complex<lf> > xa(a.begin(),a.end()),xb(b.begin(),b.end());
		xa=fft(xa),xb=fft(xb);
		for(int i=0; i<size(); ++i)xa[i]*=xb[i];
		vector<ll> ans(size());
		xa=fft(xa),ans[0]=xa[0].real()/size()+0.5;
		for(int i=1; i<size(); ++i)ans[i]=xa[size()-i].real()/size()+0.5;
		return ans;
	}
};
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n;
        scanf("%d",&n);
        vector<int> temp(n+1);
        int maxx=0;
        for (int i=1;i<=n;i++)
        {
            scanf("%d",&temp[i]);
            if (temp[i]>maxx) maxx=temp[i];
        }
        vector<ll> a(maxx+1,0);
        for (int i=1;i<=n;i++) a[temp[i]]+=1;
        a=FFT((maxx+1)<<1).ask(a,a);
        //for (int i=0;i<ax.size();i++) printf("%d %lld\n",i,ax[i]);
        for (int i=1;i<=n;i++) a[temp[i]+temp[i]]--;
        for (int i=0;i<a.size();i++) a[i]>>=1;
        for (int i=1;i<a.size();i++) a[i]+=a[i-1];
        sort(temp.begin()+1,temp.end());
        long long ans=0;
        for (int i=1;i<=n;i++)
        {
            ans+=a.back()-a[temp[i]];
            ans-=1ll*(i-1)*(n-i);
            ans-=1ll*(n-i)*(n-i-1)/2;
            ans-=n-1;
        }
        double aaa=1.0*ans/(1ll*n*(n-1)*(n-2)/6);
        printf("%.7f\n",aaa);
    }
    return 0;
}
