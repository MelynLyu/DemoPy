#include <bits/stdc++.h>

using namespace std;

int func1(long long n) {
    if(n <= 1) {
        return 1;
    }

    if(n % 2 == 0) {
        return func(n/2);
    }
    else{
        return 1 + func((n-1)/2);
    }
}

int func2(long long n) {
    int k = (int)ceil(log2(n))
    long long base = pow(2, k);
    return 1 + func1(base - n);
}

int main(void) {
    long long n;
    cin >> n;
    cout << min(func1(n), func2(n)) << endl;
}
