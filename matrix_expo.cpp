#include <bits/stdc++.h>
using namespace std;
typedef long long  ll;
typedef long double ld;
#define pb push_back
#define MAXN 200005
#define INF (ll)1e18
#define mod 1000000007 
//#define mod 998244353
#define endl '\n'
#define level 20
ll cc=0;


void boost()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
}

typedef vector<vector<ll>> matrix; 
 
void reshape(matrix &mat, int n, int m)
{
    mat.resize(n);
    for(auto &i:mat) i.resize(m);
}
 
matrix operator*(matrix &mat1, matrix &mat2)
{
    int n1=mat1.size(), m1=mat1[0].size(), n2=mat2.size(), m2=mat2[0].size();
    assert(m1==n2);
    ll sum;
    matrix ret;
    reshape(ret, n1, m2);
    for(int i=0; i<n1; ++i)
        for(int j=0; j<m2; ++j)
        {    
            sum=0;
            for(int l=0; l<m1; ++l) sum=(sum+mat1[i][l]*mat2[l][j])%mod;
            ret[i][j]=sum;
        }
    return ret;
}
 
matrix power(matrix res, ll ex)
{
    matrix tmp=res;
    --ex;
    while(ex>0){
        if(ex&1) res=res*tmp;
        tmp=tmp*tmp;
        ex>>=1;
    }
    return res;
}




int main()
{
    boost();
 
    ll i,j,k,t,x,y,n,ans1,c=0;
    ll h,z,u,q,w,ans,m,mm,mx,l,r;
    ld f;
    
    cin>>n>>k;
    ll a[n+1][n+1];
    
    matrix M;
    
    reshape(M,n,n);
    
    for(i=0;i<n;i++)
    {
        
        for(j=0;j<n;j++)
        {
            cin>>l;
            M[i][j]=l;
        }
    }
    
    M=power(M,k);
    
    c=0;
    
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            c+=M[i][j];
            c=c%mod;
        }
    }
    
    cout<<c<<endl;
    
    
return 0;
}