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
ll timer,cc1,cc;

void boost()
{
 ios_base::sync_with_stdio(false);
 cin.tie(NULL);
}

struct node
{
    ll x,y;
    bool ys;
}nil;

vector<node> seg[4*MAXN];
ll par[MAXN],sz[MAXN];
ll as[MAXN];
vpl his;
map<pll,vl> mp;

ll fp(ll x)
{
    if(par[x]==x)
    return x;
    
    return fp(par[x]);
}

bool join(ll x,ll y)
{
    ll l,r;
    l=fp(x);
    r=fp(y);
    
    if(l==r)
    return false;
    
    cc--;
    
    if(sz[l]>sz[r])
    swap(l,r);
    
    sz[r]+=sz[l];
    par[l]=r;
    
    his.pb(mkp(l,r));
    
    return true;
    
}

void rollback()
{
    auto p=his.back();
    his.pop_back();
    sz[p.se]-=sz[p.fi];
    par[p.fi]=p.fi;
    cc++;
}

void add(ll v,ll tl,ll tr,ll l,ll r,node p)
{
    if(l>r)
    return;
    
    if(l==tl&&r==tr)
    {
        seg[v].pb(p);
    }
    
    else
    {
    
    ll tm=(tl+tr)/2;
    
    add(2*v,tl,tm,l,min(r,tm),p);
    add(2*v+1,tm+1,tr,max(l,tm+1),r,p);
    }
    
}

void dfs(ll v,ll tl,ll tr)
{
    for(auto &x : seg[v])
    {
        x.ys=join(x.x,x.y);
    }
    
    if(tl==tr)
    {
        as[tl]=cc;
    }
    
    else
    {
    
    ll tm=(tl+tr)/2;
    
    dfs(2*v,tl,tm);
    dfs(2*v+1,tm+1,tr);
    
    }
    
    for(auto x :seg[v])
    {
        if(x.ys)
        rollback();
    }
}


int main()
{
 boost();
  
 ll i,t,q,l,r,ans,mid,c=0,j,z,tc,n,k;
 ll h,m,u,mm,w,x,y,l1,r1,d=0,mask,v,mx;
 ld f,f1;
 
 cin>>n>>m>>q;
 
 for(i=0;i<m;i++)
 {
     cin>>x>>y;
     if(x>y)
     swap(x,y);
     
     mp[mkp(x,y)].pb(1);
 }
 
 cc=n;
 
 for(i=0;i<=n;i++)
 {
     par[i]=i;
     sz[i]=1;
 }
 
 q++;
 
 for(i=2;i<=q;i++)
 {
     cin>>l>>x>>y;
     
     if(x>y)
     swap(x,y);
     
     mp[mkp(x,y)].pb(i);
    
 }
 
 for(auto it : mp)
 {
     x=it.fi.fi;
     y=it.fi.se;
     node p;
     
     p.x=x;
     p.y=y;
     
     for(i=0;i<sze(it.se);i+=2)
     {
         if(i+1==sze(it.se))
         {
             add(1,1,q,it.se[i],q,p);
         }
         
         else
         {
             add(1,1,q,it.se[i],it.se[i+1]-1,p);
         }
     }
 }
 
 dfs(1,1,q);
 
 for(i=1;i<=q;i++)
 cout<<as[i]<<" ";


  
  
return 0;
}