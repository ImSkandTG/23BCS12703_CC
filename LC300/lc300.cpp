#define vi vector<int>
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vi dp(n, 1);
        int mx = INT_MIN;
        for (int i=0;i<n;i++) {
            for (int j=0;j<i;j++) {
                if (nums[j] < nums[i]) dp[i] = max(dp[i], dp[j]+1);
            }
        }
        for (auto it : dp) mx = max(it, mx);
        return mx;
    }
};
