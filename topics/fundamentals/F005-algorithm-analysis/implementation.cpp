#include <bits/stdc++.h>
using namespace std;

// O(1) - Constant Time
// No dependency on n, just a single fixed operation
long long constantTime(vector<int>& arr) {
    return arr.empty() ? 0 : arr[0];
}

// O(n) - Linear Time
// We pass through all elements exactly once
long long linearTime(vector<int>& arr) {
    long long sum = 0;
    for (int i = 0; i < (int)arr.size(); i++) {
        sum += arr[i];
    }
    return sum;
}

// O(n log n) - Linearithmic Time
// Sorting, the foundation of many future algorithms
long long linearithmicTime(vector<int> arr) {
    sort(arr.begin(), arr.end());
    return arr.empty() ? 0 : arr.back();
}

// O(n^2) - Quadratic Time
// Nested loop: for every pair (i, j) we do some work
long long quadraticTime(vector<int>& arr) {
    long long count = 0;
    int n = arr.size();
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] == arr[j]) {
                count++;
            }
        }
    }
    return count;
}

int main() {
    for (int n : {1000, 2000, 4000, 8000}) {
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            arr[i] = rand() % n;
        }

        clock_t start, end;

        start = clock();
        constantTime(arr);
        end = clock();
        double t1 = (double)(end - start) * 1000.0 / CLOCKS_PER_SEC;

        start = clock();
        linearTime(arr);
        end = clock();
        double t2 = (double)(end - start) * 1000.0 / CLOCKS_PER_SEC;

        start = clock();
        linearithmicTime(arr);
        end = clock();
        double t3 = (double)(end - start) * 1000.0 / CLOCKS_PER_SEC;

        start = clock();
        quadraticTime(arr);
        end = clock();
        double t4 = (double)(end - start) * 1000.0 / CLOCKS_PER_SEC;

        cout << "n = " << n << "\n";
        cout << "  O(1)       : " << t1 << " ms\n";
        cout << "  O(n)       : " << t2 << " ms\n";
        cout << "  O(n log n) : " << t3 << " ms\n";
        cout << "  O(n^2)     : " << t4 << " ms\n";
        cout << "-----------------------------\n";
    }

    return 0;
}
