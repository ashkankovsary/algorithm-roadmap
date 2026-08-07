// Codeforces 279B - Books
// Two pointers (same direction / sliding window): grow the window while
// the remaining time budget stays non-negative, shrink it from the left
// otherwise. The window's length is the number of consecutive books read.

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    long long t;
    cin >> n >> t;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    int left = -1, right = 0, booksRead = 0, best = 0;
    t -= a[0];
    while (right < n) {
        if (t >= 0) {
            booksRead++;
            right++;
            if (right < n)
                t -= a[right];
            if (best < booksRead)
                best = booksRead;
        } else {
            booksRead--;
            left++;
            t += a[left];
        }
    }
    cout << best << "\n";

    return 0;
}
