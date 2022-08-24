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

vpl V[MAXN];
ll dis[MAXN],vis[MAXN];
priority_queue<pll,vpl,greater<pll>>pq;

void boost()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
}


int main()
{
    boost();

    ll i,j,k,n,c=0,d=0,t,x,y;
    ll l,r,ans,h,f,z,m,u,v;

    for(i=0;i<=n;i++)
    {
        dis[i]=INF;
        vis[i]=0;
        clr(V[i]);
    }
    


    dis[1]=0;
    pq.push(mkp(dis[1],1));

    while(!pq.empty())
    {
        u=pq.top().se;
        pq.pop();

        if(vis[u]==0)
        {
            vis[u]++;

        for(auto p: V[u])
        {
            v=p.fi;
            k=p.se;

            if((dis[v]>(dis[u]+k))&&(vis[v]==0))
            {
                dis[v]=dis[u]+k;
                pq.push(mkp(dis[v],v));
            }
        }
        
        }
        
    }


return 0;
}
