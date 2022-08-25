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

//https://cses.fi/problemset/task/2420

ll seg[4*MAXN][2];
ll pw[MAXN];
ll inv[MAXN];

const ll p=31;

ll sum(ll v,ll tl,ll tr,ll l,ll r,ll id)
{
    if(l>r)
    return 0;
    
    if(l==tl&&r==tr)
    return seg[v][id];
    
    else
    {
        ll tm=(tl+tr)/2;
        ll l1=sum(2*v,tl,tm,l,min(r,tm),id);
        ll r1=sum(2*v+1,tm+1,tr,max(l,tm+1),r,id);
        l1+=r1;
        l1%=mod;
        
        return l1;
    }
}

void update(ll v,ll tl,ll tr,ll val,ll pos,ll id)
{
    if(tl==tr)
    seg[v][id]=val;
    
    else
    {
        ll tm=(tl+tr)/2;
        
        if(pos<=tm)
        update(2*v,tl,tm,val,pos,id);
        
        else
        update(2*v+1,tm+1,tr,val,pos,id);
        
        seg[v][id]=seg[2*v][id]+seg[2*v+1][id];
        seg[v][id]%=mod;
    }
}



ll power(ll x,ll y)
{
    ll res=1;
    x=x%mod;

    while(y>0)
    {
        if(y&1LL)
        {
            res=res*x;
            res=res%mod;
        }

        y=y>>1LL;

            x=x*x;
            x=x%mod;
    }

    return res;
}

ll modinv(ll n)
{
    return power(n,mod-2);
}

void init()
{
    pw[0]=1;
    inv[0]=1;
    
    for(ll i=1;i<MAXN;i++)
    {
        pw[i]=pw[i-1]*p;
        pw[i]%=mod;
        inv[i]=modinv(pw[i]);
    }
}


int main()
{
 boost();
 init();
  
 ll i,t,q,l,r,ans,mid,c=0,j,z,tc,n,k;
 ll h,m,u,mm,w,x,y,l1,r1,d=0,mask,v,mx;
 ld f,f1;
 
 string s;
 char ch;
 
 cin>>n>>q;
 
 cin>>s;
 
 for(i=0;i<n;i++)
 {
     l=s[i]-'a'+1;
     z=pw[i]*l;
     z%=mod;
     
     update(1,1,n,z,i+1,0);
 }
 
 reverse(all(s));
 
 for(i=0;i<n;i++)
 {
     l=s[i]-'a'+1;
     z=pw[i]*l;
     z%=mod;
     
     update(1,1,n,z,i+1,1);
     
 }
 
 while(q--)
 {
     cin>>x;
     
     if(x==1)
     {
         cin>>l>>ch;
         l--;
         
         z=ch-'a'+1;
         z*=pw[l];
         z%=mod;
         update(1,1,n,z,l+1,0);
         
         l1=n-1-l;
         z=ch-'a'+1;
         z*=pw[l1];
         update(1,1,n,z,l1+1,1);
     }
     
     else
     {
         cin>>l>>r;
         l--;
         r--;
         z=sum(1,1,n,l+1,r+1,0);
         z*=inv[l];
         z%=mod;
         
         l1=n-1-l;
         r1=n-1-r;
         y=sum(1,1,n,r1+1,l1+1,1);
         y*=inv[r1];
         y%=mod;
         
         if(z==y)
         cout<<"YES"<<endl;
         
         else
         cout<<"NO"<<endl;
         
     }
 }


  
  
return 0;
}