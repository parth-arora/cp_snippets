//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx,avx2,fma")
//#pragma GCC optimization ("unroll-loops")
//u can always think of Binary Search to find the minimum answer...........

 
#include <bits/stdc++.h>
using namespace std;
 
typedef int ll;
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

vl V[MAXN];
ll tin[MAXN],low[MAXN],vis[MAXN];
vl g;

void dfs(ll cur,ll prev)
{
    ll c=0,d=0;
    vis[cur]++;
    tin[cur]=low[cur]=timer++;
    
    for(auto  x : V[cur])
    {
        if(vis[x]==0)
        {
            dfs(x,cur);
            low[cur]=min(low[cur],low[x]);
            
            if(low[x]>=tin[cur]&&prev!=0)
            c++;
            
            d++;
        }
        
        else if(x!=prev)
        {
         low[cur]=min(low[cur],tin[x]);
        }
    }
    
    if(d>1&&prev==0)
    {
        c++;
    }
    
    if(c>0)
    g.pb(cur);
}

int main()
{
 boost();
  
 ll i,t,q,l,r,ans,mid,c=0,j,z,tc,n,k;
 ll h,m,u,mm,w,x,y,l1,r1,d=0,mask,v,mx;
 ld f,f1;
 
 cin>>n>>m;
 timer=1;
 
 for(i=0;i<m;i++)
 {
     cin>>x>>y;
     V[x].pb(y);
     V[y].pb(x);
 }
 
 for(i=1;i<=n;i++)
 {
     if(vis[i]==0)
     dfs(i,0);
 }
 
 cout<<sze(g)<<endl;
 
 for(auto x :g)
 cout<<x<<" ";
 
 cout<<endl;


  
  
return 0;
}