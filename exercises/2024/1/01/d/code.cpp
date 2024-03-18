#include <bits/stdc++.h>

using namespace std;

struct Point {
    int x, y;
};

int main() {
    ios::sync_with_stdio(false);
    
    int T;
    cin >> T;

    while (T--) {
        Point A, B, C;

        cin >> A.x >> A.y;
        cin >> B.x >> B.y;
        cin >> C.x >> C.y;

        int ab = abs(A.x - B.x) + abs(A.y - B.y);
        int ac = abs(A.x - C.x) + abs(A.y - C.y);

        int ans = 0;

        for (int x : {A.x, B.x, C.x}) {
            for (int y : {A.y, B.y, C.y}) {
                int d1 = abs(x - A.x) + abs(x - B.x) + abs(y - A.y) + abs(y - B.y);
                int d2 = abs(x - A.x) + abs(x - C.x) + abs(y - A.y) + abs(y - C.y);

                if (d1 == ab and d2 == ac)
                    ans = max(ans, abs(x - A.x) + abs(y - A.y));
            }
        }

        cout << ++ans << endl;
    }

    return 0;
}
