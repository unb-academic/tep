#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);

    int T, N, X, Y;
    cin >> T;

    while (T--) {
        cin >> N;

        int right = 0;
        int up = 0;
        int left = 0;
        int down = 0;

        while (N--) {
            cin >> X >> Y;

            if (X > 0 and X > right)
                right = X;
            else if (Y > 0 and Y > up)
                up = Y;
            else if (X < 0 and abs(X) > left)
                left = abs(X);
            else if (Y < 0 and abs(Y) > down)
                down = abs(Y);
        }

        cout << 2 * (up + right + left + down) << endl;
    }

    return 0;
}
