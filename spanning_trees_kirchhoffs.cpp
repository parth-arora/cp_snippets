//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx,avx2,fma")
//#pragma GCC optimization ("unroll-loops")
//u can always think of Binary Search to find the minimum answer...........

//https://atcoder.jp/contests/jsc2021/tasks/jsc2021_g

 
#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pll;
typedef vector<ll> vl;
typedef vector<pll> vpl;
#define pb push_back
#define MAXN 305
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

vl V[MAXN];
ll vis[MAXN],b1[MAXN];

void dfs(ll cur,ll prev)
{
   vis[cur]++;
   b1[cur]=cc1;
   
   for(auto x :V[cur])
   {
      if(vis[x]==0)
      dfs(x,cur);
      
      else if(x!=prev)
      cc++;
   }
}


 ll power(ll n, ll k) {
  ll ans = 1 % mod; n %= mod; if (n < 0) n += mod;
  while (k) {
    if (k & 1) ans = ans * n % mod;
    n = n * n % mod;
    k >>= 1;
  }
  return ans;
}

// determinant under a prime modulo
//https://github.com/ShahjalalShohag/code-library/blob/main/Math/Determinant%20under%20Prime%20Modulo.cpp

ll Gauss(vector<vl> a) 
{
  int n = a.size(), m = (int)a[0].size();
  int free_var = 0;
  const long long MODSQ = (long long)mod * mod;
  ll det = 1, rank = 0;
  for (int col = 0, row = 0; col < m && row < n; col++) {
    int mx = row;
    for (int k = row; k < n; k++) if (a[k][col] > a[mx][col]) mx = k;
    if (a[mx][col] == 0) {det = 0; continue;}
    for (int j = col; j < m; j++) swap(a[mx][j], a[row][j]);
    if (row != mx) det = det == 0 ? 0 : mod - det;
    det = 1LL * det * a[row][col] % mod;
    int inv = power(a[row][col], mod - 2);
    for (int i = 0; i < n && inv; i++){
      if (i != row && a[i][col]) {
        int x = ((long long)a[i][col] * inv) % mod;
        for (int j = col; j < m && x; j++){
          if (a[row][j]) a[i][j] = (MODSQ + a[i][j] - ((long long)a[row][j] * x)) % mod;
        }
      }
    }
    row++; ++rank;
  }
  return det;
}

int main()
{
 boost();
  
 ll i,t,q,l,r,ans,mid,c=0,j,z,tc,n,k;
 ll h,m,u,mm,w,x,y,l1,r1,d=0,mask,v,mx;
 ld f,f1;
 
 cin>>n;
 ll a[n+1][n+1];
 
 for(i=1;i<=n;i++)
 {
 for(j=1;j<=n;j++)
 {
    
 cin>>a[i][j];
 
 if(a[i][j]==1)
 V[i].pb(j);
 
 }
 }
 
 cc=0;
 cc1=0;
 
 for(i=1;i<=n;i++)
 {
    if(vis[i]==0)
    {
    cc1++;
    dfs(i,0);
    }
 }
 
 if(cc>0)
 {
    cout<<0<<endl;
    return 0;
 }
 
 m=cc1;
 
 if(m==1)
 {
    cout<<1<<endl;
    return 0;
 }
 
 ll b[m+1][m+1];
 ll deg[m+1];
 
 vector<vl> lap(m,vl(m,0)); 
 
 memset(b,0,sizeof(b));
 memset(deg,0,sizeof(deg));
 
 // consider multiple edges and self loops
 for(i=1;i<=n;i++)
 {
    for(j=1;j<=n;j++)
    {
       if(a[i][j]==-1)
       {
          l=b1[i];
          r=b1[j];
          b[l][r]++;
       }
    }
 }
 
 for(i=1;i<=m;i++)
 {
    c=0;
    for(j=1;j<=m;j++)
    {
       c+=b[i][j];
    }
    
    deg[i]=c;
 }
 
 // no of spanning trees = cofactor of laplacian matrix
 //https://en.wikipedia.org/wiki/Laplacian_matrix
 //https://cp-algorithms.com/graph/kirchhoff-theorem.html
 
 for(i=1;i<=m;i++)
 {
    for(j=1;j<=m;j++)
    {
       if(i==j)
       lap[i-1][j-1]=deg[i];
       
       lap[i-1][j-1]-=b[i][j];
    }
 }
 
 // remove any row and any column to obtain cofactor
 
 vector<vl> lap1(m-1,vl(m-1,0)); 
 
 for(i=1;i<m;i++)
 {
    for(j=1;j<m;j++)
    lap1[i-1][j-1]=lap[i][j];
 }
 
 
 ans=abs(Gauss(lap1));
 
 cout<<ans<<endl;
 
 


  
  
return 0;
}
