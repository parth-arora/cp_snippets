#include <bits/stdc++.h>
using namespace std;
typedef long long  ll;
typedef long double ld;
#define MAXN 505
vector <ll> V[MAXN];
ll dis[MAXN][MAXN];


void boost()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
}

 /*
void dfs(ll cur)
{
    ll j,z,k,u,v;
    dis[cur]=0;
    pq.push(make_pair(dis[cur],cur));

    while(!pq.empty())
    {
        u=pq.top().second;
        pq.pop();

        for(auto x: V[u])
        {
            v=x.first;
            k=x.second;

            if(dis[v]>(dis[u]+k))
            {
                dis[v]=dis[u]+k;
                pq.push(make_pair(dis[v],v));
            }
        }
    }
}
*/


int main()
{
    boost();

    ll i,j,k,n,c=0,d=0,t,x,y;
    ll l,r,ans,h,f,z,m,u,v,q;

    cin>>n>>m>>q;

    for(i=0;i<=n;i++)
    {
        for(j=0;j<=n;j++)
        {
            if(i==j)
            {
                dis[i][j]=0;
            }

            else
            dis[i][j]=LLONG_MAX;
        }
    }

    for(i=1;i<=m;i++)
    {
        cin>>x>>y>>z;
        V[x].push_back(y);
        V[y].push_back(x);
        dis[x][y]=min(z,dis[x][y]);
        dis[y][x]=min(z,dis[y][x]);
    }

    for(k=1;k<=n;k++)
    {
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=n;j++)
            {
                if((dis[i][k]!=LLONG_MAX)&&(dis[k][j]!=LLONG_MAX))
                {
                    if(dis[i][j]>dis[i][k]+dis[k][j])
                    {
                        dis[i][j]=dis[i][k]+dis[k][j];
                    }
                }
            }
        }
    }


    while(q--)
    {
        cin>>x>>y;

        if(dis[x][y]==LLONG_MAX)
        {
            cout<<-1<<endl;
        }

        else
        {
            cout<<dis[x][y]<<endl;
        }
    }

return 0;
}
