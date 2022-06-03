#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <time.h>
using namespace std;
int modulo(int a, int b) {
  int q = a / b;
  int r;
  if (a < 0) {
    q = q - 1;
  }
  return r = a - (q * b);
}
int expmod(int a, int x, int n) {
  int t;
  if (x == 0) {
    return 1;
  } else if (modulo(x, 2) == 0) {
    t = expmod(a, x / 2, n);
    return modulo(pow(t, 2), n);
  } else {
    t = expmod(a, x - 1, n);
    a = modulo(a, n);
    return modulo((t * a), n);
  }
}
bool ES_COMPUESTO(int a, int n, int t, int u) {
  int x_0 = expmod(a, u, n);
  int x_1;
  if (x_0 == 1 || x_0 == n - 1) {
    return false;
  }
  for (int i = 1; i < t; i++) {
    x_1 = expmod(x_0, 2, n);
    if (x_1 == n - 1) {
      return false;
    }
    x_0 = x_1;
  }
  return true;
}
bool MILLER_RABIN(int n, int s) {
  int t = 0;
  int u = n - 1;
  while (modulo(u, 2) == 0) {
    u = u / 2;
    t = t + 1;
  }
  for (int j = 1; j < s; j++) {
    int a = 2 + rand() % (n - 3);
    if (ES_COMPUESTO(a, n, t, u) == false) {

      return true;
    }
  }
}
int RANDOMBITS(int b) {
  int z = pow(2, b) - 1;
  int n = rand() % z;
  int m = pow(2, b) + 1;
  n = n | m;
  return n;
}
int RANDOMGEN_PRIMOS(int b) {
  int s = pow(b,4);
  int n = RANDOMBITS(b-2);
  while (MILLER_RABIN(n, s) == false) {
    n = n + 2;
  }
  return n;
}


int main() { 
  srand(time(NULL));
  cout<<"16 bits "<<endl;
  for(int i=0;i<10;i++){
  cout << RANDOMGEN_PRIMOS(16)<<endl; }
  cout<<"32 bits "<<endl;
  for(int i=0;i<10;i++){
  cout << RANDOMGEN_PRIMOS(32)<<endl; }
  cout<<"64 bits "<<endl;
for(int i=0;i<10;i++){  
cout << RANDOMGEN_PRIMOS(64)<<endl;}}
