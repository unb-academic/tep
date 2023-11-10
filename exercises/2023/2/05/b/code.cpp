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
#include <limits>
#include <set>

using namespace std;
using ii = pair<int, int>;

const int oo = numeric_limits<int>::max();

vector<int> dijkstra(int s, int N, vector<vector<ii>> &adj)
{
    vector<int> dist(N + 1, oo);
    dist[s] = 0;

    set<ii> U;
    U.emplace(0, s);

    while (not U.empty())
    {
        int d = U.begin()->first;
        int u = U.begin()->second;
        U.erase(U.begin());

        for (auto vw : adj[u])
        {
            auto v = vw.first;
            auto w = vw.second;

            if (dist[v] > d + w)
            {
                if (U.count(ii(dist[v], v)))
                    U.erase(ii(dist[v], v));

                dist[v] = d + w;
                U.emplace(dist[v], v);
            }
        }
    }

    return dist;
}

int main()
{
    long long R;
    cin >> R;

    for (long long i = 0; i < R; i++)
    {
        int N, M, S, T;
        cin >> N >> M >> S >> T;

        vector<vector<ii>> adj(N + 1, vector<ii>(0));

        while (M--)
        {
            int A, B, W;
            cin >> A >> B >> W;

            adj[A].emplace_back(B, W);
            adj[B].emplace_back(A, W);
        }

        auto dist = dijkstra(S, N, adj);
        cout << "Case #" << i + 1 << ": ";

        if (dist[T] == oo)
            cout << "unreachable";
        else
            cout << dist[T];

        cout << endl;
    }

    return 0;
}
