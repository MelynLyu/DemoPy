#include <bits/stdc++.h>

using namespace std;

int n, a, b;
char c;
vector<vector<int>> dir = {{1,0},{0,1},{0,-1},{-1,0}};

bool dfs(vector<vector<int>>& metrics, vector<vector<bool>>& vis, int x, int y, int d) {
    if(x == n-1 && y == n-1) {
        return true;
    }
        
    vis[x][y] = true;
    int i, j, k;
    for(k = 0; k < 4; k++) {
        i = x + dir[k][0];
        j = y + dir[k][1];
        if(i >= 0 && i < n && j >= 0 && j < n && !vis[i][j] && abs(metrics[x][y] - metrics[i][j]) <= d) {
            if(dfs(metrics, vis, i, j, d)){
                return true;
            }
        }
    }        
    return false;
}

int main(void) {
    cin >> n >> a >> b;
    vector<vector<int>> metrics(n, vector<int>(n));
    vector<int> tp;
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            cin >> c;
            if(c == '.') {
                metrics[i][j] = 0;
            }
            else if(c == '#') {
                metrics[i][j] = a;
            }
            else {
                metrics[i][j] = b;
                tp.push_back(i);
                tp.push_back(j);
            }
        }
    }

    int l = 0, r = 1000, mid, ans = 0;
    while(l <= r) {
        mid = l + ((r-l)>>1);
        vector<vector<bool>> vis(n, vector<bool>(n, false));
        if(dfs(metrics, vis, 0, 0, mid)) {
            r = mid-1;
            ans = mid;
        }
        else{
            l = mid+1;
        }                
    }
    cout << ans << endl;
}
