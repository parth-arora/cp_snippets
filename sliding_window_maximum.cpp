class Solution 
{
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) 
    {
        int i,j,l,c=0,z,t,n,m;
        n=nums.size();
        vector<int> g;
        deque<int> dq;
        
        for(i=0;i<k;i++)
        {
            while(!dq.empty()&&nums[i]>=nums[dq.back()])
            {
                dq.pop_back();
            }
            
            dq.push_back(i);
        }
        
        g.push_back(nums[dq.front()]);
        
        for(i=k;i<n;i++)
        {
            
            while(!dq.empty()&&dq.front()<=(i-k))
            {
                dq.pop_front();
            }
            
            while(!dq.empty()&&nums[i]>=nums[dq.back()])
            {
                dq.pop_back();
            }
            
            dq.push_back(i);
            
            g.push_back(nums[dq.front()]);
        }
        
        return g;
    }
};