// Codeforces 1097B - Petr and a Combination Lock
// Idea: brute-force every combination of rotation directions using an
// n-bit mask (bit i set = add angle i, bit i clear = subtract angle i),
// and check whether any combination sums to a multiple of 360.
#include <bits/stdc++.h>
using namespace std;

bool isBitSet(int mask, int i) {
    return (mask & (1 << i)) != 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    int mask = 1 << n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    while (mask--) {
        int sum = 0;
        for (int i = 0; i < n; i++) {
            if (isBitSet(mask, i))
                sum += a[i];
            else
                sum -= a[i];
        }

        if (sum % 360 == 0) {
            cout << "YES\n";
            return 0;
        }
    }

    cout << "NO\n";
    return 0;
}
