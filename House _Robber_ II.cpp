class Solution {
    private:
    
    int Helper(vector<int>&arr){
        int n=arr.size();
        int prev2=0;
        int prev1=arr[0];
        for(int i=1;i<n;i++){
            int Take=prev1+0;
            int NotTake=prev2+arr[i];
            int res=max(Take,NotTake);
            prev2=prev1;
            prev1=res;
        }
        return prev1;
    }
public:
    int rob(vector<int>& nums) {
        // Size of The house
        int n=nums.size();
         // Corner Case
         if(n==1) return nums[0];
            // We just starting the rob the money from two different
            vector<int> First,Second;
            for(int i=0;i<n;i++){
                if(i!=n-1) First.push_back(nums[i]);
                if(i!=0) Second.push_back(nums[i]);
            }
            // Using Space Optimization
            return max(Helper(First),Helper(Second));
    }
};
