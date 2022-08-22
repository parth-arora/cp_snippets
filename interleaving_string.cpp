class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) 
    {
        int i,j,z,n,m,l,r;
        
        if(s3.size()!=s1.size()+s2.size())
        {
            return false;
        }
        
        n=s1.size();
        m=s2.size();
        
        int dp[n+1][m+1];
        memset(dp,0,sizeof(dp));
        dp[0][0]++;
        
        for(i=1;i<=n;i++)
        {
            if(dp[i-1][0]>0&&s1[i-1]==s3[i-1])
            dp[i][0]++;
        }
        
        for(j=1;j<=m;j++)
        {
            if(dp[0][j-1]>0&&s2[j-1]==s3[j-1])
            dp[0][j]++;
        }
        
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=m;j++)
            {
                
                if(s3[i+j-1]==s1[i-1]&&dp[i-1][j]>0)
                {
                    dp[i][j]++;
                }
                
                if(s3[i+j-1]==s2[j-1]&&dp[i][j-1]>0)
                {
                    dp[i][j]++;
                }
            }
        }
        
        return dp[n][m]>0;
        
        
        
    }
};