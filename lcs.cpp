#include <bits/stdc++.h>
using namespace std;
typedef long long  ll;
typedef long double ld;
#define pb push_back
#define MAXN 200005
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


int main()
{
    boost();
 
    ll i,j,k,t,n,ans1,c=0;
    ll h,u,q,w,m,mm,ans,l,r,z,x,y;
    ld f;
    
    string s1,s2,s;
    
    cin>>s1;
    cin>>s2;
    n=s1.size();
    m=s2.size();
    
    ll dp[n+1][m+1];
    
    for(i=0;i<=n;i++)
    {
        for(j=0;j<=m;j++)
        {
            dp[i][j]=0;
        }
    
    }
    
    
    for(i=1;i<=n;i++)
    {
       for(j=1;j<=m;j++)
       {
           if(s1[i-1]==s2[j-1])
           {
               dp[i][j]=dp[i-1][j-1]+1;
           }
           
           else
           {
               dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
           }
       }
    }
    
    //cout<<dp[n][m]<<endl;
    

    i=n;
    j=m;
    s="";
    
    while(i>0&&j>0)
    {
        if(s1[i-1]==s2[j-1])
        {
            s+=s1[i-1];
            i--;
            j--;
        }
        
        else if(dp[i-1][j]>dp[i][j-1])
        {
            i--;
        }
        
        else
        {
            j--;
        }
    }
    
    reverse(s.begin(),s.end());
    
    cout<<s<<endl;
    
return 0;
}