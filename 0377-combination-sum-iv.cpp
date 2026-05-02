class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(target + 1, -1);

        return backtrack(nums, dp, 0, target);
    }

    int backtrack(vector<int>& nums, vector<int>& memo, int sum, int target) {
        if (sum > target) return 0;
        if (sum == target) return 1;

        if (memo[sum] != -1) {
            return memo[sum];
        }

        int validPaths = 0;
        for (int i = 0; i < nums.size(); i++) {
            validPaths += backtrack(nums, memo, nums[i] + sum, target);
        }

        memo[sum] = validPaths;

        return validPaths;
    }
};
