class Solution {
    private:
       int Helper(int ind1,int ind2,string &s1,string &s2,vector<vector<int>>&dp){
            // base case
            if(ind1<0||ind2<0) return 0;
            // handle case
            // matching the charatcetr
            // DP Base case
            if(dp[ind1][ind2]!=-1) return dp[ind1][ind2];
            if(s1[ind1]==s2[ind2]){
                return dp[ind1][ind2]=1+Helper(ind1-1,ind2-1,s1,s2,dp);
            }
            return dp[ind1][ind2]=max(Helper(ind1-1,ind2,s1,s2,dp),Helper(ind1,ind2-1,s1,s2,dp));
    }
public:
    int longestCommonSubsequence(string text1, string text2) {
        // Using Memoization
       int n=text1.size();
       int m=text2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));//2D dp
       return Helper(n-1,m-1,text1,text2,dp);
    }
};
