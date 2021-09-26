#include <bits/stdc++.h>

using namespace std;

bool compare(vector<int>& time1, vector<int>& time2) {
    return time1[1] < time2[1];
}

int main(void) {
    int n;
    cin >> n;

    if(n == 0) {
        cout << 0 << endl;
        return 0;
    }

    vector<vector<int>> times(n, vector<int>(2));
    for(int i = 0; i < n; ++i) {
        cin >> times[i][0] >> times[i][1];
    }

    sort(times.begin(), times.end(), compare);
    int ans = 1, right = times[0][1];
    for(int i = 1; i < n; ++i) {
        if(times[i][0] > right) {
            ++ans;
            right = times[i][1];
        }
    }
    cout << ans << endl;
    return 0;
}
