#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
 
#include <bits/stdc++.h>
using namespace std;
 
typedef int ll;
typedef long double ld;
typedef pair<ll,ll> pll;
typedef vector<ll> vl;
#define pb push_back
#define MAXN 200005
const ll N=31;
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
ll timer,cc,cc1,n;
 
 
void boost()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

//https://cses.fi/problemset/task/2134
 
ll seg[4*MAXN],a[MAXN],depth[MAXN],dp[MAXN];
ll heavy[MAXN],ch[MAXN],chhd[MAXN],posi[MAXN];
 
vector<ll> V[MAXN];
ll parent[MAXN][level];
 
 
ll sum(ll v, ll tl, ll tr, ll l, ll r)
{
    ll tm, i, j;
 
    if (l > r)
    {
        return -INF;
    }
 
    if (l == tl && r == tr)
    {
        return seg[v];
    }
 
    tm = (tl + tr) / 2;
 
    return (max(sum(v * 2, tl, tm, l, min(r, tm)),sum(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r)));
}
 
void update(ll v,ll tl,ll tr,ll pos,ll val)
{
    ll tm;
    
    if(tl==tr)
    {
        seg[v]=val;
    }
    
    else
    {
        
    tm=(tl+tr)/2;
    
    if(pos<=tm)
    {
        update(2*v,tl,tm,pos,val);
    }
    
    else
    {
        update(2*v+1,tm+1,tr,pos,val);
    }
    
    seg[v]=max(seg[v*2],seg[v*2+1]);
    
    }
    
}
 
void dfs(ll cur, ll prev) 
{ 
    ll i,j;
    
    depth[cur] = depth[prev] + 1; 
    parent[cur][0] = prev;
    dp[cur]++;
 
    for (auto x : V[cur]) 
    { 
        if (x!=prev) 
        {
            dfs(x,cur);
            dp[cur]+=dp[x];
        }
    }
    
}
 
void dfs1(ll cur ,ll prev)
{
    ll mx=0;
    
     if(chhd[cc]==0)
    {
        chhd[cc]=cur;
    }
    
    ch[cur]=cc;
    posi[cur]=cc1++;
    
    
    for(auto x : V[cur])
    {
        if(x!=prev)
        {
            if(dp[x]>mx)
            {
                mx=dp[x];
                heavy[cur]=x;
            }
        }
    }
    
    if(heavy[cur]!=0)
    {
       dfs1(heavy[cur],cur);
    }
    
    for(auto x : V[cur])
    {
        if(x!=prev&&x!=heavy[cur])
        {
            cc++;
            dfs1(x,cur);
        }
    }
    
}
 
ll up(ll from, ll lc)
{
    ll ans=0,z,cur=from;
    
    while(ch[cur]!=ch[lc])
    {
       z=sum(1,1,n,posi[chhd[ch[cur]]],posi[cur]);
       ans=max(ans,z);
       cur=parent[chhd[ch[cur]]][0]; 
    }
    
    z=sum(1,1,n,posi[lc],posi[cur]);
    ans=max(ans,z);
    
    return ans;
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
    
    ll i,t,q,l,r,ans,mid,c,z,j,k,tc;
    ll h,m,u,mm,w,mx,x,y,l1,r1,d=0,mask;
    ld f;
    
    
    for(i=0;i<4*MAXN;i++)
    {
        seg[i]=-INF;
    }
    
       cin>>n>>q;
       cc=1;
       cc1=1;
        
        for(i=0;i<=n;i++)
        {
            V[i].clear();
            depth[i]=0;
            heavy[i]=0;
            ch[i]=0;
            chhd[i]=0;
            posi[i]=0;
            dp[i]=0;
        }
        
        for(i=0;i<=n;i++)
        {
            for(j=0;j<level;j++)
            parent[i][j]=0;
        }
        
        for(i=1;i<=n;i++)
        cin>>a[i];
        
       for(i=0;i<(n-1);i++)
        {
            cin>>x>>y;
            V[x].pb(y);
            V[y].pb(x);
        }
        
        
        dfs(1,0);
        compute(n);
        dfs1(1,0);
        
        for(i=1;i<=n;i++)
        {
            l=posi[i];
            r=a[i];
            update(1,1,n,l,r);
        }
        
        while(q--)
        {
            cin>>x;
            
            if(x==1)
            {
                cin>>l>>r;
                l=posi[l];
                update(1,1,n,l,r);
            }
            
            else
            {
                cin>>l>>r;
                z=lca(l,r);
                l1=up(l,z);
                r1=up(r,z);
                
                cout<<max(l1,r1)<<" ";
                
            }
        }
        
        
    
return 0;
}