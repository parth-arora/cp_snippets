//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx,avx2,fma")
//#pragma GCC optimization ("unroll-loops")
//u can always think of Binary Search to find the minimum answer...........

 
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

ll t[4 *MAXN], lazy[4 *MAXN],a[MAXN];
 
void push(ll v,ll val) 
{
    lazy[v*2]+=val;
    lazy[v*2+1]+=val;
}
 
void update(ll v, ll tl, ll tr, ll l, ll r, ll val) 
{
    ll z;

     if(lazy[v]!=0)
    {
        z=lazy[v];
        lazy[v]=0;
        t[v]+=z*(tr-tl+1);
                
        if(tl!=tr)
        {
            push(v,z);
        }
    }
 
 
    if (l > r)
    {
        return;
    }
        
    if (l == tl && tr == r) 
    {
        z=(tr-tl+1)*val;
        t[v]+=z;
        
        if(tl!=tr)
        {
            push(v,val);
        }
    }
    
    else 
    {
        ll tm = (tl + tr) / 2;
        update(v*2, tl, tm, l, min(r, tm),val);
        update(v*2+1, tm+1, tr, max(l, tm+1), r,val);
        t[v] = t[v*2]+ t[v*2+1];
    }
}
 
ll sum(ll v, ll tl, ll tr, ll l, ll r) 
{
     ll z;
 
     if(lazy[v]!=0)
    {
        z=lazy[v];
        lazy[v]=0;
        t[v]+=z*(tr-tl+1);
                
        if(tl!=tr)
        {
            push(v,z);
        }
    }
 
    if (l > r)
    {
        return 0;
    }
 
 
    
    if (l <= tl && tr <= r)
    {
        return t[v];
    }
    
    
    ll tm = (tl + tr) / 2;
    
    return (sum(v*2, tl, tm, l, min(r, tm))+sum(v*2+1, tm+1, tr, max(l, tm+1), r));
}

int main()
{
    boost();
    
    ll i,t,q,l,r,ans,mid,c=0,j,z,tc,n,k;
    ll h,m,u,mm,w,x,y,l1,r1,d=0,mask,v,mx;
    ld f,f1;


    
    
return 0;
}