class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        vector<int> avgs(nums.size(), -1);
        vector<long long int> prefix(nums.size(), 0);

        long long int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            prefix[i] = nums[i] + sum;
            sum += nums[i];

            if (i >= 2*k) {
                long long int cut = i - 2*k - 1 >= 0 ? prefix[i - 2*k - 1] : 0;
                avgs[i - k] = (prefix[i] - cut) / (2*k + 1);
            }
        }

        return avgs;
    }
};
