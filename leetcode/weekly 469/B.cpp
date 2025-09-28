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
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}

class Solution {
public:
    long long splitArray(vector<int>& nums) {
        int n = nums.size();
        vector<bool> inc(n, 0), dec(n, 0);
        inc[0] = 1;
        for(int i = 1; i < n; i++) 
            inc[i] = inc[i - 1] && (nums[i - 1] < nums[i]);
        dec[n - 1] = 1;
        for(int i = n - 2; i >= 0; i--)
            dec[i] = dec[i+1] && (nums[i] > nums[i+1]);
        
        vector<long long> sum(n+1, 0);
        for(int i = 0; i < n; i++) {
            sum[i + 1] = sum[i] + nums[i];
        }

        long long ans = LLONG_MAX;
        for(int i = 0; i < n-1; i++) {
            if(inc[i] && dec[i+1]) {
                long long l = sum[i + 1];
                long long r = sum[n] - sum[i + 1];
                ans = min(ans, llabs(l - r));
            }
        }
        return ans == LLONG_MAX ? -1 : ans;
    }
};