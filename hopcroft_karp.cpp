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

vpl g1;

struct Hopcroft_Karp
{
  static const int inf = 1e9;
 
  int n;
  vector<int> matchL, matchR, dist;
  vector<set<int>> g;
 
  Hopcroft_Karp(int n) :
    n(n), matchL(n+1), matchR(n+1), dist(n+1), g(n+1) {}
 
  void addEdge(int u, int v)
  {
    g[u].insert(v);
  }
 
  bool bfs()
  {
    queue<int> q;
    for(int u=1;u<=n;u++)
    {
      if(!matchL[u])
      {
        dist[u]=0;
        q.push(u);
      }
      else
      dist[u]=inf;
    }
    
    dist[0]=inf;
 
    while(!q.empty())
    {
      int u=q.front();
      q.pop();
      for(auto v:g[u])
      {
        if(dist[matchR[v]] == inf)
        {
          dist[matchR[v]] = dist[u] + 1;
          q.push(matchR[v]);
        }
      }
    }
 
    return (dist[0]!=inf);
  }
 
  bool dfs(int u)
  {
    if(!u)
      return true;
      
    for(auto v: g[u])
    {
      if(dist[matchR[v]] == dist[u]+1 &&dfs(matchR[v]))
      {
        matchL[u]=v;
        matchR[v]=u;
        
        return true;
      }
    }
    
    dist[u]=inf;
    return false;
  }
 
  int max_matching()
  {
    int matching=0;
    while(bfs())
    {
      for(int u=1;u<=n;u++)
      {
        if(!matchL[u])
          if(dfs(u))
            matching++;
      }
    }
    
    return matching;
  }
  
  void fun()
  {
      for(int i=1;i<=n;i++)
      {
          if(matchL[i])
          {
              g1.pb(mkp(i,matchL[i]));
          }
      }
  }
  
};


int main()
{
  boost();
   
  ll i,t,q,l,r,ans,mid,c=0,j,z,tc,n,k;
  ll h,m,u,mm,w,x,y,l1,r1,d=0,mask,v,mx;
  ld f,f1;
  
  cin>>n>>m>>k;
  Hopcroft_Karp matching(n+m+1);
  
  for(i=0;i<k;i++)
  {
      cin>>x>>y;
      y+=n;
      matching.addEdge(x,y);
  }
  
  ans=matching.max_matching();
  
  cout<<ans<<endl;
  
  matching.fun();
  
  for(auto  x : g1)
  {
      cout<<x.fi<<" "<<x.se-n<<endl;
  }


   
   
return 0;
}