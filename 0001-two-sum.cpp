class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result (2, 0);
        map<int,int> opps;

        for (int i = 0; i < nums.size(); i++) {
            if (opps.contains(nums[i])) {
                result[0] = opps[nums[i]];
                result[1] = i;
            };

            opps[target - nums[i]] = i;
        }

        return result;
    }
};
