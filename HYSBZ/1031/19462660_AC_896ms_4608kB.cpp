#include <bits/stdc++.h>
using namespace std;

int n;
int sa[200010], x[200010], c[200010], y[200010];
char a[200010];

inline void SA() {
  int m = 128;
  for (int i = 0; i <= m; i++) c[i] = 0;
  for (int i = 1; i <= n; i++) c[x[i]]++;
  for (int i = 1; i <= m; i++) c[i] += c[i - 1];
  for (int i = n; i; i--) sa[c[x[i]]--] = i;

  for (int k = 1, p; k <= n; k <<= 1) {
    p = 0;
    for (int i = n; i > n - k; i--) y[++p] = i;
    for (int i = 1; i <= n; i++)
      if (sa[i] > k) y[++p] = sa[i] - k;

    for (int i = 0; i <= m; i++) c[i] = 0;
    for (int i = 1; i <= n; i++) c[x[i]]++;
    for (int i = 1; i <= m; i++) c[i] += c[i - 1];
    for (int i = n; i; i--) sa[c[x[y[i]]]--] = y[i];

    p = y[sa[1]] = 1;
    for (int i = 2, a, b; i <= n; i++) {
      a = sa[i] + k > n ? -1 : x[sa[i] + k];
      b = sa[i - 1] + k > n ? -1 : x[sa[i - 1] + k];
      y[sa[i]] = (x[sa[i]] == x[sa[i - 1]]) && (a == b) ? p : ++p;
    }
    swap(x, y);
    m = p;
  }
}

int main() {
  scanf("%s", a + 1);
  n = strlen(a + 1);
  for (int i=n+1;i<=2*n;i++) a[i]=a[i-n];
  a[2*n+1]=0;
  n*=2;
  for (int i = 1; i <= n; i++) x[i] = a[i];
  SA();
  for (int i=1;i<=n;i++)
  {
      if (sa[i]<=n/2) printf("%c",a[sa[i]+n/2-1]);
  }
  return 0;
}
//