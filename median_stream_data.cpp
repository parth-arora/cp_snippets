
typedef long double ld;
typedef long long ll;
class MedianFinder 
{
public:
    priority_queue<int,vector<int>,greater<int>> ss1;
    priority_queue<int> ss;
    ld cur=DBL_MIN;
    ld f,f1;
    ll l,r;
    MedianFinder() {
        
    }
    
    void addNum(int num) 
    {
        if(ss.size()>ss1.size())
        {
            if((ld)num>=cur)
            {
                ss1.push(num);
            }
            
            else
            {
                l=ss.top();
                ss.pop();
                ss1.push(l);
                ss.push(num);
            }
            
            l=ss.top();
            r=ss1.top();
            
            l+=r;
            f=(ld)l/2.0;
            
            cur=f;
        }
        
        else if(ss1.size()>ss.size())
        {
            if((ld)num<=cur)
            {
                ss.push(num);
            }
            
            else
            {
                l=ss1.top();
                ss1.pop();
                ss.push(l);
                ss1.push(num);
            }
            
            l=ss.top();
            r=ss1.top();
            
            l+=r;
            f=(ld)l/2.0;
            
            cur=f;
        }
        
        else if(ss.size()==ss1.size())
        {
            if((ld)num>cur)
            {
                ss1.push(num);
                l=ss1.top();
                
                f=(ld)l;
                cur=f;
            }
            
            else
            {
                ss.push(num);
                l=ss.top();
                
                f=(ld)l;
                cur=f;
            }
        }
    }
    
    double findMedian() 
    {
        return cur;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */