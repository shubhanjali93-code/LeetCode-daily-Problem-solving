Problem code: https://leetcode.com/problems/range-product-queries-of-powers/?envType=daily-question&envId=2025-08-06
class Solution {
public:
    const int MOD = 1e9 + 7;

    // Fast exponentiation for modular inverse
    long long modPow(long long base, long long exp) {
        long long result = 1;
        while (exp > 0) {
            if (exp % 2) result = (result * base) % MOD;
            base = (base * base) % MOD;
            exp /= 2;
        }
        return result;
    }

    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        vector<int> powers;
        for (int i = 0; i < 31; ++i) {
            if (n & (1 << i)) powers.push_back(1 << i);
        }

        int m = powers.size();
        vector<long long> prefix(m);
        prefix[0] = powers[0];
        for (int i = 1; i < m; ++i) {
            prefix[i] = (prefix[i - 1] * powers[i]) % MOD;
        }

        vector<int> answers;
        for (auto& q : queries) {
            int l = q[0], r = q[1];
            long long product = prefix[r];
            if (l > 0) {
                long long inv = modPow(prefix[l - 1], MOD - 2);
                product = (product * inv) % MOD;
            }
            answers.push_back((int)product);
        }
        return answers;
    }
};
