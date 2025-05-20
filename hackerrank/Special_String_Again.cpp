#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'substrCount' function below.
 *
 * The function is expected to return a LONG_INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. STRING s
 */

long substrCount(int n, string s) {
    vector<int> v(n, 0);
    int ans = 0;
    int j = 0;

    for (int i = 0; i < n; i = j) {
        j = i + 1;
        int c = 1;
        while(j < n && s[i] == s[j]) {
            j++;
            c++;
        }
        ans += (c * (c + 1)) >> 1; //FÓRMULA PARA NÚMERO DE SUBSTRINGS CON CARACTERES IGUALES
        v[i] = c;
        
    }

    for (int i = 1; i < n - 1; i++) {
        if (s[i] == s[i - 1]) {
            v[i] = v[i - 1];
        }

        if (s[i - 1] == s[i + 1] && s[i] != s[i - 1]) {
            ans += min(v[i - 1], v[i + 1]);
        }
    }
    cout << ans << '\n';
    return ans;
}

int main() {
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    string s;
    getline(cin, s);

    long result = substrCount(n, s);

    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace))));

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end());

    return s;
}
