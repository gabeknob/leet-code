class Solution {
public:
    int minAbsoluteDifference(vector<int>& nums) {
        int lastOne = -1;
        int lastTwo = -1;
        int minDiff = INT_MAX;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 1) lastOne = i;
            if (nums[i] == 2) lastTwo = i;

            if (lastOne != -1 && lastTwo != -1) {
                minDiff = min(minDiff, abs(lastOne - lastTwo));
            }
        }

        if (lastOne == -1 || lastTwo == -1) return -1;

        return minDiff;
    }
};
