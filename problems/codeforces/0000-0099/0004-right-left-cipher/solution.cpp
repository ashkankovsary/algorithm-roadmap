// Codeforces 1085A - Right-Left Cipher
// Idea: the last character added to the encoded string is deducible
// from its length parity (odd -> added on the left, even -> added on
// the right). Recursively peel that character off and recurse on the
// remaining substring to reconstruct the original string.

#include <bits/stdc++.h>
using namespace std;

string decode(string_view encoded) {
    if (encoded.length() == 1) {
        return string(encoded);     // Base Case
    }

    if (encoded.length() % 2 == 0) {
        // Last character added was on the right
        return decode(encoded.substr(0, encoded.length() - 1)) + encoded.back();
    }
    // Last character added was on the left
    return decode(encoded.substr(1)) + encoded.front();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string encoded;
    cin >> encoded;
    cout << decode(encoded) << "\n";

    return 0;
}
