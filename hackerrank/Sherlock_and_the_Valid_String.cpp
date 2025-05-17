#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'isValid' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

string isValid(string s) {
    vector<int> v(26, 0);
    int m = 0;
    for (auto c : s) {
        v[c - 'a']++;
    }
    map<int, int> n;
    sort(v.rbegin(), v.rend());
    for (auto c : v) {
        if(c == 0)
            break;
        n[c]++;
        m = max(m, n[c]);
    }
    for (auto c : n) {
        if(c.second == m) {
            m = c.first;
            break;
        }
    }
    bool ok = true;
    for(auto c : v) {
        if (c == 0)
            break;
        if (c != m) {
            if (abs(c - m) > 1 && c > 1)
                return "NO";
            else if(abs(c - m) == 1 || c == 1) {
                if(ok)
                    ok = false;
                else 
                    return "NO";
            }
        }
    }
    return "YES";
}

int main() {
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = isValid(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
