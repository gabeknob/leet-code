class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left = 0;
        int right = 0;

        int currSum = 0;
        int minWindow = INT_MAX;

        for (int right = 0; right < nums.size(); right++) {
            currSum += nums[right];

            while (currSum >= target) {
                minWindow = min(minWindow, right - left + 1);
                currSum -= nums[left];
                left++;
            }
        }

        return minWindow == INT_MAX ? 0 : minWindow;
    }
};
