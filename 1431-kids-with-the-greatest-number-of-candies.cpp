class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        vector<bool> result(candies.size(), false);

        int firstMax = 0;
        for (int i = 0; i < candies.size(); i++) {
            firstMax = candies[i] > firstMax ? candies[i] : firstMax;
        }

        for (int i = 0; i < candies.size(); i++) {
            if ((candies[i] + extraCandies) >= firstMax) result[i] = true;
        }

        return result;
    }
};
