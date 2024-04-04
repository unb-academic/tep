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
    T x;
};

template<typename T>
struct Segment
{
    Point<T> A, B;

    bool contains(const Point<T> &P)
    {
        auto xmin = min(A.x, B.x);
        auto xmax = max(A.x, B.x);

        if (P.x < xmin || P.x > xmax)
            return false;

        return true;
    }
};

auto solve()
{
    int N, K;
    cin >> N >> K;

    Point<ll> p;
    Point<ll> q;
    Segment<ll> s;

    Point<ll> best {K};
    vector<Segment<ll>> segments;

    fori (i, 0, N)
    {
        cin >> p.x >> q.x;
        s.A = p;
        s.B = q;

        if (not s.contains(best))
            continue;

        segments.push_back(s);
    }

    ll left = 0, right = 50 + 1;

    for (auto seg : segments)
    {
        if (seg.A.x <= K and K <= seg.B.x)
        {
            left = max(left, seg.A.x);
            right = min(right, seg.B.x);
        }
    }

    if (left == right)
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
