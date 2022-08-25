//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx,avx2,fma")
//#pragma GCC optimization ("unroll-loops")
// u can always think of Binary Search to find the minimum answer...........

 
#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pll;
typedef vector<ll> vl;
typedef vector<pll> vpl;
#define pb push_back
#define MAXN 100005
const ll N=24;
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
ll timer,cc1,cc;

void boost()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

//https://codeforces.com/contest/600/problem/E

vl V[MAXN];

ll tin[MAXN],tout[MAXN];
ll a[MAXN],b[MAXN],a1[MAXN];
ll cnt[MAXN],dp[MAXN];

void dfs(ll cur,ll prev)
{
    dp[cur]=1;
    tin[cur]=timer++;
    a1[tin[cur]]=cur;
    
    for(auto x : V[cur])
    {
        if(x!=prev)
        {
            dfs(x,cur);
            dp[cur]+=dp[x];
        }
    }
    
    tout[cur]=timer-1;
}

void dfs1(ll cur,ll prev,ll keep)
{
    ll mx=-1,big=-1,i;
    
    for(auto x : V[cur])
    {
        if(x!=prev)
        {
            if(dp[x]>mx)
            {
                big=x;
                mx=dp[x];
            }
        }
    }
    
    for(auto x : V[cur])
    {
        if(x!=prev&&x!=big)
        {
            dfs1(x,cur,0);
        }
    }
    
    if(big!=-1)
    {
        dfs1(big,cur,1);
    }
    
    cnt[a[cur]]++;
    
    if(cnt[a[cur]]>cc1)
    {
        cc1=cnt[a[cur]];
        cc=a[cur];
    }
    
    else if(cnt[a[cur]]==cc1)
    {
        cc+=a[cur];
    }
    
    for(auto x : V[cur])
    {
        if(x!=prev&&x!=big)
        {
            for(i=tin[x];i<=tout[x];i++)
            {
                
                cnt[a[a1[i]]]++;
                
                if(cnt[a[a1[i]]]>cc1)
                {
                    cc1=cnt[a[a1[i]]];
                    cc=a[a1[i]];
                }
                
                else if(cnt[a[a1[i]]]==cc1)
                {
                    cc+=a[a1[i]];
                }
            }
        }
    }
    
    b[cur]=cc;
    
    if(keep==0)
    {
        cc1=0;
        cc=0;
        
        for(i=tin[cur];i<=tout[cur];i++)
        {
            cnt[a[a1[i]]]--;
        }
    }
    
}

int main()
{
    boost();
    
    
    ll i,t,q,l,r,mid,c=0,j,z,tc,n,m,k;
    ll h,u,mm,w,x,y,l1,r1,d=0,mask,mx;
    ld f,f1;
    
    cin>>n;
    cc=0;
    cc1=0;
    timer=1;
    
    for(i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    
    for(i=0;i<(n-1);i++)
    {
        cin>>x>>y;
        V[x].pb(y);
        V[y].pb(x);
    }
    
    dfs(1,0);
    dfs1(1,0,1);
    
    for(i=1;i<=n;i++)
    {
        cout<<b[i]<<" ";
    }
    
    cout<<endl;
    
    
return 0;
}