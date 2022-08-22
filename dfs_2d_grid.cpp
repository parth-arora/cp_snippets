#include <bits/stdc++.h>
using namespace std;
typedef long long  ll;
typedef long double ld;
#define MAXN 1005
vector <ll> V[MAXN];
ll dist[MAXN],parent[MAXN];
vector<ll> v;
ll vis[MAXN][MAXN],a[MAXN][MAXN];
ll n,m;

void boost()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
}

ll dx[] = {-1,0,1,0};
ll dy[] = {0,1,0,-1};

bool check(ll x,ll y)
{
    if(x<0||y<0||x==n||y==m)
    return false;

    if(vis[x][y]==1)
    return false;

    if(a[x][y]==0)
    return false;

    return true;
}

void dfs(ll x,ll y)
{
   ll i,j,z;

   vis[x][y]++;

   for(i=0;i<4;i++)
   {
       if(check(x+dx[i],y+dy[i]))
       {
           dfs(x+dx[i],y+dy[i]);
       }
   }

}

int main()
{
    boost();

    ll i,j,k,c=0,d=0,t,x,y;
    ll l,r,ans,h,f,z;

    cin>>n>>m;
    string s[n];

    for(i=0;i<n;i++)
    cin>>s[i];

    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            if(s[i][j]=='.')
            {
                a[i][j]=1;
            }

            else
            a[i][j]=0;
        }
    }

    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        vis[i][j]=0;
    }

    c=0;

    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            if((vis[i][j]==0)&&(a[i][j]==1))
            {
                c++;
                dfs(i,j);
            }
        }
    }

    cout<<c<<endl;

return 0;
}

