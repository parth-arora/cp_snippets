//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx,avx2,fma")
//#pragma GCC optimization ("unroll-loops")
//u can always think of Binary Search to find the minimum answer...........

//https://codeforces.com/contest/1418/problem/G

 
#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pll;
typedef vector<ll> vl;
typedef vector<pll> vpl;
#define pb push_back
#define MAXN 500005
const ll N=60;
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

string fun(string s,ll x)
{
    ll i,l,z;
    char ch;
    
    for(i=0;i<N;i++)
    {
        l=s[i]-'0';
        z=0;
        
        if((1LL<<i)&x)
        {
            z++;
        }
        
        l+=z;
        l%=3;
        ch=l+'0';
        s[i]=ch;
    }
    
    return s;
}

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
ll randnum(ll l,ll r)
{
    return uniform_int_distribution<ll>(l, r)(rng);
}

map<string,ll> mp;

int main()
{
 boost();
  
 ll i,t,q,l,r,ans,mid,c=0,j,z,tc,n,k;
 ll h,m,u,mm,w,x,y,l1,r1,d=0,mask,v,mx;
 ld f,f1;
 
 cin>>n;
 set<ll> ss;
 ll a[n+1],b[n+1];
 ll fre[n+1];
 vl V[n+1];
 string s1[n+1];
 
 for(i=1;i<=n;i++)
 {
     while(1)
     {
         l=randnum(1,INF);
         
         if(ss.find(l)==ss.end())
         {
             a[i]=l;
             ss.insert(l);
             break;
         }
     }
     
     fre[i]=0;
 }
 
 // s stores reverse mask of modulo 3 xor
 string s="";
 
 for(i=0;i<N;i++)
 {
     s.pb('0');
 }
 
 for(i=1;i<=n;i++)
 {
     cin>>b[i];
 }
 
 l=1;
 r=0;
 
 while(r<n)
 {
     r++;
     fre[b[r]]++;
     V[b[r]].pb(r);
     s1[r]=s;
     s=fun(s,a[b[r]]);
     
     if(fre[b[r]]>3)
     {
         z=sze(V[b[r]]);
         l1=V[b[r]][z-4];
         
         while(l1>=l)
         {
             fre[b[l]]--;
             mp[s1[l]]--;
             l++;
         }
     }
     
     c+=mp[s];
     mp[s1[r]]++;
     
 }
 
 cout<<c<<endl;

 


  
  
return 0;
}