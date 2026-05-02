class Solution {
public:
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        vector<int> res;
        span<int> aux{nums};
        
        for (int i = 0; i <= nums.size() - k; i++) {
            res.push_back(getXSum(aux.subspan(i, k), x));
        }

        return res;
    }

    long long getXSum(span<int> nums, int x) {
        unordered_map<int,int> frequency {};

        for (int& num : nums) {
            frequency[num]++;
        }

        auto comp = [](pair<int,int> a, pair<int,int> b) {
            auto& [aVal, aFreq] = a;
            auto& [bVal, bFreq] = b;

            if (aFreq == bFreq) return aVal < bVal;

            return aFreq < bFreq;
        };
        priority_queue<pair<int,int>, vector<pair<int,int>>, decltype(comp)> maxFreqHeap(comp);

        for (auto& [val, freq] : frequency) {
            maxFreqHeap.push({ val, freq });
        }

        long long xSum = 0;

        for (int i = 0; i < x && !maxFreqHeap.empty(); i++) {
            xSum += (long long)maxFreqHeap.top().first * maxFreqHeap.top().second;
            maxFreqHeap.pop();
        }

        return xSum;
    }
};
