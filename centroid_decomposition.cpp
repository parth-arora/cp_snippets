//https://www.codechef.com/problems/TREEDECOR
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization ("unroll-loops")
//u can always think of Binary Search to find the minimum answer...........

 
#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pll;
typedef vector<ll> vl;
typedef vector<pll> vpl;
#define pb push_back
const ll N=32;
#define INF (ll)1e18
#define MAXN 50005
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
ll timer,cc1,cc;

void boost()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

ll dp[MAXN],vis[MAXN];
ll parent[MAXN][level],depth[MAXN];
ll dis[MAXN][level];
vl V[MAXN];
ll par[MAXN],a[MAXN];
ll cnt[MAXN],cnt1[MAXN];
ll cnt2[MAXN],cnt21[MAXN];
 
void dfs(ll cur,ll prev)
{
    ll c=0;
    
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
 
ll decomp(ll cur)
{
    ll z,j;
    dfs1(cur,0);
    
    z=get(cur,0,dp[cur]);
    vis[z]++;
    
    for(auto x : V[z])
    {
        if(vis[x]==0)
        {
            j=decomp(x);
            par[j]=z;
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
 
ll dist(ll x,ll y)
{
    ll z,l;
    
    z=lca(x,y);
    l=depth[x]+depth[y]-(2*depth[z]);
    
    return l;
}


int main()
{
    boost();
    
    ll i,n,q,j,x,y,h,k,l1;
    ll d,z,l,r,c=0,ans,r1;
    
       cin>>n;
       
       for(i=1;i<=n;i++)
        cin>>a[i];
        
        for(i=1;i<n;i++)
        {
            cin>>x>>y;
            V[x].pb(y);
            V[y].pb(x);
        }
        
        dfs(1,0);
        compute(n);
        h=decomp(1);
        
        
        for(i=1;i<=n;i++)
        {
            y=i;
            c=0;
            z=-1;
            
            while(y!=0)
            {
                l=dist(i,y);
                r=l*a[i];
                cnt[y]+=r;
                cnt1[y]+=a[i];
                dis[i][c]=l;
                
                if(z!=-1)
                {
                    cnt2[z]+=r;
                    cnt21[z]+=a[i];
                }
                
                z=y;
                y=par[y];
                c++;
            }
        }
        
        cin>>q;
    
        while(q--)
        {
            cin>>l1;
            
            if(l1==1)
            {
                cin>>x>>h;
                
                y=x;
                c=0;
                z=-1;
                
                    while(y!=0)
                    {
                        l=dis[x][c];
                        r=l*(h-a[x]);
                        cnt[y]+=r;
                        cnt1[y]+=(h-a[x]);
                        
                        if(z!=-1)
                        {
                            cnt2[z]+=r;
                            cnt21[z]+=(h-a[x]);
                        }
                        
                        z=y;
                        y=par[y];
                        c++;
                    }
                    
                    a[x]=h;
            }
            
            else
            {
                cin>>x;
                ans=0;
                
                y=x;
                c=0;
                z=-1;
                
                while(y!=0)
                {
                    l=dis[x][c];
                    
                    ans+=cnt[y];
                    ans+=(cnt1[y]*l);
                        
                    if(z!=-1)
                    {
                        ans-=cnt2[z];
                        ans-=(cnt21[z]*l);
                    }
                    
                    z=y;
                    y=par[y];
                    c++;
                    
                }
            
            cout<<ans<<endl;
            }
    }
    
return 0;
}