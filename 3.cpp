#include <bits./stdc++.h>

using namespace std;

string encode(string s) {
    int n = s.size();
    vector<vector<string>>dp (n, vector<string>(n, ""));

    for(int len = 1; len <= n; ++len) {
        for(int i = 0; i < n - len + 1; ++i) {
            int j = i + len - 1;
            string tmp = s.substr(i, len);
            string rep = "";
            dp[i][j] = tmp;
            for(int k = i; k < j; ++k) {
                string leftString = dp[i][k];
                string rightString = dp[k+1][j];
                if(leftString.size() + rightString.size() < dp[i][j].size()) {
                    dp[i][j] = leftString + rightString;
                }
            }
            
            auto pos = (tmp + tmp).find(tmp, 1);
            if(pos >= tmp.size()) {
                rep = tmp;
            }
            else {
                rep = to_string(tmp.size() / pos) + '[' + dp[i][i+pos-1] + ']';
            }
            if(rep.size() < dp[i][j].size()) {
                dp[i][j] = rep;
            }
        }
        
    }
    return dp[0][n-1];
}

int main(void) {
    int ans = 0;
    string s;
    cin >> s;
    cout << encode(s).size() << endl;
    return 0;
}