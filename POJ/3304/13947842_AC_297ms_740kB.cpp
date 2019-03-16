#include<cstdio>
#include<string>
#include<cstring>
#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;

#define all(x) (x).begin(), (x).end()
#define for0(a, n) for (int (a) = 0; (a) < (n); (a)++)
#define for1(a, n) for (int (a) = 1; (a) <= (n); (a)++)
#define mes(a,x,s)  memset(a,x,(s)*sizeof a[0])
#define mem(a,x)  memset(a,x,sizeof a)
#define ysk(x)  (1<<(x))
typedef long long ll;
typedef pair<int, int> pii;
const int INF =0x3f3f3f3f;
const int maxn=  100  ;
int n;
struct Point
{
    double x,y;
    Point(double x=0,double y=0):x(x),y(y) {};
};
typedef Point Vector;
Vector operator +(Vector A,Vector B) {return Vector(A.x+B.x,A.y+B.y); }
Vector operator -(Vector A,Vector B) {return Vector(A.x-B.x,A.y-B.y); }
Vector operator *(Vector A,double p) {return Vector(A.x*p,A.y*p); }
Vector operator /(Vector A,double p) {return Vector(A.x/p,A.y/p); }
Vector operator -(Vector A)  {return  Vector(-A.x,-A.y);}

const double eps=1e-8;
int dcmp(double x)
{
    if(fabs(x)<eps)  return 0;
    else return x<0?-1:1;
}
bool operator ==(Point A,Point B) {return dcmp(A.x-B.x)==0&&dcmp(A.y-B.y)==0;}

double Cross(Vector A,Vector B)//叉乘
{
    return A.x*B.y-A.y*B.x;
}

struct Line
{
    Point p,p2;
    Vector v;
    Line(){}
    Line(Point p,Vector v):p(p),v(v){}//点线式
    void twoPointIntial(Point p,Point p2)//两点式
    {
        this->p=p;
        this->p2=p2;
        v=  p2-p;
    }

}seg[maxn+5];

typedef Line Seg;


bool intersect(Line a,Seg b)//判断直线和线段是否相交
{
    Point A=b.p;
    Point B=b.p2;
    Vector v1=a.p-A;
    Vector v2=a.p2-A;
    Vector v3=a.p-B;
    Vector v4=a.p2-B;
    return  dcmp(Cross(v1,v2))*dcmp(Cross(v3,v4))<=0; //如果线段的端点在直线上,肯定相交
}
bool solve(Point A,Point B)
{
     Line L;L.twoPointIntial(A,B);
     if( A==B )  return false;
     for(int i=0;i<n;i++)
     {
         if(!intersect(L,seg[i])    )   return false;
     }
     return true;

}
int main()
{
   std::ios::sync_with_stdio(false);
   int T;cin>>T;
   while(T--)
   {
      cin>>n;
      for0(i,n)
      {
          cin>>seg[i].p.x>>seg[i].p.y>>seg[i].p2.x>>seg[i].p2.y;
      }
      if(n==1)  {puts("Yes!");continue;}
      bool find=false;
      for(int i=0;i<n&&!find;i++)
      {
          for(int j=i+1;j<n;j++)
          {
              find|=  solve(seg[i].p ,seg[j].p);
              find|=  solve(seg[i].p ,seg[j].p2);
              find|=  solve(seg[i].p2 ,seg[j].p);
              find|=  solve(seg[i].p2 ,seg[j].p2);
              if(find)  break;
          }
      }

      puts(find?"Yes!":"No!");
   }
   return 0;
}

