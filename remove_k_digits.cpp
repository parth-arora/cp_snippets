class Solution {
public:
    string removeKdigits(string num, int k) 
    {
        int i,j,l,c=0,z,n,m;
        n=num.size();
        stack<char> ss;
        string s="";
        
        for(i=0;i<n;i++)
        {
            while(!ss.empty()&&num[i]<ss.top())
            {
                if(k>0)
                {
                    ss.pop();
                    k--;
                }
                
                else
                break;
            }
            
            ss.push(num[i]);
        }
        
        while(!ss.empty()&&k>0)
        {
            ss.pop();
            k--;
        }
        
        while(!ss.empty())
        {
            s+=ss.top();
            ss.pop();
        }
        
        while(s.back()=='0')
        s.pop_back();
        
        reverse(s.begin(),s.end());
        
        if(s.size()==0)
        s='0';
        
        return s;
        
    }
};