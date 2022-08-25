//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx,avx2,fma")
//#pragma GCC optimization ("unroll-loops")
// u can always think of Binary Search to find the minimum answer...........
 
 
#include <bits/stdc++.h>
using namespace std;
 
typedef long long  ll;
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
ll timer,cc,cc1,k;
 
void boost()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

//https://codeforces.com/contest/555/problem/E
 
ll dp[MAXN],vis[MAXN];
ll parent[MAXN][level],depth[MAXN];
vl V[MAXN],V1[MAXN];
ll par[MAXN],a[MAXN];
ll mxd;
 
void dfs(ll cur,ll prev)
{
    ll c=0;
    
    dp[cur]++;
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
 
void dfs1(ll cur ,ll prev)
{
    dp[cur]=1;
    
    for(auto x : V[cur])
    {
        if(x!=prev&&vis[x]!=1)
        {
            dfs1(x,cur);
            dp[cur]+=dp[x];
        }
    }
}
 
ll get(ll cur,ll prev,ll n)
{
    ll mx,z;
    mx=n-dp[cur];
    z=0;
    
    for(auto x : V[cur])
    {
        if(x!=prev&&vis[x]!=1)
        {
            mx=max(mx,dp[x]);
            
            if(dp[x]>(n/2))
            {
                z=x;
            }
        }
    }
    
    if(mx>(n/2))
    {
        return get(z,cur,n);
    }
    
    return cur;
}
 
void dfs2(ll cur,ll prev,ll d)
{
    if(k>=d)
    {
        if(k==d)
        cc++;
        
        else
        {
            cc+=a[k-d];
        }
    }
    
    mxd=max(mxd,d);
    
    for(auto x : V[cur])
    {
        if(x!=prev&&vis[x]!=1)
        {
            dfs2(x,cur,d+1);
        }
    }
}
 
void dfs3(ll cur, ll prev,ll d)
{
    a[d]++;
    
    for(auto x : V[cur])
    {
        if(x!=prev&&vis[x]!=1)
        {
            dfs3(x,cur,d+1);
        }
    }
}
 
ll decomp(ll cur)
{
    ll z,j;
    dfs1(cur,0);
    
    z=get(cur,0,dp[cur]);
    vis[z]++;
    mxd=0;
    
    for(auto x : V[z])
    {
        if(vis[x]==0)
        {
        dfs2(x,0,1);
        dfs3(x,0,1);
        }
    }
    
    fill(a,a+mxd+1,0);
    
    for(auto x : V[z])
    {
        if(vis[x]==0)
        {
            j=decomp(x);
            par[j]=z;
            V1[z].pb(j);
        }
    }
    
    return z;
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
 
ll dis(ll x,ll y)
{
    ll z,l;
    
    z=lca(x,y);
    l=depth[x]+depth[y]-(2*depth[z]);
    
    return l;
}
 
 
int main()
{
    boost();
    
    ll i,t,q,l,r,ans,mid,c=0,j,z,tc,m,n;
    ll h,u,mm,w,x,y,l1,r1,d=0,mask,mx;
    ld f,f1;
    
    cin>>n>>k;
    cc=0;
    
    for(i=0;i<(n-1);i++)
    {
       cin>>x>>y;
       V[x].pb(y);
       V[y].pb(x);
    }
 
    
    dfs(1,0);
    compute(n);
    h=decomp(1);
    
    cout<<cc<<endl;
    
return 0;
}
