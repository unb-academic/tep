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
    int K, S;
    cin >> K >> S;

    int ans = 0;

    fori(x, 0, K + 1)
    {
        fori(y, 0, K + 1)
        {
            if (x + y <= S && S - x - y <= K)
                ans++;
        }
    }

    cout << ans << endl;
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
