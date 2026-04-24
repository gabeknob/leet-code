class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        vector<int> zero_idxs;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) zero_idxs.push_back(i);
        }

        if (zero_idxs.size() <= k) return nums.size();
        zero_idxs.push_back(nums.size());

        int max_window = zero_idxs[k];

        for (int i = k + 1; i < zero_idxs.size(); i++) {
            int current_window = zero_idxs[i] - zero_idxs[i - 1 - k] - 1;
            max_window = max(max_window, current_window);
        }

        return max_window;
    }
};
