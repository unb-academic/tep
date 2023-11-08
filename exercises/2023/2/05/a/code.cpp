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
#include <limits>
#include <vector>
#include <bitset>
#include <queue>
#include <algorithm>

using namespace std;
using ii = pair<long long, long long>;

const long long MAX = 100010;
const long long oo = numeric_limits<long long>::max();

vector<ii> adj[MAX];
bitset<MAX> processed;

pair<vector<long long>, vector<long long>> dijkstra(long long s, long long N)
{
    vector<long long> dist(N + 1, oo), pred(N + 1, oo);
    dist[s] = 0;
    pred[s] = s;

    processed.reset();

    priority_queue<ii, vector<ii>, greater<ii>> pq;
    pq.emplace(0, s);

    while (not pq.empty())
    {
        auto [d, u] = pq.top();
        pq.pop();

        if (processed[u])
            continue;

        processed[u] = true;

        for (auto [v, w] : adj[u])
        {
            if (dist[v] > d + w)
            {
                dist[v] = d + w;
                pred[v] = u;
                pq.emplace(dist[v], v);
            }
        }
    }

    return {dist, pred};
}

vector<ii> path(long long s, long long u, const vector<long long> &pred)
{
    vector<ii> p;
    long long v = u;

    do
    {
        p.push_back(ii(pred[v], v));
        v = pred[v];
    } while (v != s);

    reverse(p.begin(), p.end());

    return p;
}

int main()
{
    long long N, M;
    cin >> N >> M;

    while (M--)
    {
        long long A, B, W;
        cin >> A >> B >> W;

        adj[A].emplace_back(B, W);
        adj[B].emplace_back(A, W);
    }

    auto [dist, pred] = dijkstra(1, N);

    if (dist[N] == oo)
    {
        cout << -1 << endl;
        return 0;
    }

    auto p = path(1, N, pred);

    for (size_t i = 0; i < p.size(); ++i)
    {
        if (i + 1 == p.size())
            cout << p[i].first << " " << p[i].second << endl;
        else
            cout << p[i].first << " ";
    }

    return 0;
}
