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

struct Dinic 
{
  struct edge 
  {
    int to, rev;
    long long flow, w;
    int id;
  };
  
  const ll inf=(ll)1e18;
  int n, s, t, mxid;
  vector<int> d, flow_through;
  vector<int> done;
  vector<vector<edge>> g;
  Dinic() {}
  
  Dinic(int _n) 
  {
    n = _n + 10;
    mxid = 0;
    g.resize(n);
  }
  
  void add_edge(int u, int v, long long w, int id = -1) 
  {
    edge a = {v, (int)g[v].size(), 0, w, id};
    edge b = {u, (int)g[u].size(), 0, 0, -2};//for bidirectional edges cap(b) = w
    g[u].emplace_back(a);
    g[v].emplace_back(b);
    mxid = max(mxid, id);
  }
  
  bool bfs() 
  {
    d.assign(n, -1);
    d[s] = 0;
    queue<int> q;
    q.push(s);
    while (!q.empty()) 
    {
      int u = q.front();
      q.pop();
      for (auto &e : g[u])
      {
        int v = e.to;
        if (d[v] == -1 && e.flow < e.w) d[v] = d[u] + 1, q.push(v);
      }
    }
    return d[t] != -1;
  }
  
  long long dfs(int u, long long flow) 
  {
      
    if (u == t) return flow;
    for (int &i = done[u]; i < (int)g[u].size(); i++) 
    {
      edge &e = g[u][i];
      if (e.w <= e.flow) 
      continue;
      
      int v = e.to;
      if (d[v] == d[u] + 1) 
      {
        long long nw = dfs(v, min(flow, e.w - e.flow));
        if (nw > 0) 
        {
          e.flow += nw;
          g[v][e.rev].flow -= nw;
          return nw;
        }
        
      }
    }
    return 0;
  }
  
  long long max_flow(int _s, int _t)
  {
    s = _s;
    t = _t;
    long long flow = 0;
    while (bfs()) 
    {
      done.assign(n, 0);
      while (long long nw = dfs(s, inf)) flow += nw;
    }
    
    flow_through.assign(mxid + 10, 0);
    for(int i = 0; i < n; i++) for(auto e : g[i]) if(e.id >= 0) flow_through[e.id] = e.flow;
    return flow;
  }
};

int main()
{
  boost();
   
  ll i,t,q,l,r,ans,mid,c=0,j,z,tc,n,k;
  ll h,m,u,mm,w,x,y,l1,r1,d=0,mask,v,mx;
  ld f,f1;
  
  cin>>n>>m;
  
  Dinic F(n+1);
  
  for(i=0;i<m;i++) 
  {
      cin>>x>>y>>w;
      F.add_edge(x,y,w);
  }
  
  ans=F.max_flow(1,n);
  cout<<ans<<endl;
  
return 0;
}