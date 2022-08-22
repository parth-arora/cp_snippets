#include <bits/stdc++.h>
using namespace std;
typedef long long  ll;
typedef long double ld;
#define pb push_back
#define MAXN 10005
#define INF (ll)1e18
#define mod 1000000007 
//#define mod 998244353
#define endl '\n'
#define level 20
ll cc=0;
 
void boost()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
}

static mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

ll powM(ll x,ll y,ll m)
{
    ll ans=1,r=1;
    x%=m;
    while(r>0&&r<=y)
    {
        if(r&y)
        {
            ans*=x;
            ans%=m;
        }
        r<<=1;
        x*=x;
        x%=m;
    }
    return ans;
}


ll modI(ll a, ll m)
{
    ll m0=m,y=0,x=1;
    if(m==1) return 0;
    while(a>1)
    {
        ll q=a/m;
        ll t=m;
        m=a%m;
        a=t;
        t=y;
        y=x-q*y;
        x=t;
    }
    if(x<0) x+=m0;
    return x;
}




ll tonelli_shanks(ll x,ll p)
{
    // Outputs a y such that (y^2)%p=x, or -1 if it doesn't exist

    if(powM(x,(p-1)/2,p)==p-1) 
    return -1;

    ll q=((p-1)>>__builtin_ctzll(p-1)),s=__builtin_ctzll(p-1)-1;
    ll r=powM(x,(q+1)/2,p),t=powM(x,q,p);

    ll z;
    while(true)
    {
        z=rng()%(p-1)+1;
        if(powM(z,(p-1)/2,p)==p-1) break;
    }
    z=powM(z,q,p);

    while(t!=1)
    {
        if(powM(t,1LL<<(s-1),p)==p-1)
        {
            t=(t*((z*z)%p))%p;
            r=(r*z)%p;
        }
        z=(z*z)%p;
        s--;
    }

    return r;
}


int main()
{
    boost();
    
    ll i,j,k,n,t,c=0,l,r,v,x,y;
    ll ans,h,z,m,u,q,mm,w,mx;
    ld f;
    
    
    l=tonelli_shanks(2,7);
    
    cout<<l<<endl;
    
 
return 0;
}
 