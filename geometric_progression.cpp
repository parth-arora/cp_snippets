#include <bits/stdc++.h>
using namespace std;
long long modpow(long long a, long long b, long long MOD){
  long long ans = 1;
  while (b > 0){
    if (b % 2 == 1){
      ans *= a;
      ans %= MOD;
    }
    a *= a;
    a %= MOD;
    b /= 2;
  }
  return ans;
}
long long gp(long long a, long long b, long long MOD){
  if (b == 0){
    return 0;
  }
  if (b % 2 == 1){
    return (1 + a * gp(a, b - 1, MOD)) % MOD;
  } else {
    return (modpow(a, b / 2, MOD) + 1) * gp(a, b / 2, MOD) % MOD;
  }
}
int main(){
  long long A, X, M;
  cin >> A >> X >> M;
  cout << gp(A, X, M) << endl;
}