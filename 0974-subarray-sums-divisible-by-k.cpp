class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int divisibleArrs = 0;

        unordered_map<int,int> windowStarts {};
        windowStarts[0] = 1;

        int currRemainder = 0;
        for (int num : nums) {
            currRemainder = ((num % k) + k + (currRemainder % k)) % k;

            if (windowStarts.count(currRemainder)) {
                divisibleArrs += windowStarts[currRemainder];
            }

            windowStarts[currRemainder]++;
        }

        return divisibleArrs;
    }
};
