#include <bits/stdc++.h>

using namespace std;

template<typename T>
bool equals(T a, T b) {
    constexpr double EPS { 1e-9 };
    return is_floating_point<T>::value ? fabs(a - b) < EPS : a == b;
}

template<typename T>
struct Point {
    T x, y;

    bool operator==(const Point<T> &P) const noexcept {
        return equals(x, P.x) and equals(y, P.y);
    }
};

template<typename T>
struct Line {
    T a, b, c;

    Line(const Point<T> &P, const Point<T> &Q)
        : a(P.y - Q.y), b(Q.x - P.x), c(P.x * Q.y - Q.x * P.y)
    {}

    bool contains(const Point<T> &P) const {
        return equals(a * P.x + b * P.y + c, 0);
    }
};

int main() {
    ios::sync_with_stdio(false);

    int N;
    cin >> N;

    vector<Point<int>> V(N);
    bool ok = false;

    for (int i = 0; i < N; i++) {
        Point<int> p;
        cin >> p.x >> p.y;

        V[i] = p;
    }

    for (auto p : V) {
        for (auto q : V) {
            if (p == q)
                continue;
            
            Line l(p, q);
            int count = 0;

            for (auto r : V)
                if (l.contains(r))
                    count++;

            if (count >= 3)
                ok = true;

            if (ok)
                break;
        }

        if (ok)
            break;
    }

    cout << (ok ? "Yes" : "No") << endl;
}
