class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double currWin = 0;

        for (int i = 0; i < k; i++) {
            currWin += nums[i];
        }

        double maxWin = currWin;

        for (int i = k - 1; i < nums.size(); i++) {
            int start = i - k + 1;
            if (start > 0) {
                currWin = currWin - nums[start - 1] + nums[i];
                maxWin = max(maxWin, currWin);
            }
        }

        double avg = maxWin / k;

        return avg;
    }
};
