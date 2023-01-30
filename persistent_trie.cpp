//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx,avx2,fma")
//#pragma GCC optimization ("unroll-loops")
//u can always think of Binary Search to find the minimum answer...........

 
#include <bits/stdc++.h>
using namespace std;
 
typedef int ll;
typedef long double ld;
typedef pair<ll,ll> pll;
typedef vector<ll> vl;
typedef vector<pll> vpl;
#define pb push_back
#define MAXN 300005
const ll N=31;
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

//https://github.com/arjan-bal/competitive-coding-library/blob/master/cpp/Data%20Structures/persistent%20trie.cpp
//https://www.codechef.com/problems/GPD

struct node{
    int f;
    node* child[2]={};
    node():f(0){}
};

typedef node* pnode;

int tf(pnode cur)
{
    if(!cur) return 0;
    return cur->f;
}

void insert(pnode &naya, pnode purana,ll num, ll lvl)
{
    if(lvl==-1){
        naya->f=tf(purana)+1;
        return ;
    }
    if((1<<lvl)&num){
        naya->child[1]=new node;
        naya->child[0]=(purana?purana->child[0]:NULL);

        if(purana) purana=purana->child[1];
        insert(naya->child[1], purana,num, lvl-1);
        naya->f=tf(naya->child[0])+tf(naya->child[1]);
        return ;
    }
    naya->child[0]=new node;
    naya->child[1]=(purana?purana->child[1]:NULL);

    if(purana) purana=purana->child[0];
    insert(naya->child[0], purana,num, lvl-1);
    naya->f=tf(naya->child[0])+tf(naya->child[1]);
    return ;
}

ll cans=0;

void maxpos(pnode l, pnode r,ll num, ll lvl)
{
    
    if(lvl==-1) return ;
    int cur=0;
    if((1<<lvl)&num){
        if(r) cur+=tf(r->child[0]);
        if(l) cur-=tf(l->child[0]);
        if(cur){
            cans|=(1<<lvl);
            if(l) l=l->child[0];
            if(r) r=r->child[0];
            maxpos(l, r,num, lvl-1);
        }
        else{
            if(l) l=l->child[1];
            if(r) r=r->child[1];
            maxpos(l, r, num,lvl-1);
        }
    }
    else{
        if(r) cur+=tf(r->child[1]);
        if(l) cur-=tf(l->child[1]);
        if(cur){
            cans|=(1<<lvl);
            if(l) l=l->child[1];
            if(r) r=r->child[1];
            maxpos(l, r, num,lvl-1);
        }
        else{
            if(l) l=l->child[0];
            if(r) r=r->child[0];
            maxpos(l, r,num, lvl-1);
        }
    }
    
    return;
}

void minpos(pnode l, pnode r,ll num, ll lvl)
{
    
    if(lvl==-1) return ;
    int cur=0;
    if((1<<lvl)&num){
        if(r) cur+=tf(r->child[1]);
        if(l) cur-=tf(l->child[1]);
        if(cur==0)
        {
            cans|=(1<<lvl);
            if(l) l=l->child[0];
            if(r) r=r->child[0];
            minpos(l, r, num,lvl-1);
        }
        
        else{
            if(l) l=l->child[1];
            if(r) r=r->child[1];
            minpos(l, r, num,lvl-1);
        }
    }
    else{
        if(r) cur+=tf(r->child[0]);
        if(l) cur-=tf(l->child[0]);
        if(cur==0)
        {
            cans|=(1<<lvl);
            if(l) l=l->child[1];
            if(r) r=r->child[1];
            minpos(l, r, num,lvl-1);
        }
        
        else{
            if(l) l=l->child[0];
            if(r) r=r->child[0];
            minpos(l, r, num,lvl-1);
        }
    }
    
    return;
}

map<ll,vpl> mp;
map<ll,pnode> roots;

void dfs(ll cur,ll prev,ll y)
{
    roots[cur]=new node;
    
    insert(roots[cur],roots[prev],y,N);
    
    for(auto x :mp[cur])
    {
        dfs(x.fi,cur,x.se);
    }
}

int main()
{
 boost();
  
 ll i,t,q,l,r,ans,mid,c=0,j,z,tc,n,k;
 ll h,m,u,mm,w,x,y,l1,r1,d=0,mask,v,mx;
 ld f,f1;
 
 cin>>n>>q;
 cin>>m>>t;
 ans=0;
 
 for(i=1;i<n;i++)
 {
     cin>>x>>y>>z;
     mp[y].pb(mkp(x,z));
 }
 
 roots[0]=new node;
 
 dfs(m,0,t);
 
 while(q--)
 {
     cin>>y;
     y^=ans;
     
     if(y==0)
     {
         cin>>l>>r>>k;
         l^=ans;
         r^=ans;
         k^=ans;
         roots[r]=new node;
         insert(roots[r],roots[l],k,N);
         
     }
     
     else
     {
         cin>>l>>k;
         l^=ans;
         k^=ans;
         
         cans=0;
         minpos(roots[0],roots[l],k,N);
         cout<<cans<<" ";
         ans=cans;
         
         cans=0;
         maxpos(roots[0],roots[l],k,N);
         cout<<cans<<endl;
         ans^=cans;
         
     }
 }
 
 


  
  
return 0;
}