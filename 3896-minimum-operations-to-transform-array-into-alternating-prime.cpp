class Solution {
public:
    int minOperations(vector<int>& nums) {
        int upper_bound = 1e5 + 10;
        vector<bool> is_prime(upper_bound, true);
        vector<int> primes;

        is_prime[0] = is_prime[1] = false;

        int steps = 0;

        for (int i = 2; i * i < upper_bound; i++) {
            if (is_prime[i] == true) {
                for (int j = i * i; j < upper_bound; j += i) {
                    is_prime[j] = false;
                }
            }
        }

        for (int i = 0; i < is_prime.size(); i++) {
            if (is_prime[i] == true) primes.push_back(i);
        }

        for (int i = 0; i < nums.size(); i++) {
            auto it = lower_bound(primes.begin(), primes.end(), nums[i]);
            int next_prime = *it; 
            int diff = next_prime - nums[i];

            if (i % 2 == 0) steps += diff;
            else if (diff == 0) {
                if (nums[i] == 2) steps += 2;
                else steps++;
            }
        }

        return steps;
    }
};
