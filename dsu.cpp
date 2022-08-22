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
ll cc=0,cc1=0;

 
void boost()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}


ll par[MAXN],sz[MAXN];

 
ll fp(ll i)
{
    if(par[par[i]]!=par[i])
    par[i]=fp(par[i]);
    
    return par[i];
}
 
void join(ll a,ll b)
{
    ll j,k;
    
    j=fp(a);
    k=fp(b);
    
    if(j==k)
    return;
    
    
    if(sz[j]>=sz[k])
    {
         sz[j]+=sz[k];
         par[k]=j;
    }
    
    else
    {
         sz[k]+=sz[j];
         par[j]=k;
    }
    
    return;
}


int main()
{
    boost();
 
    ll i,t,n,q,d=0,l,r,ans,mid,c,z,j,k;
    ll h,m,u,mm,w,mx,x,y;
    ld f;
    
    for(i=0;i<=n;i++)
    {
        par[i]=i;
        sz[i]=1;
    }
    
    l=fp(j);
    r=fp(k);
    
    if(l!=r)
    {
        join(j,k);
    }

return 0;
}