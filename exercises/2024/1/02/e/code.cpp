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
};

auto solve()
{
    ll N, X, T;
    cin >> N >> X >> T;

    if (X > T or N == 1)
    {
        cout << 0 << endl;
        return;
    }
    else if (X == T)
    {
        cout << N - 1 << endl;
        return;
    }

    auto first = max((ll) 0, N - (T/X)) * (T/X);
    auto last = min(N - (ll) 1, (T/X) - (ll) 1) * min(N, T/X) / 2;

    cout << first + last << endl;
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
