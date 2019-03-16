#include<bits/stdc++.h>
#define mul(a,b,c) (ll(a)*(b)%(c))
#define inv(a,b) pow(a,(b)-2,b)
using namespace std;
typedef long long ll;
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
struct Rader:vector<int>
{
    Rader(int n):vector<int>(1<<int(log2(n-1)+2))
    {
        for (int i=at(0)=0;i<size();i++)
            if (at(i)=at(i>>1)>>1,i&1)
                at(i)+=size()>>1;
    }
};
ll pow(ll a,ll b,ll m)
{
    ll r=1;
    for (;b;b>>=1,a=mul(a,a,m))
        if (b&1) r=mul(r,a,m);
    return r;
}
struct FNTT:Rader
{
	ll M;
	vector<ll> w;
	FNTT(int N,ll M,ll G):Rader(N),M(M),w(size(),pow(G,(M-1)/size(),M))//M费马素数，G原根
	{
		for(int i=w[0]=1; i<size(); ++i)w[i]=mul(w[i],w[i-1],M);
	}
	vector<ll> fntt(const vector<ll> &a)const
	{
		vector<ll> x(size());
		for(int i=0; i<a.size(); ++i)x[at(i)]=a[i];
		for(int i=1; i<size(); i<<=1)
			for(int j=0; j<i; ++j)
				for(int k=j; k<size(); k+=i<<1)
				{
					ll t=mul(w[size()/(i<<1)*j],x[k+i],M);
					if(x[k+i]=x[k]-t,x[k+i]<0)x[k+i]+=M;
					if(x[k]+=t,x[k]>=M)x[k]-=M;
				}
		return x;
	}
	vector<ll> ask(vector<ll> a,vector<ll> b)const
	{
		a=fntt(a),b=fntt(b);
		for(int i=0; i<size(); ++i)a[i]=mul(a[i],b[i],M);
		a=fntt(a),reverse(a.begin()+1,a.end());
		ll u=inv(size(),M);
		for(int i=0; i<size(); ++i)a[i]=mul(a[i],u,M);
		return a;
	}
};
Wint& operator*=(Wint &a,const Wint &b)
{
    vector<ll> ax(a.begin(),a.end()),bx(b.begin(),b.end());
    ax=FNTT(a.size()+b.size(),(7<<26)+1,3).ask(ax,bx);
    for (int i=1;i<ax.size();i++)
        ax[i]+=ax[i-1]/a.base,ax[i-1]%=a.base;
    return a.assign(ax.begin(),ax.end()),a.trim(0);
}
int main()
{
    for(Wint a,b;cin>>a>>b;cout<<(a*=b)<<'\n');
    return 0;
}