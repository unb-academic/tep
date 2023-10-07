/*
 * MIT License
 *
 * Copyright (c) 2023 UnB
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 **/

#include <iostream>
#include <vector>

using namespace std;

void floyd(const vector<int>& succ, long long steps) {
    int L = 1, H = 1;

    do {
        L = succ[L];
        H = succ[succ[H]];
    } while (L != H);

    L = 1;

    while (L != H) {
        L = succ[L];
        H = succ[H];

        if (--steps == 0) {
            cout << L << endl;
            return;
        }
    }

    auto mu = L;
    auto lambda = 0;

    do {
        H = succ[H];
        ++lambda;
    } while (L != H);

    int mod = steps % lambda;

    while (mod--)
        L = succ[L];

    cout << L << endl;
}

int main() {
    ios::sync_with_stdio(false);

    int N;
    long long K;
    cin >> N >> K;

    vector<int> A(N + 1, -1);

    for (int i = 1; i <= N; i++)
        cin >> A[i];

    floyd(A, K);
}
