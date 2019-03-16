#include<stdio.h>
#include<math.h>
#include<stdlib.h>
struct centre
{
       double x , y ;
};
int cas , n ;
double Area( centre p0 , centre p1 , centre p2 )
{
       double area = 0 ;
       area =  p0.x * p1.y + p1.x * p2.y + p2.x * p0.y - p1.x * p0.y - p2.x * p1.y - p0.x * p2.y; // 用行列式求三角形面积
       return area / 2 ;  // 另外在求解的过程中，不需要考虑点的输入顺序是顺时针还是逆时针，相除后就抵消了。
}
int main ()
{
    centre p0 , p1 , p2 ;
    double sum_x , sum_y , sum_area , area;
    scanf ( "%d" , &cas ) ;
    while ( cas -- )
    {
          sum_x = sum_y = sum_area = 0 ;
          scanf ( "%d" , &n ) ;
          scanf ( "%lf%lf" , &p0.x , &p0.y ) ;
          scanf ( "%lf%lf" , &p1.x , &p1.y ) ;
          for ( int i = 2 ; i < n ; ++ i )
          { 
              scanf ( "%lf%lf" , &p2.x , &p2.y ) ;
              area = Area(p0,p1,p2) ;
              sum_area += area ;
              sum_x += (p0.x + p1.x + p2.x) * area ;
              sum_y += (p0.y + p1.y + p2.y) * area ;
              p1 = p2 ;
          }
          printf ( "%.2lf %.2lf\n" , sum_x / sum_area / 3 , sum_y / sum_area / 3 ) ;
    }
    return 0 ;
}