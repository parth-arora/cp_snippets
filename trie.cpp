//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx,avx2,fma")

#include <bits/stdc++.h>
using namespace std;

typedef long long  ll;
typedef long double ld;
typedef pair<ll,ll> pll;
typedef vector<ll> vl;
#define pb push_back
#define MAXN 100005
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
ll timer;


void boost()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

struct node
{
    ll f=0;
    ll child[26]={0};
    
}nil;

vector<node> trie(1,nil);

void insert(string s)
{
    ll cur=0,i,z,l;
    
    for(auto x : s)
    {
        l=x-'a';
        
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

ll query(string s)
{
    ll cur=0,i=0,z,ans=0,l;
    
    for(auto x : s)
    {
        l=x-'a';
        
        z=trie[cur].child[l];
        
        if(z==0)
        {
            break;
        }
        
        cur=z;
        i++;
    }
    
    if(i==sze(s))
    {
        ans=trie[cur].f;
    }
    
    return ans;
}

int main()
{
    boost();
 
    ll i,t,q,l,r,ans,mid,c,z,j,k,v;
    ll h,n,m,u,mm,w,mx,x,y,l1,r1,d=0,mask;
    ld f;
    
    cin>>n>>q;
    string s;
    
    for(i=0;i<n;i++)
    {
        cin>>s;
        insert(s);
    }
    
    while(q--)
    {
        cin>>s;
        ans=query(s);
        
        cout<<ans<<endl;
    }
    
    
    
return 0;
}