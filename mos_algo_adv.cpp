#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization ("unroll-loops")
//u can always think of Binary Search to find the minimum answer...........

 
#include <bits/stdc++.h>
using namespace std;
 
typedef int ll;
typedef long double ld;
typedef pair<ll,ll> pll;
typedef vector<ll> vl;
typedef vector<pll> vpl;
#define pb push_back
#define MAXN 100005
const ll N=700;
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

ll cnt[MAXN],b[MAXN];
vl V[MAXN];

int64_t gilbertOrder(int x, int y, int pow, int rotate) {
    if (pow == 0) {
        return 0;
    }
    int hpow = 1 << (pow-1);
    int seg = (x < hpow) ? (
        (y < hpow) ? 0 : 3
    ) : (
        (y < hpow) ? 1 : 2
    );
    seg = (seg + rotate) & 3;
    const int rotateDelta[4] = {3, 0, 0, 1};
    int nx = x & (x ^ hpow), ny = y & (y ^ hpow);
    int nrot = (rotate + rotateDelta[seg]) & 3;
    int64_t subSquareSize = int64_t(1) << (2*pow - 2);
    int64_t ans = seg * subSquareSize;
    int64_t add = gilbertOrder(nx, ny, pow-1, nrot);
    ans += (seg == 1 || seg == 2) ? add : (subSquareSize - add - 1);
    return ans;
}

struct Query{
    int l, r, idx; //inclusive
    int64_t order;
    Query(){}
    Query(int a, int b, int c){
        l = a, r = b, idx = c; 
        order = gilbertOrder(l, r, 21, 0);
    }
    bool operator<(const Query& other) const {
        return order < other.order;
    }
};

void sieve()
{
    for(ll i=1;i<MAXN;i++)
    {
        for(ll j=i;j<MAXN;j+=i)
        {
            V[j].pb(i);
        }
    }
}

void rem(ll cur)
{
    
    ll l;
    
    for(auto x : V[cur])
    {
        
    cnt[x]--;
    
    if(cnt[x]==1)
    {
        l=(x/N);
        b[l]--;
    }
    
    }
    
}

void add(ll cur)
{
    ll l;
    
    for(auto x : V[cur])
    {
        
    cnt[x]++;
    
    if(cnt[x]==2)
    {
        l=(x/N);
        b[l]++;
    }
    
    }
}

int main()
{
 boost();
 sieve();
  
 ll i,t,q,l,r,ans,mid,c=0,j,z,tc,n,k;
 ll h,m,u,mm,w,x,y,l1,r1,d=0,mask,v,mx;
 ld f,f1;
 
 cin>>t;
 
 
 while(t--)
 {
     cin>>n>>q;
     mx=0;
     ll a[n+1];
     
     for(i=1;i<=n;i++)
     {
         cin>>a[i];
         mx=max(mx,a[i]);
     }
     
     vector<Query> g(q);
     ll as[q];
     
     for(i=0;i<q;i++)
     {
         cin>>l>>r;
         g[i] = Query(l, r, i);
     }
     
     
     sort(all(g));
     
     l=1;
     r=0;
     
      for(auto it : g)
      {
          while(it.l>l)
          {
              rem(a[l]);
              l++;
          }
          
          while(it.l<l)
          {
              l--;
              add(a[l]);
          }
          
          while(it.r>r)
          {
              r++;
              add(a[r]);
          }
          
          while(r>it.r)
          {
              rem(a[r]);
              r--;
          }
          
          h=(mx/N);
          ans=1;
          
          for(i=h;i>=0;i--)
          {
              if(b[i]>0)
              {
                  l1=i*N;
                  for(j=min(l1+N,MAXN)-1;j>=l1;j--)
                  {
                      if(cnt[j]>=2)
                      {
                          ans=j;
                          break;
                      }
                  }
                  
                  break;
              }
          }
          
          as[it.idx]=ans;
          
      }
      
      for(i=l;i<=r;i++)
      {
          rem(a[i]);
      }
      
      for(i=0;i<q;i++)
      cout<<as[i]<<endl;
 }


  
  
return 0;
}