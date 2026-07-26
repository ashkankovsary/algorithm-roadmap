// Codeforces 2153A - Circle of Apple Trees
// Idea: sort the beauty values; the answer is the number of distinct
// values, since one apple of each distinct beauty can always be eaten
// across successive laps around the circle, in increasing order.

#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while (t--)
    {
        int n, distinctCount = 1;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];

        sort(a.begin(), a.end());

        int last = a[0];
        for (int value : a)
        {
            if (last < value){
                last = value;
                distinctCount++;
            }
        }
        cout << distinctCount << "\n";
    }

    return 0;
}
