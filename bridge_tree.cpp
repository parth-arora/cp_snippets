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
ll timer,cc1,cc,cc2;

void boost()
{
 ios_base::sync_with_stdio(false);
 cin.tie(NULL);
}

//https://codeforces.com/contest/555/problem/E


vpl V[MAXN];
vl V1[MAXN];
ll tin[MAXN],low[MAXN],vis[MAXN];
ll dp[MAXN],a[MAXN],a1[MAXN];
ll depth[MAXN],dp1[MAXN],a2[MAXN];
ll parent[MAXN][level];

void dfs(ll cur,ll prev,ll id)
{
    ll x;
    tin[cur]=timer++;
    low[cur]=tin[cur];
    vis[cur]++;
    
    for(auto y :V[cur])
    {
       x=y.fi;
       
        if(vis[x]==0)
        {
            dfs(x,cur,y.se);
            low[cur]=min(low[cur],low[x]);
            
            if(low[x]>tin[cur])
            {
                a2[y.se]++;
            }
        }
        
        else if(x==prev&&id==y.se)
        continue;
        
        else
        {
            low[cur]=min(low[cur],tin[x]);
        }
    }
}

void dfs1(ll cur,ll prev)
{
    ll x;
    vis[cur]++;
    a[cur]=cc;
    
    for(auto  y : V[cur])
    {
        x=y.fi;
        if((vis[x]==0)&&a2[y.se]==0)
        {
            dfs1(x,cur);
        }
    }
}
 
void dfs2(ll cur,ll prev)
{
    depth[cur]=depth[prev]+1;
    parent[cur][0]=prev;
    a1[cur]=cc1;
    vis[cur]++;
    
    for(auto x : V1[cur])
    {
        if(vis[x]==0)
        {
            dfs2(x,cur);
        }
    }
}

void dfs3(ll cur,ll prev)
{
    vis[cur]++;
    
    for(auto x : V1[cur])
    {
        if(vis[x]==0)
        {
            dfs3(x,cur);
            dp1[cur]+=dp1[x];
            dp[cur]+=dp[x];
            
            if(dp1[x]>0&&dp[x]>0)
            {
                cc2++;
            }
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
  
 ll i,t,q,l,r,ans,mid,c=0,j,z,tc,n,k;
 ll h,m,u,mm,w,x,y,l1,r1,d=0,mask,v,mx;
 ld f,f1;
 
 cin>>n>>m>>q;
 timer=1;
 cc=0;
 cc1=0;
 cc2=0;
 
 for(i=1;i<=m;i++)
 {
     cin>>x>>y;
     V[x].pb(mkp(y,i));
     V[y].pb(mkp(x,i));
 }
 
 for(i=1;i<=n;i++)
 {
     if(vis[i]==0)
     {
         dfs(i,0,0);
     }
 }
 
 for(i=0;i<=n;i++)
 vis[i]=0;
 
 for(i=1;i<=n;i++)
 {
     if(vis[i]==0)
     {
         cc++;
         dfs1(i,0);
     }
 }
 
 vpl g;
 
 for(i=1;i<=n;i++)
 {
     for(auto y : V[i])
     {
         x=y.fi;
         if(a[i]!=a[x])
         {
             V1[a[i]].pb(a[x]);
         }
     }
 }
 
 
 for(i=0;i<=n;i++)
 {
     vis[i]=0;
 }
 
 for(i=1;i<=cc;i++)
 {
     if(vis[i]==0)
     {
         cc1++;
         dfs2(i,0);
     }
 }
 
 compute(cc);
 
 while(q--)
 {
     cin>>l>>r;
     l1=a[l];
     r1=a[r];
     
     if(a1[l1]!=a1[r1])
     {
         cc2++;
     }
     
     else if(l1==r1)
     {
         continue;
     }
     
     else
     {
         z=lca(l1,r1);
         dp[l1]++;
         dp[z]--;
         dp1[r1]++;
         dp1[z]--;
     }
 }
 
 for(i=0;i<=cc;i++)
 vis[i]=0;
 
 
 for(i=1;i<=cc;i++)
 {
     if(vis[i]==0)
     {
         dfs3(i,0);
     }
 }
 
 if(cc2>0)
 cout<<"No"<<endl;
 
 else
 cout<<"Yes"<<endl;
 

  
  
return 0;
}