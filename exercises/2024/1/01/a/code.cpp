#include <bits/stdc++.h>

using namespace std;

pair<long double, double> rotate(pair<int, int> point, int angle) {
    long double theta = angle * (M_PI / 180);

    long double s = sin(theta);
    long double c = cos(theta);

    long double x = point.first * c - point.second * s;
    long double y = point.second * c + point.first * s;

    return make_pair(x, y);
}

int main() {
    ios::sync_with_stdio(false);

    int A, B, D;
    cin >> A >> B >> D;

    auto ans = rotate(make_pair(A, B), D);
    cout << setprecision(9) << ans.first << ' ' << ans.second << endl;

    return 0;
}
