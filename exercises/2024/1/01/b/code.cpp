#include <bits/stdc++.h>

using namespace std;

void yes(bool value) {
    cout << (value ? "YES" : "NO") << endl;
}

int main() {
    ios::sync_with_stdio(false);

    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;

        string S;
        cin >> S;

        pair<int, int> pos(0, 0);
        bool ok = false;

        for (int i = 0; i < N; i++) {
            char mov = S[i];
            pair<int, int> dir;
    
            if (mov == 'L')
                dir = make_pair(-1, 0);
            else if (mov == 'R')
                dir = make_pair(1, 0);
            else if (mov == 'U')
                dir = make_pair(0, 1);
            else if (mov == 'D')
                dir = make_pair(0, -1);

            pos.first = pos.first + dir.first;
            pos.second = pos.second + dir.second;

            if (pos == make_pair(1, 1)) {
                ok = true;
                break;
            }
        }

        yes(ok);
    }

    return 0;
}
