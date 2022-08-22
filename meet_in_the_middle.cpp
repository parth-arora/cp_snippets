//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx,avx2,fma")
//#pragma GCC optimization ("unroll-loops")
 
#include <bits/stdc++.h>
using namespace std;
 
typedef long long  ll;
typedef long double ld;
typedef pair<ll,ll> pll;
typedef vector<ll> vl;
#define pb push_back
#define MAXN 200005
const ll N=31;
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
ll timer,cc,cc1;


void boost()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

int main()
{
    boost();
    
    ll i,t,n,q,l,r,ans,mid,c=0,j,k,z,tc;
    ll h,m,u,mm,w,mx,x,y,l1,r1,d=0,mask;
    ld f,f1;
    
    cin>>n>>k;
    ll a[n];
    
    vl g,g1,g2,g3;
    
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
    
    for(i=0;i<n/2;i++)
    {
        g.pb(a[i]);
    }
    
    for(i=n/2;i<n;i++)
    {
        g1.pb(a[i]);
    }
    
    l=sze(g);
    
    for(mask=0;mask<(1LL<<l);mask++)
    {
        c=0;
        for(i=0;i<l;i++)
        {
            if((1LL<<i)&mask)
            {
               c+=g[i]; 
            }
        }
        
        g2.pb(c);
    }
    
    r=sze(g1);
    
    for(mask=0;mask<(1LL<<r);mask++)
    {
        c=0;
        for(i=0;i<r;i++)
        {
            if((1LL<<i)&mask)
            {
               c+=g1[i]; 
            }
        }
        
        g3.pb(c);
    }
    
    sort(all(g3));
    
    ans=0;
    
    for(auto x : g2)
    {
        z=k-x;
        l1=lower_bound(all(g3),z)-g3.begin();
        r1=upper_bound(all(g3),z)-g3.begin();
        
        ans+=(r1-l1);
    }
    
    cout<<ans<<endl;
    
    
return 0;
}