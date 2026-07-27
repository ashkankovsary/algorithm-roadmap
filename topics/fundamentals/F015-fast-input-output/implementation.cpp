#include <bits/stdc++.h>
using namespace std;

int main() {
    // ---- Fast I/O setup ----
    // Must be the first statements in main, before any read or write.
    ios_base::sync_with_stdio(false); // stop syncing with C stdio
    cin.tie(nullptr);                 // stop flushing cout before every cin read

    // ---- reading input ----
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    // ---- processing ----
    long long sum = 0;
    for (int x : a) {
        sum += x;
    }

    // ---- writing output ----
    // '\n' instead of endl: endl forces a flush on every call, which is
    // slow when used repeatedly; '\n' just inserts a newline character.
    cout << sum << '\n';

    return 0;
}
