//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx,avx2,fma")
//#pragma GCC optimization ("unroll-loops")
//u can always think of Binary Search to find the minimum answer...........
//https://codeforces.com/contest/547/problem/E
 
#include <bits/stdc++.h>
using namespace std;
 
typedef int ll;
typedef long double ld;
typedef pair<ll,ll> pll;
typedef vector<ll> vl;
typedef vector<int> vi;
typedef vector<pll> vpl;
#define pb push_back
#define MAXN 400005
const ll N=32;
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

//cp algorithms
//https://cp-algorithms.com/string/suffix-array.html

template<typename T, bool maximum_mode = false>
struct RMQ {
    int n = 0, levels = 0;
    vector<vector<T>> range_min;
 
    RMQ(const vector<T> &values = {}) {
        if (!values.empty())
            build(values);
    }
 
    static int largest_bit(int x) {
        return 31 - __builtin_clz(x);
    }
 
    static T better(T a, T b) {
        return maximum_mode ? max(a, b) : min(a, b);
    }
 
    void build(const vector<T> &values) {
        n = values.size();
        levels = largest_bit(n) + 1;
        range_min.resize(levels);
 
        for (int k = 0; k < levels; k++)
            range_min[k].resize(n - (1 << k) + 1);
 
        if (n > 0)
            range_min[0] = values;
 
        for (int k = 1; k < levels; k++)
            for (int i = 0; i <= n - (1 << k); i++)
                range_min[k][i] = better(range_min[k - 1][i], range_min[k - 1][i + (1 << (k - 1))]);
    }
 
    T query_value(int a, int b) const {
        assert(0 <= a && a <= b && b < n);
        int levels = largest_bit(b - a + 1);
        return better(range_min[levels][a], range_min[levels][b + 1 - (1 << levels)]);
    }
};


template<typename T_string>
struct suffix_array{
	int n, C,d=0;
	T_string str;
	vi p, rank, lcp;
	vi c[level];
	RMQ<int> rmq;
	
	 //classes contains no. of distinct sorted suffix
    //p contains suffixes in sorted order which contains starting index of that suffix
    // c contains the class number for a particular suffix starting at ith index.
    // rank contains position of ith suffix in sorted order.
    
     //lcp contains longest common prefix for adjacent sorted suffixes
    // to find lcp of substring starting at i and j ,first find their respective index in array using rank
    // then do a rmq in the lcp array


	void build_suffix_array()
	{
	    //adding extra element at the end
		if(C <= 256) str.pb(0);
		else str.pb(-1);

		++n;		
		p.resize(n);
		
		for(int i=0;i<level;i++)
		c[i].resize(n);
		
		vi cnt(max(n, C), 0);
		
		 // form base states for 0th level;

		if(C < 256){
			for(int i = 0; i < n; ++i)
				++cnt[str[i]];
			for(int i = 0; i < n; ++i)
				p[--cnt[str[i]]] = i;
		} else{
			iota(p.begin(), p.end(), 0);
			sort(all(p), [&](int a, int b){
				return str[a] < str[b];
			});
		}

		int classes = 1;
		c[0][p[0]] = 0;

		for(int i=1; i<n; ++i)
			c[0][p[i]] = str[p[i]] == str[p[i-1]] ? classes-1 : classes++;

		vi pn(n);
		
		//form states for above levels using radix sort

		for(int len = 1; len < n && classes < n; len <<= 1)
		{
		    d++;
			for(int i = 0; i < n; ++i)
				pn[i] = p[i] >= len ? p[i] - len : p[i] - len + n;
			
			fill(cnt.begin(), cnt.begin() + classes, 0);

			for(int i = 0; i < n; ++i)
				++cnt[c[d-1][pn[i]]];

			for(int i = 1; i < classes; ++i)
				cnt[i] += cnt[i-1];

			for(int i = n-1; i >= 0; --i)
				p[--cnt[c[d-1][pn[i]]]] = pn[i];

			c[d][p[0]] = 0;
			classes = 1;
			
			 // compare adjacent suffixes to assign the class and find no. of classes
             // comparing 2^i length sufffix by breaking down into 2^(i-1) and 2^(i-1);
             
			pll prev = {c[d-1][p[0]], c[d-1][(p[0] + len) % n]};

			for(int i = 1; i < n; ++i){
				pll cur = {c[d-1][p[i]], c[d-1][(p[i] + len) % n]};
				c[d][p[i]] = cur == prev ? classes - 1 : classes++;
				prev = cur;
			}
		}
		
		//erasing extra element from str and p
		--n;
		str.pop_back();
		p.erase(p.begin());
	}

	void build_lcp()
	{
		rank.resize(n);
	    for (int i = 0; i < n; ++i)
	        rank[p[i]] = i;

	    int k = 0;
	    lcp.resize(n-1, 0);
	    for (int i = 0; i < n; ++i) {
	        if (rank[i] == n - 1) {
	            k = 0;
	            continue;
	        }
	        int j = p[rank[i] + 1];
	        while(i + k < n && j + k < n && str[i+k] == str[j+k])
	            k++;
	        lcp[rank[i]] = k;
	        if(k) k--;
	    }
	}

	suffix_array(const T_string &_str, bool need_rmq = true, int _C = 256)
	{
		str = _str, C = _C, n = _str.size();
		build_suffix_array();
		if(need_rmq && n > 1) 
			build_lcp(), rmq.build(lcp);
	}

	// 0 indexing
	int get_lcp(int a, int b)
	{
		if(a == b) return n - a;
		a = rank[a], b = rank[b];
		if(a > b) swap(a, b);
		return rmq.query_value(a, b - 1);
	}

	int compare(int a, int b, int len)
	{
		int match = get_lcp(a, b);
		if(match >= len) return 0;
		if(a + match >= n || b + match >= n) return a > b ? -1 : 1;
		return str[a + match] > str[b + match] ? 1 : -1; 
	}
};

vl seg[4*MAXN];
ll a[MAXN],b[MAXN];

void build(ll v , ll tl , ll tr)
{
	if(tl == tr)
	{
		seg[v].pb(a[tl]);
		return;
	}
	
	ll tm = (tl + tr) / 2;
	build(2*v , tl , tm);
	build(2*v + 1, tm+1 , tr);

	merge(all(seg[2*v]),all(seg[2*v+1]),back_inserter(seg[v]));
	
}

ll query(ll v , ll tl ,ll tr , ll l , ll r, ll k)
{
	if(l>r) 
	return 0;
	
	if(l==tl&&r==tr)
	{
		ll res = upper_bound(all(seg[v]), k) - seg[v].begin();
		return res;
	}
	
	ll tm= (tl+ tr) / 2;
	ll l1=query(2*v , tl , tm , l ,min(r,tm) , k);
	ll r1=query(2*v + 1 , tm + 1 , tr , max(l,tm+1) ,r, k);
	
	return l1 + r1;
}


int main()
{
 boost();
  
 ll i,t,q,l,r,ans,mid,c=0,j,z,tc,n,k,n1;
 ll h,m,u,mm,w,x,y,l1,r1,d=0,mask,v,mx;
 ld f,f1;
 
 cin>>n>>q;
 string s[n];
 
 string s1,s2;
 s1="";
 
 for(i=0;i<n;i++)
 {
     cin>>s[i];
     s1+=s[i];
     s1+='$';
 }
 
 
 suffix_array<string> suf(s1);
 
 n1=sze(s1);
 
 for(i=0;i<n;i++)
 {
     m=sze(s[i]);
     x=c;
     
     for(j=x;j<x+m;j++,c++)
     {
         b[j]=i+1;
     }
     
     b[c]=i+1;
     c++;
 }
 
  //lower_bound of string
  vpl g;
  
  for(j=0;j<n;j++)
  {
      
  m=sze(s[j]);
     
 r=n1-1;
 l=0;
 l1=n1;
      
 
 while(r>l)
 {
     s2="";
     mid=(l+r)/2;
     z=suf.p[mid];
     
     
     for(i=z;i<min(n1,z+m);i++)
     {
         s2+=s1[i];
     }
     
     if(s[j]<=s2)
     r=mid;
     
     else
     l=mid+1;
     
 }
 
 l1=l;
 
 if(l1<n1)
 {
     s2="";
     z=suf.p[l1];
     
     for(i=z;i<min(n1,z+m);i++)
     s2+=s1[i];
     
     if(s2<s[j])
     l1++;
 }
 
 
 //upper bound of string
 
 r=n1-1;
 l=0;
 
 
 while(r>l)
 {
     s2="";
     mid=(l+r)/2;
     z=suf.p[mid];
     
     
     for(i=z;i<min(n1,z+m);i++)
     {
         s2+=s1[i];
     }
     
     if(s[j]>=s2)
     l=mid+1;
     
     
     else
     r=mid;
     
 }
 
  r1=l;
 
  if(r1<n1)
 {
     s2="";
     z=suf.p[r1];
     
     for(i=z;i<min(n1,z+m);i++)
     s2+=s1[i];
     
     if(s2<=s[j])
     r1++;
 }
 
   g.pb(mkp(l1,r1-1));
  }
  
  for(i=0;i<n1;i++)
  {
      l=suf.p[i];
      a[i+1]=b[l];
  }
  
  
  build(1,1,n1);
  
  
  while(q--)
  {
      cin>>l>>r>>k;
      
      l1=g[k-1].fi+1;
      r1=g[k-1].se+1;
      
      if(l1>r1)
      cout<<0<<endl;
      
      else
      {
      
      z=query(1,1,n1,l1,r1,r);
      z-=query(1,1,n1,l1,r1,l-1);
      
      cout<<z<<endl;
      }
      
  }


  
  
return 0;
}