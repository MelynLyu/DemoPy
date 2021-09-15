#include <bits/stdc++.h>

using namespace std;

int GCD(int a, int b) {
    return b ? GCD(b, a % b) : a;
}

int ans = 0;

void recur(vector<int>& nums, int pos, int c, int p, set<vector<int>>& res, vector<int>& path) {
    if(c == p) {
        if(!res.count(path)) {
            res.emplace(path);
            ++ans;
        }
        return;
    }
    if(c > p) {
        return;
    }
    if(pos >= nums.size()) {
        return;
    }
       
    
    int sumC = nums[pos] * c + p;
    int sumP = nums[pos] * p;
    int gcd = GCD(sumC, sumP);
    sumC /= gcd;
    sumP /= gcd;
    path.emplace_back(nums[pos]);
    recur(nums, pos+1, sumC, sumP, res, path);
    path.pop_back();

    recur(nums, pos+1, c, p, res, path); 
}

int main(void) {
    int n;
    cin >> n;

    
    vector<int> nums(n);
    for(int i = 0; i < n; ++i) {
        cin >> nums[i];
    }
    sort(nums.begin(), nums.end());

    vector<int> path;
    set<vector<int>> res;
    recur(nums, 0, 0, 1, res, path);

    if(ans > 0) {
        cout << ans << endl;
    }
    else {
        cout << "No solution!" << endl;
    }
    
    return 0;
}