#include <bits/stdc++.h>

#define fori(i, ini, lim) for (ll i = ll(ini); i < ll(lim); i++)
#define ford(i, ini, lim) for (ll i = ll(ini); i >= ll(lim); i--)
#define debug(x) cout << #x << " = " << x << endl
#define ZERO (ll) 0

using namespace std;

typedef double ll;
typedef pair<ll, ll> ii;

const double EPS { 1e-9 };

template<typename T>
bool equals(T a, T b)
{
    if (is_floating_point<T>::value)
        return fabs(a - b) < EPS;
    else
        return a == b;
}

template<typename T>
struct Point
{
    T x, y;
};

template<typename T>
T D(const Point<T> &P, const Point<T> &Q, const Point<T> &R)
{
    return (P.x * Q.y + P.y * R.x + Q.x * R.y) - (R.x * Q.y + R.y * P.x + Q.x * P.y);
}

template<typename T>
struct Segment
{
    Point<T> A, B;

    bool contains(const Point<T> &P) const
    {
        T xmin = min(A.x, B.x);
        T xmax = max(A.x, B.x);
        T ymin = min(A.y, B.y);
        T ymax = max(A.y, B.y);

        if (P.x < xmin or P.x > xmax or P.y < ymin or P.y > ymax)
            return false;

        return equals((P.y - A.y)*(B.x - A.x), (P.x - A.x)*(B.y - A.y));
    }

    bool intersect(const Segment<T> &s) const
    {
        auto d1 = D(A, B, s.A);
        auto d2 = D(A, B, s.B);

        if ((equals(d1, ZERO) && contains(s.A)) || (equals(d2, ZERO) && contains(s.B)))
            return true;

        auto d3 = D(s.A, s.B, A);
        auto d4 = D(s.A, s.B, B);

        if ((equals(d3, ZERO) && s.contains(A)) || (equals(d4, ZERO) && s.contains(B)))
            return true;

        return (d1 * d2 < ZERO) && (d3 * d4 < ZERO);
    }
};

auto solve()
{
    ll x1, y1, x2, y2, x3, y3, x4, y4;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;

    Segment<ll> r = { Point<ll> { x1, y1 }, Point<ll> { x2, y2 } };
    Segment<ll> s = { Point<ll> { x3, y3 }, Point<ll> { x4, y4 } };

    if (r.intersect(s))
        cout << "YES";
    else
        cout << "NO";

    cout << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll N = 1;
    cin >> N;

    while (N--)
        solve();
}
