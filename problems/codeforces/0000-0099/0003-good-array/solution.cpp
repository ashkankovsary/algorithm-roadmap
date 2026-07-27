// Codeforces 1077C - Good Array
// Idea: track the two largest values (and their indices) in one linear
// pass. Use the total sum together with these two values to decide
// whether the array is already good, or which single element (if any)
// could be removed to make it good.

#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<pair<int,int>> a(n); // {value, original 1-based index}
    for (int i = 0; i < n; i++){
        cin >> a[i].first;
        a[i].second = i + 1;
    }

    pair<int,int> m1 = a[0], m2 = a[1];
    long long sum = a[0].first;

    for (int i = 1; i < n; i++){
        sum += a[i].first;
        if (m1.first < a[i].first){
            m2 = m1;
            m1 = a[i];
        }
        else if (m2.first < a[i].first && m2.first <= m1.first){
            m2 = a[i];
        }
    }
    sum -= m1.first; // sum of all elements except the current maximum

    vector<int> o;
    long long c = sum - m1.first; // must be long long, can exceed int range

    if (m1.first != m2.first){
        // the maximum value appears exactly once
        if (sum == 2 * m2.first)
            o.push_back(m1.second);

        if (c != m1.first)
            for (auto& x : a)
                if (x.first == c)
                    o.push_back(x.second);
    }
    else{
        // the maximum value is duplicated; removing one copy still
        // leaves the same maximum value in the remaining array
        for (auto& x : a)
            if (x.first == c)
                o.push_back(x.second);
    }

    cout << o.size() << "\n";
    for (int idx : o)
        cout << idx << " ";
    cout << "\n";

    return 0;
}
