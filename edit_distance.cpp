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
#define MAXN 5005
const ll N=32;
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

ll dp[MAXN][MAXN];
    
  ll solve(ll i,ll j,string &s1,string &s2)
    {
        int ans;
        
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        
        if(i==0)
        {
            dp[i][j]=j;
            return j;
        }
        
        if(j==0)
        {
            dp[i][j]=i;
            return i;
        }
        
        
        
        if(s1[i-1]==s2[j-1])
        {
            ans=solve(i-1,j-1,s1,s2);
        }
        
        else
        {
            ans=min(solve(i-1,j-1,s1,s2),min(solve(i,j-1,s1,s2),solve(i-1,j,s1,s2)));
            ans++;
        }
        
        dp[i][j]=ans;
        return ans;
        
        
    }

int main()
{
  boost();
   
  ll i,t,q,l,r,ans,mid,c=0,j,z,tc,n,k;
  ll h,m,u,mm,w,x,y,l1,r1,d=0,mask,v,mx;
  ld f,f1;
  
  string s1,s2;
  
  cin>>s1;
  cin>>s2;
  n=s1.size();
  m=s2.size();
  memset(dp,-1,sizeof(dp));
  
  ans=solve(n,m,s1,s2);
  
  memset(dp,-1,sizeof(dp));
  ans=min(ans,solve(m,n,s2,s1));
  
  cout<<ans<<endl;


   
   
return 0;
}