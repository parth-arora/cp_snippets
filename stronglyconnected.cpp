#include <bits/stdc++.h>
using namespace std;
typedef long long   ll;
typedef double ld;
#define MAXN 100005
#define INF (ll)1e18
#define mod 1000000007
#define endl '\n'


vector<ll> V[MAXN],V1[MAXN];
ll vis[MAXN],a[MAXN],vis1[MAXN];
vector<ll> g;
stack<ll> stck;

// basic code+ question
//vector g stores connected components
void boost()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
}

void dfs(ll cur, ll prev)
{
    ll i,j;
    vis[cur]++;

    for(auto x: V[cur])
    {
      if(vis[x]==0)
      {
       dfs(x,cur);
      }

      else
      continue;

    }

    stck.push(cur);

}

void dfs1(ll cur, ll prev)
{
    ll i,j;
    vis1[cur]++;
    g.push_back(cur);

    for(auto x: V1[cur])
    {
      if(vis1[x]==0)
      {
       dfs1(x,cur);
      }

    }

}

int main()
{
    boost();

    ll i,j,k,n,c=0,d=0,t,x,y;
    ll l,r,ans,h,z,m,u,q,mm,v,w;

    cin>>n;

    for(i=0;i<=n;i++)
    {
        V[i].clear();
        V1[i].clear();
        vis[i]=0;
        vis1[i]=0;
    }

    for(i=1;i<=n;i++)
    {
        cin>>a[i];
    }

    cin>>m;

        for(i=1;i<=m;i++)
        {
            cin>>u>>v;
            V[u].push_back(v);
            V1[v].push_back(u);
        }

   for(i=1;i<=n;i++)
    {
        if(vis[i]==0)
        dfs(i,0);
    }

    c=0;
    z=1;
    d=0;

    while(!stck.empty())
    {
        j=stck.top();
        stck.pop();

        if(vis1[j]==0)
        {
            g.clear();
            dfs1(j,0);

            mm=INF;
            d=0;
            for(i=0;i<g.size();i++)
            {
                k=g[i];
                mm=min(mm,a[k]);
            }

            c+=mm;

            for(i=0;i<g.size();i++)
            {
                k=g[i];

                if(a[k]==mm)
                {
                    d++;
                }
            }

            z=z*d;
            z=z%mod;
        }
    }


    cout<<c<<" "<<z<<endl;



return 0;
}
