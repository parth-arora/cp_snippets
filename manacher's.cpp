//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx,avx2,fma")
//#pragma GCC optimization ("unroll-loops")
//u can always think of Binary Search to find the minimum answer...........

 
#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pll;
typedef vector<ll> vl;
typedef vector<pll> vpl;
#define pb push_back
#define MAXN 200005
const ll N=32;
#define INF (ll)1e18
#define mod 1000000007
//#define mod 998244353
#define fi first
#define se second
#define mkp make_pair
#define clr(v) v.clear()
#define sze(x) ((ll)x.size())
#define all(v) v.begin(),v.end()
#define endl '\n'
#define level 20
ll timer,cc1,cc;

void boost()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
}

//for odd palindrome
//cp algorithms
string fun(string &s,ll n)
{
     vl d1(n);  // maximum odd length palindrome centered at i
  // here d1[i]=the palindrome has d1[i]-1 right characters from i
  //If the size of palindrome centered at i is x, then d1[i] stores (x+1)/2.
  // e.g. for aba, d1[1]=2;
  for (ll i = 0, l = 0, r = -1; i < n; i++) {
    ll k = (i > r) ? 1 : min(d1[l + r - i], r - i);
    while (0 <= i - k && i + k < n && s[i - k] == s[i + k]) {
      k++;
    }
    d1[i] = k--;
    if (i + k > r) {
      l = i - k;
      r = i + k;
    }
  }
  
  ll i,l=0,z;
  string s1;
  
   for(i=0;i<n;i++)
  {
      if(d1[i]>l)
      {
          l=d1[i];
          z=i;
      }
  }
  
  l--;
  for(i=z-l;i<=z+l;i++)
  {
      s1+=s[i];
  }
  
  return s1;
  
}

//for even  palindrome
//cp algorithms
string fun1(string &s,ll n)
{
    vl d2(n);  // maximum even length palindrome centered at i
  // here d2[i]=the palindrome has d2[i]-1 right characters from i
  //If the size of palindrome centered at i is x, then d2[i] stores x/2
  // e.g. for abba, d2[2]=2;
  for (ll i = 0, l = 0, r = -1; i < n; i++) 
  {
    ll k = (i > r) ? 0 : min(d2[l + r - i + 1], r - i + 1);
    while (0 <= i - k - 1 && i + k < n && s[i - k - 1] == s[i + k]) {
      k++;
    }
    d2[i] = k--;
    if (i + k > r) {
      l = i - k - 1;
      r = i + k ;
    }
  }
  
  ll i,l=0,z;
  string s1;
  
  for(i=0;i<n;i++)
  {
      if(d2[i]>l)
      {
          l=d2[i];
          z=i;
      }
  }
  
  for(i=z-l;i<z+l;i++)
  {
      s1+=s[i];
  }
  
  return s1;
 
}



int main()
{
  boost();
   
  ll i,t,q,l,r,ans,mid,c=0,j,z,tc,n,k;
  ll h,m,u,mm,w,x,y,l1,r1,d=0,mask,v,mx;
  ld f,f1;
  
  string s,s1,s2;
  cin>>s;
  
  n=s.size();
  s1=fun(s,n);
  s2=fun1(s,n);
  
  if(sze(s1)>sze(s2))
  cout<<s1<<endl;
  
  else
  cout<<s2<<endl;
  


   
   
return 0;
}