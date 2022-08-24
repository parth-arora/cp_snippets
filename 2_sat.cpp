#include <bits/stdc++.h>
using namespace std;
typedef long long  ll;
typedef long double ld;
#define pb push_back
#define MAXN 200005
#define INF (ll)1e18
#define Mod 1000000007 
//#define mod 998244353
#define endl '\n'
#define level 20
ll cc=0;

//https://cses.fi/problemset/task/1684/
 
 
void boost()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
}
 
vector<ll> V[MAXN],V1[MAXN],V2[MAXN];
 
ll vis[MAXN],vis1[MAXN],vis2[MAXN],a[MAXN],a1[MAXN],a2[MAXN],dp[MAXN];
char cl[MAXN];


 
vector<ll> g;
stack<ll> stck;
 
void dfs(ll cur,ll prev)
{
    vis[cur]++;
    
    for(auto x : V[cur])
    {
        if(vis[x]==0)
        {
            dfs(x,cur);
        }
        
    }
    
    stck.push(cur);
}
 
void dfs1(ll cur,ll prev)
{
    vis1[cur]++;
    g.pb(cur);
    
    for(auto x : V1[cur])
    {
        if(vis1[x]==0)
        {
            dfs1(x,cur);
        }
    }
}
 
 
void dfs2(ll cur,ll prev)
{
    vis2[cur]++;
    
    for(auto x : V2[cur])
    {
        if(vis2[x]==0)
        {
            dfs2(x,cur);
        }
    }
    
    g.pb(cur);
}
 
int main()
{
    boost();
    
    ll i,j,k,n,t,c=0,l,r,v,x,y,n1;
    ll ans,h,z,m,u,q,mm,w,mx,d;
    ld f;
    
    char ch,ch1;
    
    cin>>n>>m;
    n1=(2*m)+1;
    
    
    
    for(i=0;i<MAXN;i++)
    {
        vis[i]=0;
        vis1[i]=0;
        vis2[i]=0;
        dp[i]=0;
        a[i]=0;
    }
    
    for(i=0;i<n;i++)
    {
        cin>>ch>>x;
        cin>>ch1>>y;
        
        if(ch=='+')
        {
            if(ch1=='+')
            {
                l=2*x+1;
                r=2*y;
                V[l].pb(r);
                V1[r].pb(l);
                l=2*y+1;
                r=2*x;
                V[l].pb(r);
                V1[r].pb(l);
                
            }
            
            else if(ch1=='-')
            {
                l=2*x+1;
                r=2*y+1;
                V[l].pb(r);
                V1[r].pb(l);
                l=2*y;
                r=2*x;
                V[l].pb(r);
                V1[r].pb(l);
            }
        }
        
        if(ch=='-')
        {
            if(ch1=='-')
            {
                l=2*x;
                r=2*y+1;
                V[l].pb(r);
                V1[r].pb(l);
                l=2*y;
                r=2*x+1;
                V[l].pb(r);
                V1[r].pb(l);
            }
            
            else if(ch1=='+')
            {
                l=2*x;
                r=2*y;
                V[l].pb(r);
                V1[r].pb(l);
                l=2*y+1;
                r=2*x+1;
                V[l].pb(r);
                V1[r].pb(l);
            }
            
        }
        
    }
    
    
     for(i=2;i<=n1;i++)
    {
        if(vis[i]==0)
        {
            dfs(i,0);
        }
    }
    
    c=0;
    
    while(!stck.empty())
    {
        x=stck.top();
        stck.pop();
        
        if(vis1[x]==0)
        {
            g.clear();
            dfs1(x,0);
            c++;
            y=0;
            
            for(i=0;i<g.size();i++)
            {
                x=g[i];
                a2[x]=c;
            }
            
        }
    }
    
    for(i=2;i<=n1;i++)
    {
        for(auto x : V[i])
        {
            if(a2[i]!=a2[x])
            {
                V2[a2[i]].pb(a2[x]);
            }
        }
    }
    
    g.clear();
    
    for(i=1;i<=c;i++)
    {
        if(vis2[i]==0)
        {
            dfs2(i,0);
        }
    }
    
    reverse(g.begin(),g.end());
    
    for(i=0;i<g.size();i++)
    {
        l=g[i];
        dp[l]=i;
    }
    
    c=0;
    
    for(i=1;i<=m;i++)
    {
        l=2*i;
        r=(2*i)+1;
        x=a2[l];
        y=a2[r];
        
        if(x==y)
        {
            c++;
            break;
        }
        
        else
        {
            x=dp[x];
            y=dp[y];
            
            if(x>y)
            {
                a[i]++;
            }
        }
    }
    
    if(c>0)
    {
        cout<<"IMPOSSIBLE"<<endl;
    }
    
    else
    {
        for(i=1;i<=m;i++)
        {
            if(a[i]>0)
            {
                cl[i]='+';
            }
            
            else
            {
                cl[i]='-';
            }
            
            
            cout<<cl[i]<<" ";
        }
    }
 
    
    
return 0;
}