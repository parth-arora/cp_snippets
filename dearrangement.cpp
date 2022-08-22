//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx,avx2,fma")
//#pragma GCC optimization ("unroll-loops")
 
#include <bits/stdc++.h>
using namespace std;
 
typedef long long  ll;
typedef long double ld;
typedef pair<ll,ll> pll;
typedef vector<ll> vl;
#define pb push_back
#define MAXN 1005
const ll N=31;
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
ll timer,cc,cc1;


void boost()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

ll ncr[MAXN][N];

void compute()
{
    ll i,j;

for(i=0;i<MAXN;i++)
{
    
    for(j=0;j<N;j++)
    {
        
        if(j==0||i==j)
        {
            ncr[i][j]=1;
        }
        
        
        else if(j>i)
        {
            ncr[i][j]=0;
        }
        
        else
        ncr[i][j]=ncr[i-1][j-1]+ncr[i-1][j];
    }
    
}

}

int main()
{
    boost();
    compute();
    
    ll i,t,n,q,l,r,ans,mid,c=0,j,k,z,tc;
    ll h,m,u,mm,w,mx,x,y,l1,r1,d=0,mask;
    ld f,f1;
    
    
    ll a[5];
    
    a[0]=0;
    a[1]=0;
    a[2]=1;
    
    
    for(i=3;i<5;i++)
    {
        a[i]=(i-1)*(a[i-1]+a[i-2]);
    }
    
    cin>>n>>k;
    ans=1;
    
    for(i=0;i<=k;i++)
    {
        z=ncr[n][i]*a[i];
        ans+=z;
    }
    
    cout<<ans<<endl;
    
    

return 0;
}