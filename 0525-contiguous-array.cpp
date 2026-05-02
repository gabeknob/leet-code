class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int maxWindow = 0;
        unordered_map<int,int> windowStart {{ 0, -1 }};

        int currSum = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 1) ++currSum;
            if (nums[i] == 0) --currSum;


            int prevCompat;
            int currWindow;
            if (windowStart.count(currSum)) {
                prevCompat = windowStart[currSum];
                currWindow = i - prevCompat;
                maxWindow = max(maxWindow, currWindow);
            }

            if (!windowStart.count(currSum)) {
                windowStart[currSum] = i;
            }
        }

        return maxWindow;
    }
};
