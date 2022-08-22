#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define MAXN 1000005
#define INF (ll)1e18
#define mod 1000000007 
//#define mod 998244353
#define endl '\n'
ll cc=0;

ll spf[MAXN]; 


void sieve() 
{ 
    ll i,j;
    
    spf[1]=0;
    
    for(i=2; i<MAXN; i++) 
        spf[i] = i; 

    for(i=2; i*i<MAXN; i++) 
    { 
        if (spf[i] == i) 
        { 
            
            for (j=i*i; j<MAXN; j+=i) 
            {

                if (spf[j]==j) 
                {
                    spf[j] = i; 
                }
            }
        } 
    } 
}


void boost()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}


int main()
{
    boost();
 
    ll i,j,k,n,t,x,y,c=0,l,r,d=0;
    ll ans,h,z,m,u,q,mm,w,mx,num;
    ld f;
    
    sieve();
    
    
    
return 0;
}