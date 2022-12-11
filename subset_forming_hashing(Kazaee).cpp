#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization ("unroll-loops")
//u can always think of Binary Search to find the minimum answer...........
//Editorial

//https://codeforces.com/contest/1746/problem/F

 
#include <bits/stdc++.h>
using namespace std;
 
typedef int ll;
typedef long double ld;
typedef pair<ll,ll> pll;
typedef vector<ll> vl;
typedef vector<pll> vpl;
#define pb push_back
#define MAXN 300005
const ll N=30;
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

vector<bool> b[N];

void boost()
{
 ios_base::sync_with_stdio(false);
 cin.tie(NULL);
}

ll tree[MAXN][N];


ll sum(ll x,ll id)
{
    ll sum=0;
    
    while(x>0)
    {
        sum+=tree[x][id];
        x-=(x&(-x));
    }
    
    return sum;
}

void update(ll x,ll id,ll val)
{
    while(x<MAXN)
    {
        tree[x][id]+=val;
        x+=(x&(-x));
    }
}

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
ll randnum(ll l,ll r)
{
    return uniform_int_distribution<ll>(l, r)(rng);
}

struct custom_hash 
{
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
 
    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

typedef unordered_map<ll,ll,custom_hash> safe_map;

safe_map mp;

int main()
{
 boost();
  
 ll i,t,q,l,r,ans,mid,c=0,j,z,tc,n,k;
 ll h,m,u,mm,w,x,y,l1,r1,d=0,mask,v,mx;
 ld f,f1;
 
 cin>>n>>q;
 ll a[n+1];
 
 
 c=0;
 
 for(i=1;i<=n;i++)
 {
     
 cin>>a[i];
 
 if(mp[a[i]]==0)
 mp[a[i]]=c++;
 
 }
 
 vl V[q];
 r1=0;
 
 while(r1<q)
 {
     cin>>y;
     V[r1].pb(y);
     
     if(y==1)
     {
         cin>>l>>x;
         
         if(mp[x]==0)
         mp[x]=c++; 
         
         V[r1].pb(l);
         V[r1].pb(x);
     }
     
     else
     {
         cin>>l>>r>>k;
         V[r1].pb(l);
         V[r1].pb(r);
         V[r1].pb(k);
     }
     
     r1++;
     
 }
 
  
 for(i=0;i<N;i++)
 {
     b[i].resize(c+1,false);
 }
 
 
 for(i=0;i<N;i++)
 {
     z=r1;
     
     for(j=1;j<=c;j++)
     {
         l=randnum(1,mod);
         
         if(l&1)
         b[i][j]=true;
     }
     
     for(j=1;j<=n;j++)
     {
         l=mp[a[j]];
         
         if(b[i][l])
         update(j,i,1);
     }
     
 }
 
 for(i=0;i<q;i++)
 {
     if(sze(V[i])==3)
     {
         l=V[i][1];
         x=V[i][2];
         
         for(j=0;j<N;j++)
         {
             z=mp[a[l]];
             
             if(b[j][z])
             {
                 update(l,j,-1);
             }
             
             z=mp[x];
             
             if(b[j][z])
             {
                 update(l,j,1);
             }
         }
         
         a[l]=x;
     }
     
     else
     {
         l=V[i][1];
         r=V[i][2];
         k=V[i][3];
         c=0;
         
         if((r-l+1)%k!=0)
         {
             cout<<"NO"<<endl;
             continue;
         }
         
         for(j=0;j<N;j++)
         {
             z=sum(r,j)-sum(l-1,j);
             
             if((z%k)!=0)
             {
                 c++;
                 break;
             }
         }
         
         if(c>0)
         cout<<"NO"<<endl;
         
         else
         cout<<"YES"<<endl;
     }
 }
 
 


  
  
return 0;
}