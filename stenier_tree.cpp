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
ll timer,cc1,cc;

void boost()
{
 ios_base::sync_with_stdio(false);
 cin.tie(NULL);
}

//https://atcoder.jp/contests/abc364/tasks/abc364_g
//https://www.youtube.com/watch?v=BG4vAoV5kWw&t=100s

// just for reference of another question
// in bipartite graph according to konigs theorem
// 1. The maximum independent set is a complement of the minimum vertex cover.
// 2. minimum vertex cover = maximum bipartite matching

int main()
{
 boost();
  
 ll i,t,q,l,r,ans,mid,c=0,j,z,tc,n,k;
 ll h,m,u,mm,w,x,y,l1,r1,d=0,mask,v,mx;
 ld f,f1;
 
 cin>>n>>m>>k;
 vpl V[n];
 ll dp[n][(1LL<<k)];
 ll vis[n];
 
 for(i=0;i<m;i++)
 {
    cin>>x>>y>>z;
    x--;
    y--;
    V[x].pb(mkp(y,z));
    V[y].pb(mkp(x,z));
 }
 
 k--;
 
 for(i=0;i<n;i++)
 {
    for(j=0;j<(1LL<<k);j++)
    dp[i][j]=INF;
 }
 
 for(i=0;i<k;i++)
 dp[i][(1LL<<i)]=0;
 
 priority_queue<pll,vpl,greater<pll>> pq;
 
 for(mask=0;mask<(1LL<<k);mask++)
 {
    for(t=mask;t>0;t=(t-1)&mask)
    {
       for(i=0;i<n;i++)
       {
          dp[i][mask]=min(dp[i][mask],dp[i][t]+dp[i][mask^t]);
       }
    }
    
    for(i=0;i<n;i++)
    {
       if(dp[i][mask]!=INF)
         pq.push(mkp(dp[i][mask],i));
          
       vis[i]=0;
    }
       
       while(!pq.empty())
       {
          auto p=pq.top();
          pq.pop();
          
          z=p.se;
          
          if(vis[z]>0)
          continue;
          
          vis[z]++;
          
          for(auto x :V[z])
          {
             y=x.fi;
             
             if((dp[y][mask]>dp[z][mask]+x.se)&&(vis[y]==0))
             {
                dp[y][mask]=dp[z][mask]+x.se;
                pq.push(mkp(dp[y][mask],y));
             }
          }
       }
 }
 
 k++;
 
 for(i=k-1;i<n;i++)
 cout<<dp[i][(1LL<<(k-1))-1]<<endl;


  
  
return 0;
}
