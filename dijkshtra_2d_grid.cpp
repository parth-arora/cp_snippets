//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx,avx2,fma")
//#pragma GCC optimization ("unroll-loops")
//u can always think of Binary Search to find the minimum answer...........

 
#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pll;
typedef vector<ll> vl;
typedef vector<pll> vpl;
#define pb push_back
#define MAXN 1005
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
ll timer,cc1,cc,n,m;

void boost()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
}

ll dx[] = {-1,0,1,0};
ll dy[] = {0,1,0,-1};

ll a[MAXN][MAXN];
ll dis[MAXN][MAXN];
ll dis1[MAXN][MAXN];
ll vis[MAXN][MAXN];

priority_queue<pair<ll,pll>,vector<pair<ll,pll>>,greater<pair<ll,pll>>> pq;



bool check(ll x,ll y)
{
    if(x<0||y<0||x==n||y==m)
    return false;
 
    if(vis[x][y]==1)
    return false;
    
 
    return true;
}

void bfs(ll x,ll y)
{
    ll k,j,z,i;
    
    dis[x][y]=a[x][y];
    pq.push(mkp(dis[x][y],mkp(x,y)));
 
    while(!pq.empty())
    {
        auto p=pq.top();
        pq.pop();
        j=p.se.fi;
        k=p.se.se;
        
        if(vis[j][k]==0)
        {
            vis[j][k]++;
            
        for(i=0;i<4;i++)
        {
            if(check(j+dx[i],k+dy[i]))
            {
                z=dis[j][k]+a[j+dx[i]][k+dy[i]];
                
                if(dis[j+dx[i]][k+dy[i]]>z)
                {
                    dis[j+dx[i]][k+dy[i]]=z;
                    pq.push(mkp(z,mkp(j+dx[i],k+dy[i])));
                }
            }
 
        }
        
        }
    }
 
}

void bfs1(ll x,ll y)
{
    ll k,j,z,i;
    
    dis1[x][y]=a[x][y];
    pq.push(mkp(dis1[x][y],mkp(x,y)));
 
    while(!pq.empty())
    {
        auto p=pq.top();
        pq.pop();
        j=p.se.fi;
        k=p.se.se;
        
        if(vis[j][k]==0)
        {
            vis[j][k]++;
            
        for(i=0;i<4;i++)
        {
            if(check(j+dx[i],k+dy[i]))
            {
                z=dis1[j][k]+a[j+dx[i]][k+dy[i]];
                
                if(dis1[j+dx[i]][k+dy[i]]>z)
                {
                    dis1[j+dx[i]][k+dy[i]]=z;
                    pq.push(mkp(z,mkp(j+dx[i],k+dy[i])));
                }
            }
 
        }
        
        }
    }
 
}

int main()
{
  boost();
   
  ll i,t,q,l,r,ans,mid,c=0,j,z,tc,k;
  ll h,u,mm,w,x,y,l1,r1,d=0,mask,v,mx;
  ld f,f1;
  
  cin>>t;
  
  while(t--)
  {
      cin>>n>>m>>w>>k;
      
      for(i=0;i<n;i++)
      {
          for(j=0;j<m;j++)
          {
              cin>>a[i][j];
              vis[i][j]=0;
              dis[i][j]=INF;
              dis1[i][j]=INF;
          }
      }
      
      bfs(0,0);
      
      for(i=0;i<n;i++)
      {
          for(j=0;j<m;j++)
          vis[i][j]=0;
      }
      
      bfs1(n-1,m-1);
      l=INF;
      r=INF;
      ans=dis[n-1][m-1];
      
      while(k--)
      {
          cin>>x>>y;
          l=min(dis[x][y],l);
          r=min(dis1[x][y],r);
      }
      
      ans=min(ans,l+r+w);
      
      cout<<ans<<endl;
  }


   
   
return 0;
}