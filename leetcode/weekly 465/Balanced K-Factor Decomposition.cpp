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

vector<ll> get_divisors(ll n) {
          vector<ll> divs;
          for (int i = 1; 1LL * i * i <= n; i++) {
            if (n % i == 0) {
              divs.push_back(i);
              if (i != n / i) {
                divs.push_back(n / i);
              }
            }
          }
          sort(divs.begin(), divs.end());
          return divs;
}   

class Solution {
public:
    vector<int> minDifference(int n, int k) {
        
           
    }
};