// F030 - Binary Search on Answer
// Two generic templates: smallest value for which check() is true, and
// largest value for which check() is true. Both assume check() is
// monotonic over the given [lo, hi] range.

#include <bits/stdc++.h>
using namespace std;

// Finds the smallest value in [lo, hi] for which check(x) is true.
// Assumes the pattern: false, false, ..., false, true, true, ..., true.
long long binarySearchSmallestTrue(long long lo, long long hi, function<bool(long long)> check) {
    while (lo < hi) {
        long long mid = lo + (hi - lo) / 2; // round down
        if (check(mid)) {
            hi = mid;
        } else {
            lo = mid + 1;
        }
    }
    return lo;
}

// Finds the largest value in [lo, hi] for which check(x) is true.
// Assumes the pattern: true, true, ..., true, false, false, ..., false.
long long binarySearchLargestTrue(long long lo, long long hi, function<bool(long long)> check) {
    while (lo < hi) {
        long long mid = lo + (hi - lo + 1) / 2; // round up, see README
        if (check(mid)) {
            lo = mid;
        } else {
            hi = mid - 1;
        }
    }
    return lo;
}

int main() {
    // --- Example 1: smallest-true pattern ---
    // Scenario inspired by "Koko Eating Bananas": given pile sizes and a
    // time limit h, find the smallest eating speed that finishes all
    // piles in time. check(speed) is true once the speed is fast enough.
    {
        vector<long long> piles = {3, 6, 7, 11};
        long long h = 8;

        auto check = [&](long long speed) -> bool {
            long long hours = 0;
            for (long long pile : piles) {
                hours += (pile + speed - 1) / speed; // ceiling division
            }
            return hours <= h;
        };

        long long lo = 1;
        long long hi = *max_element(piles.begin(), piles.end());

        long long answer = binarySearchSmallestTrue(lo, hi, check);
        cout << "Smallest-true example answer: " << answer << endl; // expected: 4
    }

    // --- Example 2: largest-true pattern ---
    // Scenario inspired by "Aggressive Cows": given stall positions and a
    // number of cows, find the largest minimum distance achievable
    // between any two cows. check(dist) is true while dist is small
    // enough to still fit all cows.
    {
        vector<long long> stalls = {1, 2, 4, 8, 9};
        long long cows = 3;
        sort(stalls.begin(), stalls.end());

        auto check = [&](long long dist) -> bool {
            long long placed = 1;
            long long lastPosition = stalls[0];
            for (size_t i = 1; i < stalls.size(); i++) {
                if (stalls[i] - lastPosition >= dist) {
                    placed++;
                    lastPosition = stalls[i];
                }
            }
            return placed >= cows;
        };

        long long lo = 0;
        long long hi = stalls.back() - stalls.front();

        long long answer = binarySearchLargestTrue(lo, hi, check);
        cout << "Largest-true example answer: " << answer << endl; // expected: 3
    }
}
