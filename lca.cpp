
#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pll;
typedef vector<ll> vl;
#define pb push_back
#define MAXN 200005
const ll N=32;
#define INF (ll)1e18
#define mod 1000000007
//#define mod 998244353
#define fi first
#define se second
#define mkp make_pair
#define sze(x) ((ll)x.size())
#define all(v) v.begin(),v.end()
#define endl '\n'
#define level 20
ll timer,cc,cc1;
 
 
void boost()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
}
 
vl V[MAXN];
ll depth[MAXN];
ll parent[MAXN][level];
 
void dfs(ll cur,ll prev)
{
  depth[cur]=depth[prev]+1;
  parent[cur][0]=prev;
   
  for(auto x : V[cur])
  {
    if(x!=prev)
    {
      dfs(x,cur);
    }
  }
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
 
int main()
{
  boost();
   
  ll i,t,q,l,r,ans,mid,c=0,j,k,z,tc,e,n,m,mask;
  ll h,u,mm,w,mx,x,y,l1,r1,d=0;
  ld f,f1;
   
   
  for(i=0;i<=n;i++)
  {
    V[i].clear();
    depth[i]=0;
  }
   
    for(i=0;i<=n;i++)
    {
      for(j=0;j<level;j++)
      parent[i][j]=0;
    }
     
return 0;
}