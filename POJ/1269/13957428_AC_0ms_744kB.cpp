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

}seg[2];

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
/*
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
*/
int main()
{
    int n;
    while (scanf("%d",&n)!=EOF)
    {
        int i,j;
        cout<<"INTERSECTING LINES OUTPUT\n";
        for (i=0;i<n;i++)
        {
            cin>>seg[0].p.x>>seg[0].p.y>>seg[0].p2.x>>seg[0].p2.y;
            cin>>seg[1].p.x>>seg[1].p.y>>seg[1].p2.x>>seg[1].p2.y;
            if (dcmp((Cross(seg[0].p-seg[0].p2,seg[1].p-seg[1].p2))==0&&dcmp((Cross(seg[0].p-seg[1].p2,seg[1].p-seg[1].p2)))==0)) printf("LINE\n");
            else if (dcmp(Cross(seg[0].p-seg[0].p2,seg[1].p-seg[1].p2))==0)
                     printf("NONE\n");
            else
            {double x1=seg[0].p.x;
double y1=seg[0].p.y;
double x2=seg[0].p2.x;
double y2=seg[0].p2.y;
double x3=seg[1].p.x;
double y3=seg[1].p.y;
double x4=seg[1].p2.x;
double y4=seg[1].p2.y;
double a1=y1-y2,b1=x2-x1,c1=x1*y2-x2*y1;
double a2=y3-y4,b2=x4-x3,c2=x3*y4-x4*y3;
double x=(c2*b1-c1*b2)/(b2*a1-b1*a2);
double y=(a2*c1-a1*c2)/(b2*a1-b1*a2);
printf("POINT %.2f %.2f\n",x,y);
            }
        }
        cout<<"END OF OUTPUT\n";
    }
    return 0;
}



