#include <bits/stdc++.h>

#define fori(i, ini, lim) for (ll i = ll(ini); i < ll(lim); i++)
#define ford(i, ini, lim) for (ll i = ll(ini); i >= ll(lim); i--)
#define debug(x) cout << #x << " = " << x << endl

using namespace std;

typedef long long ll;
typedef pair<ll, ll> ii;
typedef tuple<ll, ll, ll> iii;

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
    ll idx;
};

double dist(const Point<ll>& p, const Point<ll>& q)
{
    return hypot(p.x - q.x, p.y - q.y);
}

pair<Point<ll>, Point<ll>> closest_pair(vector<Point<ll>>& points)
{
    sort(points.begin(), points.end(), [](const Point<ll>& p, const Point<ll>& q) {
        if (p.x == q.x)
            return p.y < q.y;
        else
            return p.x < q.x;
    });

    auto d = dist(points[0], points[1]);
    auto closest = make_pair(points[0], points[1]);

    set<iii> S;
    S.insert(iii(points[0].y, points[0].x, points[0].idx));
    S.insert(iii(points[1].y, points[1].x, points[1].idx));

    fori (i, 2, points.size())
    {
        auto P = points[i];
        auto it = S.lower_bound(iii(P.y - d, 0, P.idx));

        while (it != S.end())
        {
            auto Q = Point<ll> { .x = get<1>(*it), .y = get<0>(*it), .idx = get<2>(*it) };

            if (Q.x < P.x - d)
            {
                it = S.erase(it);
                continue;
            }

            if (Q.y > P.y + d)
                break;

            auto t = dist(P, Q);

            if (t < d)
            {
                d = t;
                closest = make_pair(P, Q);
            }

            it++;
        }

        S.insert(iii(P.y, P.x, P.idx));
    }

    return closest;
}

auto solve()
{
    ll N;
    cin >> N;

    vector<Point<ll>> points(N);

    fori (i, 0, N) {
        cin >> points[i].x >> points[i].y;
        points[i].idx = i;
    }

    auto [p, q] = closest_pair(points);

    if (p.idx > q.idx)
        cout << q.idx << ' ' << p.idx;
    else
        cout << p.idx << ' ' << q.idx;

    cout << ' ' << fixed << setprecision(6) << hypot(p.x - q.x, p.y - q.y) << endl;
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
