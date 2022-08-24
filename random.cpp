#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    
    cin>>t;
    
    while(t--)
    {
        int n;
        cin>>n;
        
    pair<int,pair<pair<int,int>,int>> p[n];
    int mx=0;
    
    for(int i=0;i<n;i++)
    {
        cin>>p[i].second.first.first;
        cin>>p[i].second.first.second;
        cin>>p[i].second.second;
        p[i].first=p[i].second.first.second-p[i].second.first.first+1;
        mx=max(mx,p[i].second.first.second);
    }
    
    
    
    int b[mx+1];
    set<int> ss;
    
    sort(p,p+n);
        
        int r=n;
        int l=1;
        int ans=n;
        vector<int> g;
        
        while(r>=l)
        {
            ss.clear();
            
            for(int i=1;i<=mx;i++)
            ss.insert(i);
            
            int c=0;
            
            memset(b,0,sizeof(b));
            
            int mid=(l+r)/2;
            
            for(int i=0;i<n;i++)
            {
                int l1=p[i].second.first.first;
                int r1=p[i].second.first.second;
                int z=p[i].second.second;
                g.clear();
                
                auto it=ss.lower_bound(l1);
                
                while(z>0)
                {
                    int y=*it;
                    
                    if(it==ss.end()||(y>r1))
                    {
                        c++;
                        break;
                    }
                    
                    else
                    {
                        int x=min(z,mid-b[y]);
                        b[y]+=x;
                        z-=x;
                        
                        if(b[y]==mid)
                        g.push_back(y);
                        
                        it++;
                    }
                }
                
                for(auto x :g)
                ss.erase(ss.find(x));
                
                if(c>0)
                break;
            }
            
            if(c==0)
            {
                ans=min(ans,mid);
                r=mid-1;
            }
            
            else
            {
                l=mid+1;
            }
            
        }
        
        
        cout<<ans;
    }
    
return 0;
}