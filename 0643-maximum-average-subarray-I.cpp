class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        if (nums.size() == 0) return 0.0;
        int maxSum = INT_MIN;

        int currSum = 0;
        for (int i = 0; i < nums.size(); i++) {
            currSum += nums[i];

            if (i >= k - 1) {
                int cut = i >= k ? nums[i - k] : 0;
                currSum -= cut;
                maxSum = max(maxSum, currSum);
            }
        }

        double maxAvg = maxSum / double(k);
        return maxAvg;
    }
};
