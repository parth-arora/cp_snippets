#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define pb push_back
#define MAXN 100005
#define INF (ll)1e18
#define mod 1000000007 
//#define mod 998244353
#define endl '\n'
ll cc=0,cc1=0;
ll timer;
 
 
void boost()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}
 
vector<ll> V[MAXN];
ll tin[MAXN],low[MAXN],vis[MAXN],par[MAXN];
 
vector<pair<ll,ll>> g;
 
void dfs(ll cur ,ll prev)
{
    tin[cur]=timer++;
    low[cur]=tin[cur];
    vis[cur]++;
    par[cur]=prev;
    
    
    for(auto x: V[cur])
    {
        if(vis[x]==0)
        {
            dfs(x,cur);
            low[cur]=min(low[cur],low[x]);
            
            if(low[x]>tin[cur])
            {
                g.pb(make_pair(x,cur));
            }
            
        }
            
            else if(x!=par[cur])
            {
                low[cur]=min(low[cur],tin[x]);
            }
    }
    
}
 
 
int main()
{
    boost();
 
    ll i,t,n,q,l,r,ans,mid,c,z,j,k,v;
    ll h,m,u,mm,w,mx,x,y,l1,r1,d=0,mask;
    ld f;
    
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
    
    cout<<g.size()<<endl;
    
    for(auto x : g)
    {
        cout<<x.first<<" "<<x.second<<endl;
    }
        
return 0;
}