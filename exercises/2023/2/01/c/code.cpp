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

int main()
{
    ios::sync_with_stdio(false);

    int N, M;
    cin >> N >> M;

    int count = 0;
    vector<vector<int>> adj(N + 1, vector<int>());

    for (int i = 0; i < M; ++i)
    {
        int A, B;
        cin >> A >> B;

        adj[A].push_back(B);
        adj[B].push_back(A);
    }

    for (int i = 0; i < M; ++i)
    {
        vector<int> to_remove;

        for (int i = 1; i < adj.size(); ++i)
            if (adj[i].size() == 1)
                to_remove.push_back(i);

        if (to_remove.size() == 0)
            break;

        count++;

        for (auto v : to_remove)
            for (auto u : adj[v])
            {
                auto it = find(adj[u].begin(), adj[u].end(), v);
                adj[u].erase(it);
                adj[v].clear();
            }
    }

    cout << count << endl;
}
