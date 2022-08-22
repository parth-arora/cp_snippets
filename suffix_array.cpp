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
typedef vector<int> vi;
typedef vector<pll> vpl;
#define pb push_back
#define MAXN 200005
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
    // to find lcp of substring starting at i and j ,first find their respective index in array usin rank
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

int main()
{
 boost();
  
 ll i,t,q,l,r,ans,mid,c=0,j,z,tc,n,k;
 ll h,m,u,mm,w,x,y,l1,r1,d=0,mask,v,mx;
 ld f,f1;
 
 string s;
 
 cin>>s;
 vpl g;
 
 suffix_array<string> suf(s);
 
 cin>>m;
 
 for(i=0;i<m;i++)
 {
     cin>>l>>r;
     l--;
     r--;
     g.pb(mkp(l,r));
 }
 
 sort(all(g),[&](const pll &p1,const pll &p2)->bool
 {
    n=suf.n;
    
    l=p1.se-p1.fi+1;
    r=p2.se-p2.fi+1;
    
    z=min(l,r);
    x=log2l(z);
    
    pll p3=make_pair(suf.c[x][p1.fi],suf.c[x][(p1.fi+z-(1LL<<x))%n]);
    pll p4=make_pair(suf.c[x][p2.fi],suf.c[x][(p2.fi+z-(1LL<<x))%n]);
    
    if(p3==p4)
    {
        if(l==r)
        return p1.fi<p2.fi;
        
        else
        return l<r;
    }
    
    else
    return p3<p4;
 });
 
 for(auto x:g)
 cout<<x.fi+1<<" "<<x.se+1<<endl;
  
  
return 0;
}