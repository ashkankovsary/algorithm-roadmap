// Codeforces 660C - Hard Process
// Binary search (largest-true pattern) on the window length x: check(x)
// slides a window of length x across the array and reports whether some
// such window has at most k zeroes. The starting index of the first
// feasible window found is remembered so the final array can be printed.

#include <bits/stdc++.h>
using namespace std;

int windowStart;

int binarySearchLargestTrue(int lo, int hi, function<bool(int)> check) {
    while (lo < hi) {
        int mid = lo + (hi - lo + 1) / 2;
        if (check(mid))
            lo = mid;
        else
            hi = mid - 1;
    }
    return lo;
}

void printResult(int ans, vector<int>& a) {
    for (size_t i = 0; i < a.size(); i++) {
        if (i >= windowStart && i < windowStart + ans)
            cout << "1 ";
        else
            cout << a[i] << " ";
    }
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int& i : a)
        cin >> i;

    auto check = [&](int x) -> bool {
        int zeroCount = 0;
        for (size_t i = 0; i < x; i++)
            if (a[i] == 0)
                zeroCount++;

        if (zeroCount <= k) {
            windowStart = 0;
            return true;
        }

        for (size_t i = 0; i < a.size() - x; i++) {
            if (a[i] == 0)
                zeroCount--;
            if (a[i + x] == 0)
                zeroCount++;
            if (zeroCount <= k) {
                windowStart = i + 1;
                return true;
            }
        }
        return false;
    };

    int lo = 0;
    int hi = a.size();
    int ans = binarySearchLargestTrue(lo, hi, check);
    cout << ans << "\n";
    printResult(ans, a);
    return 0;
}
