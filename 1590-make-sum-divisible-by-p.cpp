class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int minSubArr = INT_MAX;
        unordered_map<int,int> windowStart {};
        windowStart[0] = -1;

        int arrRemainder = 0;
        for (int i = 0; i < nums.size(); i++) {
            arrRemainder = ((nums[i] % p) + (arrRemainder % p)) % p;
        }

        if (arrRemainder == 0) return 0;

        int prevRemainder = 0;

        for (int i = 0; i < nums.size(); i++) {
            int currRemainder = ((nums[i] % p) + (prevRemainder % p)) % p;
            prevRemainder = currRemainder;

            int cut = (currRemainder - arrRemainder + p) % p;

            if (windowStart.count(cut)) {
                minSubArr = min(minSubArr, i - windowStart[cut]);
            }

            windowStart[currRemainder] = i;
        }

        return minSubArr == nums.size() ? -1 : minSubArr;
    }
};
