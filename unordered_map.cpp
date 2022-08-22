#include <bits/stdc++.h>
using namespace std;
typedef long long  ll;
typedef long double ld;
#define pb push_back
#define MAXN 100005
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

 
//use from here
 
//.reserve(1e6);
//.max_load_factor(.25);
 
// Attribution: https://codeforces.com/blog/entry/62393
 
struct custom_hash 
{
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
 
    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

typedef unordered_map<ll,ll,custom_hash> safe_map;

safe_map mp;


int main()
{
    boost();
    
    ll i,j,k,n,t,c=0,l,r,x,y;
    ll ans,h,z,m,u,q,mm,w,mx,d;
    ld f;
    cin>>t;
    
    safe_map mp;
    
    while(t--)
    {
        
    }

    
return 0;
}
 