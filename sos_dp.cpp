//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx,avx2,fma")
//#pragma GCC optimization ("unroll-loops")
//u can always think of Binary Search to find the minimum answer...........
 
 
 
#include <bits/stdc++.h>
using namespace std;
 
typedef int  ll;
typedef long double ld;
typedef pair<ll,ll> pll;
typedef vector<ll> vl;
typedef vector<pll> vpl;
#define pb push_back
#define MAXN 1000005
const ll N=20;
#define INF (ll)9e18
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

ll dp[1<<N],dp1[1<<N];

void boost()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

 
int main()
{
    boost();
    
    ll i,t,q,l,r,ans,mid,c=0,j,z,tc,n,k;
    ll h,m,u,mm,w,x,y,l1,r1,d=0,mask,v,mx;
    ld f,f1;
    
    cin>>n;
    ll a[n],b[n];
    
    for(i=0;i<n;i++)
    {
        cin>>a[i];
        dp[a[i]]++;
        c=0;
        
        for(j=0;j<N;j++)
        {
            if((1LL<<j)&a[i])
            {
                continue;
            }
            
            else
            {
                c+=(1LL<<j);
            }
        }
        
        b[i]=c;
        
        dp1[b[i]]++;
    }
    
    for(i=0;i<N;i++)
    {
        for(mask=0;mask<(1LL<<N);mask++)
        {
            l=(1LL<<i);
            
            if(l&mask)
            {
                dp[mask]+=dp[mask^l];
            }
        }
    }
    
    for(i=0;i<N;i++)
    {
        for(mask=0;mask<(1LL<<N);mask++)
        {
            l=(1LL<<i);
            
            if(l&mask)
            {
                dp1[mask]+=dp1[mask^l];
            }
        }
    }
    
    
return 0;
}