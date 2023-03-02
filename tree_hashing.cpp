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

//https://codeforces.com/contest/1800/problem/G
//http://rng-58.blogspot.com/2017/02/hashing-and-probability-of-collision.html

vl V[MAXN];
ll dep[MAXN],dp[MAXN];
ll a1[MAXN];
map<ll,ll> mp;

constexpr uint64_t Mod = (1ull<<61) - 1;
uint64_t mul(uint64_t a, uint64_t b)
{
	uint64_t l1 = (uint32_t)a, h1 = a>>32, l2 = (uint32_t)b, h2 = b>>32;
	uint64_t l = l1*l2, m = l1*h2 + l2*h1, h = h1*h2;
	uint64_t ret = (l&Mod) + (l>>61) + (h << 3) + (m >> 29) + (m << 35 >> 3) + 1;
	ret = (ret & Mod) + (ret>>61);
	ret = (ret & Mod) + (ret>>61);
	return ret-1;
}

void init()
{
    ll z=1,l;
    
    for(ll i=0;i<MAXN;i++)
    {
        z=mul(z,mod);
        a1[i]=z;
    }
}

void dfs(ll cur,ll prev)
{
    dep[cur]=dep[prev]+1;
    ll z=a1[dep[cur]];
    dp[cur]=1;
    
    for(auto x:V[cur])
    {
        if(x!=prev)
        {
            dfs(x,cur);
            dp[cur]=mul(dp[x]+z,dp[cur]);
        }
    }
}

void dfs1(ll cur,ll prev)
{
    clr(mp);
    
    ll d=0,z,l;
    
    for(auto x :V[cur])
    {
        if(x!=prev)
        {
            mp[dp[x]]++;
        }
    }
    
    for(auto x : mp)
    {
        if(x.se&1)
        {
            d++;
            z=x.fi;
        }
    }
    
    if(d>1)
    cc++;
    
    else if(d==1)
    {
        for(auto x :V[cur])
        {
            if(x!=prev)
            {
                if(dp[x]==z)
                l=x;
            }
        }
        
        dfs1(l,cur);
    }
}

int main()
{
 boost();
 init();
  
 ll i,t,q,l,r,ans,mid,c=0,j,z,tc,n,k;
 ll h,m,u,mm,w,x,y,l1,r1,d=0,mask,v,mx;
 ld f,f1;
 
 cin>>t;
 
 while(t--)
 {
     cin>>n;
     cc=0;
     
     for(i=0;i<=n;i++)
     {
         dep[i]=0;
         clr(V[i]);
         dp[i]=0;
     }
     
     for(i=1;i<n;i++)
     {
         cin>>x>>y;
         V[x].pb(y);
         V[y].pb(x);
     }
     
     dfs(1,0);
     dfs1(1,0);
     
     if(cc>0)
     cout<<"NO"<<endl;
     
     else
     cout<<"YES"<<endl;
     
 }


  
  
return 0;
}