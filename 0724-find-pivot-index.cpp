class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        vector<int> prefix(nums.size(), 0);

        for (int i = 0; i < nums.size(); i++) {
            int prev = i > 0 ? prefix[i - 1] : 0;
            prefix[i] = prev + nums[i];
        }

        int tail = prefix[prefix.size() - 1];

        for (int i = 0; i < prefix.size(); i++) {
            int prev = i > 0 ? prefix[i - 1] : 0;
            if (prev == (tail - prefix[i])) return i;
        }

        return -1;
    }
};
