class Solution {
    private:
    int Helper(int ind,int pre,vector<int>&nums,vector<vector<int>>&dp){
        // Base Case
        if(ind==nums.size()) return 0;
        // Take
        // Dp base case
        if(dp[ind][pre+1]!=-1) return dp[ind][pre+1];
        int take=0;
        if(pre==-1||nums[ind]>nums[pre]){
            take=1+Helper(ind+1,ind,nums,dp);
        }
        // NotTake
        int NotTake=Helper(ind+1,pre,nums,dp);
        return dp[ind][pre+1]=max(take,NotTake);
    }
 
public:
    int lengthOfLIS(vector<int>& nums) {
             int n=nums.size();
             vector<vector<int>>dp(n,vector<int>(n+1,-1));  //2D dp
             return Helper(0,-1,nums,dp);
   
       // Using Binary search
        vector<int>res;
        res.push_back(nums[0]);
        for(int i=1;i<nums.size();i++){
            // checking the condition to push the element in the array
            if(nums[i]>res.back()){
                res.push_back(nums[i]);
            }
            else
            {
                int ind=lower_bound(res.begin(),res.end(),nums[i])-res.begin();
                res[ind]=nums[i];
            }
        }
        return res.size();
    }
};
