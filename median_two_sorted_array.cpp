
class Solution 
{
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) 
    {
        int i,j,k,l,c=0,z,r,n,m,x,y,l1,r1,l2,r2,len,mid;
        n=nums1.size();
        m=nums2.size();
        double ans;
        
        if(n>m)
        {
            swap(nums1,nums2);
            swap(n,m);
        }
        
        l=0;
        r=n;
        len=n+m;
        z=(n+m+1)/2;
        
        while(r>=l)
        {
            mid=(l+r)/2;
            x=mid;
            y=z-x;
            
            if(x==0)
            {
                l1=INT_MIN;
            }
            
            else
            {
                l1=nums1[x-1];
            }
            
            if(x==n)
            {
                r1=INT_MAX;
            }
            
            else
            {
                r1=nums1[x];
            }
            
            if(y==0)
            {
                l2=INT_MIN;
            }
            
            else
            {
                l2=nums2[y-1];
            }
            
            if(y==m)
            {
                r2=INT_MAX;
            }
            
            else
            {
                r2=nums2[y];
            }
            
            if(l1<=r2&&l2<=r1)
            {
                if(len&1)
                {
                    ans=max(l1,l2);
                }
                
                else
                {
                    ans=max(l1,l2)+min(r1,r2);
                    ans=(double)ans/2.0;
                }
                
                break;
            }
            
            else if(l1>r2)
            {
                r=mid-1;
            }
            
            else
            {
                l=mid+1;
            }
            
        }
        
        return ans;
        
        
    }
};