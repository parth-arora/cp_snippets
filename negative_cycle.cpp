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

int main()
{
 boost();
  
 ll i,t,q,l,r,ans,mid,c=0,j,z,tc,n,k;
 ll h,m,u,mm,w,x,y,l1,r1,d=0,mask,v,mx;
 ld f,f1;
 
 cin>>n>>m;
 vector<pair<pll,ll>> g;
 
 for(i=0;i<m;i++)
 {
    cin>>x>>y>>z;
    g.pb(mkp(mkp(x,y),z));
 }
 
 ll dis[n+1];
 memset(dis,0,sizeof(dis));
 
 ll par[n+1];
 memset(par,-1,sizeof(par));
 
 vl g1;
 for(i=0;i<n;i++)
 {
    h=-1;
    for(j=0;j<m;j++)
    {
       x=g[j].fi.fi;
       y=g[j].fi.se;
       z=g[j].se;
       
       if(dis[y]>dis[x]+z)
       {
          dis[y]=max(-INF,dis[x]+z);
          par[y]=x;
          h=y;
       }
    }
 }
 
 if(h==-1)
 cout<<"NO"<<endl;
 
 else
 {
    cout<<"YES"<<endl;
    
    for(i=0;i<n;i++)
    h=par[h];
    
    for (v = h;; v = par[v]) 
    {
       g1.pb(v);
       if(v==h&&sze(g1)>1)
       break;
    }
    
    reverse(all(g1));
    
    for(auto x :g1)
    cout<<x<<" ";
    
    cout<<endl;
   
 }
 

return 0;
}
