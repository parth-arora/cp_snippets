class Solution 
{
public:

    multiset<int> ss1;
    multiset<int,greater<int>> ss;
    double cur=DBL_MIN;
    long double f,f1;
    long long l,r,K;

       void addNum(int num) 
       {
           
        if(ss.size()>ss1.size())
        {
            if((double)num>=cur)
            {
                ss1.insert(num);
            }
            
            else
            {
                l=*ss.begin();
                ss.erase(ss.begin());
                ss1.insert(l);
                ss.insert(num);
            }
            
            l=*ss.begin();
            r=*ss1.begin();
            
            l+=r;
            f=(double)l/2.0;
            
            cur=f;
        }
        
        else if(ss1.size()>ss.size())
        {
            if((double)num<=cur)
            {
                ss.insert(num);
            }
            
            else
            {
                l=*ss1.begin();
                ss1.erase(ss1.begin());
                ss.insert(l);
                ss1.insert(num);
            }
            
            l=*ss.begin();
            r=*ss1.begin();
            
            l+=r;
            f=(double)l/2.0;
            
            cur=f;
        }
        
        else if(ss.size()==ss1.size())
        {
            if((double)num>cur)
            {
                ss1.insert(num);
                l=*ss1.begin();
                
                f=(double)l;
                cur=f;
            }
            
            else
            {
                ss.insert(num);
                l=*ss.begin();
                
                f=(double)l;
                cur=f;
            }
        }
    }
    
    void eraseNum(int num)
    {
        if(ss.find(num)!=ss.end())
        ss.erase(ss.find(num));
        
        else
        ss1.erase(ss1.find(num));
        
        if(K==1)
        {
            cur=DBL_MIN;
        }
        
        else
        {
            if(ss.size()>ss1.size())
            {
                if((ss.size()-ss1.size())==2)
                {
                    l=*ss.begin();
                    ss.erase(ss.begin());
                    ss1.insert(l);
                    
                    l=*ss.begin();
                    r=*ss1.begin();
                    l+=r;
                    f=(double)l/2.0;
                    cur=f;
                    
                }
            }
            
            else if(ss1.size()>ss.size())
            {
                if((ss1.size()-ss.size())==2)
                {
                    l=*ss1.begin();
                    ss1.erase(ss1.begin());
                    ss.insert(l);
                    
                    l=*ss.begin();
                    r=*ss1.begin();
                    l+=r;
                    f=(double)l/2.0;
                    cur=f;
                    
                }
            }
            
            else if(ss.size()==ss1.size())
            {
                
                    l=*ss.begin();
                    r=*ss1.begin();
                    l+=r;
                    f=(double)l/2.0;
                    cur=f;
            }
        }
    }
    
    vector<double> medianSlidingWindow(vector<int>& nums, int k) 
    {
        int i,n;
        K=k;
        
        vector<double> g;
        n=nums.size();
        
        for(i=0;i<k;i++)
        {
            addNum(nums[i]);
        }
        
        g.push_back(cur);
        
        for(i=k;i<n;i++)
        {
            eraseNum(nums[i-k]);
            addNum(nums[i]);
            g.push_back(cur);
        }
        
        
        return g;
    }
};