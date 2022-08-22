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
#define MAXN 405
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
string s;

void boost()
{
 ios_base::sync_with_stdio(false);
 cin.tie(NULL);
}

ll fac[MAXN];

ll power(ll x,ll y)
{
    ll res=1;
    x=x%mod;

    while(y>0)
    {
        if(y&1LL)
        {
            res=res*x;
            res=res%mod;
        }

        y=y>>1LL;

            x=x*x;
            x=x%mod;
    }

    return res;
}

ll modinv(ll n)
{
    return power(n,mod-2);
}

ll ncr(ll n,ll r)
{
    if(r>n)
    return 0;
    
    if(r == 0 || r == n)
    return 1;
    
    return ((((fac[n] * modinv(fac[r]))%mod) *modinv(fac[n-r]))%mod);
}

void init()
{
    fac[0]=1;
    ll i;
    
     for(i=1;i<MAXN;i++)
    {
        fac[i]=fac[i-1]*i;
        fac[i]=fac[i]%mod;
    }
}


int dp[MAXN][MAXN][MAXN];

int solve(ll i,ll j,ll k)
{
    ll ans=0;
    
    if(j-i+1<k)
    return 0;
    
    if(k==0) 
    return 1;
    
    if(k==1)
    return j-i+1;
 
    if(dp[i][j][k] != -1)
    {
        return dp[i][j][k];
    }
 
    if(s[i]==s[j])
    {
        ans=solve(i+1,j-1,k-2);
    }
 
    ans+=solve(i+1,j,k);
    ans%=mod;
    ans+=solve(i,j-1,k);
    ans%=mod;
    ans-=solve(i+1,j-1,k);
    ans+=mod;
    ans%=mod;
 
    dp[i][j][k] = ans;
    return dp[i][j][k];
}



int main()
{
 boost();
 init();
 
 ll i,t,q,l,r,ans,mid,c=0,j,z,tc,n,k;
 ll h,m,u,mm,w,x,y,l1,r1,d=0,mask,v,mx;
 ld f,f1;
 char ch;
 
 cin>>t;
 
 for(tc=1;tc<=t;tc++)
 {
     cin>>n;
     cin>>s;
     ans=0;
     
     memset(dp,-1,sizeof(dp));
     
     for(i=0;i<n;i++)
     {
         l=dp[0][n-1][i];
         
         if(l==-1)
         l=solve(0,n-1,i);
         
         
         z=ncr(n,i);
         z=modinv(z);
         l*=z;
         l%=mod;
         ans+=l;
         ans%=mod;
     }
     
     cout<<"Case #"<<tc<<": "<<ans<<endl;
 }


  
  
return 0;
}