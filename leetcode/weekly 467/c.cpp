#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector")
#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using vi = vector<ll>;

#define sz(x) int(x.size())
#define fi first
#define se second
#define pb push_back
#define edl '\n'

template <typename T>
void fill_seq(vector<T> &v, T start = 1) {
    iota(v.begin(), v.end(), start);
}

constexpr long long LLINF = 2e18;
constexpr int INF = 2e9;
constexpr int MOD = 1e9 + 7;
constexpr int MxN = 2e5 + 5;
constexpr int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

void solve() {
    int n;
    cin >> n;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    while (t--) {
        solve();
    }
    return 0;
}

class Solution {
public:
    bool canSum(int k, const vector<int>& v, int idx, vector<vector<int8_t>>& memo) {
        if (k == 0) return true;                  
        if (idx >= (int)v.size() || k < 0) return false; 

        int8_t &cell = memo[idx][k];
        if (cell != -1) return cell;
        bool ok = canSum(k, v, idx + 1, memo);

        if (!ok && v[idx] <= k) {
            ok = canSum(k - v[idx], v, idx + 1, memo);
        }

        cell = ok;
        return ok;
    }
    vector<bool> subsequenceSumAfterCapping(vector<int>& nums, int k) {
        vector<bool> ans(nums.size());
        vector<int> tmp;

        int i = 0;
        while(i < ans.size()) {
            int x = i + 1;
            tmp = nums;
            for(int j = 0; j < ans.size(); j++) {
                tmp[j] = min(tmp[j], x);
            }
            vector<vector<int8_t>> memo(ans.size() + 1, vector<int8_t>(k + 1, -1));
            ans[i] = canSum(k, tmp, 0, memo);
            i++;
        }
        return ans;
    }
};