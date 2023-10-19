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
#include <cstring>

using namespace std;
using edge = pair<int, int>;

const int MAX = 100010;

int dfs_num[MAX], dfs_low[MAX];
vector<int> adj[MAX];

void dfs_bridge(int u, int p, int &next, vector<edge> &bridges)
{
    dfs_low[u] = dfs_num[u] = next++;

    for (auto v : adj[u]) {
        if (not dfs_num[v]) {
            dfs_bridge(v, u, next, bridges);

            if (dfs_low[v] > dfs_num[u])
                bridges.emplace_back(u, v);

            dfs_low[u] = min(dfs_low[u], dfs_low[v]);
        } else if (v != p) {
            dfs_low[u] = min(dfs_low[u], dfs_num[v]);
        }
    }
}

vector<edge> bridges(int N) {
    memset(dfs_num, 0, (N + 1) * sizeof(int));
    memset(dfs_low, 0, (N + 1) * sizeof(int));

    vector<edge> bridges;

    for (int u = 1, next = 1; u <= N; ++u)
        if (not dfs_num[u])
            dfs_bridge(u, u, next, bridges);

    return bridges;
}

int main() {
    ios::sync_with_stdio(false);

    int N, M, A, B;
    cin >> N >> M;

    for (int i = 0; i < M; i++) {
        cin >> A >> B;
        adj[A].push_back(B);
        adj[B].push_back(A);
    }

    auto bs = bridges(A);
    cout << bs.size() << '\n';
}
