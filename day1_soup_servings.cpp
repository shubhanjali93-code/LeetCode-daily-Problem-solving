class Solution {
public:
    unordered_map<int, unordered_map<int, double>> memo;

    double dp(int a, int b) {
        if (a <= 0 && b <= 0) return 0.5;
        if (a <= 0) return 1.0;
        if (b <= 0) return 0.0;
        if (memo[a][b]) return memo[a][b];

        memo[a][b] = 0.25 * (
            dp(a - 4, b) +
            dp(a - 3, b - 1) +
            dp(a - 2, b - 2) +
            dp(a - 1, b - 3)
        );
        return memo[a][b];
    }

    double soupServings(int n) {
        if (n >= 5000) return 1.0; 
        int scaled = ceil(n / 25.0);
        return dp(scaled, scaled);
    }
};
