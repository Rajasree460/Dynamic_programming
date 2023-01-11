long long int NoOfWays(int n,vector<long long int>&dp){
    //if(n==0||n==1)
    // Base  Case
    if(n<=1) return 1;
    // Memoizatiob (Base Case)
    if(dp[n]!=-1) return dp[n];
     return dp[n]=NoOfWays(n-1,dp)+NoOfWays(n-2,dp);
}
int main() {
    int n;  cin>>n;
    //Using  Memoizatiomn
    Staticslly and Dynamicaaaly
    memset(dp,-1,size(dp));
    vector<int>dp(n+1,0);
    dp[0]=1;  // Base case
    dp[1]=1;  //  Base Case
    for(int i=2;i<=n;i++){
        dp[i]=dp[i-1]+dp[i-2];
    }
    cout<<dp[n]<<endl;
    cout<<NoOfWays(n,dp);
    cout<<endl;
    for(long long int i:dp) cout<<i<<" ";
    if(n<=1) cout<<1<<endl;
    int prev1=1, prev2=1;
    int curr;
    for(int i=2;i<=n;i++){
        curr=prev1+prev2;
        prev2=prev1;
        prev1=curr;
    }
    cout<<prev1<<endl;
}
