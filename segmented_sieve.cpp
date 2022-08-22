#include <bits/stdc++.h>
using namespace std;
typedef long long  ll;
typedef long double ld;
#define pb push_back
#define MAXN 1000005
#define MAXN1 105
#define INF (ll)1e18
#define Mod 1000000007 
//#define mod 998244353
#define endl '\n'
#define level 20
ll cc=0;
 
 
void boost()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
}


//https://www.codechef.com/problems/SHA2102
ll spf[MAXN1],a[MAXN],a1[MAXN];

void sieve() 
{ 
    ll i,j;
    
    spf[1]=0;
    spf[0]=1;
    
    for(i=2; i<MAXN1; i++) 
        spf[i] = i; 

    for(i=2; i*i<MAXN1; i++) 
    { 
        if (spf[i] == i) 
        { 
            
            for (j=i*i; j<MAXN1; j+=i) 
            {

                if (spf[j]==j) 
                {
                    spf[j] = i; 
                }
            }
        } 
    } 
}
 
int main()
{
    boost();
    
    ll i,j,k,n,t,c=0,l,r,v,x,y;
    ll ans,h,z,m,u,q,mm,w,mx,d;
    ld f;
    
    sieve();
    
    cin>>t;
    
    while(t--)
    {
        cin>>l>>r;
        
        c=0;
        ans=0;
        n=r-l+1;
        
        for(i=0;i<n;i++)
        {
            a1[i]=0;
            a[i]=i+l;
        }
        
     
        for(i=2;i*i<=r;i++)
        {
            k=((l+i-1)/i*i);
            
            z=max(i*i,k);
            
            for(j=z;j<=r;j+=i)
            {
                y=a[j-l];
                c=0;
                
                while((y%i)==0)
                {
                    y=y/i;
                    c++;
                }
                
                a1[j-l]+=c;
                a[j-l]=y;
            }
        }
        
        for(i=0;i<n;i++)
        {
            if(a[i]>1)
            {
                a1[i]++;
            }
            
            c=a1[i];
            
            if(spf[c]==c)
            {
                ans++;
            }
            
        }
        
        cout<<ans<<endl;
        
    }
 
return 0;
}