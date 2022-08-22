
#include <bits/stdc++.h>
using namespace std;
typedef long long  ll;
typedef long double ld;
#define MAXN 1005
vector <ll> V[MAXN];
vector<char> v;
ll vis[MAXN][MAXN],a[MAXN][MAXN],dist[MAXN][MAXN];
pair<ll,ll> parent[MAXN][MAXN];
string s[MAXN];

ll n,m;
pair<ll,ll> p,b;

queue<pair<ll,ll>> que;

void boost()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
}

ll dx[] = {-1,0,1,0};
ll dy[] = {0,1,0,-1};

bool check(ll x,ll y)
{
    if(x<0||y<0||x==n||y==m)
    return false;

    if(vis[x][y]==1)
    return false;

    if(a[x][y]==0)
    return false;

    return true;
}

void bfs(ll x,ll y)
{
    ll k,j,z,i;

    vis[x][y]++;
    dist[x][y]=0;
    p.first=x;
    p.second=y;
    que.push(p);

    while(!(que.empty()))
    {
        p=que.front();
        que.pop();
        j=p.first;
        k=p.second;

        for(i=0;i<4;i++)
        {
            if(check(j+dx[i],k+dy[i]))
            {
                dist[j+dx[i]][k+dy[i]]=dist[j][k]+1;
                vis[j+dx[i]][k+dy[i]]++;
                parent[j+dx[i]][k+dy[i]]=p;
                b.first=j+dx[i];
                b.second=k+dy[i];
                que.push(b);
            }

            if(s[j+dx[i]][k+dy[i]]=='B')
            {
                return;
            }
        }
    }

}

int main()
{
    boost();

    ll i,j,k,c=0,d=0,t,x,y;
    ll l,r,ans,h,z,w,f;
    v.clear();
    cin>>n>>m;

    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            dist[i][j]=INT_MAX;
            vis[i][j]=0;
            b.first=-1;
            b.second=-1;
            parent[i][j]=b;
        }
    }


    for(i=0;i<n;i++)
    cin>>s[i];

    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            if(s[i][j]=='#')
            a[i][j]=0;

            else
            a[i][j]=1;

            if(s[i][j]=='A')
            {
                l=i;
                r=j;
            }

            if(s[i][j]=='B')
            {
                w=i;
                f=j;
            }
        }
    }

    c=0;

    bfs(l,r);

    if(vis[w][f]==0)
    {
        cout<<"NO"<<endl;
    }


    else
    {
        cout<<"YES"<<endl;
        b.first=-1;
        b.second=-1;

        while(parent[w][f]!=b)
        {
            p=parent[w][f];

            if((w-p.first)==1)
            {
               v.push_back('R');
            }

            else if((p.first-w)==1)
            {
                v.push_back('L');
            }

            else if((p.second-f)==1)
            {
                v.push_back('D');
            }

            else if((f-p.second)==1)
            {
               v.push_back('U');
            }

            w=p.first;
            f=p.second;
        }

        ans=v.size();

        cout<<ans<<endl;

        for(i=ans-1;i>=0;i--)
        {
            cout<<v[i]<<" ";
        }

        cout<<endl;

    }

return 0;
}

