// F035 - Two Pointers
// Two core patterns: opposite-direction pointers (sorted two-sum) and
// same-direction pointers (removing duplicates from a sorted array).
// Both rely on the array being sorted and the search space being monotonic.

#include <bits/stdc++.h>
using namespace std;

// Returns the indices (0-based) of two elements in a sorted array
// whose sum equals target. Returns {-1, -1} if no such pair exists.
pair<int, int> twoSumSorted(const vector<int>& arr, int target) {
    if (arr.empty()) {
        return {-1, -1};
    }

    int left = 0;
    int right = arr.size() - 1;

    while (left < right) {
        int currentSum = arr[left] + arr[right];

        if (currentSum == target) {
            return {left, right};
        } else if (currentSum < target) {
            left++;   // need a bigger sum
        } else {
            right--;  // need a smaller sum
        }
    }

    return {-1, -1};
}

// Removes duplicates from a sorted array in-place.
// Returns the new logical length; elements beyond it are unspecified
// and must not be accessed by the caller.
int removeDuplicates(vector<int>& arr) {
    if (arr.empty()) {
        return 0;
    }

    int n = arr.size();
    int slow = 0; // index of the last unique element placed so far

    for (int fast = 1; fast < n; fast++) {
        if (arr[fast] != arr[slow]) {
            slow++;
            arr[slow] = arr[fast];
        }
    }

    return slow + 1; // number of unique elements
}

int main() {
    // --- Example 1: opposite-direction pointers ---
    // Classic sorted two-sum: find two indices whose values sum to target.
    {
        vector<int> sorted1 = {2, 7, 11, 15};
        int target = 9;

        pair<int, int> result = twoSumSorted(sorted1, target);
        cout << "twoSumSorted -> indices: ("
             << result.first << ", " << result.second << ")" << endl;
        // expected: (0, 1)
    }

    // --- Example 2: same-direction pointers ---
    // Remove duplicates from a sorted array, in-place.
    {
        vector<int> sorted2 = {1, 1, 2, 2, 3, 4, 4, 5};
        int newLength = removeDuplicates(sorted2);

        cout << "removeDuplicates -> new length: " << newLength << ", array: ";
        for (int i = 0; i < newLength; i++) {
            cout << sorted2[i] << " ";
        }
        cout << endl;
        // expected: new length: 5, array: 1 2 3 4 5
    }
}
