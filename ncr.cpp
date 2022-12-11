#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define MAXN 100005
#define INF (ll)1e18
#define mod 1000000007 
//#define mod 998244353
#define endl '\n'
ll cc=0;

void boost()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

ll fac[MAXN];

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

ll ncr(ll n,ll r)
{
    if(r>n)
    return 0;
    
    if(r == 0 || r == n)
    return 1;
    
    return ((((fac[n] * modinv(fac[r]))%mod) *modinv(fac[n-r]))%mod);
}

void init()
{
    fac[0]=1;
    ll i;
    
     for(i=1;i<MAXN;i++)
    {
        fac[i]=fac[i-1]*i;
        fac[i]=fac[i]%mod;
    }
}



int main()
{
    boost();
    init();
 
    ll i,j,k,n,t,x,y,c=0,l,r,d=0;
    ll ans,h,z,m,u,q,mm,w,mx;
    ld f,f1;


return 0;
}
