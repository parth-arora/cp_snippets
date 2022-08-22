//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx,avx2,fma")
//#pragma GCC optimization ("unroll-loops")
//u can always think of Binary Search to find the minimum answer...........

//https://github.com/ShahjalalShohag/code-library/blob/master/Graph%20Theory/Virtual%20Tree.cpp
//https://codeforces.com/contest/1702/problem/G2
 
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

vl V[MAXN];
ll depth[MAXN],tin[MAXN];
ll parent[MAXN][level];
ll tout[MAXN];
 
void dfs(ll cur,ll prev)
{
  depth[cur]=depth[prev]+1;
  parent[cur][0]=prev;
  tin[cur]=timer++;
   
  for(auto x : V[cur])
  {
    if(x!=prev)
    {
      dfs(x,cur);
    }
  }
  
  tout[cur]=timer-1;
}
 
void compute(ll n)
{
  ll i,j,node,z;
 
  for (i=1; i<level; i++)
  {
    for (node=1;node<= n; node++)
    {
      z= parent[node][i-1];
 
      if (z!=0)
      {
        parent[node][i]=parent[z][i-1];
 
      }
    }
  }
}
 
 
ll lca(ll u, ll v)
{
  ll diff,i,j;
 
  if (depth[v] < depth[u])
  {
    swap(u, v);
  }
 
 diff = depth[v] - depth[u];
 
 
  for (i=0; i<level; i++)
  {
    if ((diff>>i)&1)
    {
      v = parent[v][i];
    }
  }
 
 
  if (u == v)
  {
    return u;
  }
 
  for (i=level-1; i>=0; i--)
  {
    if (parent[u][i] != parent[v][i])
    {
      u = parent[u][i];
      v = parent[v][i];
    }
 
  }
 
  return parent[u][0];
}

ll isanc(ll u,ll v) 
{
  return (tin[u] <= tin[v]) && (tout[v] <= tout[u]);
}
 
int main()
{
 boost();
  
 ll i,t,q,l,r,ans,mid,c=0,j,z,tc,n,k;
 ll h,m,u,mm,w,x,y,l1,r1,d=0,mask,v,mx;
 ld f,f1;
 
 cin>>n;
 timer=1;
 
 for(i=1;i<n;i++)
 {
     cin>>x>>y;
     V[x].pb(y);
     V[y].pb(x);
 }
 
 dfs(1,0);
 compute(n);
 
 cin>>q;
 
 vpl g;
 stack<ll> ss;
 
 for(i=0;i<=n;i++)
 clr(V[i]);
 
 while(q--)
 {
     cin>>k;
     clr(g);
     
     while(k--)
     {
         cin>>x;
         g.pb(mkp(tin[x],x));
     }
     
     sort(all(g));
     c=0;
     m=sze(g);
     
     for(i=1;i<m;i++)
     {
         z=lca(g[i-1].se,g[i].se);
         g.pb(mkp(tin[z],z));
     }
     
     sort(all(g));
     g.erase(unique(all(g)),g.end());
     
     sort(all(g));
     
     ss.push(g[0].se);
     
     for(i=1;i<sze(g);i++)
     {
         while(!isanc(ss.top(),g[i].se))
         ss.pop();
         
         V[ss.top()].pb(g[i].se);
         V[g[i].se].pb(ss.top());
         
         ss.push(g[i].se);
     }
     
     for(auto x :g)
     {
         if(sze(V[x.se])>2)
         c++;
     }
     
     if(c>0)
     cout<<"NO"<<endl;
     
     else
     cout<<"YES"<<endl;
     
     for(auto x :g)
     {
         clr(V[x.se]);
     }
     
 }


  
  
return 0;
}