// Codeforces 451B - Sort the Array
// Idea: make a sorted copy of the array. Compare it against the original
// to find the boundaries of the mismatched segment. If reversing exactly
// that segment reproduces the sorted copy, the answer is "yes".

#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    bool mismatchStarted = false;
    cin >> n;
    vector<int> original(n);
    for (int i = 0; i < n; i++)
        cin >> original[i];

    vector<int> sorted_ = original;
    sort(sorted_.begin(), sorted_.end());

    int left = 0, right = 0;
    for (int i = 0; i < n; i++)
    {
        if (sorted_[i] != original[i] && mismatchStarted){
            right = i;
        }
        else if (sorted_[i] != original[i] && !mismatchStarted){
            left = i;
            right = i;
            mismatchStarted = true;
        }
    }

    float mid = (float)(right + left) / 2;
    for (int i = left; i < mid; i++)
        swap(sorted_[i], sorted_[(int)(2 * mid) - i]);

    for (int i = 0; i < n; i++)
    {
        if (sorted_[i] != original[i]){
            cout << "no\n";
            return 0;
        }
    }

    cout << "yes\n";
    cout << left + 1 << " " << right + 1 << "\n";

    return 0;
}
