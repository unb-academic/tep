#include <bits/stdc++.h>

using namespace std;
using ll = long long;

template<typename T>
struct Point {
    T x, y;
};

ll solve(vector<Point<ll>> &points, int N, int K) {
    if (K == 1)
        return -1;
    
    vector<vector<bool>> found(N, vector<bool>(N));
    ll ans = 0;

    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            if (found[i][j])
                continue;

            ll res = 2;
            vector<ll> visited = {i, j};

            auto p = points[i];
            auto q = points[j];

            if (p.x == q.x) {
                for (int k = j + 1; k < N; k++) {
                    if (points[k].x != p.x)
                        continue;

                    res++;
                    visited.push_back(k);
                }
            } else if (p.y == q.y) {
                for (int k = j + 1; k < N; k++) {
                    if (points[k].y != p.y)
                        continue;

                    res++;
                    visited.push_back(k);
                }
            } else {
                ll x = q.x - p.x;
                ll y = q.y - p.y;
                ll eq = p.y * x - p.x * y;

                for (int k = j + 1; k < N; k++) {
                    if (points[k].y * x != points[k].x * y + eq)
                        continue;

                    res++;
                    visited.push_back(k);
                }
            }

            if (res >= K)
                ans++;

            ll size = visited.size();

            if (size > 2)
                for (int a = 0; a < size; a++)
                    for (int b = a + 1; b < size; b++)
                        found[visited[a]][visited[b]] = true;
        }
    }

    return ans;
}

int main() {
    ios::sync_with_stdio(false);

    int N, K;
    cin >> N >> K;

    vector<Point<ll>> points(N);
    Point<ll> p;

    for (int i = 0; i < N; i++) {
        cin >> p.x >> p.y;
        points[i] = p;
    }

    ll ans = solve(points, N, K);

    if (ans == -1)
        cout << "Infinity";
    else
        cout << ans;

    cout << endl;
}
