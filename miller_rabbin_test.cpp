
#include <bits/stdc++.h>
using namespace std;
typedef long long  ll;
typedef long double ld;
#define pb push_back
#define MAXN 100005
#define INF (ll)1e18
#define Mod 1000000007 
//#define mod 998244353
#define endl '\n'
#define level 20
ll cc=0;

#include <boost/multiprecision/cpp_int.hpp> 
using namespace boost::multiprecision; 

static mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
///remember to change boost to bost and change mod to Mod
 
void bost()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
}

bool isprime(ll n)
{
    if(n<2)
        return false;
    for(ll x:{2,3,5,7,11,13,17,19,23,29,31,37})
    {
        if(n==x)
            return true;
        bool flag=true;
        ll r=1;
        ll t=1;
        while(r<=((n-1)>>__builtin_ctzll(n-1)))
        {
            if(r&((n-1)>>__builtin_ctzll(n-1)))
                t=((__int128)t*x)%n;
            x=((__int128)x*x)%n;
            r<<=1;
        }

        if(t==1||t==n-1)
            flag=false;
        for(r=0;r<__builtin_ctzll(n-1);r++)
        {
            t=((__int128)t*t)%n;
            if(t==n-1)
                flag=false;
        }
        if(flag)
            return false;
    }
    return true;
}


int main()
{
    bost();
    
    ll i,j,k,n,t,c=0,l,r,v,x,y;
    ll ans,h,z,m,u,q,mm,w,mx;
    ld f;
    
    if(isprime(7))
    cout<<1<<endl;
    
    else
    cout<<0<<endl;


return 0;
}
 