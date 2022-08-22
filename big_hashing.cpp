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
//#define Mod 1000000007
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


constexpr uint64_t Mod = (1ull<<61) - 1;
uint64_t mul(uint64_t a, uint64_t b)
{
	uint64_t l1 = (uint32_t)a, h1 = a>>32, l2 = (uint32_t)b, h2 = b>>32;
	uint64_t l = l1*l2, m = l1*h2 + l2*h1, h = h1*h2;
	uint64_t ret = (l&Mod) + (l>>61) + (h << 3) + (m >> 29) + (m << 35 >> 3) + 1;
	ret = (ret & Mod) + (ret>>61);
	ret = (ret & Mod) + (ret>>61);
	return ret-1;
}

ll power(ll x,ll y)
{
    ll res=1;
    x=x%Mod;

    while(y>0)
    {
        if(y&1)
        {
            res=mul(res,x);
            res=res%Mod;
        }

        y=y>>1;

            x=mul(x,x);
            x=x%Mod;
    }

    return res;
}

int main()
{
 boost();
  
 ll i,t,q,l,r,ans,mid,c=0,j,z,tc,n,k;
 ll h,m,u,mm,w,x,y,l1,r1,d=0,mask,v,mx;
 ld f,f1;
 
 cin>>n;
 ll a[n+1],b[n+1];
 ll a1[n+1],b1[n+1];
 vl g;
 r=400009;
 
 for(i=1;i<=n;i++)
 {
 cin>>a[i];
 g.pb(a[i]);
 }
 
 for(i=1;i<=n;i++)
 {
 cin>>b[i];
 g.pb(b[i]);
 }
 
 sort(all(g));
 g.erase(unique(all(g)),g.end());
 map<ll,ll> mp;
 
 for(i=1;i<=n;i++)
 {
     a[i]=lower_bound(all(g),a[i])-g.begin()+1;
     b[i]=lower_bound(all(g),b[i])-g.begin()+1;
 }
 
 memset(a1,0,sizeof(a1));
 memset(b1,0,sizeof(b1));
 
 for(i=1;i<=n;i++)
 {
     if(mp[a[i]]==0)
     {
         z=power(r,a[i]);
         z*=a[i];
         z%=Mod;
         c+=z;
         c%=Mod;
     }
     
     mp[a[i]]++;
     a1[i]=c;
 }
 
 c=0;
 clr(mp);
 
 for(i=1;i<=n;i++)
 {
     if(mp[b[i]]==0)
     {
         z=power(r,b[i]);
         z*=b[i];
         z%=Mod;
         c+=z;
         c%=Mod;
     }
     
     mp[b[i]]++;
     b1[i]=c;
 }
 
 cin>>q;
 
 while(q--)
 {
     cin>>x>>y;
     
     if(a1[x]==b1[y])
     cout<<"Yes"<<endl;
     
     else
     cout<<"No"<<endl;
 }
 

  
return 0;
}