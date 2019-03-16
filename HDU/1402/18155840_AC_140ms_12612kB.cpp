#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double lf;
struct Wint:vector<int>
{
    static const int width=2,base=1e2;
    Wint(unsigned long long n=0)
    {
        for(;n;n/=base) push_back(n%base);
    }
    explicit Wint(const string &s)
    {
        for (int len=int(s.size()-1)/width+1,b,e,i=0;i!=len;i++)
            for (e=s.size()-i*width,b=max(0,e-width),push_back(0);b!=e;b++)
                back()=back()*10+s[b]-'0';
        trim(0);
    }
    Wint& trim(bool up=1)
    {
        for (int i=1;up&&i<size();i++)
        {
            if (at(i-1)<0) --at(i),at(i-1)+=base;
            if (at(i-1)>=base)at(i)+=at(i-1)/base,at(i-1)%=base;
        }
        while (!empty()&&back()<=0) pop_back();
        for (;up&&!empty()&&back()>=base;at(size()-2)%=base)
            push_back(back()/base);
        return *this;
    }
};
istream& operator>>(istream &is,Wint &n)
{
    string s;
    return is>>s,n=Wint(s),is;
}
ostream& operator<<(ostream &os,const Wint &n)
{
    if (n.empty()) return os.put('0');
    os<<n.back();
    char ch=os.fill('0');
    for (int i=n.size()-2;~i;--i)
        os.width(n.width),os<<n[i];
    return os.fill(ch),os;
}
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
Wint& operator*=(Wint &a,const Wint &b)
{
    vector<ll> ax(a.begin(),a.end()),bx(b.begin(),b.end());
    ax=FFT(a.size()+b.size()).ask(ax,bx);
    for (int i=1;i<ax.size();i++)
        ax[i]+=ax[i-1]/a.base,ax[i-1]%=a.base;
    return a.assign(ax.begin(),ax.end()),a.trim(0);
}
int main()
{
    Wint a,b;
    for (;cin>>a>>b;cout<<a<<'\n')
        a*=b;
    return 0;
}
