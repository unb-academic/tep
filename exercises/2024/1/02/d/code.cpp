#include <bits/stdc++.h>
#include <cmath>
#include <iomanip>

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
    T x, y;
};

template<typename T>
double dist(const Point<T> &P, const Point<T> &Q)
{
    return hypot(static_cast<double>(P.x - Q.x), static_cast<double>(P.y - Q.y));
}

template<typename T>
struct Segment
{
    Point<T> A, B;
};

auto solve()
{
    int N, K;
    cin >> N >> K;

    vector<Point<ll>> points(N);
    Point<ll> p;

    fori (i, 0, N)
    {
        cin >> p.x >> p.y;
        points[i] = p;
    }

    double d = 0.0;

    fori (i, 1, N)
        d += dist(points[i], points[i - 1]);

    d *= K;
    d /= 50;

    cout << fixed << setprecision(9) << d << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll N = 1;
    // cin >> N;

    while (N--)
        solve();
}
