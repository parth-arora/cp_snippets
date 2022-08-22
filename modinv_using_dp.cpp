//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx,avx2,fma")
//#pragma GCC optimization ("unroll-loops")

 
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
#define clr(v)  v.clear()
#define sze(x) ((ll)x.size())
#define all(v) v.begin(),v.end()
#define endl '\n'
#define level 20
ll timer,cc1,cc;

ll inv[MAXN];

void boost()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

int main()
{
    boost();
    
    ll i,t,n,q,l,r,ans,mid,c=0,j,k,z,tc;
    ll h,m,u,mm,w,x,y,l1,r1,d=0,mask,v,mx;
    ld f,f1;
    
    
    inv[1]=1;
    inv[0]=1;
    
    for (i=2;i<MAXN;i++)
    {
        
      inv[i] = ((mod - (mod/i)) * inv[mod%i]);
    
        if(inv[i]>=mod) 
        {
        inv[i]=inv[i]%mod;
        }
        
    }
    
 
    

return 0;
}