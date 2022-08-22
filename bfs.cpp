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
ll timer,cc1,cc;

void boost()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
}

vl V[MAXN];
ll dis[MAXN],par[MAXN],vis[MAXN];
queue<ll> que;

void bfs(ll cur,ll prev)
{
    ll u,i,z;
    vis[cur]++;
    dis[cur]=0;
    que.push(cur);

    while(!(que.empty()))
    {
        u=que.front();
        que.pop();

        for(auto x : V[cur])
        {
            
            if(vis[x]==0)
            {
            vis[x]++;
            dis[x]=dis[u]+1;
            par[z]=u;
            que.push(z);
            }
        }
    }

}

int main()
{
    boost();
    
    ll i,t,q,l,r,ans,mid,c=0,j,z,tc,n,k;
    ll h,m,u,mm,w,x,y,l1,r1,d=0,mask,v,mx;
    ld f,f1;
    
    for(i=0;i<=n;i++)
    {
        clr(V[i]);
        vis[i]=0;
        par[i]=-1;
        dis[i]=INF;

    }
    
    
return 0;
}


