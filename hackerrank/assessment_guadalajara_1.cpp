#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);



/*
 * Complete the 'countPromotionalPeriods' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts INTEGER_ARRAY orders as parameter.
 */

int countPromotionalPeriods(vector<int> orders) {
    int n = orders.size();
    if (n < 3) return 0;
    stack<long long> s;
    int ans = 0;
    for(auto x : orders) {
        while(!s.empty() && s.top() < x) {
            ans++;
            s.pop();
        }
        if(!s.empty())
            ans++;
        s.push(x);
    }

    return ans;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string orders_count_temp;
    getline(cin, orders_count_temp);

    int orders_count = stoi(ltrim(rtrim(orders_count_temp)));

    vector<int> orders(orders_count);

    for (int i = 0; i < orders_count; i++) {
        string orders_item_temp;
        getline(cin, orders_item_temp);

        int orders_item = stoi(ltrim(rtrim(orders_item_temp)));

        orders[i] = orders_item;
    }

    int result = countPromotionalPeriods(orders);

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
