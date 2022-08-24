//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx,avx2,fma")

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pll;
typedef vector<ll> vl;
#define pb push_back
#define MAXN 2000005
const ll N=31;
#define INF (ll)1e18
#define mod 1000000007
//#define mod 998244353
#define fi first
#define se second
#define mkp make_pair
#define sze(x) ((ll)x.size())
#define all(v) v.begin(),v.end()
#define endl '\n'
ll cc=0,cc1=0;
ll timer,k;


void boost()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

ll dep[MAXN],dp[MAXN];

struct node
{
    ll f=0;
    ll child[26]={0};
    
}nil;

vector<node> trie(1,nil);

void insert(string s)
{
    ll cur=0,i,z,l;
    ++trie[cur].f;
    
    for(auto x : s)
    {
        l=x-'A';
        
        z=trie[cur].child[l];
        
        if(z==0)
        {
            z=trie.size();
            trie[cur].child[l]=z;
            trie.pb(nil);
        }
        
        cur=z;
        ++trie[cur].f;
        
    }
}

void dfs(ll cur)
{
    ll i,z,l,r,x,c=0;
    
    for(i=0;i<26;i++)
    {
        x=trie[cur].child[i];
        
        if(x!=0)
        {
        dep[x]=dep[cur]+1;
        dfs(x);
        dp[cur]+=dp[x];
        }
    }
    
    l=trie[cur].f-dp[cur];
    r=(l/k);
    
    dp[cur]+=(r*k);
    cc+=(r*dep[cur]);
}


int main()
{
    boost();
 
    ll i,t,q,l,r,ans,mid,c,z,j,tc;
    ll h,n,m,u,mm,w,mx,x,y,l1,r1,d=0,mask;
    ld f;
    
    
    cin>>t;
    
    
    for(tc=1;tc<=t;tc++)
    {
        cc=0;
        cin>>n>>k;
        
        string s[n];
        
        trie.clear();
        trie.pb(nil);
        
        for(i=0;i<n;i++)
        {
            cin>>s[i];
            insert(s[i]);
        }
        
        
        for(i=0;i<MAXN;i++)
        {
            dep[i]=0;
            dp[i]=0;
        }
        
        dfs(0);
        
        cout<<"Case #"<<tc<<": "<<cc<<endl;
    }
    
return 0;
}