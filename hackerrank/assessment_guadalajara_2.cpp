#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);


/*
 * Complete the 'getTotalBalanced' function below.
 *
 * The function is expected to return a LONG_INTEGER.
 * The function accepts INTEGER_ARRAY capacity as parameter.
 */

long getTotalBalanced(vector<int> capacity) {
    int n = capacity.size();
    vector<long long> v(n + 1, 0);
    for(int i = 0; i < n; i++) {
        v[i+1] = v[i] + capacity[i];
    }

    long long ans = 0;
    for(int i = 0; i + 2 < n; i++) {
        for(int j = i+2; j < n; j++) {
            if(capacity[i] != capacity[j]) continue;
            if(v[j] - v[j+1] == capacity[i]) {
                ans++;
            }
        }
    }
    return ans;
}
int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string capacity_count_temp;
    getline(cin, capacity_count_temp);

    int capacity_count = stoi(ltrim(rtrim(capacity_count_temp)));

    vector<int> capacity(capacity_count);

    for (int i = 0; i < capacity_count; i++) {
        string capacity_item_temp;
        getline(cin, capacity_item_temp);

        int capacity_item = stoi(ltrim(rtrim(capacity_item_temp)));

        capacity[i] = capacity_item;
    }

    long result = getTotalBalanced(capacity);

    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
