//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx,avx2,fma")
//#pragma GCC optimization ("unroll-loops")
//u can always think of Binary Search to find the minimum answer...........

 
#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pll;
typedef vector<ll> vl;
typedef vector<pll> vpl;
#define pb push_back
#define MAXN 200005
const ll N=32;
#define INF (ll)1e18
#define mod 1000000000
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

struct seg_node 
{
	seg_node *left=nullptr, *right=nullptr;
	ll cnt=0, odd=0,ev=0;
};

seg_node* func(seg_node* &node, seg_node *a, seg_node *b) 
{
   
   node->odd = a->odd;
   node->ev = a->ev;
   node->cnt = a->cnt+b->cnt;
   
   if(a->cnt&1)
   {
   node->odd+=b->ev;
   node->ev+=b->odd;
   }
   
   else
   {
   node->odd+=b->odd;
   node->ev+=b->ev;
   }
   
	return node;
}

void init(vl &vec, seg_node *node, ll left, ll right) 
{
	if(left == right)
	{
		node->odd= vec[left - 1];
		node->cnt++;
		return;
	}
	
	node->left = new seg_node;
	node->right = new seg_node;
	
	init(vec, node->left, left, (left + right) >> 1);
	init(vec, node->right, ((left + right) >> 1) + 1, right);
	node = func(node, node->left, node->right);
	
}

void update(seg_node *node, ll left, ll right, ll index, ll value)
{
	if(index < left || right < index) 
	return;
	
	if(left == right) 
	{
	   if((node->cnt)&1)
	   node->ev+=index;
	   
	   else
	   node->odd+=index;
	   
		node->cnt++;
		return;
	}
	
	if(node->left == nullptr) 
	node->left = new seg_node;
	
	if(node->right == nullptr) 
	node->right = new seg_node;
	
	update(node->left, left, (left + right) >> 1, index, value);
	update(node->right, ((left + right) >> 1) + 1, right, index, value);
	node = func(node, node->left, node->right);
}

seg_node* query(seg_node *node, ll left, ll right, ll start, ll end) 
{
	if(right < start || end < left || node == nullptr) 
	return (new seg_node);
	
	if(start == left && right == end) 
	return node;
	
	ll mid = (left + right) >> 1;
	
	auto *new_node = new seg_node;
	return func(new_node, query(node->left, left, mid, start, end), query(node->right, mid + 1, right, start, end));
}

int main()
{
 boost();
  
 ll i,t,q,l,r,ans,mid,c=0,j,z,tc,n,k;
 ll h,m,u,mm,w,x,y,l1,r1,d=0,mask,v,mx;
 ld f,f1;
 
 cin>>q;
 z=0;
 ans=0;
 
 auto *root = new seg_node;
 
 while(q--)
 {
    cin>>y;
    x=y+z;
    x%=mod;
    x++;
    
       update(root,ll(1),mod,x,ll(1));
       auto *node = query(root,ll(1),mod,ll(1),mod);
       ans=node->odd;
       
       cout<<ans<<endl;
       z=ans;
 }


  
  
return 0;
}