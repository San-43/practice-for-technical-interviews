#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {

        vector<vector<int>> dp(m, vector<int>(n, 0));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int top = (i > 0) ? dp[i - 1][j] : INT_MAX;
                int left = (j > 0) ? dp[i][j - 1] : INT_MAX;
                if (i == 0 && j == 0) {
                    dp[i][j] = 1;
                } else {
                    if (top != INT_MAX && left != INT_MAX)
                        dp[i][j] = top + left;
                    else if (top != INT_MAX)
                        dp[i][j] = top;
                    else
                        dp[i][j] = left;
                }
            }
        }
        return dp[m - 1][n - 1];
    }
};