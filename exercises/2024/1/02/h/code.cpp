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
    T x, y;

    bool operator==(const Point<T> &p) const noexcept
    {
        return equals(x, p.x) and equals(y, p.y);
    }
};

template<typename T>
T D(const Point<T>& P, const Point<T>& Q, const Point<T>& R)
{
    return (P.x * Q.y + P.y * R.x + Q.x * R.y) - (R.x * Q.y + R.y * P.x + Q.x * P.y);
}

template<typename T>
struct Segment
{
    Point<T> A, B;

    bool operator==(const Segment<T> &r) const noexcept
    {
        return (A == r.A) and (B == r.B);
    }

    bool contains(const Point<T>& P) const
    {
        auto xmin = min(A.x, B.x);
        auto xmax = max(A.x, B.x);
        auto ymin = min(A.y, B.y);
        auto ymax = max(A.y, B.y);

        if (P.x < xmin || P.x > xmax || P.y < ymin || P.y > ymax)
            return false;

        return equals((P.y - A.y)*(B.x - A.x), (P.x - A.x)*(B.y - A.y));
    }

    bool intersect(const Segment<T> &s) const
    {
        auto d1 = D(A, B, s.A);
        auto d2 = D(A, B, s.B);

        if ((equals(d1, (T) 0) && contains(s.A)) || (equals(d2, (T) 0) && contains(s.B)))
            return true;

        auto d3 = D(s.A, s.B, A);
        auto d4 = D(s.A, s.B, B);

        if ((equals(d3, (T) 0) && s.contains(A)) || (equals(d4, (T) 0) && s.contains(B)))
            return true;

        return (d1 * d2 < (T) 0) && (d3 * d4 < (T) 0);
    }
};

const int MAX = 1001;

vector<ll> adj[MAX];
bitset<MAX> visited;

void dfs(int u)
{
    if (visited[u])
        return;

    visited[u] = true;

    for (auto v : adj[u])
        dfs(v);
}

auto solve()
{
    ll N, M, X, Y;
    cin >> N >> M;

    Point<ll> p, q;
    vector<Segment<ll>> segments(N);

    for (auto &v : adj)
        v.clear();

    fori (i, 0, N)
    {
        cin >> p.x >> p.y >> q.x >> q.y;
        segments[i] = Segment<ll> { p, q };
    }

    fori (i, 0, N)
    {
        fori (j, i + 1, N)
        {
            auto r = segments[i];
            auto s = segments[j];

            if (i == j or not r.intersect(s))
                continue;

            adj[i].push_back(j);
            adj[j].push_back(i);
        }
    }

    while (M--)
    {
        cin >> X >> Y;

        if (X == Y)
        {
            cout << "YES" << endl;
            continue;
        }

        visited.reset();
        dfs(Y - 1);

        if (visited[X - 1])
            cout << "YES";
        else
            cout << "NO";

        cout << endl;
    }
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
