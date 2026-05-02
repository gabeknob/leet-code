class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int, int> validFruits;
        int maxFruits = 0;

        int left = 0;
        int right = 0;
        
        while (right < fruits.size()) {
            int currFruit = fruits[right];
            validFruits[currFruit]++;

            while (validFruits.size() > 2) {
                int cut = fruits[left];

                validFruits[cut]--;
                if (validFruits[cut] == 0) validFruits.erase(cut);
                left++;
            }

            maxFruits = max(maxFruits, right - left + 1);

            right++;
        }

        return maxFruits;
    }
};
