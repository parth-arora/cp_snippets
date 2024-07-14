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
const ll N=155;
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

struct Edge
{
    ll from, to, capacity, cost;
};


//https://cp-algorithms.com/graph/min_cost_flow.html
//https://atcoder.jp/contests/abc247/tasks/abc247_g

vector<vector<ll>> adj, cost, capacity;

void shortest_paths(ll n, ll v0, vector<ll>& d, vector<ll>& p) {
    d.assign(n, INF);
    d[v0] = 0;
    vector<bool> inq(n, false);
    queue<ll> q;
    q.push(v0);
    p.assign(n, -1);

    while (!q.empty()) {
        ll u = q.front();
        q.pop();
        inq[u] = false;
        for (ll v : adj[u]) {
            if (capacity[u][v] > 0 && d[v] > d[u] + cost[u][v]) {
                d[v] = d[u] + cost[u][v];
                p[v] = u;
                if (!inq[v]) {
                    inq[v] = true;
                    q.push(v);
                }
            }
        }
    }
}

ll min_cost_flow(ll n, vector<Edge> edges, ll K, ll s, ll t) {
    adj.assign(n, vector<ll>());
    cost.assign(n, vector<ll>(n, 0));
    capacity.assign(n, vector<ll>(n, 0));
    for (Edge e : edges) {
        adj[e.from].push_back(e.to);
        adj[e.to].push_back(e.from);
        cost[e.from][e.to] = e.cost;
        cost[e.to][e.from] = -e.cost;
        capacity[e.from][e.to] = e.capacity;
    }

    ll flow = 0;
    ll cost = 0;
    vector<ll> d, p;
    while (flow < K) {
        shortest_paths(n, s, d, p);
        if (d[t] == INF)
            break;

        // find max flow on that path
        ll f = K - flow;
        ll cur = t;
        while (cur != s) {
            f = min(f, capacity[p[cur]][cur]);
            cur = p[cur];
        }

        // apply flow
        flow += f;
        cost += f * d[t];
        cur = t;
        while (cur != s) {
            capacity[p[cur]][cur] -= f;
            capacity[cur][p[cur]] += f;
            cur = p[cur];
        }
    }

   // here weights are negative so return 0 instead of -1;
    if (flow < K)
        return 0;
    else
        return cost;
}

int main()
{
 boost();
  
 ll i,t,q,l,r,ans,mid,c=0,j,z,tc,n,k;
 ll h,m,u,mm,w,x,y,l1,r1,d=0,mask,v,mx;
 ld f,f1;
 
 
 cin>>n;
 
 ll a[N][N];
 
 for(i=0;i<N;i++)
 for(j=0;j<N;j++)
 a[i][j]=INF;
 
 for(i=1;i<=n;i++)
 {
    cin>>x>>y>>z;
    a[x][y]=min(a[x][y],-z);
 }
 
 vector<Edge> g;
 Edge e;
 
 for(i=1;i<N;i++)
 {
    for(j=1;j<N;j++)
    {
       
       if(a[i][j]==INF)
       continue;
       
       e.from=i;
       e.to=j+N;
       e.capacity=1;
       e.cost=a[i][j];
       
       g.pb(e);
    }
 }
 
 for(i=1;i<N;i++)
 {
    e.from=0;
    e.to=i;
    e.capacity=1;
    e.cost=0;
    
    g.pb(e);
 }
 
 for(i=1;i<N;i++)
 {
    e.from=i+N;
    e.to=2*N;
    e.capacity=1;
    e.cost=0;
    
    g.pb(e);
 }
 
 vl g1;
 
 for(i=1;i<=n;i++)
 {
    // total vertices are 2*N so pass 2*N+1 because of 1 indexed
    ans=min_cost_flow(2*N+1,g,i,0,2*N);
    
    if(ans==0)
    break;
    
    ans*=-1;
    
    g1.pb(ans);
 }
 
 cout<<sze(g1)<<endl;
 
 for(auto x :g1)
 cout<<x<<endl;
 
  
  
return 0;
}
