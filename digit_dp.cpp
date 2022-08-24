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
#define MAXN 180
const ll N=18;
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

ll dp[N][MAXN][2];

ll solve(ll idx,ll sum,ll tight,string &s)
{
    ll i,j,k,l=0,r=0;
    
    if(idx==-1)
    {
        return sum;
    }
    
    if(dp[idx][sum][tight]!=-1&&tight!=1)
    return dp[idx][sum][tight];
    
    if(tight==1)
    {
        k=s[idx]-'0';
    }
    
    else
    k=9;
    
    for(i=0;i<=k;i++)
    {
        l=0;
        
        if(((s[idx]-'0')==i)&&tight==1)
        l++;
        
        r+=solve(idx-1,sum+i,l,s);
    }
    
    dp[idx][sum][tight]=r;
    
    return r;
    
}

int main()
{
  boost();
   
  ll i,t,q,l,r,ans,mid,c=0,j,z,tc,n,k;
  ll h,m,u,mm,w,x,y,l1,r1,d=0,mask,v,mx;
  ld f,f1;
  
  cin>>t;
  
  while(t--)
  {
      memset(dp,-1,sizeof(dp));
      
      cin>>l>>r;
      string s;
      
      s=to_string(r);
      n=sze(s);
      
      reverse(all(s));
      
       ans=solve(n-1,0,1,s);
       memset(dp,-1,sizeof(dp));
       
       if(l>0)
       {
       s=to_string(l-1);
       n=sze(s);
       reverse(all(s));
       ans-=solve(n-1,0,1,s);
       }
       
       cout<<ans<<endl;
      
  }

   
   
return 0;
}