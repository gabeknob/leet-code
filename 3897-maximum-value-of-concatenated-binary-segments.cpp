class Solution {
    const int MOD = 1e9 + 7;

    long long power(long long base, long long exp) {
        long long res = 1;
        base %= MOD;
        while (exp > 0) {
            if (exp % 2 == 1) res = (res * base) % MOD;
            base = (base * base) % MOD;
            exp /= 2;
        }
        return res;
    }

public:
    int maxValue(vector<int>& nums1, vector<int>& nums0) {
        vector<pair<int,int>> chain {};

        for (int i = 0; i < nums0.size(); i++) {
            chain.push_back({nums1[i], nums0[i]});
        }

        sort(chain.begin(), chain.end(), [](const pair<int,int>& a, const pair<int,int>& b) {
            if ((a.second == 0) != (b.second == 0)) {
                return a.second == 0; 
            }

            if (a.first != b.first) {
                return a.first > b.first;
            }

            return a.second < b.second;
        });

        long long totalValue = 0;
        for (auto& [x, y] : chain) {
            int totalLen = x + y;

            long long segVal = (power(2, x) - 1 + MOD) % MOD;
            segVal = (segVal * power(2, y)) % MOD;

            totalValue = (totalValue * power(2, totalLen)) % MOD;
            totalValue = (totalValue + segVal) % MOD;
        }

        return (int)totalValue;
    }
};
