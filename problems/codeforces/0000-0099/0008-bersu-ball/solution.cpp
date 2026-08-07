// Codeforces 489B - BerSU Ball
// Two pointers (opposite direction) on two independently sorted arrays:
// greedily match the smallest unmatched boy with the smallest unmatched
// girl whose dancing skill differs by at most 1.

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n;
    vector<int> boys(n);
    for (int i = 0; i < n; i++)
        cin >> boys[i];
    cin >> m;
    vector<int> girls(m);
    for (int i = 0; i < m; i++)
        cin >> girls[i];

    sort(boys.begin(), boys.end());
    sort(girls.begin(), girls.end());

    int boyIndex = 0, girlIndex = 0, matches = 0;
    while (boyIndex < n && girlIndex < m) {
        if (abs(boys[boyIndex] - girls[girlIndex]) <= 1) {
            boyIndex++;
            girlIndex++;
            matches++;
        } else if (boys[boyIndex] < girls[girlIndex]) {
            boyIndex++;
        } else {
            girlIndex++;
        }
    }

    cout << matches << "\n";
    return 0;
}
