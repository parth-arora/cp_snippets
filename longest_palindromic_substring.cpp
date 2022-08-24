//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx,avx2,fma")
//#pragma GCC optimization ("unroll-loops")
 
#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pll;
typedef vector<ll> vl;
#define pb push_back
#define MAXN 200005
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


int main()
{
    boost();
    // s contains the required substring and ans contains the max length of the substring

    ll i,t,n,q,l,r,ans,mid,c=0,j,k,z,tc;
    ll h,m,u,mm,w,mx,x,y,l1,r1,d=0,mask;
    ld f,f1;

    string s,S;


    cin>>S;
    s="";

        n=S.size();
        l1=0;
        r1=0;
        ans=1;
        
        ll dp[n+1][n+1];
        
        for(i=0;i<=n;i++)
        {
            for(j=0;j<=n;j++)
            {
                dp[i][j]=0;
            }
        }
        
        for(l=1;l<=n;l++)
        {
            for(i=0;i<n-l+1;i++)
            {
                j=i+l-1;
                
                if(i==j)
                {
                    dp[i][i]++;
                }
                
                else if(j==(i+1))
                {
                    if(S[i]==S[j])
                    {
                        dp[i][j]++;
                    }
                }
                
                else
                {
                    if((dp[i+1][j-1]>0)&&(S[i]==S[j]))
                    {
                        dp[i][j]++;
                    }
                }
                
                if(dp[i][j]>0)
                {
                    if(l>ans)
                    {
                        ans=l;
                        l1=i;
                        r1=j;
                    }
                }
            }
        }
        
        for(i=l1;i<=r1;i++)
        {
            s+=S[i];
        }

        cout<<s<<endl;

    }