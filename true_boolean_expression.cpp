class Solution
{
public:
    int countWays(int N, string S)
    {
        int i,j,k,l,r,m,n,c=0,z,t;
        int mod=1003;
        
        string s,s1;
        
        for(i=0;i<S.size();i++)
        {
            if(S[i]=='T'||S[i]=='F')
            {
                s+=S[i];
            }
            
            else
            s1+=S[i];
        }
        
        n=s.size();
        int dp[n][n],dp1[n][n];
        
        memset(dp,0,sizeof(dp));
        memset(dp1,0,sizeof(dp1));
        
        for(i=0;i<n;i++)
        {
            if(s[i]=='T')
            {
                dp[i][i]++;
            }
            
            else
            dp1[i][i]++;
        }
        
        
        for(l=1;l<n;l++)
        {
            for(i=0,j=l;j<n;i++,j++)
            {
                
                for(r=0;r<l;r++)
                {
                    k=i+r;
                    if(s1[k]=='&')
                    {
                        dp[i][j]+=dp[i][k]*dp[k+1][j];
                        dp1[i][j]+=dp[i][k]*dp1[k+1][j]+dp1[i][k]*dp[k+1][j]+dp1[i][k]*dp1[k+1][j];
                    }
                    
                    if(s1[k]=='|')
                    {
                        dp[i][j]+=dp[i][k]*dp1[k+1][j]+dp1[i][k]*dp[k+1][j]+dp[i][k]*dp[k+1][j];
                        dp1[i][j]+=dp1[i][k]*dp1[k+1][j];
                    }
                    
                    if(s1[k]=='^')
                    {
                        dp[i][j]+=dp[i][k]*dp1[k+1][j]+dp1[i][k]*dp[k+1][j];
                        dp1[i][j]+=dp[i][k]*dp[k+1][j]+dp1[i][k]*dp1[k+1][j];
                    }
                    
                    dp[i][j]%=mod;
                    dp1[i][j]%=mod;
                }
            }
        }
        
        return dp[0][n-1];
        
    }
};