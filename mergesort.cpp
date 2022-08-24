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

void merge(ll a[],ll l,ll r)
{
    ll mid=(l+r)/2;
    ll n=mid-l+1;
    ll m=r-mid;
    ll b1[n],b2[m];
    ll i,j,c=0;
    
    
    for(i=l;i<=mid;i++)
    {
        b1[c]=a[i];
        c++;
    }
    
    c=0;
    for(i=mid+1;i<=r;i++)
    {
        b2[c]=a[i];
        c++;
    }
    
    i=0;
    j=0;
    c=l;
    
    while(i<n&&j<m)
    {
        if(b1[i]>b2[j])
        {
           a[c]=b2[j];
           j++;
           c++;
        }
        
        else
        {
            a[c]=b1[i];
            i++;
            c++;
        }
    }
    
    while(i<n)
    {
        a[c]=b1[i];
        i++;
        c++;
    }
    
    while(j<m)
    {
        a[c]=b2[j];
        j++;
        c++;
    }
    
}

void build(ll a[],ll l,ll r)
{
    if(r==l)
    return;
    
    
    else
    {
        
    ll mid=(l+r)/2;
    
    build(a,l,mid);
    build(a,mid+1,r);
    merge(a,l,r);
    
    }
}



int main()
{
  boost();
   
  ll i,t,q,l,r,ans,mid,c=0,j,z,tc,n,k;
  ll h,m,u,mm,w,x,y,l1,r1,d=0,mask,v,mx;
  ld f,f1;
  
  cin>>n;
  ll a[n];
  
  for(i=0;i<n;i++)
  cin>>a[i];
  
  build(a,0,n-1);
  
  for(i=0;i<n;i++)
  cout<<a[i]<<" ";
  
  cout<<endl;


   
   
return 0;
}