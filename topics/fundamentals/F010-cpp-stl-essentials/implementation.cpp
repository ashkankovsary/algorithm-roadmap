#include <bits/stdc++.h>
using namespace std;

int main() {
    // ---- vector ----
    // Dynamic array: grows automatically as elements are appended.
    vector<int> nums;
    for (int i = 5; i >= 1; i--) {
        nums.push_back(i); // amortized O(1) append
    }
    // nums is now: 5 4 3 2 1

    // ---- sort (default ascending) ----
    sort(nums.begin(), nums.end());
    // nums is now: 1 2 3 4 5

    // ---- sort with a custom comparator (descending) ----
    sort(nums.begin(), nums.end(), [](int a, int b) {
        return a > b;
    });
    // nums is now: 5 4 3 2 1

    // ---- pair ----
    // Grouping two related values together, e.g. an unweighted edge (u, v).
    vector<pair<int, int>> edges;
    edges.push_back({2, 3});
    edges.push_back({1, 4});
    edges.push_back({1, 2});

    // pair has a default comparison: first by .first, then by .second.
    // This lets us sort a vector<pair<int,int>> without writing a comparator.
    sort(edges.begin(), edges.end());
    // edges is now ordered: (1,2) (1,4) (2,3)

    // ---- tuple ----
    // Grouping more than two related values, e.g. a weighted edge (u, v, weight).
    vector<tuple<int, int, int>> weightedEdges;
    weightedEdges.push_back({2, 3, 10});
    weightedEdges.push_back({1, 4, 5});
    weightedEdges.push_back({1, 2, 7});

    // Sort weighted edges by weight (the third element of the tuple).
    sort(weightedEdges.begin(), weightedEdges.end(), [](const auto& a, const auto& b) {
        return get<2>(a) < get<2>(b);
    });

    // Structured bindings: unpack a tuple into named variables.
    for (const auto& edge : weightedEdges) {
        auto [u, v, weight] = edge;
        cout << u << " -> " << v << " (weight " << weight << ")\n";
    }

    return 0;
}