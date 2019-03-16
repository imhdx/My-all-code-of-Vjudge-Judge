#include<bits/stdc++.h>
using namespace std;


#define cls(x) memset(x,0,sizeof(x))

const int maxlen = 100000;  // 单个“数字”最大长度
class HP{       // High Precision
public:
    int len , s[maxlen];    
    HP(){ (*this) = 0; };   HP(int inte){ (*this) = inte; };    HP(const char*str){ (*this) = str; };
    friend ostream & operator << (ostream & cout , const HP &x);        // 定义高精度输出方式
    HP operator = (int inte);       HP operator = (const char*str);     // 定义高精度与高精度的 + - * / % Compare(比较)
    HP operator + (const HP &b);    HP operator - (const HP &b);
    HP operator * (const HP &b);    HP operator / (const HP &b);
    HP operator % (const HP &b);    int Compare(const HP &b);
};
ostream & operator <<(ostream & cout, const HP &x){
    for(int i = x.len ; i >= 1 ; i--)   cout<< x.s[i];  return cout;
}
HP HP::operator = (int inte){
    if( inte == 0 ){ len = 1; s[1] = 0; return (*this); };
    for( len = 0 ; inte > 0 ;) { s[++len] = inte % 10 ; inte /= 10; };
    return (*this);
}
HP HP::operator = (const char* str){
    len = strlen(str);
    for(int i = 1 ; i <= len ; i++) s[i] = str[len - i] - '0';  // 需要注意
    return (*this);
}
HP HP::operator * (const HP &b){
    int i , j;  HP c;   c.len = len + b.len;
    for( i = 1 ; i <= c.len ; i++)  c.s[i] = 0;         // 清空返回值的数组
    for( i = 1 ; i <= len ; i++)    for( j = 1 ; j <= b.len ; j++)   c.s[i+j-1] += s[i]*b.s[j];
    for( i = 1 ; i < c.len ; i++){  c.s[i+1] += c.s[i] / 10 ; c.s[i] %= 10; }
    while( c.s[i] ){ c.s[i+1] = c.s[i]/10 ; c.s[i] %= 10; i++; }
    while( i>1 && !c.s[i] ) i--; c.len = i;
    return c;
}
HP HP::operator + (const HP &b){    
    int i;  HP c; c.s[1] = 0;
    for( i = 1 ; i<=len || i<=b.len || c.s[i] ; i++ ){  // 模拟十进制加法运算，写的好呀！写的好！巧妙！
        if( i <= len )      c.s[i] += s[i];
        if( i <= b.len )    c.s[i] += b.s[i];
        c.s[i+1] = c.s[i]/10;   c.s[i] %= 10;
    }
    c.len = i - 1 ;     if( c.len == 0 )    c.len = 1;
    return c;
}
HP HP::operator - (const HP &b){
    int i,j;    HP c;
    for( i = 1, j = 0; i <= len ; i++){
        c.s[i] = s[i] - j;  if(i <= b.len) c.s[i] -= b.s[i];
        if( c.s[i] < 0 ){ j = 1; c.s[i] += 10; }    
        else              j = 0;
    }
    c.len = len;    while( c.len > 1 && !c.s[c.len] )   c.len--;
    return c;
}
int HP::Compare(const HP &y){
    if( len > y.len )   return 1;
    if( len < y.len )   return -1;
    int i = len;
    while( (i>1) && (s[i]==y.s[i]) ) i--;
    return s[i] - y.s[i];           // 如果 s[i] == y.s[i] 自然返回0,s[i] > y.s[i]返回1.....很巧妙！
}
HP HP::operator / (const HP &b){
    int i,j;    HP d(0) , c;
    for( i = len ; i > 0 ; i--){
        if( !(d.len==1 && d.s[1]==0) )
            { for( j = d.len ; j > 0 ; j--) d.s[j+1] = d.s[j];  ++d.len; }
        d.s[1] = s[i];  c.s[i] = 0;
        while( j = d.Compare(b) >= 0 ){
            d = d - b;  c.s[i]++;   if(j==0)    break;
        }
    }
    c.len = len ;   while( (c.len>1) && (c.s[c.len]==0) )   c.len--;
    return c;
}
HP HP::operator % (const HP &b){
    int i,j;    HP d(0);
    for( i = len ; i > 0 ; i--){
        if( !(d.len==1 && d.s[1]==0) )
            { for( j = d.len ; j > 0 ; j--) d.s[j+1] = d.s[j];  ++d.len; }
        d.s[1] = s[i];
        while( j = d.Compare(b) >= 0 ){
            d = d - b;      if(j==0) break;
        }
    }
    return d;
}
int main(){
    int t,kase = 0;
    char s1[maxlen];
    scanf("%d",&t);
	while(t--)
    {
		if(kase)	puts("");
		kase++;
		HP ans , tmp;
		while(true){
			cls(s1);
			scanf("%s",s1);
			if( s1[0] == '0' ) break;
			tmp = s1;
			ans = ans + tmp;
		}
		cout<< ans <<endl;
	}
	return 0;
}