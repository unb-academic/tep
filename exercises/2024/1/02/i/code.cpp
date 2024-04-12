#include <bits/stdc++.h>

#define fori(i, ini, lim) for (ll i = ll(ini); i < ll(lim); i++)
#define ford(i, ini, lim) for (ll i = ll(ini); i >= ll(lim); i--)
#define debug(x) cout << #x << " = " << x << endl

using namespace std;

typedef long long ll;
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
    T x, y, q;

    bool operator==(const Point<T> &P) const noexcept
    {
        return equals(x, P.x) and equals(y, P.y);
    }
};

template<typename T>
struct Line
{
    T a, b, c;

    Line(const Point<T> &P, const Point<T> &Q): a(P.y - Q.y), b(Q.x - P.x), c(P.x * Q.y - Q.x * P.y)
    {}

    bool contains(const Point<T> &P) const
    {
        return equals(a*P.x + b*P.y + c, (ll) 0);
    }
};

template<typename T>
struct by_quality
{
    bool operator()(Point<T> const &P, Point<T> const &Q) const
    {
        return P.q < Q.q;
    }
};

auto solve()
{
    ll T, X, Y, Q;
    cin >> T;

    vector<Point<ll>> points(T);
    map<ii, ll> lines;
    
    ll ans = 0;

    fori (i, 0, T)
    {
        cin >> X >> Y >> Q;
        points[i] = Point<ll> { X, Y, Q };
        ans = max(ans, Q);
    }

    fori (i, 0, T)
    {
        fori (j, 0, T)
        {
            if (i == j)
                continue;

            auto dy = points[j].x - points[i].x;
            auto dx = points[j].y - points[i].y;

            // SPOJ uses C++14 which doesn't have gcd() function, only this one.
            auto divisor = __gcd(dx, dy);

            dx /= divisor;
            dy /= divisor;

            lines[make_pair(dy, dx)] += points[j].q;
        }

        for (auto &line : lines)
            ans = max(ans, points[i].q + line.second);

        lines.clear();
    }

    cout << ans << endl;
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
