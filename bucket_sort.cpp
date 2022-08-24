class Solution {
public:
    int maximumGap(vector<int>& nums) 
    {
          int i,t,q,l,r,ans,mid,c=0,j,z,tc,n,k;
          int h,m,u,mm,w,x,y,l1,r1,d=0,mask,v,mx;
          float f,f1;
          
          n=nums.size();
          mx=INT_MIN;
          mm=INT_MAX;
          ans=0;
          
          int b1[n+1],b2[n+1];
          for(i=0;i<=n;i++)
          {
              b1[i]=mm;
              b2[i]=mx;
          }
          
          for(i=0;i<n;i++)
          {
              mx=max(mx,nums[i]);
              mm=min(mm,nums[i]);
          }
          
          k=((mx-mm)/n)+1;
          
          for(i=0;i<n;i++)
          {
              j=(nums[i]-mm)/k;
              b1[j]=min(b1[j],nums[i]);
              b2[j]=max(b2[j],nums[i]);
          }
          
          k=INT_MIN;
          for(i=0;i<=n;i++)
          {
              if(b1[i]==INT_MAX)
              {
                  continue;
              }
              
              if(k==INT_MIN)
              {
                  k=b2[i];
                  continue;
              }
              
              ans=max(ans,b1[i]-k);
              k=b2[i];
          }
          
          return ans;
          
          
        
    }
};