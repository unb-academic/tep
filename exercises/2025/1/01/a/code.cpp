#include <bits/stdc++.h>
#include <climits>
#include <utility>

using namespace std;

int manhattan_distance(pair<int, int> a, pair<int, int> b) {
    return abs(a.first - b.first) + abs(a.second - b.second);
}

int main() {
    ios::sync_with_stdio(false);

    int N, M, a, b;
    cin >> N >> M;

    vector<pair<int, int>> A(N);
    vector<pair<int, int>> B(M);

    for (int i = 0; i < N; i++) {
        cin >> a >> b;
        A[i] = make_pair(a, b);
    }

    for (int i = 0; i < M; i++) {
        cin >> a >> b;
        B[i] = make_pair(a, b);
    }

    for (auto student : A) {
        auto min_distance = make_pair(INT_MAX, INT_MAX);

        for (int i = 0; i < M; i++) {
            auto checkpoint = B[i];
            int distance = manhattan_distance(student, checkpoint);

            if (distance < min_distance.second)
                min_distance = make_pair(i, distance);
        }

        cout << min_distance.first + 1 << endl;
    }

    return 0;
}
