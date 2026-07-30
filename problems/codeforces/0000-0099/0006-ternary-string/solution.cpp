// Codeforces 1354B2 - Ternary String
// Binary search (smallest-true pattern) on the window length k: check(k)
// slides a window of length k across the string and reports whether any
// such window contains all three characters ('1', '2', '3').

#include <bits/stdc++.h>
using namespace std;

int binarySearchSmallestTrue(int lo, int hi, function<bool(int)> check) {
    if (!check(hi))
        return 0;
    while (lo < hi) {
        int mid = lo + (hi - lo) / 2;
        if (check(mid))
            hi = mid;
        else
            lo = mid + 1;
    }
    return lo;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;

        auto check = [&](int k) -> bool {
            vector<int> charCount(3, 0);
            for (size_t i = 0; i < k; i++)
                charCount[s[i] - '1']++;

            if (charCount[0] && charCount[1] && charCount[2])
                return true;

            for (size_t i = 0; i < s.size() - k; i++) {
                charCount[s[i] - '1']--;
                charCount[s[i + k] - '1']++;
                if (charCount[0] && charCount[1] && charCount[2])
                    return true;
            }
            return false;
        };

        int lo = 3;
        int hi = s.size();
        cout << binarySearchSmallestTrue(lo, hi, check) << "\n";
    }

    return 0;
}
