class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        if (nums.size() == 0) return 0;
        if (nums.size() == 1) return nums[0] == k;

        int subArrays = 0;
        int totalSum = 0; // no need for prefix array

        unordered_map<int,int> windowStarts {}; // unordered for O(1) checks
        windowStarts[0] = 1; // needed to check first element == k

        for (int i = 0; i < nums.size(); i++) {
            int curr = nums[i] + totalSum;

            if (windowStarts.count(curr - k)) { // check first
                subArrays += windowStarts[curr - k];
            }
            
            if (windowStarts.count(curr)) {
                windowStarts[curr] += 1;
            } else {
                windowStarts[curr] = 1;
            }

            totalSum = curr; // adds element to the map last
        }

        return subArrays;
    }
};
