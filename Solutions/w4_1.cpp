#include<bits/stdc++.h>

using namespace std;
long long int karatsuba(long long int x, long long int y) {
  
  if (x < 10 || y < 10){ return (x * y); }
  
  int lx = 0;int t = 1; while(1) { if( (x / t) <= 0 ){ break; } t = t * 10; lx++; }
  
  int ly = 0; t = 1; while(1) { if( (y / t) <= 0 ){ break; } t = t * 10; ly++; }
  
  int n = 0; if(lx>ly){ n=lx; } else { n=ly; } n = (int)(n / 2);

  long long int p = pow(10, n);

  long long int a = (long long int)(x / p);

  long long int b = x % p;

  long long int c = (long long int)(y / p);

  long long int d = y % p;

  long long int ac = karatsuba(a, c);
  long long int bd = karatsuba(b, d);
  long long int ad_bc = karatsuba(a + b, c + d) - ac - bd;
  cout << ac << " ";
  cout << bd << " ";
  cout << ad_bc << endl;
  return ac * pow(10, (2 * n)) + (ad_bc * pow(10, n)) + bd;

}
int main() {
  int a,b;
  cin >> a;
  cin >> b;
  cout << karatsuba(a, b) << endl;
  return 0;
}
