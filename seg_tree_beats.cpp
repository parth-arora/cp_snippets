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
#define MAXN 300005
//const ll N=32;
#define llINF (ll)1e18
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
ll timer,cc1,cc,N;

void boost()
{
 ios_base::sync_with_stdio(false);
 cin.tie(NULL);
}


//https://usaco.guide/adv/segtree-beats?lang=cpp
// 0 indexed segment tree

ll A[MAXN];

//https://codeforces.com/contest/1484/problem/E

struct Node {
	ll sum;  // Sum tag
	ll max1;  // Max value
	ll max2;  // Second Max value
	ll maxc;  // Max value count
	ll min1;  // Min value
	ll min2;  // Second Min value
	ll minc;  // Min value count
	ll lazy;  // Lazy tag
} T[MAXN * 4];

void merge(int t) {
	// sum
	T[t].sum = T[t << 1].sum + T[t << 1 | 1].sum;

	// max
	if (T[t << 1].max1 == T[t << 1 | 1].max1) {
		T[t].max1 = T[t << 1].max1;
		T[t].max2 = max(T[t << 1].max2, T[t << 1 | 1].max2);
		T[t].maxc = T[t << 1].maxc + T[t << 1 | 1].maxc;
	} else {
		if (T[t << 1].max1 > T[t << 1 | 1].max1) {
			T[t].max1 = T[t << 1].max1;
			T[t].max2 = max(T[t << 1].max2, T[t << 1 | 1].max1);
			T[t].maxc = T[t << 1].maxc;
		} else {
			T[t].max1 = T[t << 1 | 1].max1;
			T[t].max2 = max(T[t << 1].max1, T[t << 1 | 1].max2);
			T[t].maxc = T[t << 1 | 1].maxc;
		}
	}

	// min
	if (T[t << 1].min1 == T[t << 1 | 1].min1) {
		T[t].min1 = T[t << 1].min1;
		T[t].min2 = min(T[t << 1].min2, T[t << 1 | 1].min2);
		T[t].minc = T[t << 1].minc + T[t << 1 | 1].minc;
	} else {
		if (T[t << 1].min1 < T[t << 1 | 1].min1) {
			T[t].min1 = T[t << 1].min1;
			T[t].min2 = min(T[t << 1].min2, T[t << 1 | 1].min1);
			T[t].minc = T[t << 1].minc;
		} else {
			T[t].min1 = T[t << 1 | 1].min1;
			T[t].min2 = min(T[t << 1].min1, T[t << 1 | 1].min2);
			T[t].minc = T[t << 1 | 1].minc;
		}
	}
}

void push_add(int t, int tl, int tr, ll v) {
	if (v == 0) {
		return;
	}
	T[t].sum += (tr - tl + 1) *v;
	T[t].max1 += v;
	if (T[t].max2 != -llINF) {
		T[t].max2 += v;
	}
	T[t].min1 += v;
	if (T[t].min2 != llINF) {
		T[t].min2 += v;
	}
	T[t].lazy += v;
}

// corresponds to a chmin update
void push_max(int t, ll v, bool l) {
	if (v >= T[t].max1) {
		return;
	}
	T[t].sum -= T[t].max1 * T[t].maxc;
	T[t].max1 = v;
	T[t].sum += T[t].max1 * T[t].maxc;
	if (l) {
		T[t].min1 = T[t].max1;
	} else {
		if (v <= T[t].min1) {
			T[t].min1 = v;
		} else if (v < T[t].min2) {
			T[t].min2 = v;
		}
	}
}

// corresponds to a chmax update
void push_min(int t, ll v, bool l) {
	if (v <= T[t].min1) {
		return;
	}
	T[t].sum -= T[t].min1 * T[t].minc;
	T[t].min1 = v;
	T[t].sum += T[t].min1 * T[t].minc;
	if (l) {
		T[t].max1 = T[t].min1;
	} else {
		if (v >= T[t].max1) {
			T[t].max1 = v;
		} else if (v > T[t].max2) {
			T[t].max2 = v;
		}
	}
}

void pushdown(int t, int tl, int tr) {
	if (tl == tr)
		return;
	// sum
	int tm = (tl + tr) >> 1;
	push_add(t << 1, tl, tm, T[t].lazy);
	push_add(t << 1 | 1, tm + 1, tr, T[t].lazy);
	T[t].lazy = 0;

	// max
	push_max(t << 1, T[t].max1, tl == tm);
	push_max(t << 1 | 1, T[t].max1, tm + 1 == tr);

	// min
	push_min(t << 1, T[t].min1, tl == tm);
	push_min(t << 1 | 1, T[t].min1, tm + 1 == tr);
}

void build(int t=1, int tl=0, int tr=N-1) {
	T[t].lazy = 0;
	if (tl == tr) {
		T[t].sum = T[t].max1 = T[t].min1 = A[tl];
		T[t].maxc = T[t].minc = 1;
		T[t].max2 = -llINF;
		T[t].min2 = llINF;
		return;
	}

	int tm = (tl + tr) >> 1;
	build(t << 1, tl, tm);
	build(t << 1 | 1, tm + 1, tr);
	merge(t);
}

void update_add(int l, int r, ll v, int t=1, int tl=0, int tr=N-1) {
	if (r < tl || tr < l) {
		return;
	}
	if (l <= tl && tr <= r) {
		push_add(t, tl, tr, v);
		return;
	}
	pushdown(t, tl, tr);

	int tm = (tl + tr) >> 1;
	update_add(l, r, v, t << 1, tl, tm);
	update_add(l, r, v, t << 1 | 1, tm + 1, tr);
	merge(t);
}

void update_chmin(int l, int r, ll v, int t=1, int tl=0, int tr=N-1) {
	if (r < tl || tr < l || v >= T[t].max1) {
		return;
	}
	if (l <= tl && tr <= r && v > T[t].max2) {
		push_max(t, v, tl == tr);
		return;
	}
	pushdown(t, tl, tr);

	int tm = (tl + tr) >> 1;
	update_chmin(l, r, v, t << 1, tl, tm);
	update_chmin(l, r, v, t << 1 | 1, tm + 1, tr);
	merge(t);
}

void update_chmax(int l, int r, ll v, int t=1, int tl=0, int tr=N-1) {
	if (r < tl || tr < l || v <= T[t].min1) {
		return;
	}
	if (l <= tl && tr <= r && v < T[t].min2) {
		push_min(t, v, tl == tr);
		return;
	}
	pushdown(t, tl, tr);

	int tm = (tl + tr) >> 1;
	update_chmax(l, r, v, t << 1, tl, tm);
	update_chmax(l, r, v, t << 1 | 1, tm + 1, tr);
	merge(t);
}

ll query_sum(int l, int r, int t=1, int tl=0, int tr=N-1) {
	if (r < tl || tr < l) {
		return -llINF;
	}
	if (l <= tl && tr <= r) {
		return T[t].max1;
	}
	pushdown(t, tl, tr);

	int tm = (tl + tr) >> 1;
	return max(query_sum(l, r, t << 1, tl, tm),query_sum(l, r, t << 1 | 1, tm + 1, tr));
}


int main()
{
 boost();
  
 ll i,t,q,l,r,ans,mid,c=0,j,z,tc,k,n;
 ll h,m,u,mm,w,x,y,l1,r1,d=0,mask,v,mx;
 ld f,f1;
 
 cin>>n;
 
 N=n;
 ll a[n],b[n];
 ll b1[n],b2[n];
 pll p[n];
 stack<pll> ss;
 
 for(i=0;i<n;i++)
 {
 cin>>a[i];
 p[i]=mkp(a[i],i);
 }
 
 for(i=0;i<n;i++)
 A[i]=-llINF;
 
 build();
 
 for(i=0;i<n;i++)
 cin>>b[i];
 
 ss.push(p[0]);
 
 for(i=1;i<n;i++)
 {
     while(!ss.empty()&&ss.top().fi>p[i].fi)
     {
         b1[ss.top().se]=i;
         ss.pop();
     }
     
     ss.push(p[i]);
 }
 
 while(!ss.empty())
 {
     b1[ss.top().se]=n;
     ss.pop();
 }
 
  ss.push(p[n-1]);
 
 for(i=n-2;i>=0;i--)
 {
     while(!ss.empty()&&ss.top().fi>p[i].fi)
     {
         b2[ss.top().se]=i;
         ss.pop();
     }
     
     ss.push(p[i]);
 }
 
 while(!ss.empty())
 {
     b2[ss.top().se]=-1;
     ss.pop();
 }
 
 for(i=0;i<n;i++)
 {
     l=b2[i];
     r=b1[i];
     z=0;
     
     if(i==0)
     {
         z+=b[i];
         update_chmax(i,r-1,z);
         continue;
     }
     
     if(l==-1)
     {
         z=max(z,query_sum(l+1,i-1));
     }
     
     else
     {
         z=query_sum(l,i-1);
     }
     
     z+=b[i];
     
     update_chmax(i,r-1,z);
 }
 
 ans=query_sum(n-1,n-1);
 
 cout<<ans<<endl;
 
 


  
  
return 0;
}